#include <stdio.h>

long long int d[90];

long long int dp(int x){
    if (x==0) return 0;
    if (x==1) return 1;
    if (d[x]!=0) return d[x];
    return d[x] = dp(x-1) + dp(x-2);
}

int main(void){
    int input;
	long long int output;
	scanf("%d", &input);
	output = dp(input);
	printf("%lld", output);
	return 0;
}