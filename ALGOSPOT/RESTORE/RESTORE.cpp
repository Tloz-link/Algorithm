#include <iostream>
#include <cstring>

using namespace std;

int k;
string word[16];
int cache[16][1 << 15], overlap[16][16];
void PreCalc()
{
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if (i != j && word[i].find(word[j]) != -1)
			{
				word[j] = word[k - 1];
				--k;
				i = 0;
				j = 0;
			}
		}
	}
	word[k] = "";
}

int Overlap(int last, int next)
{
	int max = min(word[last].size(), word[next].size());
	for (int i = max - 1; i > 0; --i)
		if (word[last].substr(word[last].size() - i, i) == word[next].substr(0, i))
			return i;
	return 0;
}

int Fake(int last, int used)
{
	if (used == (1 << k) - 1)
		return 0;

	int& ret = cache[last][used];
	if (ret != -1)
		return ret;
	for (int next = 0; next < k; ++next)
	{
		if (((1 << next) & used) != 0)
			continue;
		ret = max(ret, overlap[last][next] + Fake(next, used + (1 << next)));
	}
	return ret;
}

string Reconstruct(int last, int used)
{
	if (used == (1 << k) - 1)
		return "";
	for (int next = 0; next < k; ++next)
	{
		if (((1 << next) & used) != 0)
			continue;
		int ifUsed = Fake(next, used + (1 << next)) + overlap[last][next];
		if (Fake(last, used) == ifUsed)
			return (word[next].substr(overlap[last][next])) + Reconstruct(next, used | (1 << next));
	}
	return "@!@#!@$!@$!@!$";
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> k;
		for (int i = 0; i < k; ++i)
			cin >> word[i];
		PreCalc();
		for (int i = 0; i <= k; ++i)
			for (int j = 0; j <= k; ++j)
				overlap[i][j] = Overlap(i, j);
		memset(cache, -1, sizeof(cache));
		// k번째를 넣고 돌리면 첫번째 조각까지 포함해서 모든 경우의 수를 돌게된다.
		cout << Reconstruct(k, 0) << "\n";
	}
	return 0;
}
