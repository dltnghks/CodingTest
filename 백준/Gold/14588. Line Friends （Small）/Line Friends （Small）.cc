#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e7

using namespace std;

struct Line{
    int left;
    int right;
    int index;
};


bool compare(Line& a, Line& b){
    if(a.left == b.left) return a.right < b.right;
    return a.left < b.left;
}

int GetLine(vector<Line>& Lines, int index){
    
    for(int i = 0; i < Lines.size(); i++){
        if(Lines[i].index == index){
            return i;
        }
    }
    
    cout << "Not Find Line\n"; 
    return -1;
}

int main(){
    int n;
    cin >> n;
 
    vector<Line> Lines(n);
    
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        Lines[i] = {l, r, i};
    }

    sort(Lines.begin(), Lines.end(), compare);

    vector<vector<int>> graph(n, vector<int>(n, INF));

    // for(auto& line : Lines){
    //     cout << line.left << " , " << line.right << '\n';
    // }

    // Create Graph
    for(int i = 0; i < n; i++){
        Line& curLine = Lines[i];
        for(int j = i; j < n; j++){
            if(i == j){
                graph[i][j] = 0;
                continue;
            }
            Line& nextLine = Lines[j];

            // -10 -3 , -2 1 
            if(nextLine.left <= curLine.right && nextLine.right >= curLine.left){
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << graph[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(k == i) continue;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << graph[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a = GetLine(Lines, a-1);
        b = GetLine(Lines, b-1);
        
        int ans = graph[a][b];
        if(ans == INF) ans = -1;
        cout << ans << '\n';
    }


    return 0;
}