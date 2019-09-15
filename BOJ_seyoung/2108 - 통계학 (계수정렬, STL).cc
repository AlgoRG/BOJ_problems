#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Sortarray[500001];
int countA[8001];


int main() {
	int n;
	scanf("%d", &n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &Sortarray[i]);
		sum = sum + Sortarray[i];
		countA[Sortarray[i] + 4000]++;
	}

	int maxindex = 0;

	vector<int> vec;
	for (int i = 0; i < 8001; i++) {
		if (countA[maxindex] < countA[i]) {
			vec.clear();
			maxindex = i;
			vec.push_back(i - 4000);
			
		}
		// 벡터에 최빈값의 인덱스를 모두 넣기
		else if (countA[i] != 0 && countA[maxindex] == countA[i]) {
			vec.push_back(i - 4000);
		}
	}
	double av = (double)sum / n;
	
	sort(Sortarray, Sortarray + n);


	printf("%.0f\n%d\n", av, Sortarray[n / 2]);
	if (vec.size() == 1) {
		printf("%d\n", vec[0]);
	}else if (vec.size() !=0) {
		printf("%d\n", vec[1]);
	}
	printf("%d\n", Sortarray[n - 1] - Sortarray[0]);
}

