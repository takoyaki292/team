#include "card.h"
#include "mapChip.h"
#include "Player.h"
#include "Mouse.h"
card::card()
{
	for (int i = 0; i < numC; i++)
	{
		
		haveCardF[i] = true;
	}
	for (int i = 0; i < numC; i++)
	{
		if (haveCardF[i] == true)
		{
			cardPosition[i] = Vector3(600.f + i * 70.f, 800.f, 0);
		}
		if (haveCardF[i]) {
			num[i] = i + 1;
		}
	}
}

card::~card()
{
}
void card::GetCard()
{
	// カード1
	//if (mapChip::GetInstance().myTexture.card1Flag == true)
	//{
	//	// 仮としてスピードを足している
	//	Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
	//	haveCardF[0] = true;
	//
	//}
	//
	//// カード2
	//if (mapChip::GetInstance().myTexture.card2Flag == true)
	//{
	//	// 仮としてスピードを足している
	//	Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
	//	haveCardF[1] = true;
	//
	//}
	//
	//// カード3
	//if (mapChip::GetInstance().myTexture.card3Flag == true)
	//{
	//	// 仮としてスピードを足している
	//	Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
	//	haveCardF[2] = true;
	//}
	//for (int i = 0; i < numC; i++)
	//{
	//	if (haveCardF[i] == true)
	//	{
	//		cardPosition[i] = Vector3(600.f + i * 70.f, 800.f, 0);
	//	}
	//}
}



//void card::revolutionContent()
//{
//	for (int i = 6; i >0; i--)
//	{
//		if (haveCardF[i]) {
//			num[i] = i + 1;
//		}
//	}
//}


void card::Draw()
{
	if (haveCardF[0] == true)
	{
		Novice::DrawBox((int)cardPosition[0].x - w / 2, (int)cardPosition[0].y - h / 2, w, h, 0.0f, RED, kFillModeSolid);
	}
	if (haveCardF[1] == true)
	{
		Novice::DrawBox((int)cardPosition[1].x - w / 2, (int)cardPosition[1].y - h / 2, w, h, 0.0f, BLACK, kFillModeSolid);
	}
	if (haveCardF[2] == true)
	{
		Novice::DrawBox((int)cardPosition[2].x - w / 2, (int)cardPosition[2].y - h / 2, w, h, 0.0f, RED, kFillModeSolid);
	}
	if (haveCardF[3] == true)
	{
		Novice::DrawBox((int)cardPosition[3].x - w / 2, (int)cardPosition[3].y - h / 2, w, h, 0.0f, BLACK, kFillModeSolid);
	}
	if (haveCardF[4] == true)
	{
		Novice::DrawBox((int)cardPosition[4].x - w / 2, (int)cardPosition[4].y - h / 2, w, h, 0.0f, RED, kFillModeSolid);
	}
	if (haveCardF[5] == true)
	{
		Novice::DrawBox((int)cardPosition[5].x - w / 2, (int)cardPosition[5].y - h / 2, w, h, 0.0f, BLACK, kFillModeSolid);
	}
	if (haveCardF[6] == true)
	{
		Novice::DrawBox((int)cardPosition[6].x - w / 2, (int)cardPosition[6].y - h / 2, w, h, 0.0f, RED, kFillModeSolid);
	}

	
}

void card::MouseC()
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
				attack = num[i];
				num[i] = 0;
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
	// 増やす数字
	int CardUpNumber = 1;
	CardCount = CardCount + CardUpNumber;
	CardUpNumber--;
}