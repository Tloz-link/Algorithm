#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int DFS(vector<vector<char>>& field, pair<int, int> cur, char team, int count)
{
	field[cur.first][cur.second] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nx = cur.second + dx[i];
		int ny = cur.first + dy[i];
		if (nx < 0 || ny < 0 || nx >= field[0].size() || ny >= field.size())
			continue;
		if (field[ny][nx] != team)
			continue;
		count = DFS(field, make_pair(ny, nx), team, count + 1);
	}

	return count;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<vector<char>> field(M, vector<char>(N));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char c;
			cin >> c;
			field[i][j] = c;
		}
	}

	int white = 0;
	int blue = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (field[i][j] == 0)
				continue;
			char team = field[i][j];
			int count = DFS(field, make_pair(i, j), team, 1);
			if (team == 'W')
				white += count * count;
			else
				blue += count * count;
		}
	}

	cout << white << " " << blue << "\n";
	return 0;
}