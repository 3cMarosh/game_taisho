#include "stage.h"



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
	m_text.Draw();
}

void CStage::Finalize(void)
{
	m_Main_BackGround.Delete();
	m_text.Delete();
}


