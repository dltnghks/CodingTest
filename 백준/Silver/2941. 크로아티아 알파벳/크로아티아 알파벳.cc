#include <iostream>

using namespace std;

string croatiaAlphabet[]{ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };


int main() {

    int ans;
    string input;
    cin >> input;

    ans = input.length();
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        for (string croatia : croatiaAlphabet) {
            if (c == croatia[0]) {

                ans -= croatia.length() - 1;

                int tmp = i;
                i += croatia.length()-1;

                for (int j = 0; j < croatia.length(); j++) {
                    if (input[tmp + j] != croatia[j])
                    {
                        ans += croatia.length() - 1;
                        i = tmp;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << '\n';


    return 0;
}
