#include "mapChip.h"
//#include "Player.h"
#include "card.h"
#include <Novice.h>

void mapChip::NoviceMapChip(const int mapSizeX, const int mapSizeY, int chipSizeX_, int chipSizeY_, int stageMap_[][16])
{
	//Player myPlayer_;

	// マップチップの生成
	for (int y = 0; y < mapSizeY; y++)
	{
		for (int x = 0; x < mapSizeX; x++)
		{
			// なし
			if (stageMap_[y][x] == 10)
			{
				// 10の場合はブロックを作らない
			}

			// 背景ブロック
			if (stageMap_[y][x] == 11)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE); // マップチップの生成
			}

			// カード1
			if (stageMap_[y][x] == 21 && card::GetInstance().cardFlag[0] == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.card[0], 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 21 && card::GetInstance().cardFlag[0] == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード2
			if (stageMap_[y][x] == 22 && card::GetInstance().cardFlag[1] == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.card[1], 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 22 && card::GetInstance().cardFlag[1] == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード3
			if (stageMap_[y][x] == 23 && card::GetInstance().cardFlag[2] == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.card[2], 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 23 && card::GetInstance().cardFlag[2] == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード4
			if (stageMap_[y][x] == 24 && card::GetInstance().cardFlag[3] == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.card[3], 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 24 && card::GetInstance().cardFlag[3] == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード5
			if (stageMap_[y][x] == 25 && card::GetInstance().cardFlag[4] == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.card[4], 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 25 && card::GetInstance().cardFlag[4] == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード6
			if (stageMap_[y][x] == 26 && card::GetInstance().cardFlag[5] == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.card[5], 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 26 && card::GetInstance().cardFlag[5] == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード7
			if (stageMap_[y][x] == 27 && card::GetInstance().cardFlag[6] == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.card[6], 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 27 && card::GetInstance().cardFlag[6] == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)card::GetInstance().myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
			}
		}
	}
}

void mapChip::isDetection(Player& player_)
{

	///====================
	// プレイヤーとの当たり判定処理
	///====================

	if (stageMap[player_.playerTilePosY][player_.playerTilePosX] == 21 // カード1に触れたら 
		|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount)// カードを取れる上限まで行ったら
	{
		//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
		if (card::GetInstance().cardFlag[0] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount)
		{
			card::GetInstance().GetCardCount();
		}
		card::GetInstance().cardFlag[0] = true; // カードを消す

	}

	if (stageMap[player_.playerTilePosY][player_.playerTilePosX] == 22 // カード2に触れたら 
		|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount) // カードを取れる上限まで行ったら
	{
		//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
		if (card::GetInstance().cardFlag[1] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount)
		{
			card::GetInstance().GetCardCount();
		}
		card::GetInstance().cardFlag[1] = true; // カードを消す
	}

	if (stageMap[player_.playerTilePosY][player_.playerTilePosX] == 23 // カード3に触れたら
		|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount)  // カードを取れる上限まで行ったら
	{
		//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
		if (card::GetInstance().cardFlag[2] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount)
		{
			card::GetInstance().GetCardCount();
		}
		card::GetInstance().cardFlag[2] = true; // カードを消す
	}

	if (stageMap[player_.playerTilePosY][player_.playerTilePosX] == 24 // カード4に触れたら
		|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount) // カードを取れる上限まで行ったら
	{
		//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
		if (card::GetInstance().cardFlag[3] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount)
		{
			card::GetInstance().GetCardCount();
		}
		card::GetInstance().cardFlag[3] = true; // カードを消す
	}

	if (stageMap[player_.playerTilePosY][player_.playerTilePosX] == 25 // カード5に触れたら
		|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount)  // カードを取れる上限まで行ったら
	{
		//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
		if (card::GetInstance().cardFlag[4] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount)
		{
			card::GetInstance().GetCardCount();
		}
		card::GetInstance().cardFlag[4] = true; // カードを消す
	}

	if (stageMap[player_.playerTilePosY][player_.playerTilePosX] == 26 // カード6に触れたら
		|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount)  // カードを取れる上限まで行ったら
	{
		//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
		if (card::GetInstance().cardFlag[5] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount)
		{
			card::GetInstance().GetCardCount();
		}
		card::GetInstance().cardFlag[5] = true; // カードを消す
	}

	if (stageMap[player_.playerTilePosY][player_.playerTilePosX] == 27 // カード7に触れたら 
		|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount) // カードを取れる上限まで行ったら
	{
		//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
		if (card::GetInstance().cardFlag[6] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount)
		{
			card::GetInstance().GetCardCount();
		}
		card::GetInstance().cardFlag[6] = true; // カードを消す
	}

	// デバック
	Novice::ScreenPrintf(0, 100, "%f\n", card::GetInstance().CardCount);
}