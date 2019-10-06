#include <iostream>
#include <queue>

using namespace std;

#define MAX_VALUE 1001

int N, M, V;                   
int adj[MAX_VALUE][MAX_VALUE];
int dfsVisit[MAX_VALUE];
int bfsVisit[MAX_VALUE];

void dfs(int v, int N) {
	// 깊게 탐색
	
	// 탐색 시작 정점, 정점의 개수 input

	// 1. 정점 방문 표시
	dfsVisit[v] = 1;
	// 2. 정점 출력
	printf("%d ", v);

	for (int i = 1; i <= N; i++) {
		// 간선이 없거나, 방문한 적이 있다
		if (adj[v][i] == 0 || dfsVisit[i] == 1) continue; 
		// 넘어감, 간선 있고, 방문한 적 없는 것을 찾아야 함
		dfs(i, N);
	}
}

void bfs(int v, int N) {
	// 큐 생성
	queue<int> q;
	// 큐에 정점 삽입
	q.push(v);
	// 정점 방문 표시
	bfsVisit[v] = 1;
	
	// 큐가 빌 때까지
	while (!q.empty()) {
		int x = q.front();
		// 큐의 맨 앞 값 삭제
		q.pop(); 
		// 큐의 맨 앞 정점 출력
		printf("%d ", x); 

		for (int i = 1; i <= N; i++) {
			// 간선이 연결되고, 방문한 적 없으면
			if (adj[x][i] == 1 && bfsVisit[i] == 0) {
				q.push(i);
				bfsVisit[i] = 1;
			}
		}
	}
}
int main(void) {
	int x, y; // 인접 행렬 만들기용

	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	dfs(V, N);
	printf("\n");
	bfs(V, N);

	return 0;
	
}