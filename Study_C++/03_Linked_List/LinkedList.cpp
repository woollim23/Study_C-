#include <iostream>

#include "LinkedList.h"
// �߰��� ��� - tailnode, frontnode


/*------ ���� ����Ʈ �ʱ�ȭ ------*/
void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

/*------ ������ �߰� �Լ�(����Ʈ �� �ڿ�) ------*/
void PushBack(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	// ������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// �߰��� �����Ͱ� ó������ �ƴ��� Ȯ��
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode; // ������ ����̹Ƿ� ����忡 ����
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ� �ݺ�, �ؽ�Ʈ��尡 null�̸� ����
		// �ش� ����� pNext �� ������Ų ����� �ּҷ� ä��
		tNode* pCurFinalNode = _pList->pHeadNode; // ������ ��������
		while (pCurFinalNode->pNextNode) // ���� ����Ű�� �ִ� ����� �ؽ�Ʈ ��尡 ������(null) ����
		{
			pCurFinalNode = pCurFinalNode->pNextNode; // ������� �ּ� �ο�(�ݺ�)
		}
		pCurFinalNode->pNextNode = pNode; // ����Ʈ�� ����� ������ ����� �ؽ�Ʈ��� �ּҿ� ����
	}

	_pList->iCount++; // ��������
}

/*------ ������ �߰� �Լ�(����Ʈ �� �տ�) ------*/
void PushFront(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	// ������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;

	pNode->pNextNode = _pList->pHeadNode; // ����带 �� ����� �ؽ�Ʈ ���� ����
	_pList->pHeadNode = pNode; // ����Ʈ�� ����忡�� ����� ����

	_pList->iCount++; // ��������
}


/*------ �޸� ���� �Լ� ------*/
void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;

	while (pDeletNode) // ������ ����϶� ���� �ݺ�
	{
		tNode* pNext = pDeletNode->pNextNode; // ���� ������
		free(pDeletNode);// ���� ���� ����
		pDeletNode = pNext; // ������带 ���� ���� ����
	}

	_pList->iCount = 0;
}
