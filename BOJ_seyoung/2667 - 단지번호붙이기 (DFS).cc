#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_VALUE 26

// N: 전체 노드 개수, M: 간선 개수

int N, M, apar_count;
int adj[MAX_VALUE][MAX_VALUE];
int dfsVisit[MAX_VALUE][MAX_VALUE];
int numCount[MAX_VALUE*MAX_VALUE];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };


void dfs(int x, int y) {
	// 깊게 탐색

	// 탐색 시작 x, y 좌표, 2차원 배열로 생각하기

	// 1. 정점 방문 표시
	dfsVisit[x][y] = 1;

	numCount[apar_count]++;

	//해당 단지 수의 가구수 1개 추가
	
	// 기존의 탐색 방식이 아닌 4방향으로의 탐색만 진행하면 된다.
	// 4방향에 연결된 것이 없을 경우 한 단지로 보지 않기 때문에..

	for (int i = 0; i < 4; i++) {
		// 매번 새로 생성해야 한다. 배열 안의 값이 정해져있기 때문
		int nx = x + dx[i]; 
		int ny = y + dy[i];
		
		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			// 간선이 없거나, 방문한 적이 있다
			if (adj[nx][ny] == 0 || dfsVisit[nx][ny] == 1) continue;
			// 넘어감, 간선 있고, 방문한 적 없는 것을 찾아야 함
			dfs(nx, ny);
		} //좌표가 음수가 되는 것을 방지
		
	}
}

int main(void) {
	scanf("%d", &N);

	// 간선 연결하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &adj[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 방문한 적은 없는데 인접행렬의 값이 존재할 경우에
			// dfs를 새롭게 시작 (한 단지에 대한 탐색)
			if (!dfsVisit[i][j] && adj[i][j]) {
				dfs(i, j);
				// 탐색이 끝나면 단지 개수 추가
				apar_count++;
			}
		}
	}
	
	printf("%d\n", apar_count);

	sort(numCount, numCount + apar_count); // 만들어진 단지 개수만큼 오름차순 정렬
	for (int i = 0; i < apar_count; i++) 
		printf("%d\n", numCount[i]);

	return 0;
	
}