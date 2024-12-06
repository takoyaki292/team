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
	mapChip* myMapChip=new mapChip();
	Player*  myPlayer=new Player();
	Enemy*   myEnemy=new Enemy();
	card    myCard;
	Skill* skill_=new Skill();
	Judge* judge = new Judge(*myPlayer,*myEnemy,myCard);
	int scane = 0;
	enum scane
	{
		oneGame,
		twoGame
	};
	Vector2 backGroundPosition = {0.f,0.f};
	int twoGameSceneT = Novice::LoadTexture("./Resources/images/background/scene.png");
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
			myPlayer->Move();
			//myEnemy.MovePattern1(myPlayer);
			myMapChip->isDetection(*myPlayer,myCard);
			myEnemy->MovePattern1(*myPlayer);
			// 獲得処理(カード)
			//myCard.GetCardCount();
			if (myMapChip->bossEnemyFlag==true)
			{
				scane = twoGame;
				myCard.Battle();
				myMapChip->bossEnemyFlag = false;
			}
			
			break;
		case twoGame:
			myPlayer->IsAlive();
			myCard.BattleMouseC();
			skill_->BattleUpdate(myCard);
			judge->BattleUpdate(*myPlayer,*myEnemy,myCard,*skill_);
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
			myMapChip->NoviceMapChip(myMapChip->mapChipSizeX, myMapChip->mapChipSizeY, myMapChip->chipSizeX, myMapChip->chipSizeY, myMapChip->stageMap,myCard);

			//プレイヤーの描画
			myPlayer->Drow();

			//敵の描画
			myEnemy->Drow();
			break;
		case twoGame:
			Novice::DrawSprite((int)backGroundPosition.x, (int)backGroundPosition.y, twoGameSceneT, 1, 1, 0.0f, WHITE);
			myEnemy->BattleDrow();
			myCard.BattleDraw();
			myPlayer->BattleDraw();
			skill_->BattleDraw();
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
	
	delete myEnemy;
	delete myMapChip;
	delete myPlayer;
	return 0;
}
