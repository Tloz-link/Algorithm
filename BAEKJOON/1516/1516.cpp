#include <iostream>
#include <cstring>

using namespace std;

int n;
int building[501][501];
int dp[501];
int DFS(int now)
{
	int& ret = dp[now];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int prev = 1; prev <= n; ++prev)
	{
		if (building[now][prev] == -1)
			break;
		ret = max(ret, DFS(building[now][prev]));
	}
	ret += building[now][0];
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> building[i][0];
		for (int j = 1; j <= n; ++j)
		{
			cin >> building[i][j];
			if (building[i][j] == -1)
				break;
		}
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; ++i)
		cout << DFS(i) << "\n";
	return 0;
}