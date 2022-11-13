#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<int>& visited, int now)
{
	cout << now << " ";
	visited[now] = 1;

	for (int i = 0; i < graph[now].size(); ++i)
	{
		if (visited[graph[now][i]] == 1)
			continue;
		DFS(graph, visited, graph[now][i]);
	}
}

int main(void)
{
	int N, M, start;
	cin >> N >> M >> start;

	vector<vector<int>> graph(N + 1);
	vector<pair<int, int>> edge;
	vector<int> visited(N + 1, 0);

	for (int i = 0; i < M; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		edge.push_back(make_pair(v1, v2));
		edge.push_back(make_pair(v2, v1));
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); ++i)
	{
		graph[edge[i].first].push_back(edge[i].second);
	}

	DFS(graph, visited, start);
	cout << "\n";

	queue<int> queue;
	vector<int> discovered(N + 1, 0);
	queue.push(start);
	discovered[start] = 1;

	while (!queue.empty())
	{
		int now = queue.front();
		queue.pop();

		cout << now << " ";

		for (int i = 0; i < graph[now].size(); ++i)
		{
			if (discovered[graph[now][i]] == 1)
				continue;
			queue.push(graph[now][i]);
			discovered[graph[now][i]] = 1;
		}
	}
	cout << "\n";

	return 0;
}