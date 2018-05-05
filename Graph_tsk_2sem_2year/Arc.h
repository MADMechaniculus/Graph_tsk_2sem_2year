#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class MyArc
{
protected:
	string name_arc;
	string name_from;
	string name_to;
	float weight;
	int direction;
public:
	//�����������
	MyArc(string arcnm,string n1, string n2, float w, int direct)	{
		name_arc = arcnm;
		name_from = n1;
		name_to = n2;
		weight = w;
		direction = direct;	//���� 1, �� �� _from � _to; ���� 2, �� �� _to � _from; ���� 0, �� ��������������� ����;
		if ((direction < 0) || (direction > 2)){
			cout << "Error in arc initialization! Name -> " << name_arc << endl;
			cout << "Exiting recommended!!!" << endl;
		}
	}
	//����������� �� ���������
	MyArc() {
		name_arc = "#<Name_of_arc>";
		name_from = "EmptyForm";
		name_to = "EmptyTo";
		weight = 1;
		direction = 0;
	}
	//�������� ����� 1
	bool nameToComp(string name)
	{
		if (name_to == name) {
			return true;
		}
		else {
			return false;
		}
	}
	//�������� ����� 2
	bool nameFromComp(string name) {
		if (name_from == name) {
			return true;
		}
		else {
			return false;
		}
	}
	//�������� ������������ �����������
	bool check()
	{
		if ((direction < 0) || (direction > 2))	{
			return false;
		}
		else{
			return true;
		}
	}
	//�������� ��� 1
	string getNameTo() {
		return name_to;
	}
	//�������� ��� 2
	string getNameFrom() {
		return name_from;
	}
	//�������� ��� ����
	float getWeight() {
		return weight;
	}
	//������ ��� ����
	void setWeight(float wght) {
		weight = wght;
	}
	//��������������� ��������� ��������� == ��� �������� ���� MyArc
	friend bool operator==(const MyArc& left, const MyArc& right) {
		return (left.name_from == right.name_from) && (left.name_to == right.name_to);
	}
	//����������
	~MyArc() {}
};