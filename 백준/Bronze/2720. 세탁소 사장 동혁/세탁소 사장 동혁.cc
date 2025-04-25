#include <iostream>
#include <vector>

using namespace std;

int arr[] = {25, 10, 5, 1};

int main() {

    int t, c;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> c;

        int tmp = c;
        for(int j = 0; j < 4; j++){
            cout << tmp / arr[j] << " ";
            tmp %= arr[j];
        }
        cout << '\n';
    }

    
    return 0;
}