#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;
struct  CONSULTING{
	int d, m;
};
struct CONSULTING arr[15] = { 0, };
int n, duedate = 0, sum = 0, maxP = 0;

void search(int t) {
	duedate = t + arr[t].d;
	sum = sum + arr[t].m;
	if (duedate > n)
		return;
	for (int i = duedate; i < n; i++) {
		if ( i + arr[i].d > n)
			continue;
		search(i);
		sum = sum - arr[i].m;
	}
	maxP = max(maxP, sum);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].d, &arr[i].m);
	}
	for (int i = 0; i < n; i++) {
		if (i + arr[i].d <= n)
			search(i);
		sum = 0;
	}
	printf("%d", maxP);
	return 0;
}