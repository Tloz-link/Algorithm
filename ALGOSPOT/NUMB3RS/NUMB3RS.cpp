#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int d, dest, start, n; 
int connected[50][50], deg[50];
double cache[50][100];
double Search(int node, int day)
{
	// 기저 조건
	if (day == 0)
		return (dest == node) ? 1.0 : 0.0;

	double& ret = cache[node][day];
	if (ret > -0.5)
		return ret;

	ret = 0.0;
	for (int next = 0; next < n; ++next)
	{
		if (connected[node][next] == 0)
			continue;
		ret += Search(next, day - 1) / deg[next];
	}
	return ret;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n >> d >> dest;
		for (int i = 0; i < n; ++i)
		{
			int count = 0;
			for (int j = 0; j < n; ++j)
			{
				cin >> connected[i][j];
				if (connected[i][j] == 1)
					count++;
			}
			deg[i] = count;
		}

		int k;
		cin >> k;
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < k; ++i)
		{
			cin >> start;
			cout << setprecision(8) << Search(start, d) << " ";
		}
		cout << "\n";
	}
	return 0;
}