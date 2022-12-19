#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;
int n, start;
int arr[MAX];
int c1[MAX];
int memo[MAX];
int Solve()
{
	for (int i = 0; i < n; ++i)
	{
		c1[i] = 1;
		memo[i] = -1;
		for (int j = 0; j <= i; ++j)
		{
			if (arr[i] > arr[j] && c1[i] < c1[j] + 1)
			{
				c1[i] = c1[j] + 1;
				memo[i] = j;
			}
		}
	}

	int max = 0;
	start = -1; 
	for (int i = 0; i < n; ++i)
	{
		if (max < c1[i])
		{
			max = c1[i];
			start = i;
		}
	}
	return max;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int result = Solve();
	cout << result << "\n";

	// Reconstruct
	vector<int> answer(result);
	for (int i = 0; i < result; ++i)
	{
		answer[result - i - 1] = arr[start];
		start = memo[start];
	}
	for (int i = 0; i < result; ++i)
	{
		cout << answer[i] << " ";
	}
	return 0;
}
