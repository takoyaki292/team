#pragma once
#pragma once
#include "Player.h"
#include "structData.h"
#include "mapChip.h"
#include "card.h"

class Enemy
{
public:

	mapChip myMapChip;
	card card_;
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
	void BattleDraw() const;
	void BattleUpdate(card& playerCard);
	int hp = 20;

private:
	//フルのhp
	const int fHp = hp;
};