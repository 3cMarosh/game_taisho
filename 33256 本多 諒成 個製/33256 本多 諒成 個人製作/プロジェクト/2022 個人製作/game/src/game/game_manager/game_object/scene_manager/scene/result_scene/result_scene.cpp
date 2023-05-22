	#include "result_scene.h"

CResultScene::CResultScene(aqua::IGameObject* parent)
	:IScene(parent,"ResultScene")
{
}

void CResultScene::Initialize(void)
{


	m_ResultBGSprite.Create("data\\result_BG.png");

}

void CResultScene::Update(void)
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::Z))
	{
		Change(SCENE_ID::TITLE);
	}

}

void CResultScene::Draw(void)
{
	m_ResultBGSprite.Draw();
	m_Result_Label.Draw();

}

void CResultScene::Finalize(void)
{
	m_ResultBGSprite.Delete();
	m_Result_Label.Delete();

}
