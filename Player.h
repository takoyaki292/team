#pragma once
#include "Vector3.h"
#include <Novice.h>
#include "structData.h"
#include "mapChip.h"
#include "card.h"
//#include "Enemy.h"

class Enemy;
class Player
{
public:

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	
	/// <summary>
	/// Enemyに攻撃出来るようにした
	/// </summary>
	/// <param name="playerCard"></param>
	/// <param name="enemy"></param>
	//void BattleUpdate(card& playerCard, Enemy& enemy);

	void IsAlive();

	
	int hp = 10;
	bool isAlive = false;
	bool isTurn = false;
	int attck = 0;
private:
	//mapChip myMapChip;
	original player
	{
		{120,120,0},                                   // サイズ
		{player.Size.x / 2, player.Size.y / 2,0},      // 半径
		{90, 90, 0}, // ポジション
		{player.position.x - player.Radius.x, player.position.y - player.Radius.y, 0}, // 左上
		{player.position.x + player.Radius.x, player.position.y - player.Radius.y, 0}, // 右上
		{player.position.x - player.Radius.x, player.position.y + player.Radius.y, 0}, // 左下
		{player.position.x + player.Radius.x, player.position.y + player.Radius.y, 0}, // 右下
		{player.Size.x, player.Size.y, 0},             // スピード
		{Novice::LoadTexture("./Resources/images/player/ghost.png")} // テクスチャ
	};


public:
	int MoveCount = 0; //移動するたびにカウントしていく変数

	void Drow() const;
	void Move();

	

	int playerTilePosX = 0; //現在のプレイヤーのX座標
	int playerTilePosY = 0; //現在のプレイヤーのY座標

	// イージング
	float startPlayerPosX = player.position.x;
	float startPlayerPosY = player.position.y;
	float endPlayerPosX = player.position.x + player.speed.x;
	float endPlayerPosY = player.position.y + player.speed.y;

	bool easingFlag = false;
	float frameX = 0.0f;
	float endFrameX = 100.0f;

	
	//void isC();
	// 他のcppで変数の状態を取得するための関数
	static Player& GetInstance()
	{
		static Player instance;
		return instance;
	}
};
