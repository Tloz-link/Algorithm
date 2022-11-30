#include <iostream>
#include <vector>

using namespace std;

void Solve(vector<int>& in, vector<int>& post, int inStart, int inEnd, int postRoot)
{
	int inRoot = -1;
	for (int i = inStart; i <= inEnd; ++i)
	{
		if (in[i] == post[postRoot])
		{
			inRoot = i;
			break;
		}
	}
	// 기저조건
	if (inRoot == -1)
		return;
	cout << post[postRoot] << " ";

	// 왼쪽 자식, 오른쪽 자식 분할
	Solve(in, post, inStart, inRoot - 1, postRoot - (inEnd - inRoot) - 1);
	Solve(in, post, inRoot + 1, inEnd, postRoot - 1);
}

int main() {
	int N;
	cin >> N;
	vector<int> in(N);
	vector<int> post(N);
	for (int i = 0; i < N; ++i)
		cin >> in[i];
	for (int i = 0; i < N; ++i)
		cin >> post[i];
	Solve(in, post, 0, N - 1, N - 1);
	return 0;
}