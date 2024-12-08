#pragma once
#include "structData.h"
#include "mapChip.h"
#include "card.h"

class Player;

class Enemy
{
public:
	Enemy();

	/// <summary>
	/// プレイヤーの移動
	/// </summary>
	/// <param name="myPlayer"></param>
	void MovePattern1(Player& myPlayer);

	/// <summary>
	/// マップチップの描画
	/// </summary>
	void Drow();


	/// <summary>
	/// バトルの更新
	/// </summary>
	void BattleUpdate();
	/// <summary>
	/// バトルの描画
	/// </summary>
	void BattleDrow(int oneBossT_);


	void BattleOneBoss();
	void BattleTwoBoss();

	void Reset();
	bool isTurn = false;

	bool isCard = false;
	int max = 3;
	int attck;

	bool isR = false;
	int hp = 10;

	bool isAliveBoss = true;

	bool isOneBoss = true;
	bool isTwoBoss = false;

	int oneBossT = Novice::LoadTexture("./Resources/images/enemy/boss.png");
	int twoBossT = Novice::LoadTexture("./Resources/images/enemy/enemy01.png");
private:
	mapChip myMapChip;
	card card_;
	//フルのhp
	const int fHp = hp;
	////マップシーンの設定
	original enemy{
		{120, 120, 0}, // サイズ
		{enemy.Size.x / 2, enemy.Size.y / 2,0},      // 半径
		{90.0f, 90.0f, 0}, // ポジション
		{enemy.position.x - enemy.Radius.x, enemy.position.y - enemy.Radius.y, 0}, // 左上
		{enemy.position.x + enemy.Radius.x, enemy.position.y - enemy.Radius.y, 0}, // 右上
		{enemy.position.x - enemy.Radius.x, enemy.position.y + enemy.Radius.y, 0}, // 左下
		{enemy.position.x + enemy.Radius.x, enemy.position.y + enemy.Radius.y, 0}, // 右下
		{enemy.Size.x, enemy.Size.y, 0}, // スピード
		{Novice::LoadTexture("./Resources/images/player/enemy01.png")}
	};

	//バトルシーンの設定
	original BattlEnemy{
		{800,100, 0}, // サイズ
		{BattlEnemy.Size.x / 2, BattlEnemy.Size.y / 2, 0}, // 半径
		{90, 90}, //  ポジション
		{0 - BattlEnemy.Radius.x, 0 - BattlEnemy.Radius.y, 0}, //  左上
		{0 + BattlEnemy.Radius.x, 0 - BattlEnemy.Radius.y, 0}, //  右上
		{0 - BattlEnemy.Radius.x, 0 + BattlEnemy.Radius.y, 0}, //  左下
		{0 + BattlEnemy.Radius.x, 0 + BattlEnemy.Radius.y, 0}, //  右下
		{0, 0, 0}, // スピード
		{Novice::LoadTexture("./Resources/images/player/enemy01.png")}
	};

	int attckNum = 0;

	
	Vector2 hpPosition = { 700,100 };
	Vector2 cardPosition = { 850,400 };


};