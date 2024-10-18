/*
* �ﰢ���� �� ��
*
<����>
�ﰢ���� �� ���� ���̰� �־��� �� ���� ���̿� ���� ������ ���� �����Ѵ�.

Equilateral :  �� ���� ���̰� ��� ���� ���
Isosceles : �� ���� ���̸� ���� ���
Scalene : �� ���� ���̰� ��� �ٸ� ���
�� �־��� �� ���� ���̰� �ﰢ���� ������ �������� ���ϴ� ��쿡�� "Invalid" �� ����Ѵ�. ���� ��� 6, 3, 2�� �� ��쿡 �ش��Ѵ�. ���� �� ���� ���̺��� ������ �� ���� ������ ���� ���� ������ �ﰢ���� ������ �������� ���Ѵ�.

�� ���� ���̰� �־��� �� �� ���ǿ� ���� ����� ����Ͻÿ�.

<�Է�>
�� �ٿ��� 1,000�� ���� �ʴ� ���� ���� 3���� �Էµȴ�. ������ ���� 0 0 0�̸� �� ���� ������� �ʴ´�.

<���>
�� �Է¿� �´� ��� (Equilateral, Isosceles, Scalene, Invalid) �� ����Ͻÿ�.

<���� �Է� 1>
7 7 7
6 5 4
3 2 5
6 2 6
0 0 0
<���� ��� 1>
Equilateral
Scalene
Invalid
Isosceles
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int m = max({ a,b,c });

		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		if (m>=(a+b+c-m))
		{
			cout << "Invalid";
		}
		else if (a == b && a == c && b == c)
		{
			cout << "Equilateral";
		}
		else if (a == b || b == c || a == c)
		{
			cout << "Isosceles";
		}
		else if (a != b && a != c && b != c)
		{
			cout << "Scalene";
		}
		cout << endl;
	}
	return 0;
}
