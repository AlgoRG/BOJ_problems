#include <iostream>

using namespace std;

int main() {
	int i, j, num, length;
	int count[10001] = { 0 }; //10000���� ���� �ڿ���
	scanf("%d", &length);

	for (i = 1; i < length + 1; i++) {
		scanf("%d", &num);
		count[num]++; //�ش� ���� ���� Ƚ�� ����
	}

	for (i = 1; i < 10001; i++) {
		if (count[i] != 0) {
			for (j = 0; j < count[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}