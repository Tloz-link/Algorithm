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
		ret = min(ret, i + Solve(clocks, swtch + 1)); // i + solve() 방식으로 하면 알아서 누른 횟수가 계속 더해짐
		// 되돌릴 필요 없이 그냥 한번씩만 누르면 됨 (4번 누르면 자동으로 처음이 되니까)
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