#include "title_scene.h"

CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

CTitleScene::~CTitleScene(void)
{
}

void CTitleScene::Initialize(void)
{
	m_Title_BackGround.Create("data\\white.png");
	m_Title_Sprite.Create("data\\title.png");
	m_Title_message.Create("data\\start_message.png");
	m_Title_message.position = aqua::CVector2(520.0f, 500.0f);
	m_Title_Sprite.position = aqua::CVector2(400.0f, 240.0f);
}

void CTitleScene::Update(void)
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::Z))
	{
		Change(SCENE_ID::GAME_MAIN);
	}
}

void CTitleScene::Draw(void)
{
	m_Title_BackGround.Draw();
	m_Title_Sprite.Draw();
	m_Title_message.Draw();
}

void CTitleScene::Finalize(void)
{
	m_Title_BackGround.Delete();
	m_Title_Sprite.Delete();
	m_Title_message.Delete();
}

float CTitleScene::GetTime()
{
	return 0.0f;
}
