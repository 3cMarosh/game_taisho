
/*!
 *  @file       unit.h
 *  @brief      ���j�b�g
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
  *  @brief      ���j�b�g�N���X
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
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent      �e�I�u�W�F�N�g
     *  @param[in]  name        �I�u�W�F�N�g��
     *  @param[in]  category    �J�e�S���[��
     */
    IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category);

    /*!
     *  @brief      �f�X�g���N�^
     */
    virtual ~IUnit(void) = default;

    /*!
     *  @brief      ������
     *
     *  @param[in]  file_name   �e�N�X�`���t�@�C����
     */
    virtual void    Initialize(const std::string& file_name);

    /*!
     *  @brief      �X�V
     */
    virtual void    Update(void);

    /*!
     *  @brief      �`��
     */
    virtual void    Draw(void);

    /*!
     *  @brief      ���
     */
    virtual void    Finalize(void);

    /*!
     *  @brief      �_���[�W����
     *
     *  @param[in]  damage  �_���[�W��
     */
    virtual bool    Damage(int damage);

    /*!
     *  @brief      �ʒu�擾
     *
     *  @return     �ʒu
     */
    aqua::CVector2  GetPosition(void);

    /*!
     *  @brief      ���S�ʒu�擾
     *
     *  @return     ���S�ʒu
     */
    aqua::CVector2  GetCenterPosition(void);

    /*!
     *  @brief      �A�^���̔��a�擾
     *
     *  @return     �A�^���̔��a
     */
    float           GetHitRadius(void);

    /*!
     *  @brief      ���݂̃��C�t�擾
     *
     *  @return     ���݂̃��C�t
     */
    int             GetLife(void);

    /*!
     *  @brief      �ő僉�C�t�擾
     *
     *  @return     �ő僉�C�t
     */
    int             GetMaxLife(void);

protected:
    /*!
     *  @brief      �ړ�
     */
    virtual void    Move(void);

    /*!
     *  @brief      ���S
     */
    virtual void    Dead(void);

    /*!
     *  @brief      ���ID
     */
    enum class STATE
    {
        MOVE,   //! �ړ�
        DEAD,   //! ���S
    };

    static const int    m_default_max_life;             //! �����̍ő僉�C�t
    static const float  m_limit_dead_time;              //! ���S����
    aqua::CSprite       m_UnitSprite;                   //! ���j�b�g�X�v���C�g
    aqua::CSprite       m_UnitShadowSprite;             //! ���j�b�g�e�X�v���C�g
    aqua::CVector2      m_Position;                     //! �ʒu
    aqua::CVector2      m_Velocity;                     //! ���x
    aqua::CVector2      m_Accelerator;                  //! �����x
    bool                m_LandingFlag;                  //! ���n�t���O
    float               m_HitRaius;                     //! �A�^���̔��a
    int                 m_Life;                         //! ���C�t
    int                 m_MaxLife;                      //! �ő僉�C�t
    bool                m_InvincibleFlag;               //! ���G�t���O
    STATE               m_State;                        //! ���
    aqua::CTimer        m_DeadTimer;                    //! ���S�^�C�}�[
    aqua::CTimer        m_SmokeTimer;                   //! �����̃G�t�F�N�g�Ƀ^�C�}�[
};
