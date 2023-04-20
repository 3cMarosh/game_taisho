

/*!
 *  @file       scene_id.h
 *  @brief      シーンID
 *  @author     Kazuya Maruyama
 *  @date       2021/04/25
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

 /*!
  *  @brief      シーンID
  */
enum class SCENE_ID
{
    DUMMY,           //! ダミーID
    TITLE,           //! タイトルシーン  
    START,           //!ゲームスタート演出シーン
    GAME_MAIN,       //! ゲームメインシーン
    RESULT,          //!リザルトシーン

     
};
