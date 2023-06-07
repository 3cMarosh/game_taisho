#include "result_scene.h"

const float CResultScene::m_result_time = 15.0f;

CResultScene::CResultScene(aqua::IGameObject* parent)
	:IScene(parent,"ResultScene")
{
}

CResultScene::~CResultScene(void)
{
}

void CResultScene::Initialize(void)
{
}

void CResultScene::Update(void)
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::SPACE))
	{
		Change(SCENE_ID::TITLE);
	}
}

void CResultScene::Draw(void)
{
}

void CResultScene::Finalize(void)
{
}

float CResultScene::GetTime()
{
	return 0.0f;
}
