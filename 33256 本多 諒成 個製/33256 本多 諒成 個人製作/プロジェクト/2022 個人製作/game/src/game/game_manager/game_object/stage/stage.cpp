#include "stage.h"

const float CStage::m_ground_line = 600.0f;
const float CStage::m_gravity = 9.8f;


CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Stage")
{
}

void CStage::Initialize(void)
{
	m_Main_BackGround.Create("data\\BG.png");
	m_Main_BackGround1.Create("data\\BG.png");

	m_Sky_Notes1.Create("data\\sky_notes_touka.png");
	m_Sky_Notes2.Create("data\\sky_notes_touka.png");
	m_Sky_Notes3.Create("data\\sky_notes_touka.png");
	m_Sky_Notes4.Create("data\\sky_notes_touka.png");

	m_Main_BackGround.position = aqua::CVector2(0.0f,0.0f);
	m_Main_BackGround1.position = aqua::CVector2(1280.0f, 0.0f);
	m_Sky_Notes1.position = aqua::CVector2::ZERO;
	m_Sky_Notes2.position = aqua::CVector2(1280.0f, 0.0f);
	m_Sky_Notes3.position = aqua::CVector2(0.0f,579.0f);
	m_Sky_Notes4.position = aqua::CVector2(1280.0f, 579.0f);
}

void
CStage::
Update(void)
{
	m_Main_BackGround.position.x -= 7.0f;
	m_Main_BackGround1.position.x -= 7.0f;
	m_Sky_Notes1.position.x -=15.0f;
	m_Sky_Notes2.position.x -=15.0f;
	m_Sky_Notes3.position.x -=15.0f;
	m_Sky_Notes4.position.x -=15.0f;

	if (m_Main_BackGround.position.x < -1280.0f)
	{
		m_Main_BackGround.position.x = 1280.0f + (m_Main_BackGround.position.x + 1280.0f);
	}
	if (m_Main_BackGround1.position.x < -1280.0f)
	{
		m_Main_BackGround1.position.x = 1280.0f + (m_Main_BackGround1.position.x + 1280.0f);
	}


	if (m_Sky_Notes1.position.x < -1280.0f)
	{
		m_Sky_Notes1.position.x = 1280.0f + (m_Sky_Notes1.position.x + 1280.0f);
	}
	if (m_Sky_Notes2.position.x < -1280.0f)
	{
		m_Sky_Notes2.position.x = 1280.0f + (m_Sky_Notes2.position.x + 1280.0f);
	}
	if (m_Sky_Notes3.position.x < -1280.0f)
	{
		m_Sky_Notes3.position.x = 1280.0f + (m_Sky_Notes3.position.x + 1280.0f);
	}
	if (m_Sky_Notes4.position.x < -1280.0f)
	{
		m_Sky_Notes4.position.x = 1280.0f + (m_Sky_Notes4.position.x + 1280.0f);
	}
}

void CStage::Draw(void)
{
	m_Main_BackGround.Draw();
	m_Main_BackGround1.Draw();
	//m_Sky_Notes1.Draw();
	//m_Sky_Notes2.Draw();
	//m_Sky_Notes3.Draw();
	//m_Sky_Notes4.Draw();
}

void CStage::Finalize(void)
{
	m_Main_BackGround.Delete();
	m_Main_BackGround1.Delete();
	m_Sky_Notes1.Delete();
	m_Sky_Notes2.Delete();
	m_Sky_Notes3.Delete();
	m_Sky_Notes4.Delete();
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

