#include <iostream>

using namespace std;

int main()
{
    int map[101][101] = {0,};
    int ans = 0;
    
    for(int i = 0 ; i < 4; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
    
        for(int j = y1; j < y2; j++){
            for(int k = x1; k < x2; k++){
                if(map[j][k] == 0){
                    map[j][k]++;
                    ans++;
                }
            }
        }
        
    }
    
    cout << ans << '\n';

    return 0;
}