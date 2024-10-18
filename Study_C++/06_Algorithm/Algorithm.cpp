#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// ����
template<typename T>
class Vector
{
private:
	T* _data = nullptr;
	int _size = 0;
	int _capacity = 0;

public:
	Vector(){}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	// ������ ���� �Լ�
	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// ���� �۾�
			int newCapacity = static_cast<int>(_capacity * 1.5);
			// _capacity�� 0�̳� 1�� ��� üũ
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// ������ ����
		_data[_size] = value;
		// ������ ���� ����
		_size++;
	}

	// ���� ���� ���� �Լ�
	void reserve(int capacity)
	{
		if (_capacity >= capacity)
		{
			return;
		}

		_capacity = capacity;

		T* newData = new T[_capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data)
			delete[] _data;

		// ��ü
		_data = newData;

	}

	T& operator[](const int pos) { return _data[pos]; }
	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}
		 
		_size = 0;
	}
};

// ����Ʈ - ���
template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}

	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

public:
	Node*	 _prev;
	Node*	 _next;
	T		 _data;
};

// ���ͷ�����
template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{
	
	}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	// it++
	Iterator& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	// it--
	Iterator& operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->_data;
	}

	// ������ üũ
	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}
	// �ٸ��� üũ
	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};

// ����Ʈ
template<typename T>
class List
{
public:
	Node<T>* _head;
	Node<T>* _tail;
	int			_size;

public:
	List() : _size(0)
	{
		// ���� ���, ���� ����
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}

	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

private:
	// ���ο��� �μ�Ʈ �����ϴ� �Լ�
	// [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]
	// [head] <-> [1] <-> [prevNode] <-> "[newNode]" <-> [before] <-> [tail]
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		// ���� ����� ���� ��忡 ���ο� ��带 ����
		prevNode->_next = newNode;
		// ���ο� ����� ���� �翬�� ���� ���
		newNode->_prev = prevNode;

		// �� ����� ������
		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}
	
	// Ư�� ��� ������ �����ϴ� �Լ�
	// [head] <-> [prevNode] <-> "[node]" <-> [nextNode] <-> [tail]
	// [head] <-> [prevNode] <-> [nextNode] <-> [tail]
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	// ������ ��ȯ �Լ�
	int size() { return _size; }

public:
	using iterator = Iterator<T>;
	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	// it '�տ�' �߰�
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}
};

// ����
template<typename T, typename Container = vector<T>>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	Container _container;
};

// ť
template<typename T>
class ArrayQueue
{
public:
	ArrayQueue()
	{
		_container.resize(100);
	}
	void push(const T& value)
	{
		// [][][front][][][][][back][][][]
		// [fromt][][][][][back][][][][][]
		// TODO : ��á���� üũ
		if (_size == _container.size())
		{
			// ���� �۾�
			int newSize = max(1, _size * 2); // _size�� 0�̸� �ּ� 1�� ��ȯ����
			vector<T> newData;
			newData.resize(newSize);

			// ������ ����
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}
		_container[_back] = value;
		_back = (_back + 1) % _container.size(); // ���⼭�� ������� capacity ���� ����
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};

template<typename T>
class ListQueue
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_front();
	}

	T& front()
	{
		return _container.front();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	list<T> _container;
};

int main()
{
	//  ------------- ���� ---------------
	/*
	vector<int> v;

	// resize�� ����, capacity�� ���� 10���� ����
	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;
	// capacity �� ����
	v.reserve(100);
	cout << v.size() << " " << v.capacity() << endl;

	for (int i = 0; i < 200; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;

	v.clear();

	cout << v.size() << " " << v.capacity() << endl;

	*/

	//  ------------ ����Ʈ --------------
	/*
	List<int> li;
	List<int>::iterator eraseIt;
	// [ ] <-> [ ] <-> [ ] <-> [ ]  <-> [ ]  <-> [ ]
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();

	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}
	*/

	//  ------------- ���� ---------------
	/*
	Stack<int, list<int>> s;

	// ����
	s.push(1);
	s.push(2);
	s.push(3);

	// �����Ͱ� ����ֳ� üũ
	while (s.empty() == false)
	{
		// �ֻ��� ����
		int data = s.top();
		// �ֻ��� ���� ����
		s.pop();

		cout << data << endl;
	}

	int size = s.size();
	*/

	//  -------------- ť ----------------
	/*
	ArrayQueue<int> q;

	for (int i = 0; i < 100; i++)
	{
		q.push(i);
	}

	while (q.empty() == false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();

	*/
} 