#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int n, m;
int R[100];
double T[501][501];
double M[501][501];
int choice[101][501];
double cache[101][501];
string words[501];

double Recognize(int segment, int prevMatch)
{
	if (segment == n)
		return 0;
	double& ret = cache[segment][prevMatch];
	if (ret != 1.0)
		return ret;

	ret = -1e200;
	int& choose = choice[segment][prevMatch];
	for (int thisMatch = 1; thisMatch <= m; ++thisMatch)
	{
		double cand = T[prevMatch][thisMatch] + M[thisMatch][R[segment]] + Recognize(segment + 1, thisMatch);
		if (ret < cand)
		{
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

string Reconstruct(int segment, int prevMatch)
{
	int choose = choice[segment][prevMatch];
	string ret = words[choose];
	if (segment < n - 1)
		ret = ret + " " + Reconstruct(segment + 1, choose);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int count;
	cin >> m >> count;

	for (int i = 1; i <= m; ++i)
		cin >> words[i];

	for (int i = 1; i <= m; ++i)
	{
		double t;
		cin >> t;
		T[0][i] = log(t);
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			double t;
			cin >> t;
			T[i][j] = log(t);
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			double m;
			cin >> m;
			M[i][j] = log(m);
		}
	}

	while (count--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string word;
			cin >> word;
			for (int j = 1; j <= m; ++j)
			{
				if (words[j] == word)
				{
					R[i] = j;
					break;
				}
			}
		}

		for (int i = 0; i < 101; ++i)
		{
			for (int j = 0; j < 501; ++j)
			{
				cache[i][j] = 1.0;
			}
		}

		Recognize(0, 0);
		cout << Reconstruct(0, 0) << "\n";
	}
	return 0;
}