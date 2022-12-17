#include <iostream>

using namespace std;

int n, m, price[20], pref[20];
int c[201];
int Sushi()
{
	c[0] = 0;
	for (int budget = 1; budget <= m; ++budget)
	{
		int cand = 0;
		for (int dish = 0; dish < n; ++dish)
		{
			if (budget >= price[dish])
			{
				cand = max(cand, c[(budget - price[dish]) % 201] + pref[dish]);
			}
		}
		c[budget % 201] = cand;
	}
	return c[m % 201];
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n >> m;
		m /= 100;
		for (int i = 0; i < n; ++i)
		{
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		cout << Sushi() << "\n";
	}
	return 0;
}
