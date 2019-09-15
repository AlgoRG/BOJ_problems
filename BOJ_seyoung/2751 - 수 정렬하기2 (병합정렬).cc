#include <iostream>

using namespace std;

int Acount[1000001];

void merge(int data[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (data[i] <= data[j]) {
			Acount[k] = data[i];
			i++;
		}
		else {
			Acount[k] = data[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (int t = j; t <= n; t++) {
			Acount[k] = data[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			Acount[k] = data[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) {
		data[t] = Acount[t];
	}
}

void mergeSort(int data[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(data, m, middle);
		mergeSort(data, middle + 1, n);
		merge(data, m, middle, n);
	}
}


int main() {
	int n;
	int array[1000001] = { 0 };

	scanf("%d", &n);

	for (int i = 1; i < n+1; i++) {
		scanf("%d", &array[i]);
	}

	mergeSort(array, 1, n);

	for (int i = 1; i < n+1; i++) {
		printf("%d\n", array[i]);
	}

}

