#include <iostream>

using namespace std;

const int MAX = 1500000;
int n;
int T[MAX];
int P[MAX];
int dp[MAX + 1];
int Solve()
{
	for (int i = n - 1; i >= 0; --i)
	{
		if (i + T[i] > n)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
		}
	}
	return dp[0];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> T[i] >> P[i];
		dp[i + 1] = 0;
	}
	int result = Solve();
	cout << result << "\n";
	return 0;
}
