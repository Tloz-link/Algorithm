#include <iostream>
#include <cstring>

using namespace std;

int n;
int forest[501][501];
int dp[501][501];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int DFS(int row, int col)
{
	int& ret = dp[row][col];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = row + dy[i];
		int nx = col + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;
		if (forest[row][col] >= forest[ny][nx])
			continue;
		ret = max(ret, DFS(ny, nx) + 1);
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> forest[i][j];

	memset(dp, -1, sizeof(dp));

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			answer = max(answer, DFS(i, j));
		}
	}
	cout << answer;
	return 0;
}