#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 10

using namespace std;

struct Pos{
    int x;
    int y;

    Pos(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int map[SIZE+1][SIZE+1] = {0,};
vector<Pos> edges;

int Distance(Pos a, Pos b ){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool CheckTriagle(){
    // 좌표 간 단순화를 위해 edges를 참조하여 읽기 쉬운 변수로 저장
    Pos a = edges[0];
    Pos b = edges[1];
    Pos c = edges[2];

    // 삼각형 안에 있는지를 확인하는 보조 함수 (벡터 외적 이용)
    auto isInside = [](Pos p, Pos a, Pos b, Pos c) {
        auto cross = [](Pos p1, Pos p2, Pos p3) {
            return (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
        };
        int d1 = cross(p, a, b);
        int d2 = cross(p, b, c);
        int d3 = cross(p, c, a);

        // 점이 삼각형 내부 혹은 변 위에 있는 경우 true
        bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
        bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
        return !(has_neg && has_pos);
    };

    for(int y = 1; y <= SIZE; y++){
        for(int x = 1; x <= SIZE; x++){
            Pos p(x, y);
            bool inside = isInside(p, a, b, c);

            if(inside){
                if(map[y][x] != 1) return false;
            } else {
                if(map[y][x] != 0) return false;
            }
        }
    }

    return true;
}

bool Compare(Pos& a, Pos& b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main() {
    
    // 세 꼭짓점을 찾기
    // 자기 점 기준으로 한 쪽만 1인 점이 꼭짓점임
    // 꼭짓점이 3개가 넘어가거나, 부족한 경우 0을 리턴
    for(int i = 1; i <= SIZE; i++){
        string input;
        cin >> input;
        for(int j = 1; j <= SIZE; j++){
            map[i][j] = input[j-1] - '0';
        }
    }


    // 꼭짓점 찾기
    int moveX[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int moveY[] = {1, 0, -1, -1, -1, 0, 1, 1};
    for(int i = 1; i <= SIZE; i++){
        for(int j = 1; j <= SIZE; j++){
            
            // 0은 패쓰
            if(map[i][j] == 0) continue;

            int cnt = 0;
            int oneCnt = 0;
            for(int k = 0; k < 8; k++){
                int nextX = j + moveX[k];
                int nextY = i + moveY[k];

                if(nextX > 0 && nextX <= SIZE && nextY > 0 && nextY <= SIZE)
                {
                    // 상하좌우만 카운팅
                    if(map[nextY][nextX] == 1 && k % 2 == 1) oneCnt++;
                    else if(map[nextY][nextX] == 0) cnt ++;
                }else{
                    cnt ++;
                }
            }

            if(cnt >= 5 && oneCnt <= 2){
                //cout << cnt << ", " << oneCnt << " : " << i << ", " << j << '\n';
                edges.push_back(Pos(j, i));
            }
            
        }
    }


    // 꼭짓점 3개인지 확인
    if(edges.size() != 3){
        cout << 0;
        return 0;
    }

    // 꼭짓점 간 거리 확인 - 한 점으로부터 나머지 두 점의 거리가 동일한 경우가 존재하지 않으면 안됨.
    if(!(Distance(edges[0], edges[1]) == Distance(edges[0], edges[2]) ||
        Distance(edges[1], edges[0]) == Distance(edges[1], edges[2]) ||
        Distance(edges[2], edges[0]) == Distance(edges[2], edges[1])
    ))
    {
        cout << 0;
        return 0;
    }

    sort(edges.begin(), edges.end(), Compare);

    // 각 점을 이어서 만든 삼각형 안의 좌표가 모두 1인지 확인
    // 삼각형 외부가 모두 0인지 확인
    if(!CheckTriagle()){
        cout << 0;
        return 0;
    }
    
    for(Pos& edge : edges){
        cout << edge.y << " " << edge.x << '\n';
    }

    return 0;
}