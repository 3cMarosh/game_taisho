
/*!
 *  @file       crow.cpp
 *  @brief      カラス
 *  @author     Kazuya Maruyama
 *  @date       2021/05/20
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "enemy_sky.h"
#include "..\..\..\stage\stage.h"
#include "..\..\../effect_manager/effect_manager.h"
#include "..\..\../unit/unit.h"
#include "..\..\../stage/stage.h"
#include "..\..\..\character\character.h"

//const int           CEnemySky::m_max_life = 1;
const int           CEnemySky::m_CreateInteaval = 1;

/*
 *  コンストラクタ
 */
CEnemySky::
CEnemySky(aqua::IGameObject* parent)
    :IEnemy(parent, "EnemySky")
{
}

/*
 *  初期化
 */
void
CEnemySky::
Initialize(void)
{
    m_Esky.Create("data\\character.png");

    CStage* stage = (CStage*)aqua::FindGameObject("Stage");

    if (!stage) return;

    m_Esky.position.y = 350.0f;
    m_Esky.position.x = 1290.0f;

    m_Esky.GetTextureWidth();
    m_Esky.GetTextureHeight();

    //m_Life = m_max_life;

    m_Esky.color = 0xffff8080;

    m_Character_p = (CCharacter*)aqua::FindGameObject("Character");
    m_Effect_p = (CEffectManager*)aqua::FindGameObject("EffectManager");
}

void CEnemySky::Update(void)
{
    aqua::CVector2 EnemyCenter = 
    { 
        m_Esky.position.x + m_Esky.GetTextureWidth(),
        m_Esky.position.y + m_Esky.GetTextureHeight(),
    };

    if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::SPACE))
    {
        m_Esky.Delete();
    }
    m_Esky.position.x -= 7.0f;
}

void CEnemySky::Draw(void)
{
    m_Esky.Draw();
}

void CEnemySky::Finalize(void)
{
    m_Esky.Delete();
}
