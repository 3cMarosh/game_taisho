

#pragma once

#include "aqua.h"
class CEnemy;
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
    : public aqua::IGameObject
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
    void        Initialize(void) override;

    /*!
     *  @brief      �X�V
     */
    void        Update(void) override;

    /*!
     *  @brief      �`��
     */
    void        Draw(void) override;

    /*!
     *  @brief      ���
     */
    void        Finalize(void) override;

    //! ����
    void        Input(void);

    //! �o��
    void        Output(void);

    aqua::CVector2 GetCenterPosition();

private:
    //! ��ʃN���A�J���[

    CEnemy* m_Enemy_p;

    static const unsigned int   m_clear_color;

    aqua::CSprite               m_CharaSprite;
    aqua::CLinePrimitive        m_Line;
    aqua::CLabel                m_CheckLabel;
    aqua::CVector2              m_Position;
    aqua::CVector2              m_Velocity;
    aqua::CVector2              m_Accelerate;
    bool                        m_LandFlag;
    static const float          m_friction;
};
