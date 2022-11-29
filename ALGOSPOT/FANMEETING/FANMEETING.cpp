#include <iostream>
#include <vector>
#include <string>

using namespace std;
// �ҹ��� ����Ǯ�̸� ���� ī������ �˰���

// ������ ���� ī�����ٿ����� �ø��� ������ �ʿ��ϱ� ������ �� �Լ��� �ʿ���
void Normalize(vector<int>& num)
{
	num.push_back(0);
	for (int i = 0; i < num.size() - 1; ++i)
	{
		if (num[i] < 0)
		{
			//SubFrom�� ���� �ڸ��� ���� ó��
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			//AddTo, Multiply�� ���� �ڸ��� �ø� ó��
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

vector<int> Multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			c[i + j] += a[i] * b[j];
		}
	}
	//������ ���� ī�����ٸ� �ּ� ����
	//Normalize(c);
	return c;
}

void AddTo(vector<int>& a, const vector<int>& b, int k)
{
	while (a.size() < b.size() + k)
		a.push_back(0);
	for (int i = 0; i < b.size(); ++i)
		a[i + k] += b[i];
	//������ ���� ī�����ٸ� �ּ� ����
	//Normalize(a);
}

void SubFrom(vector<int>& a, const vector<int>& b)
{
	for (int i = 0; i < b.size(); ++i)
		a[i] -= b[i];
	//������ ���� ī�����ٸ� �ּ� ����
	//Normalize(a);
}

vector<int> Karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();
	if (an < bn) return Karatsuba(b, a);
	// ���� ���� 2����
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 100) return Multiply(a, b);

	// ����
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = Karatsuba(a1, b1);
	vector<int> z0 = Karatsuba(a0, b0);
	AddTo(a0, a1, 0);
	AddTo(b0, b1, 0);
	vector<int> z1 = Karatsuba(a0, b0);
	SubFrom(z1, z0);
	SubFrom(z1, z2);
	vector<int> ret;
	AddTo(ret, z0, 0);
	AddTo(ret, z1, half);
	AddTo(ret, z2, half + half);
	return ret;
}

int Hugs(const string& members, const string& fans)
{
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i)
		A[i] = (members[i] == 'M');
	for (int i = 0; i < M; ++i)
		B[M - 1 - i] = (fans[i] == 'M');
	vector<int> C = Karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i)
	{
		if (C[i] == 0)
			++allHugs;
	}
	return allHugs;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		string members;
		string fans;
		cin >> members >> fans;
		cout << Hugs(members, fans) << "\n";
	}
	return 0;
}