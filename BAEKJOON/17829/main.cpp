#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string S, W;
int cache[101][101];
int Solve(int w, int s)
{
	// 계산한적 있는 경우는 캐싱해둔 데이터 반환
	int& ret = cache[w][s];
	if (ret != -1)
		return ret;

	// 각 글자가 매칭이 될 경우 w, s모두 한칸 전진
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
		return ret = Solve(w + 1, s + 1);

	// w가 끝나면 s도 끝났는 지 확인
	if (w == W.size())
		return ret = (s == S.size());

	// w가 *일경우 *에 0개를 매칭하거나 1개 이상 매칭한 경우를 재귀
	if (W[w] == '*')
	{
		if (Solve(w + 1, s) || (s < S.size() && Solve(w, s + 1)))
			return ret = 1;
	}

	// 모두 해당 안되면 0반환
	return ret = 0;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		cin >> W;
		int N;
		cin >> N;
		vector<string> arr(N);
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		for (int i = 0; i < N; ++i)
		{
			memset(cache, -1, sizeof(cache));
			S = arr[i];
			if (Solve(0, 0) == 1)
				cout << arr[i] << "\n";
		}
	}
	return 0;
}