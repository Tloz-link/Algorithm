#include <iostream>

using namespace std;

int n;
int dp[501][501];
int sum[501];
int chap[501];
int Solve()
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j + i <= n; ++j)
		{
			int& val = dp[j][j + i];
			val = 1000000000;
			for (int k = j; k < i + j; ++k)
			{
				val = min(val, dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
			}
		}
	}
	return dp[1][n];
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}
		cout << Solve() << "\n";
	}
	return 0;
}
