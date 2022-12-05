#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 99999999;
int n;
int pSum[100], pSqrSum[100], A[100];
int cache[100][10];

void PreCalc()
{
	// 배열 정렬 후 부분합, 부분 제곱합 구하기
	sort(A, A + n);
	pSum[0] = A[0];
	pSqrSum[0] = A[0] * A[0];
	for (int i = 1; i < n; ++i)
	{
		pSum[i] = pSum[i - 1] + A[i];
		pSqrSum[i] = pSqrSum[i - 1] + (A[i] * A[i]);
	}
	memset(cache, -1, sizeof(cache));
}

int MinError(int lo, int hi)
{
	// 부분합, 부분 제곱합을 사용하여 O(1)로 최소 오류차를 구한다.
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqrSum = pSqrSum[hi] - (lo == 0 ? 0 : pSqrSum[lo - 1]);

	int m = int((double)sum / (hi - lo + 1) + 0.5);
	int ret = sqrSum - (2 * m * sum) + (m * m * (hi - lo + 1));
	return ret;
}

int Solve(int from, int pairs)
{
	if (from == n)
		return 0;
	if (pairs == -1)
		return INF;
	int& ret = cache[from][pairs];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int size = 0; size + from < n; ++size)
		ret = min(ret, MinError(from, from + size) + Solve(from + size + 1, pairs - 1));
	return ret;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int pairs;
		cin >> n >> pairs;
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		PreCalc();

		cout << Solve(0, pairs - 1) << "\n";
	}
	return 0;
}