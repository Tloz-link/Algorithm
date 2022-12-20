#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int map[500][500];
int cache[500][500];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int Solve(int y, int x)
{
	if (y == n - 1 && x == m - 1)
		return 1;
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (map[y][x] > map[ny][nx])
			ret += Solve(ny, nx);
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	memset(cache, -1, sizeof(cache));
	int result = Solve(0, 0);
	cout << result << "\n";
	return 0;
}
