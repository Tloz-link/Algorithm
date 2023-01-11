#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n;
double dist[100][100];
double posX[100];
double posY[100];

bool decision(double d)
{
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		++seen;
		for (int next = 0; next < n; ++next)
		{
			if (!visited[next] && dist[here][next] <= d)
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return seen == n;
}

double optimize()
{
	double lo = 0;
	double hi = 1416.00;
	for (int it = 0; it < 100; ++it)
	{
		double mid = (lo + hi) / 2;
		if (decision(mid))
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	return hi;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> posX[i] >> posY[i];

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				double deltaX = posX[i] - posX[j];
				double deltaY = posY[i] - posY[j];
				double distance = sqrt(deltaX * deltaX + deltaY * deltaY);
				dist[i][j] = distance;
				dist[j][i] = distance;
			}
		}

		double ret = optimize();
		cout << fixed << setprecision(2);
		cout << (int)((ret * 100) + 0.5f) / 100.0 << "\n";
	}
	return 0;
}