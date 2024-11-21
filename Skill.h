#pragma once
#include "structData.h"
#include <Novice.h>
class Player;
class Skill
{
public:
	

	void Draw();

	void Update();

	void Effect();
private:
	original skill_
	{
		{100,100,0},// サイズ
		{skill_.Size.x, skill_.Size.y,0},      // 半径
		{1800, 300, 0}, // ポジション
		{skill_.position.x -skill_.Radius.x,  skill_.position.y - skill_.Radius.y, 0}, // 左上
		{skill_.position.x + skill_.Radius.x, skill_.position.y - skill_.Radius.y, 0}, // 右上
		{skill_.position.x - skill_.Radius.x, skill_.position.y + skill_.Radius.y, 0}, // 左下
		{skill_.position.x + skill_.Radius.x, skill_.position.y + skill_.Radius.y, 0}, // 右下
		{skill_.Size.x, skill_.Size.y, 0},             // スピード
		{}//Novice::LoadTexture("./Resources/images/player/ghost.png")} // テクスチャ
	};

	int mouseX;
	int mouseY;
	bool isM = false;
	bool isTrigger = false;

};