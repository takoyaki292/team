#include "mapChip.h"
#include <Novice.h>
#include "card.h"
#include "Player.h"

mapChip::mapChip()
{
}

void mapChip::NoviceMapChip(const int mapSizeX, const int mapSizeY, int chipSizeX_, int chipSizeY_, int stageMap_[][16], card& card_, int oneBackT)
{
	Novice::DrawSprite(0, 0, oneBackT, 1.0f, 1.0f, 0.0f, WHITE);
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

			//// ボス
			if (stageMap_[y][x] == 12)
			{
				if (bossEnemyFlag == false)
				{
					Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, myTexture.enemy, 2.0f, 2.0f, 0.0f, WHITE); // マップチップの生成
				}
			}

			// 背景ブロック
			if (stageMap_[y][x] == 11)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, myTexture.block, 1.0f, 1.0f, 0.0f, WHITE); // マップチップの生成
			}

			for (int i = 0; i < cardNumber; i++) // カードの数が7枚の場合
			{
				if (stageMap_[y][x] == 21 + i)
				{
					if (card_.cardFlag[i] == false && isCard[i] == false)
					{
						Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)myTexture.card[i], 1.0f, 1.0f, 0.0f, WHITE);
					}
					else if (isCard[i] == true)
					{
						Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)myTexture.block, 1.0f, 1.0f, 0.0f, WHITE);
					}
				}
			}
		}
	}


	// カードを詰めて表示
	int drawIndex = 0; // 詰めて描画するためのインデックス
	for (int i = 0; i < cardNumber; i++)
	{
		if (card_.cardFlag[i] == true)
		{
			Novice::DrawSprite(1500 + drawIndex * 80, 0, mapHaveCard, 1.0f, 1.0f, 0.0f, WHITE);
			drawIndex++; // 次の位置に詰めて描画する
		}
	}
}

void mapChip::isDetection(Player& player_, card& card_, int stageMap_[][16])
{
	///====================
	// プレイヤーと敵の当たり判定処理
	///====================

	if (stageMap_[player_.playerTilePosY][player_.playerTilePosX] == 12// カード1に触れたら 
		|| stageMap_[player_.playerTilePosY][player_.playerTilePosX] == 13)//
	{
		bossEnemyFlag = true;
	}

	///====================
	// プレイヤーとの当たり判定処理
	///====================

	for (int i = 0; i < cardNumber; i++) // カードの数が7枚の場合
	{
		if (stageMap_[player_.playerTilePosY][player_.playerTilePosX] == 21 + i// カード1に触れたら 
			|| card_.CardCount >= card_.cardMaximumCount)// カードを取れる上限まで行ったら
		{
			//一度しか通らなくさせるためフラグが折れる前に一度だけ実行
			if (card_.cardFlag[i] == false && card_.CardCount < card_.cardMaximumCount)
			{
				if (isCard[i] == false)
				{
					card_.GetCardCount();
					isCard[i] = true;
					card_.cardFlag[i] = true;
				}

			}
			isCard[i] = true;
		}
		if (card_.cardFlag[i] == true)
		{
			card_.Battle();
		}
	}


	// デバック
	///Novice::ScreenPrintf(0, 100, "%f\n", card::GetInstance().CardCount);
}

// マップ切り替え用の関数
void mapChip::ResetCardFlagsOnMapChange(int stageMap_[][16], int newMapSizeX, int newMapSizeY, card& card_) {
	for (int i = 0; i < cardNumber; i++) {
		bool foundCard = false;

		// 新しいマップに該当するカードが存在するか確認
		for (int y = 0; y < newMapSizeY; y++) {
			for (int x = 0; x < newMapSizeX; x++) {
				if (stageMap_[y][x] == 21 + i) {
					foundCard = true;
					break;
				}
			}
			if (foundCard) break;
		}

		// カードが新しいマップにない場合はリセット
		if (!foundCard) {
			card_.cardFlag[i] = false;
			isCard[i] = false;
		}
	}
}
