#pragma once
#include "Arc.h"
#include "vertex.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>

class Graph
{
protected:
	list<MyVertex> vert_list;
	list<MyVertex>::iterator list_it;
	MyVertex changed_vertex_first;
	MyVertex changed_vertex_second;
	MyArc changed_arc;
	string name;
public:
	//������� �����������
	Graph(string nam) {
		name = nam;
		vert_list.clear();
	}
	//����������� �� ���������
	Graph() {
		name = "#<EmptyGraph>";
		vert_list.clear();
	}
	//��������� ������� � ����� ��� ������ ������
	void createVertex(string name, float x, float y) {
		MyVertex vert(name, x, y);
		if (vert_list.empty()) {
			vert_list.push_front(vert);
		}
		else {
			vert_list.push_back(vert);
		}
	}
	//������ ��� �����
	string getName() {
		return name;
	}
	//�������� ������� �� �����
	bool deleteVertex(MyVertex selectedVertex) {
		MyVertex tempVert;
		bool flag = false;
		list<MyVertex>::iterator vertIt = vert_list.begin();
		while (vertIt != vert_list.end()) {
			tempVert = *vertIt;
			if (selectedVertex == tempVert) {
				flag = true;
				break;
			}
		}
		if (flag) {
			vert_list.remove(selectedVertex);
			return true;
		}
		else
			return false;
	}
	//���������� ��������� ��������� == ��� �������� ������ Graph
	friend bool operator==(const Graph& left, const Graph& right) {
		return left.name == right.name;
	}
};