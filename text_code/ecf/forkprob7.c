/* $begin forkprob7 */
#include "csapp.h"
int counter = 1;

int main()
{
    if (fork() == 0)
    {
        printf("child before %d\n", counter);
        counter--;
        printf("child aftere %d\n", counter);
        exit(0);
    }
    else
    {
        Wait(NULL);
        printf("parent before %d\n", counter);
        printf("counter = %d\n", ++counter);
    }
    exit(0);
}
/* $end forkprob7 */
