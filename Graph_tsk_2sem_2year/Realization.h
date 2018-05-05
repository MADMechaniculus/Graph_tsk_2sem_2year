#pragma once
#include "View.h"
#include "Arc.h"
#include "Graph.h"
#include "vertex.h"
#include "SFML\Graphics.hpp"
#include <list>
#include <iostream>
#include <iterator>
#include <string>
//�������� ����� � ������ ������
void createNewGraph(string name, list<Graph> myList) {
	Graph newGraph(name);
	myList.push_back(newGraph);
}
//�������� ����� �� ������ ������
void deleteGraph(string name, list<Graph> myList) {
	Graph tempG;
	string tempN;
	bool flag = false;
	list<Graph>::iterator grphIt = myList.begin();
	while (grphIt != myList.end()) {
		tempG = *grphIt;
		tempN = tempG.getName();
		if (tempN == name) {
			flag = true;
			break;
		}
		*grphIt++;
	}
	if (flag)
		myList.remove(tempG);
}
//�������� �������
void createVertex(Graph selectedGraph, string vertexName, float X, float Y) {
	selectedGraph.createVertex(vertexName, X, Y);
}
//�������� �������
bool deleteVertex(Graph selectedGraph, MyVertex selectedVertex) {
	return selectedGraph.deleteVertex(selectedVertex);
}
//�������� ����� �����
bool createArc(string name,MyVertex selectedVertexFirst, MyVertex selectedVertexSecond, int direction, float weight) {
	//direction - (0, <->), (1, ->), (2, <-);
	MyArc tempArc(name, selectedVertexFirst.getName(), selectedVertexSecond.getName(), weight, direction);
	selectedVertexFirst.pushNewArc(tempArc);
	selectedVertexSecond.pushNewArc(tempArc);
}
//�������� �����
//bool deleteArc()