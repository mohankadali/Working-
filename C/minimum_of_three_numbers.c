#include<stdio.h>

int smallest(int x, int y, int z)
{
        int c = 0;
        while ( x && y && z )
        {
                if( (x >> 31) & 1 || (y >> 31) & 1 || (z >>31) & 1)
               // if( x & (1 << 31) || (y & (1 <<31)) || ( z & (1 << 31)))
                {
                        printf("give postive values...\n") ;
                        return ;
                }
                x--;  y--; z--; c++;
        }
        return c;
}

int main()
{
        int x = 182, y = 15, z = 912;
        printf("Minimum of 3 numbers is %d", smallest(x, y, z));
        return 0;
}
