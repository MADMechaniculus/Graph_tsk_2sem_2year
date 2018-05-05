#pragma once
//Ёто было не просто, но результат того стоил...
#include "SFML\Graphics.hpp"
#include "Arc.h"
#include "Graph.h"
#include "vertex.h"
#include "Realization.h"
#include <iostream>
#include <string>
#include <Windows.h>

#include "IMGUI\imgui.h"
#include "IMGUI\imgui-sfml.h"

#include "glut.h"				//Ёто дл€ OpenGL

#include "SFML\Graphics\RenderWindow.hpp"

#include <SFML\System\Clock.hpp>
#include <SFML\Window\Event.hpp>
//¬се выше-перечисленные подключени€ нужны!!

bool testBool = false;
float testFloat = 0.f;
int testInt = 0;
const char* items[] = { "first", "second", "third" };
int testInt1 = 0;
int testInt2 = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);

	sf::Color bgColor;
	float color[3] = { 0.f, 0.f, 0.f };

	// здесь мы будем использовать массив char. „тобы использовать
	// std::string нужно сделать действи€, описанные во второй части
	char windowTitle[255] = "ImGui + SFML = <3";
	window.setTitle(windowTitle);

	sf::Clock deltaClock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Sample window"); // создаЄм окно
		ImGui::Checkbox("testCheck", &testBool);
		ImGui::SliderFloat("testSlider", &testFloat, 0.f, 100.f);
		ImGui::SliderInt("intSlider", &testInt, 0, 100);
		if (ImGui::Button("MyButton", ImVec2(75, 25))) {
			Beep(500, 500);
		}
		ImGui::Combo("comboTest", &testInt1, items, 3);
		ImGui::RadioButton("radio0", &testInt2, 0);
		ImGui::SameLine();
		ImGui::RadioButton("radio1", &testInt2, 1);
		ImGui::SameLine();
		ImGui::RadioButton("radio2", &testInt2, 2);

		ImGui::BeginChild(1, ImVec2(200,200), true);
		ImGui::Text("This is the test window :)");
		ImGui::EndChild();

		if (ImGui::TreeNode("stuff")) {
			ImGui::Text("TreeNode");
			ImGui::TreePop();
		}

		ImGui::End(); // end window

		window.clear(bgColor); // заполн€ем окно заданным цветом
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
}