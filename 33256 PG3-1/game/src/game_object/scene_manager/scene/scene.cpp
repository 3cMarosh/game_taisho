
/*!
 *  @file       scene.cpp
 *  @brief      シーン
 *  @author     Kazuya Maruyama
 *  @date       2021/04/25
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "scene.h"
#include "..\scene_manager.h"

const std::string   IScene::m_scene_category = "Scene";

/*
 *  コンストラクタ
 */
IScene::
IScene(aqua::IGameObject* parent, const std::string& object_name)
    : aqua::IGameObject(parent, object_name, m_scene_category)
{
}

/*
 *  シーンの変更
 */
void
IScene::
Change(SCENE_ID id)
{
    // 親のシーンマネージャーを呼び出す
    CSceneManager* sm = (CSceneManager*)GetParent();

    // シーンを変更する
    sm->Change(id);
}

/*
 *  シーンをスタックする
 */
void
IScene::
PushScene(SCENE_ID id)
{
    // 親のシーンマネージャーを呼び出す
    CSceneManager* sm = (CSceneManager*)GetParent();

    // シーンをスタックする
    sm->Push(id);
}

/*
 *  スタックされたシーンを取り出す
 */
void
IScene::
PopScene(void)
{
    // 親のシーンマネージャーを呼び出す
    CSceneManager* sm = (CSceneManager*)GetParent();

    // スタックされたシーンを取り出す
    sm->Pop();
}

/*
 *  シーンをリセットする
 */
void
IScene::
ResetScene(void)
{
    // 親のシーンマネージャーを呼び出す
    CSceneManager* sm = (CSceneManager*)GetParent();

    // リセット
    sm->Reset();
}
