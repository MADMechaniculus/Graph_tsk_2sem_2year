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
	//Конструктор
	MyVertex(string nm, float x, float y) {
		setName(nm);
		deque<MyArc> arc_deq(20);
		setCoord(x, y);
	}
	//Конструктор по умолчанию
	MyVertex() {
		name = "#<Name_of_vertex>";
		deque<MyArc> arc_deq(20);
	}
	//Добавить связь в список связей
	void pushNewArc(MyArc newArc) {
		arc_deq.push_back(newArc);
	}
	//Запросить имя
	string getName() {
		return name;
	}
	//Проверка наличия дуг в очереди
	bool check() {
		if (arc_deq.empty() == true) {
			return false;	//Выдать информацию о том, что вершина изолирована
		}
		else {
			return true;	//Продолжить рядовое выполнение алгоритмов
		}
	}
	//Ввод координат вершины при размещении её на поле
	void setCoord(float x, float y) {
		X = x;
		Y = y;
	}
	//Задать имя вершины
	void setName(string nm) {
		name = nm;
	}
	//Переопределение бинарного оператора == для myVertex
	friend bool operator==(const MyVertex& left, const MyVertex& right) {
		return left.name == right.name;
	}
	//Деструктор
	~MyVertex() {}
};