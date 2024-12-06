#pragma once
#include "Player.h"
#include "Enemy.h"
#include "card.h"
#include "Skill.h"
class Judge
{
public:
	Judge(Player& player_,Enemy& enemy_,card& card_);
	
	/// <summary>
	/// どっちのターンが終わってる関数
	/// </summary>
	/// <param name="player_"></param>
	/// <param name="enemy_"></param>
	void BattleTrun(Player& player_, Enemy& enemy_, card& card_);
	/// <summary>
	/// どっちが大きいかの関数
	/// </summary>
	/// <param name="enemy_"></param>
	void BattleIsJudge(Player& player_, Enemy& enemy, Skill& skill_);

	/// <summary>
	/// 戻す
	/// </summary>
	void BattleReset(Player& player_, Enemy& enemy_,card& card_, Skill& skill_);

	/// <summary>
	/// 更新(ラウンド)
	/// </summary>
	void BattleUpdate(Player& player_, Enemy& enemy_, card& card_, Skill& skill_);
private:
	//Skill skill_;
	bool isA = false;

	
};
