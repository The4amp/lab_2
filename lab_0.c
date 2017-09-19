#include <stdio.h>
#include <math.h>
#include <stdlib.h>

	double x;
	double a = 0.0;
	double b = 10.0;
	int n = 20;
	
double func(double x1){
	return sin(x1/2);
	}

void tab(){
	double h = (b-a)/(n);	
	FILE *ff;	
	ff = fopen("text.txt", "wb");

	double t = 0.0;
    for (int i=0;i<n;i++){
        t=a+i*h;
        fprintf(ff,"%lf %lf\n", t , func(t));
    }
	fclose(ff);
	}	
int main(int argc, char **argv)
{
	tab();
	system("PAUSE");
	
	
	return 0;
}
