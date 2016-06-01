#include <stdio.h>
#include <math.h>
using namespace std;


#define EPS 1e-7
+/*
UVA 10341 Solve it
Problem type : binary search for searching root of an equation
use binary search for finding root in bisection method.
lot of wrong answers because of cmath header !!!
f(a)*f(b) < 0,then there exists a root in this interval
*/
int p, q, r, s, t, u;

double solveFn(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bisection(){
	double low = 0, high = 1;
	while (low + EPS < high){
		double mid = (low + high) / 2;
		if (solveFn(low) * solveFn(mid) <= 0){
			high = mid;
		}
		else{
			low = mid;
		}
	}
	return (low + high) / 2;
}
int main() {

	LL n, i, j, k, result = 0, temp, m;
	LL x, y, z, sum, test_case, length, ans, len;


	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
	{
		if (solveFn(0)*solveFn(1) > 0){
			puts("No solution");
		}
		else
		{	
			printf("%.4lf\n", bisection());
		}
	}
	return 0;
}