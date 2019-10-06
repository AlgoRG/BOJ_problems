#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int visited[100001];            // 방문
int parent[100001];            // 부모 저장
int n;

vector<int> adj[100001]; //인접행렬
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int x, y, next;
	cin >> n;

	for (int i = 1; i < 100001; i++) {
		adj[i].push_back(0); //각 노드 벡터의 0번째는 부모노드를 가르킴, 기본값 0 설정
	}

	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	
	// bfs 사용
	q.push(1); // 큐에 저장
	
	// 큐가 빌 때까지
	while (!q.empty()) {
		int x = q.front();
		q.pop(); // 맨 앞에 있는 값 큐에서 삭제하기

		visited[x] = true;
		for (int i = 1; i < adj[x].size(); i++) {
			next = adj[x][i];
			if (visited[next] == true)
				continue;
			else {
				adj[next][0] = x;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout<< adj[i][0]<<"\n";
	}


}
