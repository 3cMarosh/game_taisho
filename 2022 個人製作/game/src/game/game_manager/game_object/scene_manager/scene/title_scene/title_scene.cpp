#include "title_scene.h"
#include"..\scene_manager.h"


const float CTitleScene::m_fade_speed = 180.0f;	//スタートメッセージのフェード速度

CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

void CTitleScene::Initialize(void)
{
	m_TitleBGSprite.Create("data\\title_background.png");	//タイトル背景の描画
	m_StartSprite.Create("data\\Start_Message.png");			//PushZKeyの描画

	m_StartSprite.position		= aqua::CVector2(450.0f,550.0f);
	m_StartSprite.scale			= aqua::CVector2(0.25f, 0.25f);
	m_TitleBGSprite.position	= aqua::CVector2(0.0f, 0.0f);
	
	m_FadeSpeed = 0.0f;

}

void CTitleScene::Update(void)
{
	//スタートメッセージのフェード処理
	int alpha = m_StartSprite.color.alpha;
																			
	m_FadeSpeed += aqua::DegToRad(m_fade_speed) * aqua::GetDeltaTime();

	alpha = (int)(abs(sin(m_FadeSpeed)) * (float)aqua::CColor::MAX_COLOR);

	m_StartSprite.color.alpha = (unsigned char)alpha;

	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::Z))
	{
		Change(SCENE_ID::GAME_MAIN);
	}
}

void CTitleScene::Draw(void)
{
	m_TitleBGSprite.Draw();
	m_StartSprite.Draw();
	m_tLabel.Draw();
}

void CTitleScene::Finalize(void)
{
	m_TitleBGSprite.Delete();
	m_StartSprite.Delete();
	m_tLabel.Delete();
}
