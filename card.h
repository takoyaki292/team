#pragma once
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
	/// 革命のスキルの効果
	/// </summary>
	//void revolutionContent();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	/// カードとマウスの当たり判定
	/// </summary>
	void MouseC();
	//カードの枚数
	static const int numC =7;
	bool haveCardF[numC] = {};
	//マウスの左が押されているかのフラグ
	bool isT = false;
	
	int num[numC] = {};
	
	//威力
	int attack ;
	static constexpr int maxSize = numC;
private:
	int haveCard[numC] = {};
	Vector3 cardPosition[numC] = {};
	int w = 50;
	int h = 100;

	int mouseX;
	int mouseY;
	//マウスがカードの座標いるかのフラグ
	bool isMouse = false;

	int tW = 100;
	int tH= 150;
};
