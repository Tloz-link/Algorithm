#include <iostream>

using namespace std;

const int EMPTY = -456123;
int board[50];
int cache[50][50];
int NumberGame(int left, int right)
{
	if (left > right)
		return 0;
	int& ret = cache[left][right];
	if (ret != EMPTY)
		return ret;

	ret = max(board[left] - NumberGame(left + 1, right), board[right] - NumberGame(left, right - 1));
	if (right - left >= 1)
	{
		ret = max(ret, -NumberGame(left + 2, right));
		ret = max(ret, -NumberGame(left, right - 2));
	}
	return ret;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> board[i];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cache[i][j] = EMPTY;
		cout << NumberGame(0, n - 1) << "\n";
	}
	return 0;
}
