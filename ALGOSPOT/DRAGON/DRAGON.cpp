#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000000000 + 1;
int length[51];

void PreCalc()
{
	length[0] = 1;
	for (int i = 1; i <= 50; ++i)
		length[i] = min(MAX, length[i - 1] * 2 + 2);
}

char Curve(const string& seed, int generation, int skip)
{
	if (generation == 0)
		return seed[skip];

	for (int i = 0; i < seed.size(); ++i)
	{
		if (seed[i] == 'X' || seed[i] == 'Y')
		{
			if (skip >= length[generation])
				skip -= length[generation];
			else if (seed[i] == 'X')
				return Curve("X+YF", generation - 1, skip);
			else
				return Curve("FX-Y", generation - 1, skip);
		}
		else if (skip > 0)
			skip--;
		else
			return seed[i];
	}
	return 0;
}

int main() {
	int C;
	cin >> C;
	PreCalc();

	while (C--)
	{
		int generation, p, l;
		cin >> generation >> p >> l;

		for (int i = p - 1; i < p + l - 1; ++i)
			cout << Curve("FX", generation, i);
		cout << "\n";
	}
	return 0;
}
