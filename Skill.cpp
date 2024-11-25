#include "Skill.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
class card;
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

void Skill::Update(card& cardInstance)
{
    Mouse();

    Effect(cardInstance);
}

void Skill::Effect(card& cardInstance)
{
    //スキルの効果
    //一個目
    if (skillF[0] == true)
    {
        revolution(cardInstance);
        skillF[0] = false;
        isTrigger = false;
    }
    //二個目
    else  if (skillF[1] == true)
    {
        twice(cardInstance);
        skillF[1] = false;
        isTrigger = false;
    }
    //三個目
    else  if (skillF[2] == true)
    {
        randomNum(cardInstance);
        isTrigger = false;
        skillF[2] = false;
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

//勝利条件を変えるようにする
void Skill::revolution(card& cardInstance)
{
    for (int i = 0; i < cardInstance.maxSize; i++)
    {   
        if (cardInstance.haveCardF[i]) {
            cardInstance.num[i] = cardInstance.maxSize - i;
            //break;
        }
    }
}

void Skill::twice(card& cardInstance)
{
    for (int i = 0; i < cardInstance.maxSize; i++)
    {
        if (cardInstance.haveCardF[i]) {
            cardInstance.num[i] = i * 2;
        }
    }
}

void Skill::randomNum(card& cardInstance)
{
    unsigned int currentTime = static_cast<unsigned int>(time(nullptr));
    srand(currentTime);
    //シャッフルの配列
    std::vector<int> availableNums = { 1, 2, 3, 4, 5, 6, 7 };
    std::random_device rd;
    std::mt19937 g(rd());

    // シャッフル
    std::shuffle(availableNums.begin(), availableNums.end(), g);

    int numIndex = 0;
    for (int i = 0; i < cardInstance.maxSize; i++)
    {
        if (cardInstance.haveCardF[i]) {
            cardInstance.num[i] = availableNums[numIndex];
            numIndex++;
        }
    }
}
