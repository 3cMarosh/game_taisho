#pragma once


#pragma once

#include "aqua.h"
#include"game_object/player/IPlayer.h"

class CBulletManager;
/*!
 *  @class      CGame
 *
 *  @brief      �Q�[���N���X
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
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�I�u�W�F�N�g
     */
    CCharacter(aqua::IGameObject* parent);

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CCharacter(void) = default;

    /*!
     *  @brief      ������
     */
    void        Initialize(void)override ;

    /*!
     *  @brief      �X�V
     */
    void        Update(void)override;

    /*!
     *  @brief      �`��
     */
    //void        Draw(void);

    /*!
     *  @brief      ���
     */
    //void        Finalize(void);

    //! ����
    void        Input(void);

    ////! �o��
    //void        Output(void);

    //!�ړ�
    void        Move(void);

    aqua::CVector2 GetCenterPosition();

private:
    //! ��ʃN���A�J���[


    static const unsigned int   m_clear_color;
    static const int            m_max_life;

    aqua::CLinePrimitive        m_Line;
    aqua::CLabel                m_CheckLabel;
    aqua::CVector2              m_Position;
    aqua::CVector2              m_Velocity;
    aqua::CVector2              m_Accelerate;

    int                         m_Life;
    int                         m_attack_cost;

    bool                        m_LandFlag;
    bool                        m_DeadFlag;
    
    float                       m_move_speed;

    CBulletManager*             m_bullet_manager;
    
    static const float          m_friction;
};
