#include <iostream>
// 1,000,000개 일 때는 무조건 N*logN으로 풀어야 함
// 1초에 1억번 연산

using namespace std;

void quickSort(int *, int, int);

int main(){
	int number;
	int array[1000001];
	cin >> number;
	// 데이터 하나씩 입력
	for (int i = 0; i < number; i++) {
		cin >> array[i];
	}

	quickSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		cout << array[i]<<endl;
	}

}

void quickSort(int *data, int start, int end) {
	if (start >= end) {
		return; // 배열 길이가 1일 경우
	}

	int key = start;
	int i = start + 1, j = end, temp; // i는 큰값 찾기, j는 작은 값 찾기

	while (i <= j) { //엇갈릴 때 까지 반복
		while (data[i] <= data[key] && i <= end) {
			i++;
		} //key값보다 큰거 나올때까지 반복

		while (data[j] >= data[key] && j > start) {
			j--;
		} //key값보다 큰거 나올때까지 반복

		//엇갈린 상태가 된다면, 
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp; // key값과 작은 값 서로 교체
		} // 이 때 while문 빠져나오게 됨, 그리고 그룹이 2개로 분할됨

		else {
			//엇갈리지 않은 상태라면
			temp = data[i];
			data[i] = data[j];
			data[j] = temp; //작은 값과 큰 값 서로 교체
		}  

	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end); // 끝나게 된 기준이 j의 인덱스에 위치한 값이 됨

}
