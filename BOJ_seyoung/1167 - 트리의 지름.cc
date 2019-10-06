#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

const int MAX = 100000 + 1;

int V;
bool visited[MAX];
vector< pair<int, int> > graph[MAX];

int diameter=0;
int farthestNode=0;


void DFS(int node, int cost){
        // 이미 방문한 노드라면 종료 
		if (visited[node])
            return;
            
		// 1. 방문 표시 
        visited[node] = true;

        //지름 업데이트
        if (diameter < cost){
            diameter = cost; // 가장 큰 값을 지름으로 업데이트 
            farthestNode = node; // 현재 노드를 루트노드로부터 가장 먼 노드로 갱신
        }
        for (int i = 0; i < graph[node].size(); i++){
        	 DFS(graph[node][i].first, cost + graph[node][i].second);
		}
           
		// 기존에는 배열로 해서 연결된 간선이 있는 지 한 번 더 확인하는 과정을 거쳐야 함
		// vector 사용 시, 연결된 것들만 어차피 보여서 한 번 더 처리할 필요 없음 
		
		// 기존 값에 다음 노드의 비용도 같이 더해야 누적값으로의 계산이 가능  
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>V; // 정점의 개수
	 
	for (int i=0; i<V; i++){
		int node;
		cin >>node; // 거리의 기준이 되는 정점  
		
		 while (1){
            	int node2, cost; // 연결된 정점과 거리 저장 
                cin >> node2;
                if (node2 == -1) // 노드 이름 대신 -1이 입력될 경우  
                        break; // 반복 종료 
                cin >> cost; 
                graph[node].push_back({ node2, cost }); 
				// 어차피 반대 노드일 때 또 나오니까 
				// 양방향으로 더해줄 필요 없음  
        }
	}
	
	DFS(1, 0);
	diameter=0;
	memset(visited, false, sizeof(visited)); // 초기화 
	DFS(farthestNode, 0);
	
	cout<<diameter<<"\n";
	return 0; 
}