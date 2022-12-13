#include <iostream>
#include <cstring>

using namespace std;

const int INF = 100000000;
int n;
int W[16][16];
int cache[16][1<<16];

int TSP(int here, int visited)
{
	// 기저 조건 : 모든 노드 순회
	if ((1 << n) - 1 == visited)
		return W[here][0] == 0 ? INF : W[here][0];

	int& ret = cache[here][visited];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int next = 0; next < n; ++next)
	{
		if (((1 << next) & visited) != 0 || W[here][next] == 0)
			continue;
		ret = min(ret, TSP(next, (1 << next) + visited) + W[here][next]);
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> W[i][j];
	memset(cache, -1, sizeof(cache));
	// 항상 0번 마을에서 시작, 0번 마을 비트마스킹
	cout << TSP(0, 1);
	return 0;
}
