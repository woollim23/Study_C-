/*
* �Ҽ� ã��
* 
<����>
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

<�Է�>
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

<���>
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.

<���� �Է� 1>
4
1 3 5 7
<���� ��� 1>
3
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int res = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		int cnt = 0;
		cin >> tmp;

		for (int j = 1; j < tmp; j++)
		{
			if (tmp % j == 0)
			{
				cnt++;
			}
		}
		if (cnt == 1)
		{
			res++;
		}
	}

	cout << res;
	return 0;
}