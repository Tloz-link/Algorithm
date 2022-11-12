#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int V, E, begin;
	cin >> V >> E >> begin;

	vector<vector<pair<int, int>>> graph(V + 1);
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	priority_queue<pair<int, int>> queue;
	vector<int> dist(V + 1, INT32_MAX);
	queue.push(make_pair(0, begin));
	dist[begin] = 0;

	while (!queue.empty())
	{
		int weight = -queue.top().first;
		int now = queue.top().second;
		queue.pop();
			
		for (int i = 0; i < graph[now].size(); ++i)
		{
			int next = graph[now][i].first;
			int minWeight = weight + graph[now][i].second;

			if (minWeight < dist[next])
			{
				dist[next] = minWeight;
				queue.push(make_pair(-minWeight, next));
			}
		}
	}
	
	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INT32_MAX)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}
