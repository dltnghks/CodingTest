#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
   
    int n = 0;
    cin >> n;

    vector<ll> costs;
    for(int i = 0; i < n; i++){
        ll c;
        cin >> c;
        costs.push_back(c);
    }

    ll maxCost;
    cin >> maxCost;

    ll res = 0;
    ll first = 0;
    ll end = maxCost;
    ll mid = 0;

    while(first <= end){
        mid = (first + end) / 2;

        ll sumCost = 0;
        for(auto c : costs){
            sumCost += min(mid, c);
        }

        if(sumCost <= maxCost && res < sumCost){
            //cout << sumCost << " , " << mid  << '\n';
            res = mid;
        }

        if(sumCost > maxCost){
            end = mid - (ll)1;
        }else{
            first = mid + (ll)1;
        }  
    }


    ll ans = 0;
    for(auto c : costs){
        ans = max(ans, min(res, c));
    }
    cout << ans;


    return 0;
}