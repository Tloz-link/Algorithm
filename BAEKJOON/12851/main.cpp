#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> queue;
	bool visited[100001] = {0};
	queue.push(make_pair(N, 0));
	
	int min = INT32_MAX;
	int count = 0;
	while (!queue.empty())
	{
		int number = queue.front().first;
		int time = queue.front().second;
		queue.pop();
		visited[number] = true;

		if (time > min)
			continue;

		if (number == K)
		{
			min = time;
			count++;
			continue;
		}

		if (number != 0 && visited[number - 1] == false)
			queue.push(make_pair(number - 1, time + 1));
		if (number != 100000 && visited[number + 1] == false)
			queue.push(make_pair(number + 1, time + 1));
		if (number <= 50000 && visited[number * 2] == false)
			queue.push(make_pair(number * 2, time + 1));
	}

	cout << min << "\n" << count;
	return 0;
}