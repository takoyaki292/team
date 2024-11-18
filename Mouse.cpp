#include "Mouse.h"

Mouse::Mouse()
{
	isMouse = false;
	isT = false;
}

Mouse::~Mouse()
{
}



void Mouse::cMouse(Vector3 card_,int cardW_, int cardH_)
{
	int BX1 = card_.x - cardW_;
	int BX2 = card_.x + cardW_;
	int BY1 = card_.y - cardH_;
	int BY2 = card_.y + cardH_;
	Novice::GetMousePosition(&mouseX, &mouseY);

	if (mouseX >= BX1 && mouseX <= BX2 && mouseY >= BY1 && mouseY <= BY2)
	{
		isMouse = true;
	}
	else
	{
		isMouse= false;
	}

	if (isMouse == true && Novice::IsTriggerMouse(0))
	{
		isT = true;
	}
}
