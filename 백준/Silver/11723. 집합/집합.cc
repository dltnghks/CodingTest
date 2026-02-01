#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned int s;

void add(int num){
    s |= (1 << num);
}

void remove(int num){
    s &= ~(1 << num);
}

void check(int num){
    int n = s & (1 << num);
    if(n == 0)
        cout << "0\n";
    else
        cout << "1\n";
}

void toggle(int num){
    s ^= (1 << num);
}

void all(){
    s = (1 << 21) - 1;
}

void empty(){
    s = 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    s = 0;

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        string instruction;
        int num;
        cin >> instruction;

        if(instruction == "add"){
            cin >> num;
            add(num);
        }
        else if(instruction == "remove"){
            cin >> num;
            remove(num);
        }
        else if(instruction == "check"){
            cin >> num;
            check(num);
        }
        else if(instruction == "toggle"){
            cin >> num;
            toggle(num);
        }
        else if(instruction == "all"){
            all();
        }
        else if(instruction == "empty"){
            empty();
        }
        else{
            cout << "error\n";
        }
    }
    
    return 0;
}
