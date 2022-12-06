#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int cache[101];

int Tile(int n)
{
	// ���� ���� : �ʺ� 1������ ��� 1 ��ȯ
	if (n <= 1)
		return 1;
	int& ret = cache[n];
	if (ret != -1)
		return ret;
	return ret = (Tile(n - 1) + Tile(n - 2)) % MOD;
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
		// ��ü ����� ���� ���ϰ�
		int ret = Tile(n);
		// �ű⼭ ��Ī�� ������ ����
		if (n % 2 == 1)
			cout << (ret - Tile(n / 2) + MOD) % MOD << "\n";
		else
		{
			ret = (ret - Tile(n / 2) + MOD) % MOD;
			cout << (ret - Tile(n / 2 - 1) + MOD) % MOD << "\n";
		}
	}
	return 0;
}