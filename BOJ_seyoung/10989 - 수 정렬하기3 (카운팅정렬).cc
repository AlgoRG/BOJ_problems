#include <iostream>

using namespace std;

int count[10001];

int main() {
	int i, j, num, length;
	scanf("%d", &length);

	for (i = 1; i < length + 1; i++) {
		scanf("%d", &num);
		count[num]++; 
	}

	for (i = 1; i < 10001; i++) {
		while (count[i] != 0) {
			printf("%d\n", i);
			count[i]--;
		}
	}
}
