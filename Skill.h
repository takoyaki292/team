#pragma once
#include "structData.h"
#include <Novice.h>
#include "AABB.h"
#include "card.h"

class Player;
class Skill
{
public:
	
	Skill();
	/// <summary>
	/// 描画
	/// </summary>
	void BattleDraw();
	/// <summary>
	/// 更新
	/// </summary>
	void BattleUpdate(card& cardInstance);

	/// <summary>
	/// カードの効果
	/// </summary>
	void BattleEffect(card& cardInstance);

	/// <summary>
	/// マウスとの当たり判定
	/// </summary>
	void BattleMouse();

	/// <summary>
	/// 革命のスキル
	/// </summary>
	/// <param name="cardInstance"></param>
	void BattleRevolution();
	/// <summary>
	/// 二倍になるスキル
	/// </summary>
	void BattleTwice(card& cardInstance);
	/// <summary>
	/// ランダムになるスキル
	/// </summary>
	void BattleRandomNum(card& cardInstance);

	bool isRevolution = false;
private:
	//スキルボタンを表示するため
	original skillBotan_
	{
		{100,100,0},// サイズ
		{skillBotan_.Size.x, skillBotan_.Size.y,0},      // 半径
		{1800, 300, 0}, // ポジション
		{skillBotan_.position.x -skillBotan_.Radius.x,  skillBotan_.position.y - skillBotan_.Radius.y, 0}, // 左上
		{skillBotan_.position.x + skillBotan_.Radius.x, skillBotan_.position.y - skillBotan_.Radius.y, 0}, // 右上
		{skillBotan_.position.x - skillBotan_.Radius.x, skillBotan_.position.y + skillBotan_.Radius.y, 0}, // 左下
		{skillBotan_.position.x + skillBotan_.Radius.x, skillBotan_.position.y + skillBotan_.Radius.y, 0}, // 右下
		{skillBotan_.Size.x, skillBotan_.Size.y, 0},             // スピード
		{}//Novice::LoadTexture("./Resources/images/player/ghost.png")} // テクスチャ
	};

	int mouseX;
	int mouseY;

	static const int skillNum = 3;
	bool isM = false;
	bool isTrigger = false;

	Vector2 skillPosition[skillNum] = {};
	Vector2 r[skillNum] = {};
	bool skillF[skillNum] = {false,false,false};
	bool skillH[skillNum];

	float BX1[skillNum] = {};
	float BX2[skillNum] = {};
	float BY1[skillNum] = {};
	float BY2[skillNum] = {};

	
	
};