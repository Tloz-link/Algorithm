#include <iostream>

using namespace std;

const int INF = 1000000000;
int n, k;
int coin[101];
int dp[10001];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	for (int i = 1; i <= k; ++i)
	{
		int& ret = dp[i];
		ret = INF;

		for (int j = 0; j < n; ++j)
		{
			if (i - coin[j] >= 0)
			{
				if (dp[i - coin[j]] == INF)
				{
					continue;
				}

				ret = min(ret, dp[i - coin[j]] + 1);
			}
		}
	}

	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];
	return 0;
}