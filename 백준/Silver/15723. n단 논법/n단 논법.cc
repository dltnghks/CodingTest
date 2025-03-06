#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m, tmp;
vector<int> graph(27, -1);

void Input(){
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s, '\n');
        int first = s[0] - 'a';
        int second = s[5] - 'a';
        graph[first] = second;
    }
}

bool DFS(int s, int e){
    if(graph[s] == -1) return false;
    else{
        if(graph[s] == e) return true;
        return DFS(graph[s], e);
    }
}

void Cal(){
    cin >> m;
    cin.ignore();
    for(int i = 0; i < m; i++){
        string s;
        getline(cin, s);
        int first = s[0] - 'a';
        int second = s[5] - 'a';
        if(DFS(first, second)){
            cout << "T\n";
        }else{
            cout << "F\n";
        }
    }
}

int main()
{
	// 입력
    Input();

    // 계산
    Cal();

	return 0;
}