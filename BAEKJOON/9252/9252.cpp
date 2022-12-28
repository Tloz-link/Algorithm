#include <iostream>
#include <cstring>

using namespace std;

string s1, s2;
int dp[1001][1001];

int main()
{
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int i = s1.size();
	int j = s2.size();
	string answer = "";

	while (i > 0 && j > 0)
	{
		if (dp[i][j] == dp[i][j - 1])
		{
			--j;
		}
		else if (dp[i][j] == dp[i - 1][j])
		{
			--i;
		}
		else
		{
			answer += s1[i - 1];
			--i;
			--j;
		}
	}

	cout << dp[s1.length()][s2.length()] << "\n";
	for (int i = answer.size() - 1; i >= 0; --i)
		cout << answer[i];
	return 0;
}
