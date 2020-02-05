#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;
struct POS {
	int y, x;
};
vector<POS> home, chicken, pick;
int n, m, t, ans;

void dfs(int pos) {
	if (pick.size() == m) {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int num = 1000000;
			for (int j = 0; j < pick.size(); j++) {
				num = min(num, abs(home[i].y - pick[j].y) + abs(home[i].x - pick[j].x));
			}
			sum += num;
		}
		ans = min(ans, sum);
		return;
	}
	for (int i = pos; i < chicken.size(); i++) {
		pick.push_back(chicken[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main(void) {
	POS target;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &t);
			if (t == 1) {
				target.y = i; target.x = j;
				home.push_back(target);
			}
			if (t == 2) {
				target.y = i; target.x = j;
				chicken.push_back(target);
			}
		}
	}
	ans = 1000000;
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
