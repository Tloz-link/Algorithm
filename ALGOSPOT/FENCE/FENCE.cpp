#include <iostream>
#include <vector>

using namespace std;

int Solve(vector<int>& fence, int left, int right)
{
	//±âÀú Á¶°Ç
	if (left == right)
	{
		return fence[left];
	}

	int midLeft = (left + right) / 2;
	int midRight = (left + right) / 2 + 1;

	int ret = 0;
	// ¿ÞÂÊ Àý¹Ý Å½»ö
	ret = max(ret, Solve(fence, left, midLeft));
	// ¿À¸¥ÂÊ Àý¹Ý Å½»ö
	ret = max(ret, Solve(fence, midRight, right));

	// ¿ÞÂÊ + ¿À¸¥ÂÊ Å½»ö
	int minHeight = min(fence[midLeft], fence[midRight]);
	ret = max(ret, minHeight * (midRight - midLeft + 1));
	while (midLeft != left || midRight != right)
	{
		if (midLeft == left)
			minHeight = min(minHeight, fence[++midRight]);
		else if (midRight == right)
			minHeight = min(minHeight, fence[--midLeft]);
		else
			if (fence[midLeft - 1] > fence[midRight + 1])
				minHeight = min(minHeight, fence[--midLeft]);
			else
				minHeight = min(minHeight, fence[++midRight]);
		
		ret = max(ret, minHeight * (midRight - midLeft + 1));
	}

	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		int N;
		cin >> N;
		vector<int> fence(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> fence[i];
		}
		cout << Solve(fence, 0, N - 1) << "\n";
	}
	return 0;
}