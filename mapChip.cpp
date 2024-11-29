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

			for (int i = 0; i < maxCard; i++) { // カードの数が7枚の場合
				if (stageMap_[y][x] == countCard + i) {
					if (card::GetInstance().haveCardF[i] == false) {
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

	for (int i = 0; i < maxCard; i++) { 
		if (stageMap[player_.playerTilePosY][player_.playerTilePosX] ==countCard + i
			|| card::GetInstance().CardCount >= card::GetInstance().cardMaximumCount) {

			// 一度しか通らないように、フラグがfalseでカード上限未満の場合のみ実行
			if (card::GetInstance().haveCardF[i] == false && card::GetInstance().CardCount < card::GetInstance().cardMaximumCount) {
				card::GetInstance().GetCardCount();
				card::GetInstance().cF[i] = true;
				card::GetInstance().haveCardF[i] = true;
			}
			//最大枚数になったら、強制的にtrueにしている
			else if(card::GetInstance().CardCount == card::GetInstance().cardMaximumCount)
			{
				card::GetInstance().haveCardF[i] = true; 
			}
			
		}
	}
}