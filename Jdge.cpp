#include "Jdge.h"
Judge::Judge(Player& player_, Enemy& enemy_, card& card_)
{
	
	player_.isTurn = false;
	enemy_.isTurn = false;
	player_.attck = 0;
	enemy_.attck = 0;
	card_.isT = false;
	
}

void Judge::BattleTrun(Player& player_,Enemy& enemy_,card& card_)
{
	if (card_.isT == true)
	{
		player_.attck = card_.attack;
		player_.isTurn = true;
	}
	if (enemy_.isTurn == true)
	{
		enemy_.BattleUpdate();
		//enemy_.isTurn = true;
	}
	if (player_.isTurn==false&& enemy_.isTurn == false)
	{
		enemy_.isTurn = true;
		enemy_.isR = true;
	}
	
}

void Judge::BattleIsJudge(Player& player_,Enemy& enemy_)
{
	if (player_.attck != 0 && enemy_.attck != 0)
	{
		//スキルを使わない場合
		if (skill_.isRevolution == false)
		{
			if (player_.attck > enemy_.attck)
			{
				enemy_.hp -= player_.attck;
			}
			else if (enemy_.attck > player_.attck)
			{
				player_.hp -= enemy_.attck;
			}
		}
		//スキルを使った場合
		else if (skill_.isRevolution == true)
		{
			if (player_.attck > enemy_.attck)
			{
				player_.hp -= enemy_.attck;
				//m(player_, enemy_);
			}
			else if (enemy_.attck > player_.attck)
			{
				enemy_.hp -= player_.attck;
			}
		}
	}
}

void Judge::BattleReset(Player& player_,Enemy& enemy_,card& card_)
{
  	player_.isTurn = false;
	enemy_.isTurn = false;
	player_.attck = 0;
	enemy_.attck = 0;
	card_.isT = false;

	//enemy_.isCard = false;
	//player_.isCard = false;
}

void Judge::BattleUpdate(Player& player_,Enemy& enemy_,card& card_)
{
	if (player_.isTurn == true && enemy_.isTurn == true)
	{
		enemy_.isCard = true;
		player_.isCard = true;
		BattleIsJudge(player_,enemy_);
		BattleReset(player_,enemy_,card_);
	}
	else
	{
		BattleTrun(player_, enemy_, card_);
		enemy_.isCard =false;
		player_.isCard = false;
	}
}
