#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double monte_carlo(int loop){
    double x, y;
    int i, cntr;
    cntr = 0;

    for (i=0; i < loop; i++){
        srand(i);
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if(x*x + y*y < 1){
            cntr++;
            //printf("%d, %lf, %lf\n", cntr, x, y);
        }
    }
    printf("%d/ %d\n", cntr, loop);
    return (double)4 * (double)cntr / (double)loop;
}

int main(void)
{
    int loop;
    loop = 100000;
    printf("%lf\n", monte_carlo(loop));

    return 0;
}