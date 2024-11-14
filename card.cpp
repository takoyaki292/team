#include "card.h"
#include "mapChip.h"
#include "Player.h"

void card::GetCard()
{
	// カード1
	if (mapChip::GetInstance().myTexture.card1Flag == true)
	{
		// 仮としてスピードを足している
		Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
		haveCardF[0] = true;
		
	}

	// カード2
	if (mapChip::GetInstance().myTexture.card2Flag == true)
	{
		// 仮としてスピードを足している
		Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
		haveCardF[1] = true;
		
	}

	// カード3
	if (mapChip::GetInstance().myTexture.card3Flag == true)
	{
		// 仮としてスピードを足している
		Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
		haveCardF[2] = true;
	}
	for (int i = 0; i < numC; i++)
	{
		if (haveCardF[i] == true)
		{
			cardPosition[i] = Vector3(600.f+i*70.f, 800.f, 0);
		}
	}
}
void card::contentCard()
{
	for (int i = 0; i < numC; i++)
	{
		if (haveCardF[i] == true)
		{
			num = i;
			break;
		}
	}
}

void card::Draw()
{
	
	for (int i = 0; i < numC; i++)
	{
		if (haveCardF[i] == true)
		{	
			Novice::DrawBox((int)cardPosition[i].x, (int)cardPosition[i].y, w, h, 0.0f, WHITE, kFillModeSolid);
		}
	}
}



