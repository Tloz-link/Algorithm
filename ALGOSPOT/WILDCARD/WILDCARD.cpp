#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string S, W;
int cache[101][101];
int Solve(int w, int s)
{
	// ������� �ִ� ���� ĳ���ص� ������ ��ȯ
	int& ret = cache[w][s];
	if (ret != -1)
		return ret;

	// �� ���ڰ� ��Ī�� �� ��� w, s��� ��ĭ ����
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
		return ret = Solve(w + 1, s + 1);

	// w�� ������ s�� ������ �� Ȯ��
	if (w == W.size())
		return ret = (s == S.size());

	// w�� *�ϰ�� *�� 0���� ��Ī�ϰų� 1�� �̻� ��Ī�� ��츦 ���
	if (W[w] == '*')
	{
		if (Solve(w + 1, s) || (s < S.size() && Solve(w, s + 1)))
			return ret = 1;
	}

	// ��� �ش� �ȵǸ� 0��ȯ
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