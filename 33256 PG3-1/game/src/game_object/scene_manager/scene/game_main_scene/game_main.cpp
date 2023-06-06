#include "game_main.h"
#include"game_object\stage\stage.h"
#include"game_object/burret_manager/burret_manager.h"
#include"game_object/player/character/character.h"
#include"game_object/player/character2/character2.h"
#include"game_object/player/IPlayer.h"

const std::string CGameMainScene::m_object_name = "GameMain";
const float CGameMainScene::m_game_main_time = 9999.0f;

CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,"GameMainScene")
{
}

CGameMainScene::~CGameMainScene(void)
{
}

void CGameMainScene::Initialize(void)
{
	aqua::CreateGameObject<CStage>(this);
	aqua::CreateGameObject<CCharacter>(this);
	aqua::CreateGameObject<CCharacter2>(this);
	aqua::CreateGameObject<CBulletManager>(this);


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

void CGameMainScene::Draw(void)
{
	IGameObject::Draw();
}

void CGameMainScene::Finalize(void)
{
	IGameObject::Finalize();
}

float CGameMainScene::GetTime()
{
	return m_GameMainTime.GetTime();
}
