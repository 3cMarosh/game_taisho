#pragma once


#pragma once

#include "aqua.h"
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
class CCharacter
    : public IPlayer
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親オブジェクト
     */
    CCharacter(aqua::IGameObject* parent);

    /*!
     *  @brief      デストラクタ
     */
    ~CCharacter(void) = default;

    /*!
     *  @brief      初期化
     */
    void        Initialize(void)override ;

    /*!
     *  @brief      更新
     */
    void        Update(void)override;

    /*!
     *  @brief      描画
     */
    //void        Draw(void);

    /*!
     *  @brief      解放
     */
    //void        Finalize(void);

    //! 入力
    void        Input(void);

    ////! 出力
    //void        Output(void);

    //!移動
    void        Move(void);

    //aqua::CVector2 GetCenterPosition();

private:
    //! 画面クリアカラー


    static const unsigned int   m_clear_color;

    //aqua::CSprite               m_CharaSprite;
    aqua::CLinePrimitive        m_Line;
    aqua::CLabel                m_CheckLabel;
    aqua::CVector2              m_Position;
    aqua::CVector2              m_Velocity;
    aqua::CVector2              m_Accelerate;

    bool                        m_LandFlag;
    
    float                       m_move_speed;

    CBulletManager*             m_bullet_manager;
    
    static const float          m_friction;
};
