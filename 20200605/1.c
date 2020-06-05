#include <stdio.h>
#include <stdlib.h>

#define G 9.80665 //重力加速度
#define TIME 10 //落下時間

double v(double t){
    return G * t;
}

double x(double t){
    return 0.5 * G * t * t;
}

int main(void){
    double data_x[TIME * 100];
    double data_v[TIME * 100];

    FILE *fp;
    fp = fopen("result.csv", "w");

    int cntr; //配列の番号管理用
    cntr = 0;
    double t;
    for(t = 0; t < TIME; t+=0.1){
        data_x[cntr] = x(t);
        data_v[cntr] = v(t);
        cntr++;
        printf("%lf, %lf, %lf\n", t, data_v[cntr-1], data_x[cntr-1]);
        fprintf(fp, "%lf, %lf, %lf\n", t, data_v[cntr-1], data_x[cntr-1]);
    }

    fclose(fp);
    return 0;
}