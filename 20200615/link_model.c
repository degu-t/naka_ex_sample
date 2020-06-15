#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define L1 10
#define L2 10
#define THETA_MAX 30
#define THETA_MIN 0
#define BIN 0.1
#define SIZE (int)(THETA_MAX * THETA_MAX / BIN / BIN)

//XとYをまとめて返す関数を作ってもよいが，面倒なのでやめる
//そうしたい場合は返り値をポインタにすればいいんじゃないかな(適当)
double calc_X(double theta1, double theta2){
    double X;
    X = L1 * cos(theta1) + L2 * cos(theta2 + theta1);
    return X;
}

double calc_Y(double theta1, double theta2){
    double Y;
    Y = L1 * sin(theta1) + L2 * sin(theta2 + theta1);

    return Y;
}

//頭を使いたくないので計算量や長さを考えず筋肉で解決する
//効率化などは知らん
int main(void)
{
    double theta1, theta2;
    double value_XY[SIZE][2];
    int cntr;

    FILE *fp;
    fp = fopen("result.csv", "w");

    cntr = 0;
    double theta1_rad, theta2_rad; //sin, cosはラジアンを引数にとる
    for(theta1 = THETA_MIN; theta1 < THETA_MAX; theta1 += BIN){
        for(theta2 = THETA_MIN; theta2 < THETA_MAX; theta2 += BIN){
            theta1_rad = theta1 * M_PI / 180;
            theta2_rad = theta2 * M_PI / 180;
            value_XY[cntr][0] = calc_X(theta2_rad, theta1_rad);
            value_XY[cntr][1] = calc_Y(theta2_rad, theta1_rad);
            //printf("%lf, %lf\n", theta1, theta2);
            fprintf(fp, "%lf, %lf\n", value_XY[cntr][0], value_XY[cntr][1]);
            cntr++;
        }
    }
    fclose(fp);
    return 0;
}