/*
* �ﰢ�� �ܿ��
*
<����>
â���̴� �ﰢ���� ������ �� �������� ���Ѵ�. ���� ���α׷��� �̿��� �̸� �ܿ���� �Ѵ�.

�ﰢ���� �� ���� �Է¹��� ����,

�� ���� ũ�Ⱑ ��� 60�̸�, Equilateral
�� ���� ���� 180�̰�, �� ���� ���� ��쿡�� Isosceles
�� ���� ���� 180�̰�, ���� ���� ���� ��쿡�� Scalene
�� ���� ���� 180�� �ƴ� ��쿡�� Error

�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

<�Է�>
�� 3���� �ٿ� ���� �ﰢ���� ���� ũ�Ⱑ �־�����. ��� ������ 0���� ũ��, 180���� �۴�.

<���>
������ ���� ���� Equilateral, Isosceles, Scalene, Error �� �ϳ��� ����Ѵ�.

<���� �Է� 1>
60
70
50
<���� ��� 1>
Scalene
*/

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if ((a == 60) && (b == 60) && (c == 60))
	{
		cout << "Equilateral";
	}
	else if (a + b + c != 180)
	{
		cout << "Error";
	}
	else
	{
		if (a == b || a == c || b == c)
		{
			cout << "Isosceles";
		}
		else
		{
			cout << "Scalene";
		}
	}
	return 0;
}
