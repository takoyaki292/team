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
	}

	// カード2
	if (mapChip::GetInstance().myTexture.card2Flag == true)
	{
		// 仮としてスピードを足している
		Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
	}

	// カード3
	if (mapChip::GetInstance().myTexture.card3Flag == true)
	{
		// 仮としてスピードを足している
		Player::GetInstance().player.position.x += Player::GetInstance().player.speed.x;
	}

}

