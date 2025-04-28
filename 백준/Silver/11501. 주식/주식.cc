#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<long long> valueVec;

int main() {

    // 주식 하나를 산다.
    // 원하는 만큼 가지고 있는 주식을 판다.
    // 아무것도 안한다.
    cin >> t;


    for(int i = 0; i < t; i++){
        cin >> n;
        valueVec = vector<long long>(n);
        
        for(int j = 0; j < n; j++){
            cin >> valueVec[j];
        }

        
        long long sum = 0;
        long long maxValue = 0;
        for(int j = n-1; j >= 0; j--){
            
            maxValue = max(maxValue, valueVec[j]);

            if(maxValue > valueVec[j]){
                sum += maxValue - valueVec[j];
            }
        }
    
        cout << sum << '\n';
    }


    return 0;
}