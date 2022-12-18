#include <iostream>
#include <cstring>

using namespace std;

int n;
int stair[300];
int c[4];
int Solve()
{
	c[0] = stair[0];
	c[1] = stair[0] + stair[1];
	for (int i = 2; i < n; ++i)
		c[i % 4] = max(c[(i - 2 + 4) % 4] + stair[i], c[(i - 3 + 4) % 4] + stair[i - 1] + stair[i]);
	return c[(n - 1) % 4];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> stair[i];
	memset(c, 0, sizeof(c));
	cout << Solve();
	return 0;
}
