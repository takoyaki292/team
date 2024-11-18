//#include "Mouse.h"
//
//Mouse::Mouse()
//{
//	mouseX = 0;
//	mouseY = 0;
//	isMouse = false;
//	isT = false;
//}
//
//Mouse::~Mouse()
//{
//}
//void Mouse::cMouse(Vector3 card_[card::numC], int cardW_, int cardH_)
//{
//	float BX1[card::numC]={};
//	float BX2[card::numC]={};
//	float BY1[card::numC]={};
//	float BY2[card::numC]={};
//
//	for (int i = 0; i < card::numC; i++)
//	{
//		BX1[i] = card_[i].x - cardW_;
//		BX2[i] = card_[i].x + cardW_;
//		BY1[i] = card_[i].y - cardH_;
//		BY2[i] = card_[i].y + cardH_;
//		Novice::GetMousePosition(&mouseX, &mouseY);
//
//		if (mouseX >= BX1[i] && mouseX <= BX2[i] && mouseY >= BY1[i] && mouseY <= BY2[i])
//		{
//			isMouse = true;
//		}
//		else
//		{
//			isMouse = false;
//		}
//
//		if (isMouse == true && Novice::IsTriggerMouse(0))
//		{
//			isT = true;
//		}
//	}
//	
//}
//
//