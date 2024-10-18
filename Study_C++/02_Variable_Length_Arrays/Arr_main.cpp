/*----�����迭----*/

#include <iostream>
#include <time.h>

#include "Arr.h"
using namespace std;

void BubbleSort(int* _pData, int _iCount)
{
	// �����Ͱ� 1�� ���ϸ� �������� ����
	if (_iCount <= 1)
		return;

	while (true)
	{
		bool bFinish = true;

		// �������� ����
		for (int i = 0; i < (_iCount - 1); i++)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}

		if (bFinish) // �������� ����
			break;
	}
}

int main()
{
	tArr s = {};
	InitArr(&s);

	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		int iRand = rand() % 100 + 1; // 1 ~ 100 ���� ��������
		PushBack(&s, iRand);
	}

	Sort(&s, BubbleSort); // �Լ��� �̸���ü�� �ּ�, & ��������

	for (int i = 0; i < s.iCount; i++)
	{
		cout << s.pInt[i] << " ";
	}

	ReleaseArr(&s);

	return 0;
}