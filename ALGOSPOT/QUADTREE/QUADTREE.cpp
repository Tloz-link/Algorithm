#include <iostream>
#include <string>

using namespace std;

string Reverse(string::iterator& it)
{
	char node = *(it++);
	// ���� ����
	if (node == 'w' || node == 'b')
		return string(1, node);

	// ������ ���� ũ���� ���� ������ ����
	string leftUp = Reverse(it);
	string rightUp = Reverse(it);
	string leftDown = Reverse(it);
	string rightDown = Reverse(it);

	// ������ ���� ����
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