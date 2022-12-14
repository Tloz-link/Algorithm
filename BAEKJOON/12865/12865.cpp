#include <iostream>
#include <cstring>

using namespace std;

int n;
int cache[100001][100];
int volumn[100], need[100];
int Pack(int capacity, int item)
{
	if (item == n)
		return 0;

	int& ret = cache[capacity][item];
	if (ret != -1)
		return ret;
	ret = Pack(capacity, item + 1);
	if (volumn[item] <= capacity)
		ret = max(ret, Pack(capacity - volumn[item], item + 1) + need[item]);
	return ret;
}

int main()
{
	int capacity;
	cin >> n >> capacity;
	for (int i = 0; i < n; ++i)
		cin >> volumn[i] >> need[i];
	memset(cache, -1, sizeof(cache));
	cout << Pack(capacity, 0);
	return 0;
}
