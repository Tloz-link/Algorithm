#include <iostream>
#include <vector>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks)
{
	for (int clock : clocks)
	{
		if (clock != 12)
			return false;
	}
	return true;
}

void Press(vector<int>& clocks, int swtch)
{
	for (int i = 0; i < CLOCKS; ++i)
	{
		if (linked[swtch][i] == 'x')
		{
			clocks[i] += 3;
			if (clocks[i] == 15)
				clocks[i] = 3;
		}
	}
}

int Solve(vector<int>& clocks, int swtch)
{
	if (swtch == SWITCHES)
		return (areAligned(clocks)) ? 0 : INF;

	int ret = INF;
	for (int i = 0; i < 4; ++i)
	{
		ret = min(ret, i + Solve(clocks, swtch + 1)); // i + solve() ������� �ϸ� �˾Ƽ� ���� Ƚ���� ��� ������
		// �ǵ��� �ʿ� ���� �׳� �ѹ����� ������ �� (4�� ������ �ڵ����� ó���� �Ǵϱ�)
		Press(clocks, swtch);
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	vector<int> clocks(CLOCKS);

	while (C--)
	{
		for (int i = 0; i < CLOCKS; ++i)
		{
			cin >> clocks[i];
		}

		int ret = Solve(clocks, 0);
		if (ret == INF)
			ret = -1;
		cout << ret << "\n";
	}
	return 0;
}