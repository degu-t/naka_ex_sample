#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double monte_carlo(int loop){
    srand(time(NULL));

    double x, y;
    int i, cntr;
    
    FILE *fp;
    fp = fopen("result.csv", "w");

    for (i=0; i < loop; i++){
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if(x*x + y*y < 1){
            cntr++;
            printf("%lf, %lf\n", x, y);
        }
    }

    return 4 * cntr / loop;
}

int main(void)
{
    int loop;
    loop = 1000;
    printf("%lf\n", monte_carlo(loop));

    return 0;
}