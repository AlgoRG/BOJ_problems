#include <iostream>

using namespace std;

int main() {
	// 1초에 1억번 연산
	// 1000^2 = 1,000,000번
	int array[1001];

	int number, i, j, min, index, temp;
	cin >> number;
	for (i = 0; i < number; i++) {
		cin >> array[i];
	}

	// 선택 정렬, 최솟값을 찾아서 교환하는 것

	for (i = 0; i < number; i++) {
		min = 1001;
		for (j = i; j < number; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (i = 0; i < number; i++) {
		cout << array[i] << endl;
	}
}