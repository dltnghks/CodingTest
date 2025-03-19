#include <iostream>
#include <vector>
#include <queue>

#define MAX 1e6

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    
    int size = max(n,k)*2 + 1;
    vector<int> dis(size, MAX);

    priority_queue<pair<int, int>> pq;
    pq.push({0, n});
    dis[n] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int curDis = -pq.top().first;
        pq.pop();

        //cout << cur << '\n';
    
        if(dis[cur] < curDis) continue;

        int move[] = {-1, 1};
        for(int i = 0 ; i < 2; i++){
            int next = cur + move[i];
            int nextDis = curDis+1;
            if(0 <= next && next < size && dis[next] > nextDis){
                dis[next] = min(dis[next], nextDis);
                pq.push({-nextDis, next});
            }
        }

        int next = cur * 2;
        if(0 < next && next < size){
            dis[next] = min(dis[next], curDis);
            pq.push({-curDis, next});
        }
        
    }

    // int index = 0;
    // for(auto val : dis){
    //     cout << index++ << ": " << val << '\n';
    // }

    cout << dis[k] << '\n';

    return 0;
}