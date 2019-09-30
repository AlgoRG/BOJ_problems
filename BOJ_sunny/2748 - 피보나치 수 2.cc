#include <iostream>
using namespace std;
long long d[91];
long long fibo(int x) {
	if (x == 0 || x == 1)    return x;
	if (d[x] != 0)    return d[x];
	return d[x] = fibo(x - 1) + fibo(x - 2);
}

int main(void) {
	int n;
	cin >> n;
	printf("%lld\n", fibo(n));
	return 0;
}