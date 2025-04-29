#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> wVec;

int day[] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30 ,31 ,30 ,31 };

int change(int m, int d){
    int sum = 0;
    for (int i = 1; i < m; i++) {
        sum += day[i];
    }
    sum += d;
    return sum;
}

int main() {

    int n;
    cin >> n;

    int pivotS = change(3, 1);      // 시작일 3월 1일
    int pivotE = change(11, 30);    // 종료일 11월 30일

    vector<pair<int, int>> flowers;

    for (int i = 0; i < n; i++) {
        int sm, sd, em, ee;
        cin >> sm >> sd >> em >> ee;
        
        int st = change(sm, sd);
        int et = change(em, ee);
        
        // 공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다. => 종료일이 3월1일인 것들은 컷, 시작일이 11월 30일인 것도 컷
        if (et <= pivotS || st > pivotE) {
            continue;
        }

        flowers.push_back({ st, et });
    }
    n = flowers.size();

    sort(flowers.begin(), flowers.end());

    /*for (auto& flower : flowers) {
        cout << flower.first << " , " << flower.second << '\n';
    }*/

    // 정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다. => 최솟값 찾기

    // 일단 3월 1일 전에 최댓값 찾기 -> count
    int curS = 0;
    int curE = 0;
    int curIndex = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if (flowers[i].first <= pivotS && (curE < flowers[i].second))
        {
            curS = flowers[i].first;
            curE = flowers[i].second;
            curIndex = i;
        }
        else if (flowers[i].first > pivotS) {
            break;
        }
    }

    if (curE == 0) {
        cout << 0 << '\n';
        return 0;
    }
    ans++;
    //cout << "curE : " << curE << '\n';

    // 그 이후 시작일과 마지막일 사이에서 최댓값 찾기 -> count
    // 찾은 값이 11월 30일을 넘어가면 종료
    while (curE <= pivotE) {
        pivotS = curE;
        for (int i = curIndex+1; i < n; i++)
        {
            if (flowers[i].first <= pivotS && (curE < flowers[i].second))
            {
                curS = flowers[i].first;
                curE = flowers[i].second;
                curIndex = i;
            }
            else if(flowers[i].first > pivotS){
                break;
            }
        }
        //cout << "curE : " <<  curE << '\n';
        if (pivotS == curE) break;
        ans++;
    }

    if (curE <= pivotE) {
        cout << 0 << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}