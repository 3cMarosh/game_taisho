#pragma once
#pragma once

/*!
 *  @file       scene.h
 *  @brief      シーン
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
  *  @brief      シーンクラス
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
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     *  @param[in]  object_name     オブジェクト名
     */
    IScene(aqua::IGameObject* parent, const std::string& object_name);

    /*!
     *  @brief      デストラクタ
     */
    virtual ~IScene(void) = default;

    /*!
     *  @brief      シーンを変更する
     *              スタックされている全てのシーンを削除し変更する
     *
     *  @param[in]  id      シーンID
     */
    void    Change(SCENE_ID id);

    /*!
     *  @brief      シーンをスタックする
     *
     *  @param[in]  id      シーンID
     */
    void    PushScene(SCENE_ID id);

    /*!
     *  @brief      スタックされたシーンを取り出す
     */
    void    PopScene(void);

    /*!
     *  @brief      シーンをリセットする
     */
    void    ResetScene(void);

private:
    //! シーンカテゴリー
    static const std::string    m_scene_category;
};
