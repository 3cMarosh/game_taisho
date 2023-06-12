#include "gauge.h"

CGauge::CGauge(aqua::IGameObject* parent)
	:IGameObject(parent,"CGauge")
{
}

void CGauge::Setup(CATEGORY_ID category)
{
	m_category = category;
}

void CGauge::Initialize()
{
	m_GaugeSprite.Create("data\\gauge.png");
	m_2GaugeSprite.Create("data\\gauge.png");
	m_GaugeMAXSprite.Create("data\\gauge_max.png");
	m_2GaugeMAXSprite.Create("data\\gauge_max.png");

	m_1Ppointer = ((IPlayer*)aqua::FindGameObject("Character"));
	m_2Ppointer = ((IPlayer*)aqua::FindGameObject("Character2"));

	m_2GaugeSprite.position.x = aqua::GetWindowWidth() - 100;
	m_2GaugeMAXSprite.position.x = aqua::GetWindowWidth() - 100;

}

void CGauge::Update()
{
	float cost = m_1Ppointer->Getcost();
	float cost2 = m_2Ppointer->Getcost();

	cost /= 10;
	cost2 /= 10;

	m_GaugeMAXSprite.rect.bottom = 720*cost;
	m_2GaugeMAXSprite.rect.bottom = 720*cost2;

}

void CGauge::Draw()
{
	m_GaugeSprite.		Draw();
	m_2GaugeSprite.		Draw();
	m_GaugeMAXSprite.	Draw();
	m_2GaugeMAXSprite.	Draw();
}

void CGauge::Finalize()
{
	m_GaugeSprite.Delete();
	m_2GaugeSprite.Delete();
	m_GaugeMAXSprite.Delete();
	m_2GaugeMAXSprite.Delete();

}
