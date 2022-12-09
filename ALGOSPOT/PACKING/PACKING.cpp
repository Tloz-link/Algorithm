#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, c;
string items[100];
int volumns[100];
int want[100];
int cache[1001][100];

int Pack(int capacity, int item)
{
	if (item == n)
		return 0;

	int& ret = cache[capacity][item];
	if (ret != -1)
		return ret;
	ret = Pack(capacity, item + 1);
	if (capacity >= volumns[item])
		ret = max(ret, Pack(capacity - volumns[item], item + 1) + want[item]);
	return ret;
}

void Reconstruct(int capacity, int item, vector<string>& answer)
{
	if (item == n)
		return;

	if (Pack(capacity, item) == Pack(capacity, item + 1))
	{
		Reconstruct(capacity, item + 1, answer);
	}
	else
	{
		answer.push_back(items[item]);
		Reconstruct(capacity - volumns[item], item + 1, answer);
	}
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n >> c;
		for (int i = 0; i < n; ++i)
			cin >> items[i] >> volumns[i] >> want[i];
		memset(cache, -1, sizeof(cache));
		int result = Pack(c, 0);
		vector<string> answer;
		Reconstruct(c, 0, answer);
		cout << result << " " << answer.size() << "\n";
		for (int i = 0; i < answer.size(); ++i)
			cout << answer[i] << "\n";
	}
	return 0;
}