#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include <Novice.h>
class Mouse
{
public:
	Mouse();
	~Mouse();

	/// <summary>
	/// マウスの当たる判定
	/// </summary> 
	void cMouse(Vector3 card_,int w_,int h_);
	/// <summary>
	/// クリックした時のフラグ
	/// </summary>
	bool isT = false;
private:
	
	int mouseX;
	int mouseY;
	//マウスがカードに触れているかのフラグ
	bool isMouse=false;
};