#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double monte_carlo(int loop){
    double x, y;
    int i, cntr;
    cntr = 0;

    FILE *fp1, *fp2;
    fp1 = fopen("xy.csv", "w");
    fp2 = fopen("in_circle.csv", "w");

    for (i=0; i < loop; i++){
        srand(i);
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        fprintf(fp1, "%lf, %lf\n", x, y);

        if(x*x + y*y < 1){
            cntr++;
            fprintf(fp2, "%lf, %lf\n", x, y);
        }
    }
    printf("%d/ %d\n", cntr, loop);
    fclose(fp1);
    fclose(fp2);
    return (double)4 * (double)cntr / (double)loop;
}

int main(void)
{
    int loop;
    loop = 100000;
    printf("%lf\n", monte_carlo(loop));

    return 0;
}