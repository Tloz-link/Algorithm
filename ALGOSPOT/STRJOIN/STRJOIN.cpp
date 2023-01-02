#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; ++i)
		{
			int item;
			cin >> item;
			pq.push(item);
		}

		int ret = 0;
		while (pq.size() > 1)
		{
			int min1 = pq.top();
			pq.pop();
			int min2 = pq.top();
			pq.pop();
			ret += min1 + min2;
			pq.push(min1 + min2);
		}
		cout << ret << "\n";
	}
	return 0;
}