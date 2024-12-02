#pragma once
#include "Vector3.h"
#include "Mouse.h"
class card
{
public:
	card();
	~card();
	
	void Battle();
	/// <summary>
	/// 革命のスキルの効果
	/// </summary>
	//void revolutionContent();
	/// <summary>
	/// 描画
	/// </summary>
	void BattleDraw();
	/// <summary>
	/// カードとマウスの当たり判定
	/// </summary>
	void BattleMouseC();
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

public:
	// カードにふれたかどうかの判定フラグ
	static const int FlagNunber = 7;// カードの枚数

	bool cardFlag[FlagNunber] = {};// カード
	//bool BlockFlag = {};// 白ブロック

	// スキルカードにどれだけ当たったか判定する変数
	float CardCount = 0;
	// 取れるカードの上限
	float cardMaximumCount = 3;

	// 他のcppで変数の状態を取得するための関数
	static card& GetInstance()
	{
		static card instance;
		return instance;
	}

	void GetCardCount();
};
