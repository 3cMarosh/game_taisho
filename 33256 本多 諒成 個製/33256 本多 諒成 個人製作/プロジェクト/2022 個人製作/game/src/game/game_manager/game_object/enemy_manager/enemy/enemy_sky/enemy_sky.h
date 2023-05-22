
/*!
 *  @file       crow.h
 *  @brief      カラス
 *  @author     Kazuya Maruyama
 *  @date       2021/05/20
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include"..\enemy.h"
#include "aqua.h"

class CCharacter;
class CEffectManager;

 /*!
  *  @class      CEnemySky
  *
  *  @brief      カラスクラス
  *
  *  @author     Kazuya Maruyama
  *
  *  @date       2021/05/20
  *
  *  @version    1.0
  */
class CEnemySky 
    : public IEnemy
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent      親オブジェクト
     */
    CEnemySky(aqua::IGameObject* parent);

    /*!
     *  @brief      デストラクタ
     */
    ~CEnemySky(void) = default;

    /*!
     *  @brief      初期化
     */
    void    Initialize(void) override;

    void    Update(void)override;

    void    Draw(void)override;

    void    Finalize(void)override;

private:

    aqua::CSprite m_Esky;

    CCharacter* m_Character_p;
    CEffectManager* m_Effect_p;

    float  m_Life;
  

    static const int            m_CreateInteaval;
    //static const int            m_max_life;

    bool                        m_DeadFlag;
};
