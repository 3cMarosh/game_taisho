#pragma once


#pragma once

#include"aqua.h"
#include"game_object/player/IPlayer.h"

class CBulletManager;
/*!
 *  @class      CGame
 *
 *  @brief      ゲームクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2020/04/01
 *
 *  @version    1.0
 */
class CCharacter2
    : public IPlayer
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親オブジェクト
     */
    CCharacter2(aqua::IGameObject* parent);

    /*!
     *  @brief      デストラクタ
     */
    ~CCharacter2(void) = default;

    /*!
     *  @brief      初期化
     */
    void        Initialize(void)override;

    /*!
     *  @brief      更新
     */
    void        Update(void)override;

    ///*!
    // *  @brief      描画
    // */
    //void        Draw(void);

    ///*!
    // *  @brief      解放
    // */
    //void        Finalize(void);

    //! 入力
    void        Input(void);


    //!移動
    void        Move(void);

    aqua::CVector2 GetCenterPosition();

private:
    //! 画面クリアカラー


    static const unsigned int   m_clear_color;
    static const int            m_max_life;

    aqua::CLinePrimitive        m_Line;
    aqua::CLabel                m_CheckLabel;
    aqua::CVector2              m_Position;
    aqua::CVector2              m_Velocity;
    aqua::CVector2              m_Accelerate;
    aqua::CTimer                m_CostTimer;

    int                         m_Life;
    
    float                       m_move_speed;
    float                       m_move_center_speed;

    CBulletManager*             m_bullet_manager;

    static const float          m_friction;
};
