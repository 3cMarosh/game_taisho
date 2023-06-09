#include "stage.h"



CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
	{
	}

void CStage::Initialize(void)
{
	m_Main_BackGround.Create("data\\main_haikei.png");
	m_1PGuage.Create("data\\gauge.png");
	m_2PGuage.Create("data\\gauge.png");
	m_2PGuage.position.x = aqua::GetWindowWidth() - 100;

}

void
CStage::
Update(void)
{
}

void CStage::Draw(void)
{
	m_Main_BackGround.Draw();
	m_1PGuage.Draw();
	m_2PGuage.Draw();
	m_text.Draw();
}

void CStage::Finalize(void)
{
	m_Main_BackGround.Delete();
	m_1PGuage.Delete();
	m_2PGuage.Delete();
	m_text.Delete();
}


