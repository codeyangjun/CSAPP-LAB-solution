/* $begin forkprob2 */
#include "csapp.h"

void end(void)
{
    printf("2\n");
    printf("L1\n");
    fflush(stdout);

}

int main()
{
    printf("L0\n");
    if (Fork() == 0)
        atexit(end);
    printf("L2\n");

    if (Fork() == 0)
    {
        printf("0\n");
        printf("L3\n");
        fflush(stdout);
    }
    else
    {
        printf("1\n");
        printf("L4\n");
        fflush(stdout);
    }
    printf("L5\n");
    exit(0);
}
/* $end forkprob2 */
