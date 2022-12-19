#include <iostream>

using namespace std;

const int MAX = 1000;
int n;
int arr[MAX];
int c1[MAX];
int c2[MAX];
int Solve()
{
	for (int i = 0; i < n; ++i)
	{
		c1[i] = 1;
		for (int j = 0; j <= i; ++j)
		{
			if (arr[i] > arr[j] && c1[i] < c1[j] + 1)
			{
				c1[i] = c1[j] + 1;
			}
		}
	}

	for (int i = n - 1; i >= 0; --i)
	{
		c2[i] = 1;
		for (int j = i; j < n; ++j)
		{
			if (arr[i] > arr[j] && c2[i] < c2[j] + 1)
			{
				c2[i] = c2[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (max < c1[i] + c2[i] - 1)
		{
			max = c1[i] + c2[i] - 1;
		}
	}
	return max;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << Solve();
	return 0;
}
