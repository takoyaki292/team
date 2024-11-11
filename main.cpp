#include <Novice.h>
#include "mapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "card.h"

const char kWindowTitle[] = "t";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//float kWindowWidth = 1920; // ウィンドウの横幅
	//float kWindowHeight = 1080; // ウィンドウの縦幅

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1920, 1080);

	// インスタンス生成
	mapChip myMapChip;
	Player  myPlayer;
	Enemy   myEnemy;
	card    myCard;

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

		// 移動処理
		myPlayer.Move();
		myEnemy.MovePattern1(myPlayer);

		// 獲得処理(カード)
		myCard.GetCard();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// マップチップの描画
		myMapChip.NoviceMapChip(myMapChip.mapChipSizeX, myMapChip.mapChipSizeY, myMapChip.chipSizeX, myMapChip.chipSizeY, myMapChip.stageMap);

		//プレイヤーの描画
		myPlayer.Drow();

		//敵の描画
		myEnemy.Drow();


		// デバックの描画
		//Novice::ScreenPrintf(0, 100, "%f\n", myEnemy.enemy.position.y);

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
	return 0;
}
