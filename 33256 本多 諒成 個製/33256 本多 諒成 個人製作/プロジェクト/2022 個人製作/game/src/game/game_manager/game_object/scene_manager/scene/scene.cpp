
/*!
 *  @file       scene.cpp
 *  @brief      �V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/04/25
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "scene.h"
#include "..\scene\scene_manager.h"

const std::string   IScene::m_scene_category = "Scene";

/*
 *  �R���X�g���N�^
 */
IScene::
IScene(aqua::IGameObject* parent, const std::string& object_name)
    : aqua::IGameObject(parent, object_name, m_scene_category)
{
}

/*
 *  �V�[���̕ύX
 */
void
IScene::
Change(SCENE_ID id)
{
    // �e�̃V�[���}�l�[�W���[���Ăяo��
    CSceneManager* sm = (CSceneManager*)GetParent();

    // �V�[����ύX����
    sm->Change(id);
}

/*
 *  �V�[�����X�^�b�N����
 */
void
IScene::
PushScene(SCENE_ID id)
{
    // �e�̃V�[���}�l�[�W���[���Ăяo��
    CSceneManager* sm = (CSceneManager*)GetParent();

    // �V�[�����X�^�b�N����
    sm->Push(id);
}

/*
 *  �X�^�b�N���ꂽ�V�[�������o��
 */
void
IScene::
PopScene(void)
{
    // �e�̃V�[���}�l�[�W���[���Ăяo��
    CSceneManager* sm = (CSceneManager*)GetParent();

    // �X�^�b�N���ꂽ�V�[�������o��
    sm->Pop();
}

/*
 *  �V�[�������Z�b�g����
 */
void
IScene::
ResetScene(void)
{
    // �e�̃V�[���}�l�[�W���[���Ăяo��
    CSceneManager* sm = (CSceneManager*)GetParent();

    // ���Z�b�g
    sm->Reset();
}
