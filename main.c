#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 20

double omega(double *arr, int k, double x){
	double result = 1;
	for (int i = 0; i <= k; i++) {
		result *= (x - arr[i]);
	}
	return result;
}

double RozdRizn(double *x, double *y, double k) {
	double result = 0;
	
	for (int i = 0; i <= k; i++) {
		double multi = 1;
		
		for (int j = 0; j <= k; j++){
			if (j != i) {
				multi *= (x[i] - x[j]);
			} 
		}
		
		result += y[i]/multi;
	}
	return result;
}

double newton(int n, double x, double *xArr, double *y)
{
	double result = 0;
	result += y[0];
	
	for (int i = 1; i <= n; i++){
		result += omega(xArr, i - 1, x) * RozdRizn(xArr, y, i);
	}
	
	return result;
}

int main(int argc, char **argv)
{
	FILE *file;
    file = fopen("text.txt","r");
    double x[N + 1], y[N + 1];
    for (int i=0;i<N;i++){
       fscanf(file, "%lf %lf\n", &x[i] , &y[i]);
    }
    
    printf("%e", newton(10, 3.14, x, y));
    
    fclose(file);
    return 0;	
} 
 
