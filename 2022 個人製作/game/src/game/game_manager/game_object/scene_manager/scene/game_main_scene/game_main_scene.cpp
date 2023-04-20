#include"game_main_scene.h"
#include"game/game_manager/game_object/ui_compornent/start_message/start_message.h"
#include"game/game_manager/game_object/ui_compornent/finish_message/finish_message.h"
#include"game/game_manager/game_object/stage/stage.h"
#include"game\game_manager\game_object\character\character.h"	
#include"game/game_manager/game_object/effect_manager/effect_manager.h"
#include"game/game_manager/game_object/enemy_manager/enemy_manager.h"


const std::string CGameMainScene::m_object_name = "GameMain";
const float CGameMainScene::m_game_main_time = 30.0f;


CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,"GameMainScene")
{
}

CGameMainScene::~CGameMainScene(void)
{
}

void CGameMainScene::Initialize(void)
{

	// ステージ生成
	aqua::CreateGameObject<CStage>(this);

	aqua::CreateGameObject<CCharacter>(this);

	aqua::CreateGameObject<CEnemyManager>(this);

	aqua::CreateGameObject<CEffectManager>(this);

	//状態設定
	IGameObject::Initialize();
	m_GameMainTime.Setup(m_game_main_time);


}

void CGameMainScene::Update(void)
{
	if (m_GameMainTime.Finished())
	{
		Change(SCENE_ID::RESULT);
	}

	m_GameMainTime.Update();
	IGameObject::Update();

}

float CGameMainScene::GetTime()
{
	return m_GameMainTime.GetTime();
}

