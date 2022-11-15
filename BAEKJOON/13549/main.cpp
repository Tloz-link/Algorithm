#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> queue;
	bool discovered[100001] = {0};
	queue.push(make_pair(N, 0));
	
	int answer = -1;
	while (!queue.empty())
	{
		int number = queue.front().first;
		int time = queue.front().second;
		queue.pop();

		int next = number;
		while (next <= 100000)
		{
			if (next == K)
			{
				answer = time;
				break;
			}

			discovered[next] = true;
			if (next != 0 && discovered[next - 1] == false)
			{
				queue.push(make_pair(next - 1, time + 1));
				discovered[next - 1] = true;
			}
			if (next != 100000 && discovered[next + 1] == false)
			{
				queue.push(make_pair(next + 1, time + 1));
				discovered[next + 1] = true;
			}
			next *= 2;
			if (next == 0)
				break;
		}

		if (answer == time)
			break;
	}

	cout << answer;
	return 0;
}