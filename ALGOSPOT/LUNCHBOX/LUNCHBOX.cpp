#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int wave[10000];
int eat[10000];
int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> wave[i];
		for (int i = 0; i < n; ++i)
			cin >> eat[i];

		vector<pair<int, int>> order;
		for (int i = 0; i < n; ++i)
			order.push_back(make_pair(-eat[i], i));
		sort(order.begin(), order.end());

		int ret = 0;
		int beginEat = 0;
		for (int i = 0; i < n; ++i)
		{
			int lunch = order[i].second;
			beginEat += wave[lunch];
			ret = max(ret, beginEat + eat[lunch]);
		}
		cout << ret << "\n";
	}
	return 0;
}