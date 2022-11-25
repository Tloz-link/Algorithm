#include <iostream>
#include <vector>

using namespace std;

const int coverType[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} }  // �̰� {1, -1}�ε� {-1, 1} �س��� �̰��ϳ� ��ã�� 30���� �ظų�
};
bool Set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int PutBlock(vector<vector<int>>& board)
{
	int y = -1, x = -1;

	// ���� ��, ���� ���ʿ� �ִ� ��ĭ ã��
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}

	if (y == -1)
		return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type)
	{
		if (Set(board, y, x, type, 1) == true)
			ret += PutBlock(board);
		Set(board, y, x, type, -1);
	}
	return ret;
}

int main(void)
{
	int C, H, W;
	cin >> C;

	while (C--)
	{
		cin >> H >> W;
		vector<vector<int>> board(H, vector<int>(W));
		int blank = 0;
		for (int y = 0; y < H; ++y)
		{
			for (int x = 0; x < W; ++x)
			{
				char c;
				cin >> c;
				if (c == '#')
					board[y][x] = 1;
				else
				{
					board[y][x] = 0;
					++blank;
				}
			}
		}

		// ��ĭ�� 3�� ����� �ƴϸ� �Ұ���
		if (blank % 3 != 0)
		{
			cout << 0 << "\n";
			continue;
		}

		cout << PutBlock(board) << "\n";
	}
	return 0;
}