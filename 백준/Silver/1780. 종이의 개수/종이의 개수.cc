#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int ans[3];

void Solve(int startX, int startY, int size){
    int startNum = map[startY][startX];

    ans[startNum+1]++;

    if(size == 1) return;

    for(int i = startY; i < startY+size; i++){
        for(int j = startX; j < startX+size; j++){
            if(startNum != map[i][j]){
                ans[startNum+1]--;
                // 아홉조각으로 자르기

                int newSize = size/3;

                Solve(startX, startY, newSize);
                Solve(startX + newSize, startY, newSize);
                Solve(startX + 2 * newSize, startY, newSize);
                
                startY += newSize;
                Solve(startX, startY, newSize);
                Solve(startX + newSize, startY, newSize);
                Solve(startX + 2 * newSize, startY, newSize);

                startY += newSize;
                Solve(startX, startY, newSize);
                Solve(startX + newSize, startY, newSize);
                Solve(startX + 2 * newSize, startY, newSize);
                return;
            }
        }
    }
}

int main() {

    int n;
    cin >> n;

    map = vector<vector<int>>(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    Solve(0, 0, n);

    for(auto& n : ans){
        cout << n << '\n';
    }

    return 0;
}