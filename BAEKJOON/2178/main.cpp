#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<vector<char>> maze(N, vector<char>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char c;
			cin >> c;
			maze[i][j] = c;
		}
	}
	queue<pair<int, int>> queue;
	vector<vector<int>> dist(N, vector<int>(M, 0));
	queue.push(make_pair(0, 0));
	maze[0][0] = '0';
	dist[0][0] = 1;

	while (!queue.empty())
	{
		int y = queue.front().first;
		int x = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || nx >= maze[0].size() || ny >= maze.size())
				continue;
			if (maze[ny][nx] == '0')
				continue;
			maze[ny][nx] = '0';
			dist[ny][nx] = dist[y][x] + 1;
			queue.push(make_pair(ny, nx));
		}
	}

	cout << dist[N - 1][M - 1] << "\n";
	return 0;
}