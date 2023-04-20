#include "stage.h"
#include"..\effect_manager\effect_manager.h"

const float CStage::m_ground_line = 600.0f;
const float CStage::m_gravity = 9.8f;

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Stage")
{
}

void CStage::Initialize(void)
{
	//メイン背景のクリエイト
	m_Main_BackGround.Create("data\\BG.png");
	m_Main_BackGround1.Create("data\\BG.png");

	//上下音符画像のクリエイト
	m_Sky_Notes1.Create("data\\sky_notes_touka.png");
	m_Sky_Notes.Create("data\\sky_notes_touka.png");
	m_Sky_Notes3.Create("data\\sky_notes_touka.png");
	m_Sky_Notes4.Create("data\\sky_notes_touka.png");

	m_NotesBackSorite1.Create("data\\shiro1.png");
	m_NotesBackSorite2.Create("data\\shiro1.png");
	m_NotesBackSorite3.Create("data\\shiro1.png");
	m_NotesBackSorite4.Create("data\\shiro1.png");

	m_NotesBackSorite1.position = aqua::CVector2(0.0f, 120.0f);
	m_NotesBackSorite2.position = aqua::CVector2(0.0f, 240.0f);
	m_NotesBackSorite3.position = aqua::CVector2(0.0f, 360.0f);
	m_NotesBackSorite4.position = aqua::CVector2(0.0f, 480.0f);

	m_Main_BackGround.position = aqua::CVector2(0.0f,0.0f);
	m_Main_BackGround1.position = aqua::CVector2(1280.0f, 0.0f);

	m_Sky_Notes.position = aqua::CVector2::ZERO;
	m_Sky_Notes1.position = aqua::CVector2(1280.0f, 0.0f);
	m_Sky_Notes3.position = aqua::CVector2(0.0f,579.0f);
	m_Sky_Notes4.position = aqua::CVector2(1280.0f, 579.0f);
	m_TextSprite.position = aqua::CVector2(0.0f, 620.0f);

	m_Effect_Notes = (CEffectManager*)aqua::FindGameObject("EffectManager");

}

void
CStage::
Update(void)
{
	m_Main_BackGround.position.x -= 7.0f;
	m_Main_BackGround1.position.x -= 7.0f;
	m_Sky_Notes.position.x -= 15.0f;
	m_Sky_Notes1.position.x -= 15.0f;
	m_Sky_Notes3.position.x -= 15.0f;
	m_Sky_Notes4.position.x -= 15.0f;

	//メイン背景のスクロール
	if (m_Main_BackGround.position.x < -1280.0f)
	{
		m_Main_BackGround.position.x = 1280.0f + (m_Main_BackGround.position.x + 1280.0f);
	}
	if (m_Main_BackGround1.position.x < -1280.0f)
	{
		m_Main_BackGround1.position.x = 1280.0f + (m_Main_BackGround1.position.x + 1280.0f);
	}
	//音符画像のスクロール(上)
	if (m_Sky_Notes.position.x < -1280.0f)
	{
		m_Sky_Notes.position.x = 1280.0f + (m_Sky_Notes.position.x + 1280.0f);
	}
	if (m_Sky_Notes1.position.x < -1280.0f)
	{
		m_Sky_Notes1.position.x = 1280.0f + (m_Sky_Notes1.position.x + 1280.0f);
	}
	//音符画像のスクロール(下)
	if (m_Sky_Notes3.position.x < -1280.0f)
	{
		m_Sky_Notes3.position.x = 1280.0f + (m_Sky_Notes3.position.x + 1280.0f);
	}
	if (m_Sky_Notes4.position.x < -1280.0f)
	{
		m_Sky_Notes4.position.x = 1280.0f + (m_Sky_Notes4.position.x + 1280.0f);
	}

	//キーボードを押したときのレーンエフェクトのようなもの

	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::A))
	{

		(m_Effect_Notes)->Create(EFFECT_ID::NOTES1, aqua::CVector2(0.0f,120.0f));
	}
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::S))
	{

		(m_Effect_Notes)->Create(EFFECT_ID::NOTES2, aqua::CVector2(0.0f,240.0f));
	}
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::K))
	{

		(m_Effect_Notes)->Create(EFFECT_ID::NOTES3, aqua::CVector2(0.0f,360.0f));
	}
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::L))
	{

		(m_Effect_Notes)->Create(EFFECT_ID::NOTES4, aqua::CVector2(0.0f,480.0f));
	}
}

void CStage::Draw(void)
{
	m_Main_BackGround.Draw();
	m_Main_BackGround1.Draw();
	m_Sky_Notes.Draw();
	m_Sky_Notes1.Draw();
	m_Sky_Notes3.Draw();
	m_Sky_Notes4.Draw();
	m_TextSprite.Draw();
}

void CStage::Finalize(void)
{
	m_Main_BackGround.Delete();
	m_Main_BackGround1.Delete();
	m_Sky_Notes.Delete();
	m_Sky_Notes1.Delete();
	m_Sky_Notes3.Delete();
	m_Sky_Notes4.Delete();
	m_TextSprite.Delete();
}

float
CStage::
GetGroundLine(void) const
{
	return m_ground_line;
}

float
CStage::
GetGravity(void) const
{
	return m_gravity * aqua::GetDeltaTimeScale();
}

