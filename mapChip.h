#pragma once
#include <Novice.h>
#include "structData.h"
#include "Player.h"

//class Player;
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
	//マップチップの表示
	void NoviceMapChip(const int mapSizeX, const int mapSizeY, int chipSizeX_, int chipSizeY_, int stageMap_[][16]);

	// 他のcppで変数の状態を取得するための関数
	static mapChip& GetInstance()
	{
		static mapChip instance;
		return instance;
	}

	// カウントをアップさせる関数
	void isDetection(Player& player_);
	int chipSizeX = 120; // マップチップの横サイズ
	int chipSizeY = 120; // マップチップの横サイズ
	
	// マップ生成に必要な変数
	static const int mapChipSizeX = 16;  // マップチップの数
	static const int mapChipSizeY = 9;  // マップチップの数
private:
	
	// マップ情報
	int stageMap[mapChipSizeY][mapChipSizeX] =
	{
		{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
		{10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10},
		{10, 11, 11, 11, 11, 11, 26, 11, 11, 11, 11, 11, 11, 11, 11, 10},
		{10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10},
		{10, 11, 21, 11, 24, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10},
		{10, 11, 11, 23, 11, 11, 11, 25, 11, 11, 11, 11, 11, 11, 11, 10},
		{10, 11, 22, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10},
		{10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10},
		{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	};
	

};
