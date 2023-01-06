#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int INF = 1000000000;
int n, m;
vector<int> canEat[50], eaters[50];
int best;

void Search(int food, vector<int>& edible, int chosen)
{
	if (chosen >= best)
		return;

	int first = 0;
	while (first < n && edible[first] > 0)
		first++;
	if (first == n)
	{
		best = chosen;
		return;
	}

	for (int j = 0; j < canEat[first].size(); ++j)
	{
		int food = canEat[first][j];
		for (int i = 0; i < eaters[food].size(); ++i)
			edible[eaters[food][i]]++;
		Search(food + 1, edible, chosen + 1);
		for (int i = 0; i < eaters[food].size(); ++i)
			edible[eaters[food][i]]--;
	}
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			canEat[i].clear();
		for (int i = 0; i < m; ++i)
			eaters[i].clear();
		
		unordered_map<string, int> map;

		for (int i = 0; i < n; ++i)
		{
			string name;
			cin >> name;
			map[name] = i;
		}

		for (int i = 0; i < m; ++i)
		{
			int num;
			cin >> num;
			
			for (int j = 0; j < num; ++j)
			{
				string name;
				cin >> name;
				eaters[i].push_back(map[name]);
				canEat[map[name]].push_back(i);
			}
		}

		vector<int> edible(n, 0);
		best = INF;
		Search(0, edible, 0);
		cout << best << "\n";
	}
	return 0;
}