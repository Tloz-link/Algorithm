#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> matrix;
int dp[500][500];
int Solve()
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j + i < n; ++j)
		{
			int& val = dp[j][j + i];
			val = 1000000000;
			for (int k = j; k < i + j; ++k)
			{
				val = min(val, dp[j][k] + dp[k + 1][j + i] + (matrix[j].first * matrix[k].second * matrix[i + j].second));
			}
		}
	}
	return dp[0][n - 1];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int r, c;
		cin >> r >> c;
		matrix.push_back(make_pair(r, c));
	}

	cout << Solve();
	return 0;
}
