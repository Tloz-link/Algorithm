#include <iostream>

using namespace std;

int r, c;
int Solve(int row, int column, int start, int size)
{
	// ��������
	if (row > r || r >= row + size || column > c || c >= column + size)
		return -1;
	if (row == r && column == c)
		return start;

	int ret = 0;
	int nSize = size / 2;
	int nStart = nSize * nSize;
	// ����
	ret = max(ret, Solve(row, column, start, nSize));
	ret = max(ret, Solve(row, column + nSize, start + (nStart * 1), nSize));
	ret = max(ret, Solve(row + nSize, column, start + (nStart * 2), nSize));
	ret = max(ret, Solve(row + nSize, column + nSize, start + (nStart * 3), nSize));
	return ret;
}

int main() {
	int N;
	cin >> N >> r >> c;
	// 2�� �¼��� (1 << N)���� �ϸ� ����
	cout << Solve(0, 0, 0, (1 << N));
	return 0;
}