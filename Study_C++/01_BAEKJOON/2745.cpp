/*
* ���� ��ȯ

<����>
B���� �� N�� �־�����.�� ���� 10�������� �ٲ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
10������ �Ѿ�� ������ ���ڷ� ǥ���� �� ���� �ڸ��� �ִ�.�̷� ��쿡�� ������ ���� ���ĺ� �빮�ڸ� ����Ѵ�.
A: 10, B : 11, ..., F : 15, ..., Y : 34, Z : 35

<�Է�>
ù° �ٿ� N�� B�� �־�����. (2 �� B �� 36)
B���� �� N�� 10�������� �ٲٸ�, �׻� 10�ﺸ�� �۰ų� ����.

<���>
ù° �ٿ� B���� �� N�� 10�������� ����Ѵ�.

<���� �Է� 1>
ZZZZZ 36
<���� ��� 1>
60466175
*/


#include <iostream>
#include <string>
using namespace std;

int func(int B, int cnt)
{
	if (cnt == 0)
		return 1;
	return B * func(B, cnt-1);
}

int main()
{
	int B;
	string N;
	int res = 0;
	int cnt = 0;

	cin >> N >> B;

	for (int i = (N.length()-1); i >= 0; i--)
	{
		if (isalpha(N[i]))
		{
			res += ((N[i] - 55) * func(B, cnt));
		}
		else
		{
			res += ((N[i] - '0') * func(B, cnt));
		}
		cnt++;
	}

	cout << res;

	return 0;
}