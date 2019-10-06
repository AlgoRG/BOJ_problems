#include <iostream>
#include <queue>

using namespace std;

#define MAX_VALUE 100
 
int N, M, numCount=-1;                   
int adj[MAX_VALUE][MAX_VALUE];
int dfsVisit[MAX_VALUE];
int bfsVisit[MAX_VALUE];


int dfs(int v, int N) {
	// 깊게 탐색
	
	// 탐색 시작 정점, 정점의 개수 input

	// 1. 정점 방문 표시
	dfsVisit[v] = 1;

	numCount = numCount + 1;

	for (int i = 1; i <= N; i++) {
		// 간선이 없거나, 방문한 적이 있다
		if (adj[v][i] == 0 || dfsVisit[i] == 1) continue; 
		// 넘어감, 간선 있고, 방문한 적 없는 것을 찾아야 함
		dfs(i, N);
	}

	return numCount;
}

int main(void) {
	int x, y; // 인접 행렬 만들기용

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	// 1번 컴퓨터가 바이러스에 걸렸을 때, 걸리게 되는 컴퓨터의 개수 구하기
	// 탐색 시작 노드를 1로 설정
	
	// dfs 와 bfs 중 메모리를 덜 사용하는 dfs 사용
	printf("%d", dfs(1, N));

	return 0;
	
}