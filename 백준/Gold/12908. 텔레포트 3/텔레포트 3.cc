#include <iostream>
#include <vector>
#include <queue>

#define INF 1e10
#define START 0
#define END 7
#define SIZE 8
using namespace std;

#define ll long long

struct Point{
    ll x;
    ll y;
};

ll calDis(Point& s, Point& e){
    return abs(s.x- e.x) + abs(s.y- e.y);
}

vector<Point> pointVec(SIZE);
vector<vector<ll>> pointDisVec(SIZE, vector<ll>(8, INF));

int main(){

    ll xs, xe, ys, ye;

    cin >> xs >> ys;
    cin >> xe >> ye;
    
    pointVec[START] = {xs, ys};
    pointVec[END] = {xe, ye};
    
    for(ll i = 1; i <= 6; i+=2){
        ll tpsx, tpsy, tpex, tpey;
        cin >> tpsx >> tpsy >> tpex >> tpey;
        pointVec[i] = {tpsx, tpsy};
        pointVec[i+1] = {tpex, tpey};
    }
 
    
    // Init Graph
    for(ll i = 0; i < SIZE; i++){
        pointDisVec[i][i] = 0;
        for(ll j = 0; j < SIZE; j++){
            if(i==j) continue;
            if((i % 2 == 1 && j == i+1 )|| (i % 2 == 0 && j == i-1) ){
                pointDisVec[i][j] = min(pointDisVec[i][i] + 10, calDis(pointVec[i], pointVec[j]));
            }else{
                pointDisVec[i][j] = calDis(pointVec[i], pointVec[j]);
            }
        }
    }

    // for(ll i = 0; i < SIZE; i++){
    //     for(ll j = 0; j < SIZE; j++){
    //         cout << '\t' << pointDisVec[i][j] << " ";
    //     }
    //     cout << '\n';
    // }


    for(ll k = 0; k < SIZE; k++){
        for(ll i = 0; i < SIZE; i++){
            if(i == k) continue;
            for(ll j = 0; j < SIZE; j++){
                if(i == j) continue;
                pointDisVec[i][j] = min(pointDisVec[i][j], pointDisVec[i][k] + pointDisVec[k][j]);
            }
        }
    }

    cout << pointDisVec[START][END];
    return 0;
}