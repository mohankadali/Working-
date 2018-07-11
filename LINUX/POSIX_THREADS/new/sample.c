#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_TICKETS 35

#define NUM_SELLERS 4

/**
 * The ticket counter and its associated lock will be accessed
 * all threads, so made global for easy access.
 */
static void SellTickets(void);
static int numTickets = NUM_TICKETS;
static Semaphore ticketsLock;
static void RandomDelay(int atLeastMicrosecs, int atMostMicrosecs)
{
        long choice;
        int range = atMostMicrosecs - atLeastMicrosecs;
        PROTECT(choice = random());                     // protect non-re-entrancy
        ThreadSleep(atLeastMicrosecs + choice % range); // put thread to sleep
}
/**
 * Our main is creates the initial semaphore lock in an unlocked state
 * (one thread can immediately acquire it) and sets up all of
 * the ticket seller threads, and lets them run to completion.  They
 * should all finish when all tickets have been sold. By running with the
 * -v flag, it will include the trace output from the thread library.
 */
void main(int argc, char **argv)
{
        int i;
        char name[32];
        int verbose = (argc == 2 && (strcmp(argv[1], "-v") == 0));
        InitThreadPackage(verbose);
        ticketsLock = SemaphoreNew("Tickets Lock", 1);
        for (i = 0; i < NUM_SELLERS; i++) {
                sprintf(name, "Seller #%d", i);
                // give each thread a distinct name
                ThreadNew(name, SellTickets, 0);
        }
        RunAllThreads(); 
        // Let all threads loose
        SemaphoreFree(ticketsLock);
        // to be tidy, clean up
        printf("All done!\n");
}

/**
 * SellTickets
 * -----------
 * This is the routine forked by each of the ticket-selling threads.
 * It will loop selling tickets until there are no more tickets left
 * to sell.  Before accessing the global numTickets variable,
 * it acquires the ticketsLock to ensure that our threads don't step
 * on one another and oversell on the number of tickets.
 */
static void SellTickets(void)
{
        int done = 0;
        int numSoldByThisThread = 0;
        // local vars are unique to each thread
        while (!done) {
                /**
                 * imagine some code here which does something independent of
                 * the other threads such as working with a customer to determine
                 * which tickets they want.  Simulate with a small random delay
                 * to get random variations in output patterns.
                 */
                RandomDelay(500000, 2000000);
                SemaphoreWait(ticketsLock);// ENTER CRITICAL SECTION
                if (numTickets == 0) {// here is safe to access numTickets
                        done = 1; // a "break" here instead of done variable
                } else {
                        numTickets--;
                        numSoldByThisThread++;
                        printf("%s sold one (%d left)\n", ThreadName(), numTickets);
                }
                SemaphoreSignal(ticketsLock);
                // LEAVE CRITICAL SECTION
        }
        printf("%s noticed all tickets sold! (I sold %d myself) \n",ThreadName(), numSoldByThisThread);
}
/**
 * RandomDelay
 * -----------
 * This is used to put the current thread to sleep for a little
 * bit to simulate some activity or perhaps just to vary the
 * execution patterns of the thread scheduling.  The low and high
 * limits are expressed in microseconds, the thread will sleep
 * at least the lower limit, and perhaps as high as upper limit
 * (or even more depending on the contention for the processors).
 */
