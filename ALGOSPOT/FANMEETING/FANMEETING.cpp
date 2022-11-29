#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 팬미팅 문제풀이를 위한 카라츠바 알고리즘

// 곱셈을 위한 카라츠바에서는 올림과 내림이 필요하기 때문에 이 함수가 필요함
void Normalize(vector<int>& num)
{
	num.push_back(0);
	for (int i = 0; i < num.size() - 1; ++i)
	{
		if (num[i] < 0)
		{
			//SubFrom을 위한 자릿수 내림 처리
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			//AddTo, Multiply를 위한 자릿수 올림 처리
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
	//곱셈을 위한 카라츠바면 주석 해제
	//Normalize(c);
	return c;
}

void AddTo(vector<int>& a, const vector<int>& b, int k)
{
	while (a.size() < b.size() + k)
		a.push_back(0);
	for (int i = 0; i < b.size(); ++i)
		a[i + k] += b[i];
	//곱셈을 위한 카라츠바면 주석 해제
	//Normalize(a);
}

void SubFrom(vector<int>& a, const vector<int>& b)
{
	for (int i = 0; i < b.size(); ++i)
		a[i] -= b[i];
	//곱셈을 위한 카라츠바면 주석 해제
	//Normalize(a);
}

vector<int> Karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();
	if (an < bn) return Karatsuba(b, a);
	// 기저 조건 2가지
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 100) return Multiply(a, b);

	// 분할
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