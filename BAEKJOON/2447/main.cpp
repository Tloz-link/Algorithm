#include <iostream>

using namespace std;

const int MAX = 2187; // 3^7
const char base[3][3] = {
	{'*', '*', '*'},
	{'*', ' ', '*'},
	{'*', '*', '*'}
};
char sky[MAX][MAX];
void FillBlank(int y, int x, int size)
{
	for (int dy = 0; dy < size; ++dy)
	{
		for (int dx = 0; dx < size; ++dx)
		{
			sky[dy + y][dx + x] = ' ';
		}
	}
}

void FillStar(int y, int x, int size)
{
	// 기저 조건
	if (size == 3)
	{
		for (int dy = 0; dy < size; ++dy)
		{
			for (int dx = 0; dx < size; ++dx)
			{
				sky[dy + y][dx + x] = base[dy][dx];
			}
		}
	}
	else
	{
		// 작은 문제로 분할
		// 병합은 FillStar, FillBlank에서 알아서 함
		int nSize = size / 3;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (i == 1 && j == 1)
					FillBlank(y + nSize * i, x + nSize * j, nSize);
				else
					FillStar(y + nSize * i, x + nSize * j, nSize);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	FillStar(0, 0, N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << sky[i][j];
		}
		cout << "\n";
	}
	return 0;
}