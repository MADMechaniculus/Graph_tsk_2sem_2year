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
	//Конструктор
	MyArc(string arcnm,string n1, string n2, float w, int direct)	{
		name_arc = arcnm;
		name_from = n1;
		name_to = n2;
		weight = w;
		direction = direct;	//Если 1, то от _from к _to; Если 2, то от _to к _from; Если 0, то двунаправленная дуга;
		if ((direction < 0) || (direction > 2)){
			cout << "Error in arc initialization! Name -> " << name_arc << endl;
			cout << "Exiting recommended!!!" << endl;
		}
	}
	//Конструктор по умолчанию
	MyArc() {
		name_arc = "#<Name_of_arc>";
		name_from = "EmptyForm";
		name_to = "EmptyTo";
		weight = 1;
		direction = 0;
	}
	//Проверка имени 1
	bool nameToComp(string name)
	{
		if (name_to == name) {
			return true;
		}
		else {
			return false;
		}
	}
	//Проверка имени 2
	bool nameFromComp(string name) {
		if (name_from == name) {
			return true;
		}
		else {
			return false;
		}
	}
	//Проверка корректности направления
	bool check()
	{
		if ((direction < 0) || (direction > 2))	{
			return false;
		}
		else{
			return true;
		}
	}
	//Получить имя 1
	string getNameTo() {
		return name_to;
	}
	//Получить имя 2
	string getNameFrom() {
		return name_from;
	}
	//Получить вес дуги
	float getWeight() {
		return weight;
	}
	//Задать вес дуги
	void setWeight(float wght) {
		weight = wght;
	}
	//Переопределение бинарного оператора == для объектов типа MyArc
	friend bool operator==(const MyArc& left, const MyArc& right) {
		return (left.name_from == right.name_from) && (left.name_to == right.name_to);
	}
	//Деструктор
	~MyArc() {}
};