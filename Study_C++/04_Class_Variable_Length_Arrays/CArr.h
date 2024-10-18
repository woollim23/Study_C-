#pragma once
#include <assert.h>
/*-----Ŭ���� ���� ���� �迭(vector)-----*/

template<typename T> // Ŭ���� ���ø����� ��ȯ
class CArr
{
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	void Push_Back(const T& _Data); // ������ �״�� �ޱ� ����, �ּ� ������ ��ȣ
	void Resize(int _iResizeCount); // ���Ҵ� �Լ�, ���� ĭ���� ����
	T* data() { return m_pData; } // �������� ���� �ּ� ��ȯ
	int size() { return m_iCount; } // ���� ���� ������ ����
	int capacity() { return m_iMaxCount; } // �ִ� ������ ����
	T& operator[] (int idx); // �迭ó�� �� �� �ֵ���, �ε��� �޴� �Լ�

	class iterator; // �ݺ��� �Լ� ���漱��
	iterator begin(); // ������ ����Ű�� iterator �� ���� ��ȯ����
	iterator end();
	iterator erase(const iterator& _iter);

public:
	CArr();
	~CArr();

	// �ݺ���(iterator)�� �����迭�� �����ϴ� ������ ��Ҹ� ����Ű�� ����
	// �̳�Ŭ������ �ݺ��� �����غ���
	// CArr�� �����̺� ������ ���� ���� -> inner Ŭ������ �����ϰ� �ִ� Ŭ������ private ����� ���� ����
	// ���ø� ���� ��
	class iterator
	{
	private:
		CArr* m_pArr; // iterator �� ����Ų �����͸� �����ϴ� �����迭 �ּ�
		T* m_pData; // �����͵��� ���� �ּ�
		int m_iIdx; // ����Ű�� �������� �ε���

	public:
		// �������� ������
		T& operator * ()
		{
			// �����迭�� �˰� �ִ� �ּҿ�, iterator �� �˰��ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			// iterator �� end iterator �� ���
			if ((m_pArr->m_pData != m_pData) || (-1 == m_iIdx))
				assert(nullptr);

			return m_pData[m_iIdx];
		}

		// ++ ���� ���������� ����
		// �ߺ� ������ ���� ��ȯ���� �ڱ� �ڽ�����
		iterator& operator ++()
		{
			// end iterator �� ���
			// �����Ͱ� ���Ҵ� �Ǿ� �ּҰ��� ����� ���
			if ((m_pArr->m_pData != m_pData) || (-1 == m_iIdx))
				assert(nullptr); // ���� ��Ȳ

			// iterator �� ������ �����͸� ����Ű�� �ִ� ���
			// --> end iterator�� �ȴ�.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ++ ���� ���������� ����
		// ��ȯ���� ���۷����� ����. ���� ������ �����ϴ� ���� �ƴ� �Ǵٸ� ���纻�� �����ϰ� �Ǵ� ��
		iterator operator ++(int)
		{
			// ���� �����ڸ� �̿��Ͽ� ���� ���ͷ����Ͱ� ���� ���ͷ����ͷ� �����
			iterator copy_iter = *this;

			// ������ ������ ���������� Ȱ��
			++(*this);

			// ���纻�� �����Ͽ� �������� ���� ��ȯ
			return copy_iter;
		}

		// -- ����, ���� ���� �����غ���
		// ����
		iterator& operator --()
		{
			// begin iterator �� ���
			// �����Ͱ� ���Ҵ� �Ǿ� �ּҰ��� ����� ���
			// ����� �����Ͱ� ���� ���
			if ((this->m_iIdx == 0) || (m_pArr->m_pData != m_pData) || (m_pArr->size() == 0))
				assert(nullptr); // ���� ��Ȳ
			else
			{
				--m_iIdx;
			}

			return *this;
		}

		iterator operator --(int)
		{
			// ���� �����ڸ� �̿��Ͽ� ���� ���ͷ����Ͱ� ���� ���ͷ����ͷ� �����
			iterator copy_iter = *this;

			// ������ ������ ���������� Ȱ��
			--(*this);

			// ���纻�� �����Ͽ� �������� ���� ��ȯ
			return copy_iter;
		}

		// �񱳿�����
		bool operator == (const iterator& _otheriter)
		{
			// ������ �ּҿ� �ε��� ��� ��ġ�ؾ� ��
			if ((m_pData == _otheriter.m_pData) && (m_iIdx == _otheriter.m_iIdx))
			{
				return true;
			}
			
			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			/*
			if ((m_pData == _otheriter.m_pData) && (m_iIdx == _otheriter.m_iIdx))
			{
				return false;
			}

			return true;
			*/

			return !(*this == _otheriter);
		}
		
	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1) // �������� end�� ���� (�����Ͱ� ����ִ� ����)
		{}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
		{}

		~iterator()
		{}
	};
};

/*-------- �ʱ�ȭ �Լ� ---------*/
// ������ ��������� �ʱ�ȭ �ϴ°� ���������� ���� ���� ����
template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	// new �����Ҷ� ���� Ű����, int * 2��ŭ ���� �Ҵ�
	m_pData = new T[2];

}

/*-------- �޸� ���� �Լ� ---------*/
template<typename T>
CArr<T>::~CArr()
{
	// free�� ���� �ּ�����
	// ������ ������������ []�� ����, ������ ���� ����
	delete[] m_pData;
}

/*-------- ������ �߰� �Լ� ---------*/
template<typename T>
void CArr<T>::Push_Back(const T& _Data)
{
	// �� ������ �Ҵ��� ������ �� ä������ Ȯ��
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// ���Ҵ�
		Resize(this->m_iMaxCount * 2);
	}

	// ������ �߰�
	this->m_pData[this->m_iCount++] = _Data;
}

/*-------- ���Ҵ� �Լ� ---------*/
template<typename T>
void CArr<T>::Resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // ���� ����� �ڵ�
	}
	// 1. �������� ��ų ������ŭ �����Ҵ� ��
	T* pNew = new T[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� ����
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pData;

	// 4. �迭�� ���� �Ҵ��� ������ ����Ű�� ��
	m_pData = pNew;

	// 5. MaxCount ������ ����(2��)
	m_iMaxCount = _iResizeCount;
}

/*-------- �ε��� �Լ� ---------*/
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

// ������ ����Ű�� iterator �� ���� ��ȯ����
// Ÿ�Գ��� ���� ���� -> Ư�� Ÿ���̶� ���� �˸��� ����
template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	/* �����ڷ� ����� �Ǹ鼭 ������
	iterator iter;
	// ������� �ݺ��ڰ� ������ ������ �������� ���� �ּҿ� �Ȱ��� ��
	iter.m_pData = this->m_pData;
	// ������ ����Ű�Ƿ� 0
	iter.m_iIdx = 0;

	return iter;
	*/

	// �����Ͱ� �������� ��ȯ, begin() == end()
	if (0 == m_iCount)
		return iterator(this, m_pData, -1);

	// ������ �ο��� �ʿ䵵 ���� �ӽ� ��ü ����� ��� ��ȯ
	return iterator(this, m_pData, 0);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// ������ ������ �׸��� ���� ��, �������
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(const iterator& _iter)
{
	return iterator();
}
