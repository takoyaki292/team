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
void card::contentCard()
{
	//for (int i = 0; i < numC; i++)
	//{
	//	if(haveCardF[i]) {
	//		num = i + 1; 
	//		break;
	//	}
	//}
	
	
}

void card::Draw()
{

	for (int i = 0; i < numC; i++)
	{
		if (haveCardF[i] == true)
		{
			Novice::DrawBox((int)cardPosition[i].x-w/2, (int)cardPosition[i].y-h/2, w, h, 0.0f, GREEN, kFillModeSolid);
		}
		
	}
	Novice::ScreenPrintf(0, 0, "isT:%d", isT);
	
}

void card::MouseC()
{
	Novice::GetMousePosition(&mouseX, &mouseY);

	float BX1[numC];
	float BX2[numC];
	float BY1[numC];
	float BY2[numC];
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
		}
		
		
	}

	if (isMouse == true && Novice::IsTriggerMouse(0))
	{
		isT = true;
	}

	if (isT)
	{
		isMouse = false;
	}
}


