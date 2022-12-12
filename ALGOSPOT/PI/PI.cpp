#include <iostream>
#include <cstring>

using namespace std;

const int INF = 99999999;
int cache[10000];
string N;
int Classify(int start, int end)
{
	string s = N.substr(start, end - start);
	// ù ���ڷ� ���� ���ڿ��� ������ ���̵�1
	if (s == string(s.size(), s[0]))
		return 1;

	// ������������ �˻�
	bool progressive = true;
	for (int i = 0; i < s.size() - 1; ++i)
		if (s[i + 1] - s[i] != s[1] - s[0])
			progressive = false;

	// ���������̰� ������ 1, -1�̸� ���̵�2
	if (progressive && abs(s[1] - s[0]) == 1)
		return 2;

	bool alternating = true;
	for (int i = 0; i < s.size() - 2; ++i)
		if (s[i + 2] != s[i])
			alternating = false;

	// �����ư��� ������ ���̵�4
	if (alternating)
		return 4;

	// ������ ���������� ���̵�5
	if (progressive)
		return 5;

	return 10;
}

int Solve(int index)
{
	// ���� ����
	if (index == N.size())
		return 0;
	int& ret = cache[index];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int length = 3; length <= 5; ++length)
		if (index + length <= N.size())
			ret = min(ret, Classify(index, index + length) + Solve(index + length));
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << Solve(0) << "\n";
	}
	return 0;
}
