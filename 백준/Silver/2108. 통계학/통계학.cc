#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    vector<int> vec(n);
    vector<int> numCount(8001);
    double avg = 0;
    int midean = 0;
    vector<int> mode;
    int modeCount = 0;
    int range = 0;

    double sum = 0;
    int minNum = 4001;
    int maxNum = -4001;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        sum += vec[i];

        numCount[vec[i] + 4000]++;
        modeCount = max(modeCount, numCount[vec[i] + 4000]);
        maxNum = max(maxNum, vec[i]);
        minNum = min(minNum, vec[i]);
    }

    sort(vec.begin(), vec.end());

    // 산술 평균 출력
    avg = round(sum / (double)n);
    if (avg == -0) avg = 0;
    cout << avg << '\n';

    // 중앙값 출력
    midean = vec[n / 2];
    cout << midean << '\n';

    // 최빈값 출력
    for (int i = minNum; i <= maxNum; i++) {
        if (modeCount == numCount[i + 4000]) {
            mode.push_back(i);
        }
    }
    sort(mode.begin(), mode.end());

    int modeNum = mode[0];
    if (mode.size() >= 2) modeNum = mode[1];
    
    cout << modeNum << '\n';

    // 범위 출력
    range = abs(maxNum - minNum);
    cout << range << '\n';

    return 0;
}
