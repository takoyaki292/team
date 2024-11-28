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
	/// ラウンドの関数
	/// </summary>
	/// <param name="player_"></param>
	/// <param name="enemy_"></param>
	//void r(Player& player_,Enemy& enemy_);
	/// <summary>
	/// どっちのターンが終わってる関数
	/// </summary>
	/// <param name="player_"></param>
	/// <param name="enemy_"></param>
	void Trun(Player& player_, Enemy& enemy_, card& card_);
	/// <summary>
	/// どっちが大きいかの関数
	/// </summary>
	/// <param name="enemy_"></param>
	void isJudge(Player& player_, Enemy& enemy);

	/// <summary>
	/// 戻す
	/// </summary>
	void m(Player& player_, Enemy& enemy_,card& card_);

	/// <summary>
	/// 更新
	/// </summary>
	void Update(Player& player_, Enemy& enemy_, card& card_);
private:
	//Player& player_;
	//Enemy& enemy_;
	//card& card_;
	Skill skill_;
	bool isA = false;
};