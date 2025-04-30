#include <iostream>
#include <vector>
using namespace std;

int n;
const int MOD = 1000;

vector<vector<int>> matrixMult(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
    return result;
}

vector<vector<int>> matrixPower(vector<vector<int>> base, long long exp) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    // 단위 행렬로 초기화
    for (int i = 0; i < n; i++) result[i][i] = 1;

    while (exp > 0) {
        if (exp % 2 == 1) result = matrixMult(result, base);
        base = matrixMult(base, base);
        exp /= 2;
    }

    return result;
}

int main() {
    long long b;
    cin >> n >> b;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    vector<vector<int>> result = matrixPower(A, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
