#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> queue;
	bool discovered[100001] = {0};
	int prev[100001] = {0};
	queue.push(make_pair(N, 0));
	
	int answer = -1;
	while (!queue.empty())
	{
		int number = queue.front().first;
		int time = queue.front().second;
		queue.pop();

		if (number == K)
		{
			answer = time;
			break;
		}

		if (number != 0 && discovered[number - 1] == false)
		{
			queue.push(make_pair(number - 1, time + 1));
			discovered[number - 1] = true;
			prev[number - 1] = number;
		}
		if (number != 100000 && discovered[number + 1] == false)
		{
			queue.push(make_pair(number + 1, time + 1));
			discovered[number + 1] = true;
			prev[number + 1] = number;
		}
		if (number <= 50000 && discovered[number * 2] == false)
		{
			queue.push(make_pair(number * 2, time + 1));
			discovered[number * 2] = true;
			prev[number * 2] = number;
		}
	}

	vector<int> order;
	int idx = K;
	while (idx != N)
	{
		order.push_back(idx);
		idx = prev[idx];
	}
	order.push_back(N);

	cout << answer << "\n";
	for (int i = order.size() - 1; i >= 0; --i)
	{
		cout << order[i] << " ";
	}
	return 0;
}