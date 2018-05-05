#pragma once
#include "SFML\Graphics.hpp"
#include "Graph.h"
#include <string>

using namespace sf;

class point {
private:
	float X, Y;
	bool isSelected, isDrawed;
	Sprite sprt;
public:
	//����������� ������ point - ����������� ������������� Vertex
	point(float x, float y, Graph nameOfGraph, string nameOfVert) {
		X = x;
		Y = y;
		isSelected = true;
		nameOfGraph.createVertex(nameOfVert, x, y);

		Image img;
		img.loadFromFile("primitives/point_prm.png");
		Texture txt;
		txt.loadFromImage(img);
		sprt;
		sprt.setTexture(txt);
		sprt.setTextureRect(IntRect(0, 0, 32, 32));
		sprt.setPosition(X, Y);
	}
	//������� ��� ��������� ��������� ������
	void selection() {
		isSelected = !isSelected;
	}
	//���������� ��������� �������
	void update(float time) {
		if (isSelected) {
			sprt.setTextureRect(IntRect(32, 0, 32, 32));
		}
		else {
			sprt.setTextureRect(IntRect(0, 0, 32, 32));
		}
		sprt.setPosition(X, Y);
	}
	//������ ������� �������
	void setPos(float x, float y) {
		X = x;
		Y = y;
	}

};