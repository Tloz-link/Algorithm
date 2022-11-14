#include <iostream>
#include <vector>

using namespace std;

int DFS(vector<vector<int>>& net, vector<int>& comp, int cur, int count)
{
	comp[cur] = 0;

	for (int i = 0; i < net[cur].size(); ++i)
	{
		int next = net[cur][i];
		if (comp[next] == 0)
			continue;
		count = DFS(net, comp, next, count + 1);
	}

	return count;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> net(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		net[v1].push_back(v2);
		net[v2].push_back(v1);
	}
	vector<int> comp(N + 1, 1);
	cout << DFS(net, comp, 1, 0);
	return 0;
}