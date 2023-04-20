
/*!
 *  @file       game.cpp
 *  @brief      �Q�[���Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/06
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "game.h"
#include"game_object/game_object.h"
#include"game/game_manager/game_object/scene_manager/scene/scene_manager.h"
#include"game/game_manager/game_object/character/character.h"
#include"game/game_manager/game_object/enemy_manager/enemy_manager.h"
const unsigned int CGame::m_clear_color = 0xff7f7f7f;


/*
 *  �R���X�g���N�^
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  ������
 */
void
CGame::
Initialize(void)
{
    // �ŏ��ɍ��I�u�W�F�N�g�Q

    aqua::CreateGameObject<CSceneManager>(this);

    IGameObject::Initialize();
}

/*
 *  �X�V
 */
void
CGame::
Update(void)
{
    // �q�N���X�̍X�V
    IGameObject::Update();
}


/*
 *  �`��
 */
void
CGame::
Draw(void)
{
    // ��ʂ̃N���A
    aqua::Clear(m_clear_color);

    // �`�悵�����I�u�W�F�N�g�Q

    IGameObject::Draw();
}

void CGame::Finalize(void)
{
    // �q�N���X�̉��
    IGameObject::Finalize();

}
