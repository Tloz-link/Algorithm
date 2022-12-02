#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Solve(vector<vector<int>>& board, int row, int col, int size)
{
	// 기저조건
	if (size == 1)
		return board[row][col];

	// 분할
	int cand[4]; 
	int nSize = size / 2;
	cand[0] = Solve(board, row, col, nSize);
	cand[1] = Solve(board, row + nSize, col, nSize);
	cand[2] = Solve(board, row, col + nSize, nSize);
	cand[3] = Solve(board, row + nSize, col + nSize, nSize);

	// 병합
	int second = -10000;
	int largest = -10000;
	for (int num : cand)
	{
		if (largest < num)
		{
			second = largest;
			largest = num;
		}
		else if (second < num)
		{
			second = num;
		}
	}

	return second;
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			cin >> board[i][j];
		}
	}
	cout << Solve(board, 0, 0, N);
	return 0;
}
