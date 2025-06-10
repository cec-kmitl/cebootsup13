#include <stdio.h>

double cook(double n) {
   double i, y = 0.0000001;
   for(i = 1; i*i <= n; ++i);
   for(--i; i*i < n; i += y);
   return i;
}


int main(){
    double n;
    scanf("%lf", &n);
    printf("%.6lf", cook(n));
}
