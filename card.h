#pragma once
#include "Vector3.h"
class card
{
public:
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

	static const int numC = 7;
	bool haveCardF[numC] = {};
private:
	int haveCard[numC] = {};
	Vector3 cardPosition[numC] = {};
	int w = 50;
	int h = 100;
	int num = 0;
};

