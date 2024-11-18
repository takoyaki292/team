#include "mapChip.h"
#include <Novice.h>

void mapChip::NoviceMapChip(const int mapSizeX, const int mapSizeY, int chipSizeX_, int chipSizeY_, int stageMap_[][16/*mapChipSizeY*/])
{
	// マップチップの生成
	for (int y = 0; y < mapSizeX; y++)
	{
		for (int x = 0; x < mapSizeY; x++)
		{
			// なし
			if (stageMap_[y][x] == 10)
			{
				// 10の場合はブロックを作らない
			}

			// 背景ブロック
			if (stageMap_[y][x] == 11)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)mapChip::GetInstance().myTexture.Block, 1.0f, 1.0f, 0.0f, WHITE); // マップチップの生成
			}

			// カード1
			if (stageMap_[y][x] == 12 && mapChip::GetInstance().myTexture.card1Flag == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)mapChip::GetInstance().myTexture.card1, 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 12 && mapChip::GetInstance().myTexture.card1Flag == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)mapChip::GetInstance().myTexture.Block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード2
			if (stageMap_[y][x] == 13 && mapChip::GetInstance().myTexture.card2Flag == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)mapChip::GetInstance().myTexture.card2, 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 13 && mapChip::GetInstance().myTexture.card2Flag == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)mapChip::GetInstance().myTexture.Block, 1.0f, 1.0f, 0.0f, WHITE);
			}

			// カード3
			if (stageMap_[y][x] == 14 && mapChip::GetInstance().myTexture.card3Flag == false)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)mapChip::GetInstance().myTexture.card3, 1.0f, 1.0f, 0.0f, WHITE);
			}
			//取られた際
			if (stageMap_[y][x] == 14 && mapChip::GetInstance().myTexture.card3Flag == true)
			{
				Novice::DrawSprite(x * chipSizeX_, y * chipSizeY_, (int)mapChip::GetInstance().myTexture.Block, 1.0f, 1.0f, 0.0f, WHITE);
			}
		}
	}
}