#include <iostream>

using namespace std;

int main() {

	int array[3];

	int i, j, min, index, temp;

	for (i = 0; i < 3; i++) {
		cin >> array[i];
	}

	// 선택 정렬, 최솟값을 찾아서 교환하는 것

	for (i = 0; i < 3; i++) {
		min = 1000001;
		for (j = i; j < 3; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (i = 0; i < 3; i++) {
		cout << array[i]<<" ";
	}
}