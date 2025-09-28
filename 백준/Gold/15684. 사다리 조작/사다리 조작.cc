#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAIL -1

vector<pair<int, int>> lineVec;             // 비활성화된 라인 vector, first -> 세로선 번호, second -> 높이
vector<vector<bool>> isLineVec;             // isLineVec[i][j] -> j높이의 가로선이 i번째 세로선과 i+1번째 세로선을 연결하고 있는가? true = 연결, false = 연결 X
int n, m, h;                                // n - 세로선 개수, m - 이미 설치된 가로선 수, h - 높이

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int recursive(int newActiveLineCount, int targetCount, int curIndex){
    if(targetCount > newActiveLineCount){
        for(int i = curIndex; i < lineVec.size(); i++){
            pair<int, int> lineVal = lineVec[i];

            // 연속으로 켜지는 경우 패쓰.
            if(isLineVec[lineVal.first-1][lineVal.second])
                continue;

            isLineVec[lineVal.first][lineVal.second] = true;
            int res = recursive(newActiveLineCount+1, targetCount, i+1);
            if(FAIL != res){
                return 0;
            }
            isLineVec[lineVal.first][lineVal.second] = false;
        }
        return FAIL;
    }
    
    // 모든 선 연결 후 계산해보기
    for(int i = 1; i <= n; i++){
        int curLineNum = i;
        for(int j = 1; j <= h; j++){
            if(isLineVec[curLineNum][j] == true){
                curLineNum = curLineNum + 1;
            }else if(isLineVec[curLineNum-1][j] == true ){
                curLineNum = curLineNum - 1;
            }
        }

        if(i != curLineNum){
            return FAIL;
        }
    }

    return 0;
}

bool cal(int n){
    if(FAIL != recursive(0, n, 0)){
        return true;
    }
    return false;
}

int main(){
    // 입력
    cin >> n >> m >> h;

    lineVec = vector<pair<int, int>>();
    isLineVec = vector<vector<bool>>(n+2, vector<bool>(h+2, false));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        isLineVec[b][a] = true;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= h; j++){
            // 본인이 활성화 되어있지 않고 양 옆에 라인이 없는 경우 
            if(!isLineVec[i][j] && !isLineVec[i-1][j] && !isLineVec[i+1][j]){
                //비활성 라인 맵에 추가
                lineVec.push_back({i, j});
            }
        }   
    }

    sort(lineVec.begin(), lineVec.end(), compare);

    // 로직
    int ans = FAIL;
    for(int i = 0; i <= 3; i++){
        // 0, 1, 2, 3개인 경우 하나씩 해보기
        if(cal(i)){
            ans = i;
            break;
        }
    }

    // 출력
    cout << ans;

    return 0;
}