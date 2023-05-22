
/*!
 *  @file       unit.cpp
 *  @brief      ユニット
 *  @author     Kazuya Maruyama
 *  @date       2021/05/20
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "unit.h"
#include "..\stage\stage.h"

const int   IUnit::m_default_max_life = 1;
const float IUnit::m_limit_dead_time = 0.5f;

/*
 *  コンストラクタ
 */
IUnit::
IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category)
    : aqua::IGameObject(parent, name, category)
    , m_Position(aqua::CVector2::ZERO)
    , m_Velocity(aqua::CVector2::ZERO)
    , m_Accelerator(aqua::CVector2::ZERO)
    , m_LandingFlag(false)
    , m_HitRaius(0.0f)
    , m_MaxLife(m_default_max_life)
    , m_Life(m_default_max_life)
    , m_InvincibleFlag(false)
{
}

/*
 *  初期化
 */
void
IUnit::
Initialize(const std::string& file_name)
{
    m_UnitSprite.Create(file_name);
    m_UnitSprite.anchor.x = (float)m_UnitSprite.GetTextureWidth() / 2.0f;
    m_UnitSprite.anchor.y = (float)m_UnitSprite.GetTextureHeight() / 2.0f;

    m_UnitShadowSprite.Create(file_name);
    m_UnitShadowSprite.color = 0x40000000;
    m_UnitShadowSprite.anchor.x = (float)m_UnitShadowSprite.GetTextureWidth() / 2.0f;
    m_UnitShadowSprite.anchor.y = 0.0f;
    m_UnitShadowSprite.scale.x = 1.0f;
    m_UnitShadowSprite.scale.y = -0.25f;

    m_HitRaius = (float)m_UnitSprite.GetTextureWidth() / 4.0f;

    m_State = STATE::MOVE;

    m_DeadTimer.Setup(m_limit_dead_time);

    m_SmokeTimer.Setup(0.3f);
}

/*
 *  更新
 */
void
IUnit::
Update(void)
{
    switch (m_State)
    {
    case STATE::MOVE:   Move();     break;
    case STATE::DEAD:   Dead();     break;
    }
}

/*
 *  描画
 */
void
IUnit::
Draw(void)
{
    m_UnitShadowSprite.Draw();
    m_UnitSprite.Draw();
}

/*
 *  解放
 */
void
IUnit::
Finalize(void)
{
    m_UnitSprite.Delete();
    m_UnitShadowSprite.Delete();
}

/*
 *  ダメージ処理
 */
bool
IUnit::
Damage(int damage)
{
    if (m_InvincibleFlag) return false;
    if (m_State == STATE::DEAD) return false;

    m_Life -= damage;

    if (m_Life <= 0)
    {
        m_Life = 0;

        m_State = STATE::DEAD;

        if (m_GameObjectCategory == "EnemyUnit")
        {
            //CDestroyScore* score = (CDestroyScore*)aqua::FindGameObject("DestroyScore");

            //score->AddScore(1);
        }
    }

    //CEffectManager* effect = (CEffectManager*)aqua::FindGameObject("EffectManager");
    //effect->Create(EFFECT_ID::HIT, GetCenterPosition());

    return true;
}

/*
 *  位置取得
 */
aqua::CVector2
IUnit::
GetPosition(void)
{
    return m_Position;
}

/*
 *  中心位置取得
 */
aqua::CVector2
IUnit::
GetCenterPosition(void)
{
    aqua::CVector2 t = aqua::CVector2((float)m_UnitSprite.GetTextureWidth() / 2.0f, (float)m_UnitSprite.GetTextureHeight() / 2.0f);

    return m_Position + t;
}

/*
 *  アタリの半径取得
 */
float
IUnit::
GetHitRadius(void)
{
    return m_HitRaius;
}

/*
 *  現在のライフ取得
 */
int
IUnit::
GetLife(void)
{
    return m_Life;
}

/*
 *  最大ライフ取得
 */
int
IUnit::
GetMaxLife(void)
{
    return m_MaxLife;
}

/*
 *  移動
 */
void
IUnit::
Move(void)
{
    //CEffectManager* effect = (CEffectManager*)aqua::FindGameObject("EffectManager");

    CStage* stage = (CStage*)aqua::FindGameObject("Stage");

    if (!stage) return;

    if (!m_LandingFlag)
        m_Accelerator.y += stage->GetGravity();

    m_Velocity += m_Accelerator;

    m_Position += m_Velocity * aqua::GetDeltaTime();

    m_Accelerator = aqua::CVector2::ZERO;

    float ground_line = stage->GetGroundLine() - (float)m_UnitSprite.GetTextureHeight();

    if (m_Position.y >= ground_line)
    {
        m_Position.y = ground_line;

        m_Velocity.y = 0.0f;

        m_LandingFlag = true;
    }

    if (m_Position.x < (float)(-m_UnitSprite.GetTextureWidth()))
        DeleteObject();

    m_UnitSprite.position = m_Position;


    aqua::CVector2 t = aqua::CVector2(m_UnitSprite.position.x, stage->GetGroundLine());

    m_UnitShadowSprite.position = t - aqua::CVector2(0.0f, (float)m_UnitShadowSprite.GetTextureHeight() * m_UnitShadowSprite.scale.y);

    float kyori = 0;

    kyori = (ground_line - m_UnitSprite.position.y) + 10.0f;

    if (m_LandingFlag == false)
    {
        m_UnitShadowSprite.color.alpha = -kyori;
    }
}

/*
 *  死亡
 */
void
IUnit::
Dead(void)
{

    m_DeadTimer.Update();

    if (m_DeadTimer.Finished())
        DeleteObject();
}
