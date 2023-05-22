
/*!
 *  @file       unit.h
 *  @brief      ユニット
 *  @author     Kazuya Maruyama
 *  @date       2021/05/20
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

 /*!
  *  @class      IUnit
  *
  *  @brief      ユニットクラス
  *
  *  @author     Kazuya Maruyama
  *
  *  @date       2021/05/20
  *
  *  @version    1.0
  */
class IUnit
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent      親オブジェクト
     *  @param[in]  name        オブジェクト名
     *  @param[in]  category    カテゴリー名
     */
    IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category);

    /*!
     *  @brief      デストラクタ
     */
    virtual ~IUnit(void) = default;

    /*!
     *  @brief      初期化
     *
     *  @param[in]  file_name   テクスチャファイル名
     */
    virtual void    Initialize(const std::string& file_name);

    /*!
     *  @brief      更新
     */
    virtual void    Update(void);

    /*!
     *  @brief      描画
     */
    virtual void    Draw(void);

    /*!
     *  @brief      解放
     */
    virtual void    Finalize(void);

    /*!
     *  @brief      ダメージ処理
     *
     *  @param[in]  damage  ダメージ量
     */
    virtual bool    Damage(int damage);

    /*!
     *  @brief      位置取得
     *
     *  @return     位置
     */
    aqua::CVector2  GetPosition(void);

    /*!
     *  @brief      中心位置取得
     *
     *  @return     中心位置
     */
    aqua::CVector2  GetCenterPosition(void);

    /*!
     *  @brief      アタリの半径取得
     *
     *  @return     アタリの半径
     */
    float           GetHitRadius(void);

    /*!
     *  @brief      現在のライフ取得
     *
     *  @return     現在のライフ
     */
    int             GetLife(void);

    /*!
     *  @brief      最大ライフ取得
     *
     *  @return     最大ライフ
     */
    int             GetMaxLife(void);

protected:
    /*!
     *  @brief      移動
     */
    virtual void    Move(void);

    /*!
     *  @brief      死亡
     */
    virtual void    Dead(void);

    /*!
     *  @brief      状態ID
     */
    enum class STATE
    {
        MOVE,   //! 移動
        DEAD,   //! 死亡
    };

    static const int    m_default_max_life;             //! 初期の最大ライフ
    static const float  m_limit_dead_time;              //! 死亡時間
    aqua::CSprite       m_UnitSprite;                   //! ユニットスプライト
    aqua::CSprite       m_UnitShadowSprite;             //! ユニット影スプライト
    aqua::CVector2      m_Position;                     //! 位置
    aqua::CVector2      m_Velocity;                     //! 速度
    aqua::CVector2      m_Accelerator;                  //! 加速度
    bool                m_LandingFlag;                  //! 着地フラグ
    float               m_HitRaius;                     //! アタリの半径
    int                 m_Life;                         //! ライフ
    int                 m_MaxLife;                      //! 最大ライフ
    bool                m_InvincibleFlag;               //! 無敵フラグ
    STATE               m_State;                        //! 状態
    aqua::CTimer        m_DeadTimer;                    //! 死亡タイマー
    aqua::CTimer        m_SmokeTimer;                   //! 砂煙のエフェクトにタイマー
};
