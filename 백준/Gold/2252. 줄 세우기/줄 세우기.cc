#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // 1. 그래프와 진입 차수(inDegree) 테이블 생성
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); // a 뒤에 b가 선다
        inDegree[b]++;         // b의 진입 차수 증가 (내 앞에 한 명 더 생김)
    }

    // 2. 진입 차수가 0인(바로 줄 서도 되는) 학생 큐에 넣기
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    // 3. 큐가 빌 때까지 반복 (위상 정렬 수행)
    while(!q.empty()){
        // 1. 큐에서 학생(cur)을 꺼내고 출력한다.
        int cur = q.front();
        cout << cur << " ";
        q.pop();

        // 2. graph[cur]에 연결된 다음 학생(next)들의 inDegree를 1 줄인다.
        for(int next : graph[cur]){
            inDegree[next]--;
            // 3. 만약 inDegree가 0이 된 학생이 있다면 큐에 넣는다.
            if(inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    return 0;
}