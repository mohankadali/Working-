#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define NUM_GPIO_PINS   21
#define MAX_GPIO_NUMBER 32
#define BUF_SIZE        4
#define PATH_SIZE 20
int main(int argc, char **argv)
{
        int i = 0, index = 0, value;
        int fd[NUM_GPIO_PINS];
        char path[PATH_SIZE];
        char buf[BUF_SIZE];
        if (argc != 2) {

                printf("Option low/high must be used\n");
                exit(EXIT_FAILURE);
        }
        // Open all GPIO pins
        for (i = 0; i < MAX_GPIO_NUMBER; i++) {
                if (i != 0 && i != 1 && i != 5 && i != 6 &&
                                i != 12 && i != 13 && i != 16 && i != 19 &&
                                i != 20 && i != 21 
                                && i != 26) {
                        snprintf(path, sizeof(path), "/dev/raspiGpio%d", i);
                        fd[index] = open(path, O_WRONLY);
                        if (fd[index] < 0) {
                                perror("Error opening GPIO pin");
                                exit(EXIT_FAILURE);
                        }
                        index++;
                }
        }
        // Set direction of GPIO pins to output
        printf("Set GPIO pins to output, logic level :%s\n", argv[1]);
        strncpy(buf, "out", 3);
        buf[3] = '\0';
        for (index = 0; index < NUM_GPIO_PINS; index++) {
                if (write(fd[index], buf, sizeof(buf)) < 0) {
                        perror("write, set pin output");
                        exit(EXIT_FAILURE);
                }
        }
        // Set logic state of GPIO pins low/high
        value = atoi(argv[1]);
        if (value == 1) {
                strncpy(buf, "1", 1);
                buf[1] = '\0';
        } else if (value == 0) {
                strncpy(buf, "0", 1);
                buf[1] = '\0';
        } else {
                printf("Invalid logic value\n");
                exit(EXIT_FAILURE);
        }
        for (index = 0; index < NUM_GPIO_PINS; index++) {
                if (write(fd[index], buf, sizeof(buf)) < 0) {
                        perror("write, set GPIO state of GPIO pins");
                        exit(EXIT_FAILURE);
                }
        }
        return EXIT_SUCCESS;
}



