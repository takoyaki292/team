#include "mapChip.h"
#include <Novice.h>
#include "card.h"
#include "Player.h"
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
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, myTexture.block, 1.0f, 1.0f, 0.0f, WHITE); // マップチップの生成
			}

			for (int i = 0; i < 7; i++) { // カードの数が7枚の場合
				if (stageMap_[y][x] == 21 + i) {
					if (card::GetInstance().cardFlag[i] == false) {
						Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)myTexture.card[i], 1.0f, 1.0f, 0.0f, WHITE);
					}
					else {
						Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
					}
				}
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