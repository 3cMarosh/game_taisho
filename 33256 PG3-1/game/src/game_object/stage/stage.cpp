#include "stage.h"

const float CStage::m_ground_line = 600.0f;
const float CStage::m_gravity = 9.8f;


CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
	{
	}

void CStage::Initialize(void)
{
	m_Main_BackGround.Create("data\\main_haikei.png");

}

void
CStage::
Update(void)
{
}

void CStage::Draw(void)
{
	m_Main_BackGround.Draw();
	m_Main_BackGround1.Draw();
	m_Sky_Notes.Draw();
	m_Sky_Notes1.Draw();
	m_TextSprite.Draw();
	m_text.Draw();
}

void CStage::Finalize(void)
{
	m_Main_BackGround.Delete();
	m_Main_BackGround1.Delete();
	m_Sky_Notes.Delete();
	m_Sky_Notes1.Delete();
	m_TextSprite.Delete();
	m_text.Delete();
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

