#pragma once
/*--------- Ŭ���� ���ø� ����Ʈ ---------*/

/*--------- ��� ����ü ���ø� ---------*/
template<typename T>
struct tListNode // c++ ������ ����ü�� Ŭ������ �����
{
	T data;
	tListNode<T>* pPrev;
	tListNode<T>* pNext; // ���ο��� �����Ͽ� <T> ��������

	// ����ü �⺻ ������(������ ���� X)
	tListNode()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}

	// ����ü ������(������ ���� o)
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

/*--------- ����Ʈ Ŭ���� ---------*/
template<typename T>
class CList
{
public:
	// �ܺο� �ֱ� ������ <T>�� �� �پ����
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;
	int m_iCount;

public:
	void push_back(const T& _data);  // T�� �����̱� ������ �������� ���̱� ���� ���۷����� �޾ƿ�
	void push_front(const T& _data); // ���� ������ �����ϱ� ���� const Ű���带 ����

public:
	CList();
	~CList();
};


/*--------- ������ �Է� �Լ�(�ǵ�) ---------*/
template<typename T>
void CList<T>::push_back(const T& _data)
{
	// �Էµ� �����͸� ������ ��带 �����Ҵ� ��
	// �����ڸ� ���� ���ڸ� �����Ͽ� �ʱ�ȭ ��(����)
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	if (nullptr == m_pHead)
	{
		// ó�� �Էµ� �����Ͷ��
		m_pHead = pNewNode; // ��� ������Ų ��带 ��尡 ����Ű�� ��
		m_pTail = pNewNode; // ù ���� ���� ������ ���� 
	}
	else
	{
		// �����Ͱ� 1�� �̻󿡼� �Էµ� ���
		// ���� ���� ������ ������(tail)�� �����ϰ� �ִ� ��尡
		// ���� ������ ���� ���� ����Ű�� ��

		// ���� ���� ���� ������ ����� �ؽ�Ʈ �ּҿ� ��� ������ ��带 ����Ű�� �� 
		m_pTail->pNext = pNewNode;

		// ��� ������ ����� �� ��� �ּҿ� ���� ���� ���� ������ ��带 ����Ű�� ��
		pNewNode->pPrev = m_pTail;

		// ���� List�� ���� ������ ���� ��� ������ ���
		m_pTail = pNewNode;

	}
	// ������ ���� ����
	m_iCount++;
}


/*--------- ������ �Է� �Լ�(�Ǿ�) ---------*/
template<typename T>
void CList<T>::push_front(const T& _data)
{
	// ���� ����Ʈ�� �˰� �ִ� ����ּҸ� ���� �����ϴ� ����� �ؽ�Ʈ���� �Է�
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	// ���� ������� ���� ��� �ּڰ��� ��� ������ ��带 �Է��Ͽ�, ���� ����Ű�� ��
	m_pHead->pPrev = pNewNode;

	// ��� ������ ��带 ���ο� ����ּҷ� ����
	m_pHead = pNewNode;

	// ������ ���� ����
	m_iCount++;
}


/*--------- ������ ---------*/
template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{
}


/*--------- �Ҹ��� ---------*/
template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;

	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNext;
	}
}