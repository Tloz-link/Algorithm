#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<pair<int, int>>> rotations;
int blockSize;

vector<string> Rotate(const vector<string>& board)
{
	vector<string> ret(board[0].size(), string(board.size(), ' '));
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			ret[j][board.size() - i - 1] = board[i][j];
		}
	}
	return ret;
}

void GenerateRotations(vector<string> board)
{
	rotations.clear();
	rotations.resize(4);

	for (int rot = 0; rot < 4; ++rot)
	{
		int originY = -1;
		int originX = -1;
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j] == '#')
				{
					if (originY == -1)
					{
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
			}
		}
		board = Rotate(board);
	}

	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size();
}

int boardH, boardW;
int covered[10][10];
int best;

bool Set(int y, int x, const vector<pair<int, int>>& block, int delta)
{
	bool ret = true;
	for (int i = 0; i < block.size(); ++i)
	{
		int ny = y + block[i].first;
		int nx = x + block[i].second;
		if (ny < 0 || ny >= boardH || nx < 0 || nx >= boardW)
			ret = false;
		else if ((covered[ny][nx] += delta) > 1)
			ret = false;
	}

	return ret;
}

bool Prunning(int placed) {
	int empty = 0;
	for (int i = 0; i < boardH; ++i)
		for (int j = 0; j < boardW; ++j)
			if (covered[i][j] == 0)
				empty++;
	return (empty / blockSize) + placed <= best;
}

void Search(int placed)
{
	if (Prunning(placed))
		return;

	int y = -1;
	int x = -1;

	for (int i = 0; i < boardH; ++i)
	{
		for (int j = 0; j < boardW; ++j)
		{
			if (covered[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	if (y == -1)
	{
		best = max(best, placed);
		return;
	}

	for (int i = 0; i < rotations.size(); ++i)
	{
		if (Set(y, x, rotations[i], 1))
			Search(placed + 1);
		Set(y, x, rotations[i], -1);
	}
	covered[y][x] = 1;
	Search(placed);
	covered[y][x] = 0;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int blockH, blockW;
		cin >> boardH >> boardW >> blockH >> blockW;

		for (int i = 0; i < boardH; ++i)
		{
			for (int j = 0; j < boardW; ++j)
			{
				char c;
				cin >> c;
				if (c == '#')
					covered[i][j] = 1;
				else
					covered[i][j] = 0;
			}
		}

		vector<string> block(blockH);
		for (int i = 0; i < blockH; ++i)
			cin >> block[i];
		GenerateRotations(block);
		best = 0;
		Search(0);
		cout << best << "\n";
	}
	return 0;
}