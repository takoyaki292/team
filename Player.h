#pragma once
#include "Vector3.h"
#include <Novice.h>
#include "structData.h"
#include "mapChip.h"
#include "card.h"
#include "Vector2.h"

class Enemy;
class card;
class Player
{
public:
	Player();

	void BattleDraw();
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	void IsAlive();

	int hp = 10;
	bool isAlive = true;
	bool isTurn = false;
	int attck = 0;

	bool isCard = false;

	void BatteUpdate();
private:
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
		{Novice::LoadTexture("./Resources/images/player/player01.png")} // テクスチャ
	};


	original battePlayer
	{
		{120,120,0},                                   // サイズ
		{player.Size.x / 2, player.Size.y / 2,0},      // 半径
		{1500, 800, 0}, // ポジション
		{player.position.x - player.Radius.x, player.position.y - player.Radius.y, 0}, // 左上
		{player.position.x + player.Radius.x, player.position.y - player.Radius.y, 0}, // 右上
		{player.position.x - player.Radius.x, player.position.y + player.Radius.y, 0}, // 左下
		{player.position.x + player.Radius.x, player.position.y + player.Radius.y, 0}, // 右下
		{player.Size.x, player.Size.y, 0},             // スピード
		{Novice::LoadTexture("./Resources/images/player/player01.png")} // テクスチャ
	};
	Vector2 hpPosition = { 700,1000 };
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


	card* card_;

};