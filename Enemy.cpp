﻿#include "Enemy.h"
#include "Player.h"
#include <time.h>

void Enemy::Drow() const
{
	Novice::DrawQuad(
		(int)enemy.LeftTop.x + (int)enemy.position.x, (int)enemy.LeftTop.y + (int)enemy.position.y,
		(int)enemy.RightTop.x + (int)enemy.position.x, (int)enemy.RightTop.y + (int)enemy.position.y,
		(int)enemy.LeftBottom.x + (int)enemy.position.x, (int)enemy.LeftBottom.y + (int)enemy.position.y,
		(int)enemy.RightBottom.x + (int)enemy.position.x, (int)enemy.RightBottom.y + (int)enemy.position.y,
		0, 0, (int)enemy.Size.x, (int)enemy.Size.y,
		(int)enemy.Texture, WHITE);
}

void Enemy::MovePattern1(Player& myPlayer)
{
	srand((unsigned int)time(NULL)); // 乱数の種を初期化
	//enemy.speed.x = enemy.Size.x; // スピードの初期化
	//enemy.speed.y = enemy.Size.y; // スピードの初期化

	if (myPlayer.MoveCount % 5 == 0 && enemy.speed.x != 0)//三の倍数の時に行動
	{
		int randomPattern = rand() % 4 + 1;  // 1から4のランダムなパターンを生成

		// 1～4の行動をランダムで起こす
		if (randomPattern == 1)
		{
			if (enemy.position.x + enemy.Size.x < 29 * enemy.Size.x) //範囲外に出ないようにする処理
			{
				enemy.position.x += enemy.speed.x;
				//enemy.speed.x = 0;
				myPlayer.MoveCount += 1;
			}
		}
		else if (randomPattern == 2)
		{
			if (enemy.position.x - enemy.Size.x > 0) // 範囲外に出ないようにする処理
			{
				enemy.position.x -= enemy.speed.x;
				//enemy.speed.x = 0;
				myPlayer.MoveCount += 1;
			}
		}
		else if (randomPattern == 3)
		{
			if (enemy.position.y + enemy.Size.y < 15* enemy.Size.y) // 範囲外に出ないようにする処理
			{
				enemy.position.y += enemy.speed.y;
				//enemy.speed.y = 0;
				myPlayer.MoveCount += 1;
			}
		}
		else if (randomPattern == 4)
		{
			if (enemy.position.y + enemy.Size.y > 0) // 範囲外に出ないようにする処理
			{
				enemy.position.y -= enemy.speed.y;
				//enemy.speed.y = 0;
				myPlayer.MoveCount += 1;
			}
		}
	}

}
