#include <stdio.h>
#define NUM 100

double data_y[NUM] = {-0.77778,-0.25553,1.2009,2.2131,3.6336,4.791,5.7383,7.2255,8.1048,9.3268,10.992,11.603,10.912,
11.196,14.331,13.486,15.735,16.695,19.137,18.586,19.275,20.751,21.738,22.602,23.13,23.702,25.708,25.583,26.77,29.327,
29.141,30.307,31.981,32.162,34.029,34.093,35.979,36.704,37.123,37.669,38.531,40.027,40.896,41.896,43.805,43.931,45.873,
45.737,47.72,47.704,49.151,50.661,50.719,51.683,54.292,54.571,54.629,56.331,56.639,58.33,59.784,58.751,61.487,62.754,
62.794,64.907,64.827,64.88,65.223,67.444,69.122,69.839,70.884,71.204,72.665,72.457,74.024,74.965,76.838,77.463,77.683,
79.428,79.955,80.951,82.952,83.432,84.603,85.907,86.419,87.646,88.715,90.021,90.538,92.143,92.198,93.131,95.278,94.785,
96.103,97.699};
double data_x[NUM];
double time_step = 0.1;

//分散を計算する関数
//mainにxとy2回も書きたくないの，わかるかしら
double var(double* data, double num, double avr){
    //data[]は配列(ポインタ渡し)，numは配列サイズ(というかデータ数)，avrは平均
    int i;
    double sum_diff, ret;
    sum_diff = 0;
    for(i=0; i < num; i++){
        sum_diff += (data[i] - avr) * (data[i] - avr);
    }

    ret = sum_diff / num;
    return ret;
}

//共分散を計算する関数
//mainに書くのなんかやだ
double cov(double* data_x, double* data_y, double num, double avr_x, double avr_y){
    int i;
    double sum_diff, ret;
    sum_diff = 0;
    for (i=0; i<num; i++){
        sum_diff += (data_x[i] - avr_x) * (data_y[i] - avr_y);
    }
    ret = sum_diff / num;

    return ret;
}


//

int main(void) {
	// your code goes here
	
	int i;
	double num = (double)NUM;//割り算用の個数
	for(i = 0 ; i < NUM ; i++){
	    
	    data_x[i] = i*time_step;
	    printf("%f,%f\n",data_x[i], data_y[i]);
	}
	
	//ここまでの処理で自由落下の速度に関して
	//input_velに誤差が入った速度，input_timeに時間
	//がそれぞれの配列に入っている
    //これらの値を使って最小二乗法により，自由落下のモデル式を算出する
	
	//ヒント　１次式の最小二乗法は平均，分散，共分散の値から計算できる
	

	//平均の計算
	double sum_x=0;
	double sum_y=0;
	double ave_x=0;
	double ave_y=0;
	for(i = 0 ; i < NUM ; i++){
		sum_x = sum_x + data_x[i];
		sum_y = sum_y + data_y[i];
		
	}
	ave_x = sum_x/num;
	ave_y = sum_y/num;	
	printf("ave_x %f\n", ave_x);
	printf("ave_y %f\n", ave_y);

	
	//分散の計算
	double var_x;//分散x
	double var_y;//分散y

    var_x = var(data_x, num, ave_x);
    var_y = var(data_y, num, ave_y);
	printf("var_x %f\n", var_x);
	printf("var_y %f\n", var_y);

	
	//共分散の計算
	double cov_xy;
    cov_xy = cov(data_x, data_y, num, ave_x, ave_y);
	printf("cov_xy %f\n", cov_xy);

	//式の係数を求める
	double a;
	double b;

    //関数にするほどじゃないので書いちゃう
    a = cov_xy / var_x;
    b = ave_y - a * ave_x;
	printf("y = %f*x + %f \n", a , b);
	
	return 0;
}