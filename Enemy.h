#pragma once
#include "structData.h"
#include "mapChip.h"
#include "card.h"

class Player;

class Enemy
{
public:
	original enemy{
		{(float)myMapChip.chipSizeX,(float)myMapChip.chipSizeY, 0}, // サイズ
		{enemy.Size.x / 2, enemy.Size.y / 2, 0}, // 半径
		{0 + enemy.Radius.x, 0 + enemy.Radius.y, 0}, //  ポジション
		{0 - enemy.Radius.x, 0 - enemy.Radius.y, 0}, //  左上
		{0 + enemy.Radius.x, 0 - enemy.Radius.y, 0}, //  右上
		{0 - enemy.Radius.x, 0 + enemy.Radius.y, 0}, //  左下
		{0 + enemy.Radius.x, 0 + enemy.Radius.y, 0}, //  右下
		{enemy.Size.x, enemy.Size.y, 0}, // スピード
		{Novice::LoadTexture("./Resources/images/player/enemy01.png")}
	};
	original BattlEnemy{
		{800,100, 0}, // サイズ
		{BattlEnemy.Size.x / 2, BattlEnemy.Size.y / 2, 0}, // 半径
		{1360, 0}, //  ポジション
		{0 - BattlEnemy.Radius.x, 0 - BattlEnemy.Radius.y, 0}, //  左上
		{0 + BattlEnemy.Radius.x, 0 - BattlEnemy.Radius.y, 0}, //  右上
		{0 - BattlEnemy.Radius.x, 0 + BattlEnemy.Radius.y, 0}, //  左下
		{0 + BattlEnemy.Radius.x, 0 + BattlEnemy.Radius.y, 0}, //  右下
		{0, 0, 0}, // スピード
		{Novice::LoadTexture("./Resources/images/player/enemy01.png")}
	};

	void Drow() const;
	//void MovePattern1(Player& myPlayer);
	
	/// <summary>
	/// 戦闘フェーズの描画
	/// </summary>
	void BattleDraw() const;
	/// <summary>
	/// playerに攻撃できる関数
	/// </summary>
	/// <param name="player"></param>
	void BattleUpdate(Player& player);
	int hp = 20;

	bool isTurn= false;
private:
	mapChip myMapChip;
	card card_;
	//フルのhp
	const int fHp = hp;
	//敵の攻撃力(仮)
	int attck = 5;
};