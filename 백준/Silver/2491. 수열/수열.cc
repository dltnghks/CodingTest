#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int increaseCur = -1;
    int decreaseCur = 10;
    int increaseCnt = 0;
    int decreaseCnt = 0;
    int maxCnt = 0;
    int minCnt = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (increaseCur <= input) {
            increaseCnt++;
            increaseCur = input;
        }
        else {
            maxCnt = max(increaseCnt, maxCnt);
            increaseCnt = 1;
            increaseCur = input;
        }

        if (decreaseCur >= input) {
            decreaseCnt++;
            decreaseCur = input;
        }
        else {
            minCnt = max(decreaseCnt, minCnt);
            decreaseCnt = 1;
            decreaseCur = input;
        }
    }
    maxCnt = max(increaseCnt, maxCnt);
    minCnt = max(decreaseCnt, minCnt);

    cout << max(maxCnt, minCnt);

    return 0;
}
