#include "card.h"
#include "mapChip.h"
#include "Player.h"
#include "Mouse.h"
card::card()
{
	for (int i = 0; i < numC; i++)
	{
		cardFlag[i] = false;
		if (haveCardF[i] == true)
		{
			cardPosition[i] = Vector3(600.f + i * 70.f, 800.f, 0);
		}
		if (cardFlag[i]) {
			num[i] = i + 1;
		}
	}
	CardCount = 0;
	cardMaximumCount = 3;
	CardUpNumber = 1;
}

card::~card()
{
}


void card::Battle()
{
	int validCardCount = 0; // 有効なカードの数を追跡
	for (int i = 0; i < numC; i++)
	{
		if (cardFlag[i] == true)
		{
			haveCardF[i] = true;
			num[i] = i + 1; 
			attckA[i] = num[i];
			cardPosition[i] = Vector3(600.f + validCardCount * 70.f, 800.f, 0); 
			validCardCount++; // 有効なカード数を増やす
		}
		else
		{
			haveCardF[i] = false;
		}
	}
}

void card::BattleDraw()
{

	for (int i = 0; i < maxSize; i++)
	{
		// attckA[i] に応じてカード画像を変更
		int cardIndex = attckA[i] - 1;  // attckAは1から7の範囲と仮定
		if (cardIndex >= 0 && cardIndex < 8)
		{
			Novice::DrawSprite((int)cardPosition[i].x - w / 2, (int)cardPosition[i].y - h / 2, cardT[cardIndex], 0.4f, 0.4f, 0.0f, WHITE);
		}
	}
}

void card::BattleMouseC()
{
	Novice::GetMousePosition(&mouseX, &mouseY);

	float BX1[numC]={};
	float BX2[numC]={};
	float BY1[numC]={};
	float BY2[numC]={};
	int halfW = w / 2; // 幅を半分にする
	int halfH = h / 2; // 高さを半分にする
	for (int i = 0; i < card::numC; i++)
	{
		BX1[i] = cardPosition[i].x - halfW;
		BX2[i] = cardPosition[i].x + halfW;
		BY1[i] = cardPosition[i].y - halfH;
		BY2[i] = cardPosition[i].y + halfH;
		if (mouseX > BX1[i] && mouseX < BX2[i] && mouseY > BY1[i] && mouseY < BY2[i])
		{
			isMouse = true;
			//押した
			if (Novice::IsTriggerMouse(0))
			{
				isT = true;
				haveCardF[i] = false;
				attack = attckA[i];
				attckA[i] = 0;
			}
		}
		else
		{
			isMouse = false;
		}
		//他と同じようにならないように処理を書いてる
		if (isT)
		{
			isMouse = false;		
		}
	}
}


void card::GetCardCount()
{
	CardCount = CardCount + CardUpNumber;
	if (CardUpNumber > 0) {
		CardUpNumber--;  // CardUpNumber をゼロ以下にしない
	}
}


void card::GetCardNumDraw()
{
	if (CardCount >= 2)
	{
		Novice::DrawBox(1000, 0, w, h, 0.0f, WHITE, kFillModeSolid);

	}
}
