#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

// 입력 범위가 32비트 정수 전체이기 때문에 입력에 없는 작은 값을 쓰기 위해 64비트 정수 사용
const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];
int Solve(int indexA, int indexB)
{
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1)
		return ret;
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);
	for (int nextA = indexA + 1; nextA < n; ++nextA)
	{
		if (maxElement < A[nextA])
			ret = max(ret, Solve(nextA, indexB) + 1);
	}
	for (int nextB = indexB + 1; nextB < m; ++nextB)
	{
		if (maxElement < B[nextB])
			ret = max(ret, Solve(indexA, nextB) + 1);
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		for (int i = 0; i < m; ++i)
			cin >> B[i];
		memset(cache, -1, sizeof(cache));
		// 인덱스를 함수 하나에서 모두 훑기 위해 +2를 했기 때문에 결과에서 2를 빼줘야 함
		cout << Solve(-1, -1) - 2 << "\n";
	}
	return 0;
}