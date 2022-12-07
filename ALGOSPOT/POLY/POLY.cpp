#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10000000;
int cache[101][101];

int Poly(int n, int first)
{
	// 기저 조건
	if (n == first)
		return 1;

	int& ret = cache[n][first];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second)
		ret += ((first + second - 1) * Poly(n - first, second) % MOD);
	return ret = (ret % MOD);
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int n;
		cin >> n;
		memset(cache, -1, sizeof(cache));
		int ret = 0;
		for (int i = 1; i <= n; ++i)
			ret += Poly(n, i);
		cout << (ret % MOD) << "\n";
	}
	return 0;
}