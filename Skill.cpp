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

void Skill::BattleDraw()
{
    if (isTrigger==false)
    {
        
	    //Novice::DrawEllipse((int)skillBotan_.position.x, (int)skillBotan_.position.y, (int)skillBotan_.Radius.x, (int)skillBotan_.Radius.y, 0.0f, BLACK, kFillModeSolid);
	    Novice::DrawSprite((int)skillBotanT_.position.x - (int)skillBotanT_.Radius.x / 2, (int)skillBotanT_.position.y - (int)skillBotanT_.Radius.y / 2, skillTeX,1.9f,1.9f,0.0f,WHITE);
    }
    else if(isTrigger==true)
    {
        for (int i = 0; i < skillNum; i++)
        {
            //Novice::DrawEllipse((int)skillPosition[i].x, (int)skillPosition[i].y, (int)r[i].x, (int)r[i].y, 0.0f, BLACK, kFillModeSolid);
            Novice::DrawSprite((int)skillPosition[i].x - (int)r[i].x / 2, (int)skillPosition[i].y - (int)r[i].y / 2, skillT[i], 1, 1, 0.0f, WHITE);
         }
    }
}

void Skill::BattleUpdate(card& cardInstance)
{
    BattleMouse();

    BattleEffect(cardInstance);
}

void Skill::BattleEffect(card& cardInstance)
{
    //スキルの効果
    //一個目
    if (skillF[0] == true)
    {
        BattleRevolution();
        skillF[0] = false;
        isTrigger = false;
    }
    //二個目
    if (skillF[1] == true)
    {   
        BattleTwice(cardInstance);
        skillF[1] = false;
        isTrigger = false;
    }
    //三個目
    //if (skillF[2] == true)
    //{
    //    //BattleRandomNum(cardInstance);
    //    isTrigger = false;
    //    skillF[2] = false;
    //}
}

void Skill::BattleMouse()
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
void Skill::BattleRevolution()
{
    isRevolution = true;
}

void Skill::BattleTwice(card& cardInstance)
{
    for (int i = 0; i < cardInstance.maxSize; i++)
    {
        if (cardInstance.haveCardF[i]) {
            cardInstance.attckA[i] = i + 3;
        }
    }
}

void Skill::BattleRandomNum(card& cardInstance)
{
    unsigned int currentTime = static_cast<unsigned int>(time(nullptr));
    srand(currentTime);

    // シャッフル用の配列
    std::vector<int> availableNums = { 1, 2, 3, 4, 5, 6, 7 };
    std::random_device rd;
    std::mt19937 g(rd());

    // 配列のシャッフル
    std::shuffle(availableNums.begin(), availableNums.end(), g);

    int numIndex = 0; // シャッフルされた数値のインデックス

    for (int i = 0; i < cardInstance.maxSize; i++)
    {
        if (cardInstance.haveCardF[i]) // 有効なカードであるか確認
        {
            if (numIndex < availableNums.size()) // 範囲外アクセスを防止
            {
                cardInstance.attckA[i] = availableNums[numIndex];
                numIndex++;
            }
            else
            {
                // 追加の安全対策: numIndexがシャッフル配列のサイズを超えた場合
                break;
            }
        }
    }
}

void Skill::Reset()
{
    isM = false;
    isTrigger = false;

    for (int i = 0; i < skillNum; i++)
    {
        skillPosition[i] = { 600.f + i * 300.f,300.f };
        skillF[i] = false;
        r[i] = { 50.0f,50.f };
    }
}

