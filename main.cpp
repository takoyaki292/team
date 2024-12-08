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
	Novice::Initialize(kWindowTitle,(int)kWindowWidth, (int)kWindowHeight);
	
	int scane = 0;
	enum scane
	{
		title,
		s,
		onePhaseMapGame,
		onePhaseBattleGame,
		twoPhaseMapGame,
		twoPhaseBattleGame,
		gameOver,
		gameClaer,
	};
	Vector2 backGroundPosition = {0.f,0.f};
	int gameTitleSceneT = Novice::LoadTexture("./Resources/images/background/gameTitle.png");
	int twoGameSceneT = Novice::LoadTexture("./Resources/images/background/scene.png");
	int gameOverSceneT = Novice::LoadTexture("./Resources/images/background/gameOver.png");
	int sSceneT = Novice::LoadTexture("./Resources/images/background/s.png");
	
	// インスタンス生成
	mapChip* myMapChip = new mapChip();
	Player* myPlayer = new Player();
	Enemy* myEnemy = new Enemy();
	card* myCard=new card();
	Skill* skill_ = new Skill();
	Judge* judge = new Judge(*myPlayer, *myEnemy, *myCard);
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
		case title:
			if (keys[DIK_UP] && preKeys[DIK_UP])
			{
				myMapChip = new mapChip();
				myPlayer = new Player();
				myEnemy = new Enemy();
				myCard=new card();
				skill_ = new Skill();
				judge = new Judge(*myPlayer, *myEnemy, *myCard);
				scane = onePhaseMapGame;
			}
			
			if (keys[DIK_DOWN] && preKeys[DIK_DOWN])
			{
				scane = s;
			}
			break;
		case s:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE])
			{
				scane = title;
			}
			break;
		case onePhaseMapGame:
			// 移動処理
			myPlayer->Move();
			myMapChip->isDetection(*myPlayer,*myCard,myMapChip->stageMap);
			myEnemy->MovePattern1(*myPlayer);
			// 獲得処理(カード)
			//myCard.GetCardCount();
			if (myMapChip->bossEnemyFlag==true)
			{
				scane = onePhaseBattleGame;
				myCard->Battle();
				myMapChip->bossEnemyFlag = false;
			}
			
			break;
		case onePhaseBattleGame:
			//myPlayer->BatteUpdate();
			myCard->BattleMouseC();
			skill_->BattleUpdate(*myCard);
			judge->BattleUpdate(*myPlayer,*myEnemy,*myCard,*skill_);

			if (myEnemy->isAliveBoss == false)
			{
				scane = twoPhaseMapGame;
				
				myPlayer = new Player();
				myEnemy = new Enemy();
				myCard = new card();;
				skill_ = new Skill();
				judge = new Judge(*myPlayer, *myEnemy, *myCard);
				myMapChip = new mapChip();
				//myMapChip->ResetCardFlagsOnMapChange(myMapChip->stageTwoMap, myMapChip->mapChipSizeX, myMapChip->chipSizeY, *myCard);
			}
			if(myPlayer->isAlive==false)
			{
				scane = gameOver;
			}
			if (myEnemy->isAliveBoss == false)
			{
				scane = twoPhaseMapGame;
			}
			break;
		case twoPhaseMapGame:
			
			// 移動処理
			myPlayer->Move();
			myMapChip->isDetection(*myPlayer, *myCard,myMapChip->stageTwoMap);
			myEnemy->MovePattern1(*myPlayer);
			// 獲得処理(カード)
			//myCard.GetCardCount();
			if (myMapChip->bossEnemyFlag == true)
			{
				scane = twoPhaseBattleGame;
				myCard->Battle();
				myMapChip->bossEnemyFlag = false;
			}

			break;
		case twoPhaseBattleGame:
			//myPlayer->BatteUpdate();
			myCard->BattleMouseC();
			skill_->BattleUpdate(*myCard);
			judge->BattleUpdate(*myPlayer, *myEnemy,*myCard, *skill_);

			if (myEnemy->isAliveBoss == false)
			{
				scane = gameClaer;
			}
			if (myPlayer->isAlive == false)
			{
				scane = gameOver;
			}
			break;
		case gameOver:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE])
			{
				scane = title;
			}
			break;
		case gameClaer:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE])
			{
				scane = title;
			}
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
		case title:
			Novice::DrawSprite((int)backGroundPosition.x, (int)backGroundPosition.y, gameTitleSceneT, 1, 1, 0.0f, WHITE);
			break;
		case s:
			Novice::DrawSprite((int)backGroundPosition.x, (int)backGroundPosition.y, sSceneT, 1, 1, 0.0f, WHITE);
			break;
		case onePhaseMapGame:
			// マップチップの描画
			myMapChip->NoviceMapChip(myMapChip->mapChipSizeX, myMapChip->mapChipSizeY, myMapChip->chipSizeX, myMapChip->chipSizeY, myMapChip->stageMap,*myCard,myMapChip->oneMapBackT);

			//プレイヤーの描画
			myPlayer->Drow();

			//敵の描画
			myEnemy->Drow();
			break;
		case onePhaseBattleGame:
			Novice::DrawSprite((int)backGroundPosition.x, (int)backGroundPosition.y, twoGameSceneT, 1, 1, 0.0f, WHITE);
			myEnemy->BattleDrow();
			myCard->BattleDraw();
			myPlayer->BattleDraw();
			skill_->BattleDraw();
			break;
		case twoPhaseMapGame:
			// マップチップの描画
			myMapChip->NoviceMapChip(myMapChip->mapChipSizeX, myMapChip->mapChipSizeY, myMapChip->chipSizeX, myMapChip->chipSizeY, myMapChip->stageTwoMap, *myCard, myMapChip->oneMapBackT);

			//プレイヤーの描画
			myPlayer->Drow();

			//敵の描画
			myEnemy->Drow();
			break;
		case twoPhaseBattleGame:
			Novice::DrawSprite((int)backGroundPosition.x, (int)backGroundPosition.y, twoGameSceneT, 1, 1, 0.0f, WHITE);
			myEnemy->BattleDrow();
			myCard->BattleDraw();
			myPlayer->BattleDraw();
			skill_->BattleDraw();
			break;
		case gameOver:
			Novice::DrawSprite((int)backGroundPosition.x, (int)backGroundPosition.y, gameOverSceneT, 1, 1, 0.0f, WHITE);
			break;
		case gameClaer:
			Novice::DrawBox((int)backGroundPosition.x, (int)backGroundPosition.y, (int)kWindowWidth, (int)kWindowHeight, 0.0f, WHITE, kFillModeWireFrame);
			break;
		}
		//Novice::ScreenPrintf(0, 0, "scane=%d", scane);

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
	delete judge;
	delete skill_;
	return 0;
}
