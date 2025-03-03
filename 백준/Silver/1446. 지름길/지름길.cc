#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct InputStruct {
	int s;
	int e;
	int dis;
}InputStruct;

bool Compare(InputStruct& a, InputStruct& b) {
	return a.s < b.s;
}

int main()
{
	// 입력
	int n, d;
	cin >> n >> d;

	vector<int> disVec(d+1, d+1);
	vector<InputStruct> InputVec;
	disVec[0] = 0;

	for (int i = 0; i < n; i++) {
		int s, e, dis;
		cin >> s >> e >> dis;
		if (e > d) continue;
		InputVec.push_back({ s, e, dis });
	}

	sort(InputVec.begin(), InputVec.end(), Compare);

	int index = 0;
	for (int i = 1; i <= d; i++) {
		disVec[i] = min(disVec[i], disVec[i-1]+1);
		while (index < InputVec.size() && InputVec[index].s <= i) {
			InputStruct curInput = InputVec[index];
			//cout << "지름길 " << curInput.e << " :  " << disVec[curInput.e] << " 비교 " << disVec[curInput.s] + curInput.dis << '\n';
			disVec[curInput.e] = min(disVec[curInput.e], disVec[curInput.s] + curInput.dis);
			index++;
		}
	}

	for (int i = 1; i <= d; i++) {
		//cout << i << " : " << disVec[i] << '\n';
	}

	// 출력
	cout << disVec[d] << '\n';

	return 0;
}