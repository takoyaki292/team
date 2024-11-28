#include <Novice.h>
#include "mapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "card.h"
#include "Skill.h"
#include "Jdge.h"

const char kWindowTitle[] = "t";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	float kWindowWidth = 1920; // ウィンドウの横幅
	float kWindowHeight = 1080; // ウィンドウの縦幅

	// ライブラリの初期化
	//Novice::Initialize(kWindowTitle, 1280, 720);
	Novice::Initialize(kWindowTitle,(int)kWindowWidth, (int)kWindowHeight);
	//Novice::SetWindowMode(kFullscreen);
	// インスタンス生成
	mapChip myMapChip;
	Player  myPlayer;
	Enemy   myEnemy;
	card    myCard;
	Skill* skill_=new Skill();
	Judge* judge = new Judge(myPlayer,myEnemy,myCard);
	int scane = 0;
	enum scane
	{
		oneGame,
		twoGame
	};
	//int num = 0;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();
		Novice::GetHitKeyStateAll(keys);


		// キー入力を受け取る
		memcpy(preKeys, keys, 256);

		///
		/// ↓更新処理ここから
		///
		switch (scane)
		{
		case oneGame:
			// 移動処理
			myPlayer.Move();
			//myEnemy.MovePattern1(myPlayer);

			// 獲得処理(カード)
			myCard.GetCard();
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE])
			{
				scane = twoGame;
			}
			
			break;
		case twoGame:

			myCard.MouseC();
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE])
			{
				myCard.isT = false;
			}
			//myCard.contentCard();
			
			judge->Update(myPlayer,myEnemy,myCard);
			//judge->isJudge(myPlayer,myEnemy,*skill_);

			skill_->Update(myCard);
			
			break;
		}
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scane)
		{
		case oneGame:
			// マップチップの描画
			//myMapChip.NoviceMapChip(myMapChip.chipSizeX, myMapChip.chipSizeY, myMapChip.chipSizeX, myMapChip.chipSizeY, myMapChip.stageMap);

			//プレイヤーの描画
			myPlayer.Drow();

			//敵の描画
			myEnemy.Drow();
			
			break;
		case twoGame:
			myEnemy.BattleDraw();
			myCard.Draw();
			myPlayer.Drow();
			Novice::ScreenPrintf(0, 330, "player.hp:%d", myPlayer.hp);
			Novice::ScreenPrintf(0, 350, "enemy.hp:%d", myEnemy.hp);

			skill_->Draw();
			
			Novice::ScreenPrintf(0, 700, "Enemy attck:%d", myEnemy.attck);
			Novice::ScreenPrintf(0, 730, "Player attck:%d", myPlayer.attck);
			break;
		}
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
		{
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();

	delete judge;
	delete skill_;
	return 0;
}
