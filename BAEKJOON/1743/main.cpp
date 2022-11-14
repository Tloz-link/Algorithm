#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int DFS(vector<vector<int>>& floor, pair<int, int> cur, int count)
{
	floor[cur.first][cur.second] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int ny = cur.first + dy[i];
		int nx = cur.second + dx[i];
		if (ny < 0 || nx < 0 || ny >= floor.size() || nx >= floor[0].size())
			continue;
		if (floor[ny][nx] == 0)
			continue;
		count = DFS(floor, make_pair(ny, nx), count + 1);
	}

	return count;
}

int main(void)
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> floor(N, vector<int>(M, 0));
	for (int i = 0; i < K; ++i)
	{
		int y, x;
		cin >> y >> x;
		floor[y - 1][x - 1] = 1;
	}

	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (floor[i][j] == 0)
				continue;
			int count = DFS(floor, make_pair(i, j), 1);
			answer = (answer > count) ? answer : count;
		}
	}

	cout << answer;
	return 0;
}