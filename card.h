﻿#pragma once
#include "Vector3.h"
#include "Mouse.h"
class card
{
public:

	card();
	~card();
	// カードを手に入れた時の関数
	void GetCard();
	/// <summary>
	/// カードの効果
	/// </summary>
	void contentCard();


	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void MouseC();
	static const int numC =7;
	bool haveCardF[numC] = {};
private:
	int haveCard[numC] = {};
	Vector3 cardPosition[numC] = {};
	int w = 50;
	int h = 100;
	int num = -1;

	int mouseX;
	int mouseY;
	bool isMouse = false;
	bool isT = false;
};
