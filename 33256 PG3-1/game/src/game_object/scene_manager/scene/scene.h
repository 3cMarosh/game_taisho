#pragma once
#pragma once

/*!
 *  @file       scene.h
 *  @brief      �V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/04/25
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "scene_id.h"

 /*!
  *  @class      IScene
  *
  *  @brief      �V�[���N���X
  *
  *  @author     Kazuya Maruyama
  *
  *  @date       2021/04/25
  *
  *  @version    1.0
  */
class IScene
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     *  @param[in]  object_name     �I�u�W�F�N�g��
     */
    IScene(aqua::IGameObject* parent, const std::string& object_name);

    /*!
     *  @brief      �f�X�g���N�^
     */
    virtual ~IScene(void) = default;

    /*!
     *  @brief      �V�[����ύX����
     *              �X�^�b�N����Ă���S�ẴV�[�����폜���ύX����
     *
     *  @param[in]  id      �V�[��ID
     */
    void    Change(SCENE_ID id);

    /*!
     *  @brief      �V�[�����X�^�b�N����
     *
     *  @param[in]  id      �V�[��ID
     */
    void    PushScene(SCENE_ID id);

    /*!
     *  @brief      �X�^�b�N���ꂽ�V�[�������o��
     */
    void    PopScene(void);

    /*!
     *  @brief      �V�[�������Z�b�g����
     */
    void    ResetScene(void);

private:
    //! �V�[���J�e�S���[
    static const std::string    m_scene_category;
};
