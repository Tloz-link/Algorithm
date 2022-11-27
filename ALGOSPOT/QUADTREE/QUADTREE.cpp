#include <iostream>
#include <string>

using namespace std;

string Reverse(string::iterator& it)
{
	char node = *(it++);
	// 기저 조건
	if (node == 'w' || node == 'b')
		return string(1, node);

	// 문제를 같은 크기의 하위 문제로 나눔
	string leftUp = Reverse(it);
	string rightUp = Reverse(it);
	string leftDown = Reverse(it);
	string rightDown = Reverse(it);

	// 각각의 답을 병합
	return "x" + leftDown + rightDown + leftUp + rightUp;
}

int main() {
	int C;
	cin >> C;

	while (C--)
	{
		string tree;
		cin >> tree;
		string::iterator it = tree.begin();
		cout << Reverse(it) << '\n';
	}
	return 0;
}