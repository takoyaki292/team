#pragma once
#include <Novice.h>
#include "structData.h"


class mapChip
{
public:

	///=======================================================================
	//注意
	///=======================================================================
	/*
	// Novice.cpp
	// スプライトの最大数
	static const int32_t kMaxSpriteCount = 9999;　になっていないとエラーがおきます
	*/
	

	///==========================================================================
	// 画像の変数の初期化
	///==========================================================================

	



	//マップチップの表示
	void NoviceMapChip(const int mapSizeX, const int mapSizeY, int chipSizeX_, int chipSizeY_, int stageMap_[][16/*mapChipSizeY*/]);

	// 他のcppで変数の状態を取得するための関数
	static mapChip& GetInstance()
	{
		static mapChip instance;
		return instance;
	}
	int chipSizeX = 120; // マップチップの横サイズ
	int chipSizeY = 120; // マップチップの横サイズ
	
private:
	

	// マップチップ画像(仮)
	allMapChip myTexture
	{
		{ Novice::LoadTexture("./Resources/images/mapChip/block01.png") }, /* ブロック*/ {false}, // 当たっているか判定するフラグ
		{ Novice::LoadTexture("./Resources/images/mapChip/card01.png")  }, /* カード1 */ {false}, // 当たっているか判定するフラグ
		{ Novice::LoadTexture("./Resources/images/mapChip/card01.png")  }, /* カード2 */ {false}, // 当たっているか判定するフラグ
		{ Novice::LoadTexture("./Resources/images/mapChip/card01.png")  }, /* カード3 */ {false}  // 当たっているか判定するフラグ
	};
	// マップ生成に必要な変数
	static const int mapChipSizeX = 16;  // マップチップの数
	static const int mapChipSizeY = 9;  // マップチップの数

	// マップ情報
	int stageMap[mapChipSizeY][mapChipSizeX] =
	{
		{11, 13, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{12, 14, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
		{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	};

		

};
