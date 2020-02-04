#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int map[8][8];
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
int n, m;
int ans = 0;

void spread() {
	queue<int> q;
	int copy[8][8];
	int visited[8][8] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j] = map[i][j];
			if (copy[i][j] == 2) {
				q.push(i * 10 + j);
				visited[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int cy = q.front() / 10;
		int cx = q.front() % 10;
		q.pop();
		copy[cy][cx] = 2;
		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (visited[ny][nx]==0 && copy[ny][nx] == 0) {
				visited[ny][nx] = 1;
				q.push(ny * 10 + nx);
			}
		}
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy[i][j] == 0)
				++num;
		}
	}
	ans = max(ans, num);
}

void pick_dfs(int cnt, int sy, int sx) {
	if (cnt == 3) {
		spread();
		return;
	}
	for (int i = sy; i < n; i++) {
		for (int j = sx; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				pick_dfs(cnt + 1, i, j);
				map[i][j] = 0;
			}
		}
		sx = 0;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	pick_dfs(0, 0, 0);
	printf("%d", ans);
	return 0;
}