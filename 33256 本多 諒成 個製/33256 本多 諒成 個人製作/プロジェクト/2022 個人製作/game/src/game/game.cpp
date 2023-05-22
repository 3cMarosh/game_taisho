
/*!
 *  @file       game.cpp
 *  @brief      ゲーム管理
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
 *  コンストラクタ
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  初期化
 */
void
CGame::
Initialize(void)
{
    // 最初に作るオブジェクト群

    aqua::CreateGameObject<CSceneManager>(this);

    IGameObject::Initialize();
}

/*
 *  更新
 */
void
CGame::
Update(void)
{
    // 子クラスの更新
    IGameObject::Update();
}


/*
 *  描画
 */
void
CGame::
Draw(void)
{
    // 画面のクリア
    aqua::Clear(m_clear_color);

    // 描画したいオブジェクト群

    IGameObject::Draw();
}

void CGame::Finalize(void)
{
    // 子クラスの解放
    IGameObject::Finalize();

}
