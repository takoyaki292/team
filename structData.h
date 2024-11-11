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

struct allMapChip final //マップチップ
{
	const int Block;/*テクスチャ変数*/ bool BlockFlag;/*当たり判定の変数*/
	const int card1;/*テクスチャ変数*/ bool card1Flag;/*当たり判定の変数*/
	const int card2;/*テクスチャ変数*/ bool card2Flag;/*当たり判定の変数*/
	const int card3;/*テクスチャ変数*/ bool card3Flag;/*当たり判定の変数*/
};