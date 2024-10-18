#pragma once
// - ���Ḯ��Ʈ�� �����͸� �ް� ���θ��� ��忡 �����͸� ������ ��, ������ ��忡 �̾� ����

// ���� ���
typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode;
}tNode;

// ���� ����Ʈ 
typedef struct _tagList 
{
	tNode* pHeadNode; // ������ ��� �ּ� ����
	int iCount; // ��尹��
}tLinkedList;

// ���� ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList);

// ������ �߰� �Լ�(����Ʈ �� �ڿ�)
void PushBack(tLinkedList* _pList, int _iData);

// ������ �߰� �Լ�(����Ʈ �� �տ�)
void PushFront(tLinkedList* _pList, int _iData);

// �޸� ���� �Լ�
void ReleaseList(tLinkedList* _pList);