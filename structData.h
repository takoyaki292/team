#pragma once
#include "Vector3.h"

struct original final // キャラ全般変数
{
	Vector3 Size;		 // サイズ
	Vector3 Radius;		 // 半径
	Vector3 position;	 // ポジション
	Vector3 LeftTop;	 // 左上
	Vector3 RightTop;	 // 右上
	Vector3 LeftBottom;	 // 左下
	Vector3 RightBottom; // 右下
	Vector3 speed;       // スピード
	const int Texture;   // テクスチャ
};

struct allCard final
{
	static constexpr int mapChipCount = 7; // 配列サイズの定義

	const int block;
	int card[mapChipCount];
};