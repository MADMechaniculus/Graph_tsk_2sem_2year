#pragma once
#include "Arc.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
#include <iterator>

using namespace std;

class MyVertex
{
protected:
	string name;
	deque<MyArc> arc_deq;
	deque<MyArc>::iterator it_deq;
	float X, Y;
public:
	//�����������
	MyVertex(string nm, float x, float y) {
		setName(nm);
		deque<MyArc> arc_deq(20);
		setCoord(x, y);
	}
	//����������� �� ���������
	MyVertex() {
		name = "#<Name_of_vertex>";
		deque<MyArc> arc_deq(20);
	}
	//�������� ����� � ������ ������
	void pushNewArc(MyArc newArc) {
		arc_deq.push_back(newArc);
	}
	//��������� ���
	string getName() {
		return name;
	}
	//�������� ������� ��� � �������
	bool check() {
		if (arc_deq.empty() == true) {
			return false;	//������ ���������� � ���, ��� ������� �����������
		}
		else {
			return true;	//���������� ������� ���������� ����������
		}
	}
	//���� ��������� ������� ��� ���������� � �� ����
	void setCoord(float x, float y) {
		X = x;
		Y = y;
	}
	//������ ��� �������
	void setName(string nm) {
		name = nm;
	}
	//��������������� ��������� ��������� == ��� myVertex
	friend bool operator==(const MyVertex& left, const MyVertex& right) {
		return left.name == right.name;
	}
	//����������
	~MyVertex() {}
};