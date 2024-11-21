#include "Skill.h"

void Skill::Draw()
{
	Novice::DrawEllipse((int)skill_.position.x, (int)skill_.position.y, (int)skill_.Radius.x, (int)skill_.Radius.y, 0.0f, BLACK, kFillModeSolid);
}

void Skill::Update()
{
	Novice::GetMousePosition(&mouseX,&mouseY);

    if (mouseX > skill_.LeftTop.x && mouseX < skill_.RightTop.x && mouseY > skill_.LeftTop.y && mouseY < skill_.LeftBottom.y)
    {
        isM = true; 
        if (Novice::IsTriggerMouse(0))
        {
            isTrigger = true;
            Effect();
        }
    }
}

void Skill::Effect()
{
}
