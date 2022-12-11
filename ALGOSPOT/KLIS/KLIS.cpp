#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];

int LIS(int start)
{
	int& ret = cacheLen[start + 1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int next = start + 1; next < n; ++next)
		if (start == -1 || S[start] < S[next])
			ret = max(ret, LIS(next) + 1);
	return ret;
}

int Count(int start)
{
	if (LIS(start) == 1)
		return 1;
	int& ret = cacheCnt[start + 1];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = start + 1; next < n; ++next)
		if ((start == -1 || S[start] < S[next]) && LIS(start) == LIS(next) + 1)
			ret = min<long long>(MAX, (long long)ret + Count(next));
	return ret;
}

void Reconstruct(int start, int skip, vector<int>& lis)
{
	if (start != -1)
		lis.push_back(S[start]);

	vector<pair<int, int>> followers;
	for (int next = start + 1; next < n; ++next)
		if ((start == -1 || S[start] < S[next]) && LIS(start) == LIS(next) + 1)
			followers.push_back(make_pair(S[next], next));
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); ++i)
	{
		int idx = followers[i].second;
		int cnt = Count(idx);
		if (cnt <= skip)
			skip -= cnt;
		else
		{
			Reconstruct(idx, skip, lis);
			break;
		}
	}
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int k;
		cin >> n >> k;
		
		for (int i = 0; i < n; ++i)
			cin >> S[i];

		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));
		LIS(-1);
		Count(-1);

		vector<int> lis;
		Reconstruct(-1, k - 1, lis);
		cout << lis.size() << "\n";
		for (int i = 0; i < lis.size(); ++i)
			cout << lis[i] << " ";
		cout << "\n";
	}
	return 0;
}