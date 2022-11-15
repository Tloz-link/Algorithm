#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	long A, B;
	cin >> A >> B;

	queue<pair<long, int>> queue;
	queue.push(make_pair(A, 1));

	int answer = -1;
	while (!queue.empty())
	{
		long number = queue.front().first;
		int order = queue.front().second;
		queue.pop();

		if (number == B)
		{
			answer = order;
			break;
		}

		long next = number * 2;
		if (next <= B)
			queue.push(make_pair(next, order + 1));
		next = 10 * number + 1;
		if (next <= B)
			queue.push(make_pair(next, order + 1));
	}

	cout << answer;
	return 0;
}