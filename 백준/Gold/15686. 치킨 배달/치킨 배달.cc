#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e7

using namespace std;

vector<pair<int, int>> chickenVec;
vector<pair<int, int>> houseVec;
int ans = INF;

int GetDis(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int n, m;
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;

            if (num == 2) chickenVec.push_back({ i, j });
            else if (num == 1) houseVec.push_back({i, j});
        }
    }

    // (치킨집 개수)C(m)일 때 최솟값 구하기
    vector<vector<int>> combVec;
    for(int i = 0; i < chickenVec.size(); i++){
        queue<vector<int>> q;
        q.push(vector<int>(1, i));
        while(!q.empty()){
            vector<int> cur = q.front(); 
            q.pop();
            
            if(m == cur.size()) 
            {
                combVec.push_back(cur);
                continue;
            }
            
            for(int j = *(cur.end()-1)+1; j < chickenVec.size(); j++){
                vector<int> newComb(cur);
                newComb.push_back(j);
                q.push(newComb);
            }
        }
    }

    for(auto& comb : combVec){
        int index = 1;
        int tmpRes = 0;
        for (auto& house : houseVec) {
            int res = INF;
            //cout << index++ << " : ";
            for (auto& v : comb) {
                pair<int, int> chicken = chickenVec[v];
                //cout << GetDis(house, chicken) << " ";
                res = min(res, GetDis(house, chicken));
            }
            tmpRes += res;
            //cout << '\n';
        }
        ans = min(ans, tmpRes);
    }

    cout << ans;

    return 0;
}