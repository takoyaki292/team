#include "Skill.h"

Skill::Skill()
{
    isM = false;
    isTrigger = false;

    for (int i = 0; i < skillNum; i++)
    {
        skillPosition[i] = { 600.f + i * 300.f,300.f };
        skillF[i] =false;
        r[i] = { 50.0f,50.f };
    }
}

void Skill::Draw()
{
    if (isTrigger==false)
    {
	    Novice::DrawEllipse((int)skillBotan_.position.x, (int)skillBotan_.position.y, (int)skillBotan_.Radius.x, (int)skillBotan_.Radius.y, 0.0f, BLACK, kFillModeSolid);
    }
    else if(isTrigger==true)
    {
        for (int i = 0; i < skillNum; i++)
        {
            Novice::DrawEllipse((int)skillPosition[i].x, (int)skillPosition[i].y, (int)r[i].x, (int)r[i].y, 0.0f, BLACK, kFillModeSolid);
         }
    }
}

void Skill::Update()
{
    Mouse();

    //スキルの効果
    for (int i= 0; i < skillNum; i++)
    {
        if (skillF[i] == true)
        {
            Effect();
        }
    }


}

void Skill::Effect()
{
    //スキルの効果
    //一個目
    if (skillF[0] == true)
    {
        skillF[0] == false;
    }
    //二個目
    else  if (skillF[1] == true)
    {
        skillF[1] == false;
    }
    //三個目
    else  if (skillF[2] == true)
    {
        skillF[2] == false;
    }
}

void Skill::Mouse()
{
    Novice::GetMousePosition(&mouseX, &mouseY);

    if (mouseX > skillBotan_.LeftTop.x && mouseX < skillBotan_.RightTop.x && mouseY > skillBotan_.LeftTop.y && mouseY < skillBotan_.LeftBottom.y)
    {
        isM = true;
        if (Novice::IsTriggerMouse(0))
        {
            isTrigger = true;           
        }
    }

    
    if (isTrigger == true)
    {
        isM = false;
        for (int i = 0; i < skillNum; i++)
        {
            BX1[i] = skillPosition[i].x - r[i].x;
            BX2[i] = skillPosition[i].x + r[i].x;
            BY1[i] = skillPosition[i].y - r[i].y;
            BY2[i] = skillPosition[i].y + r[i].y;
            if (mouseX > BX1[i] && mouseX < BX2[i] && mouseY > BY1[i] && mouseY < BY2[i])
            {
                if (Novice::IsTriggerMouse(0))
                {
                    skillF[i] = true;
                    
                }
            }
            
        }
    }
    
    
}
