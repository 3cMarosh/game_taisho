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
	m_Title_Label.text = "";

}

void CTitleScene::Update(void)
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::SPACE))
	{
		Change(SCENE_ID::GAME_MAIN);
	}
}

void CTitleScene::Draw(void)
{
	m_Title_BackGround.Draw();
}

void CTitleScene::Finalize(void)
{
	m_Title_BackGround.Delete();
}

float CTitleScene::GetTime()
{
	return 0.0f;
}
