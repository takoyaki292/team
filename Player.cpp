#include "Player.h"
#include "mapChip.h"
#include "Novice.h"

void Player::Drow()
{
	Novice::DrawQuad
	(
		(int)player.LeftTop.x + (int)player.position.x, (int)player.LeftTop.y + (int)player.position.y,
		(int)player.RightTop.x + (int)player.position.x, (int)player.RightTop.y + (int)player.position.y,
		(int)player.LeftBottom.x + (int)player.position.x, (int)player.LeftBottom.y + (int)player.position.y,
		(int)player.RightBottom.x + (int)player.position.x, (int)player.RightBottom.y + (int)player.position.y,
		0, 0,
		(int)player.Size.x, (int)player.Size.y,
		(int)player.Texture, WHITE
	);
}

void Player::Move()
{
	player.speed.x = player.Size.x; // スピードのリセット
	player.speed.y = player.Size.y; // スピードのリセット

	playerTilePosX = (int)player.position.x / (int)player.Size.x;// 現在のプレイヤーの更新
	playerTilePosY = (int)player.position.y / (int)player.Size.y;// 現在のプレイヤーの更新


	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);


	///====================
	// 移動処理
	///====================

	if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0 || preKeys[DIK_RIGHT] == 0 && keys[DIK_RIGHT] != 0)
	{
		if (player.position.x + player.Size.x < 16 * player.Size.x) //範囲外に出ないようにする処理
		{
			player.position.x += player.speed.x;
			MoveCount += 1;
			player.speed.x = 0;
		}
	}

	if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0 || preKeys[DIK_LEFT] == 0 && keys[DIK_LEFT] != 0)
	{
		if (player.position.x - player.Size.x > 0) 
		{
			player.position.x -= player.speed.x;
			player.speed.x = 0;
			MoveCount += 1;
		}
	}

	if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0 || preKeys[DIK_UP] == 0 && keys[DIK_UP] != 0)
	{
		if (player.position.y - player.Size.y > 0) 
		{
			player.position.y -= player.speed.y;
			player.speed.y = 0;
			MoveCount += 1;
		}
	}

	if (preKeys[DIK_S] == 0 && keys[DIK_S] != 0 || preKeys[DIK_DOWN] == 0 && keys[DIK_DOWN] != 0)
	{
		if (player.position.y + player.Size.y < 9 * player.Size.y) // 範囲外に出ないようにする処理
		{
			player.position.y += player.speed.y;
			player.speed.y = 0;
			MoveCount += 1;
		}
	}

	///====================
	// 当たり判定処理
	///====================

	//if (mapChip::GetInstance().stageMap[playerTilePosY][playerTilePosX] == 12)// カード1に触れたら 
	//{
	//	mapChip::GetInstance().myTexture.card1Flag = true; // カードを消す
	//}
	//
	//if (mapChip::GetInstance().stageMap[playerTilePosY][playerTilePosX] == 13) // カード2に触れたら 
	//{
	//	mapChip::GetInstance().myTexture.card2Flag = true; // カードを消す
	//}
	//
	//if (mapChip::GetInstance().stageMap[playerTilePosY][playerTilePosX] == 14) // カード3に触れたら 
	//{
	//	mapChip::GetInstance().myTexture.card3Flag = true; // カードを消す
	//}


}
