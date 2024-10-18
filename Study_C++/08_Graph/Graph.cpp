#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{

};

vector<Vertex> vertices; // ����
vector<vector<int>> adjacent; // ����� ����
vector<bool> visited; // �湮 ���� ��� (����)
vector<bool> discovered; // �߰� ���� ��� (�ʺ�)
void CreateGraph()
{
	vertices.resize(6); // ���� 6��
	adjacent = vector<vector<int>>(6);

	// ���� ����Ʈ
	//adjacent[0].push_back(1);
	//adjacent[0].push_back(3);
	//adjacent[1].push_back(0);
	//adjacent[1].push_back(2);
	//adjacent[1].push_back(3);
	//adjacent[3].push_back(4);
	//adjacent[5].push_back(4);

	// ���� ���
	adjacent = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0},
		{ 1, 0, 1, 1, 0, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
	};
}


// DFS (Depth First Search) ���� �켱 Ž��
void Dfs(int here)
{
	// �湮
	visited[here] = true;
	cout << "Visited : " << here << endl;
	// ���� ����Ʈ version
	// ��� ���� ������ ��ȸ�Ѵ�
	/*
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}
	*/

	// ������� version
	// ��� ���� ������ ��ȸ�Ѵ�
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		// ���� �湮���� ���� ���� ������ �湮
		if (visited[there] == false)
			Dfs(there);
	}
}
// DFS All
void DfsAll()
{
	visited = vector<bool>(6, false);
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
}


// Bfs (Breadth First search) �ʺ� �켱 Ž��
void Bfs(int here)
{
	// ������ ���� �߰� �Ǿ�����?
	vector<int> parent(6, -1);
	// ���������� ��ŭ ������ �ִ���?
	vector<int> distance(6, -1);

	// (1) �߰��� ���⼭
	queue<int> q;
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front(); // ���� �湮�� ����
		q.pop();
		// (2) �湮�� ���⼭
		cout << "Visited : " << here << endl;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == 0)
				continue;
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}

	int a = 3;
}

void BfsAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}

int main()
{
	CreateGraph();
	//visited = vector<bool>(6, false);
	//Dfs(0);
	//DfsAll();

	discovered = vector<bool>(6, false);
	Bfs(0);
}