#include <iostream>
#include <cstring>

using namespace std;

int n;
int cache[2001];
int attack[2000];

int Solve(int start)
{
	int& ret = cache[start + 1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int next = start + 1; next < n; ++next)
		if (start == -1 || attack[start] > attack[next])
			ret = max(ret, Solve(next) + 1);
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> attack[i];
	memset(cache, -1, sizeof(cache));
	cout << n - (Solve(-1) - 1);
	return 0;
}
