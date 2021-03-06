#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[20000];
int n;

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		if (isdigit(a[i])) {
			sum = sum + a[i] - '0';
		}
	}
	return sum;
}
bool compare(string a, string b) {
	// 길이가 짧은 순서 우선
	// a가 자기 자신
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	// 길이가 같은 경우, 
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);

		if (aSum != bSum) {
			return aSum < bSum;
		}
		else {
			return a < b;
		}
		
	} 
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
			cout << a[i] << endl;
	}
	
}