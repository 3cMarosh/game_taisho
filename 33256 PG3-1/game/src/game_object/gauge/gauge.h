#pragma once
#include"aqua.h"
#include"..\player\IPlayer.h"

class CGauge :public aqua::IGameObject
{
public:
	CGauge(aqua::IGameObject* parent);
	~CGauge() = default;

	void Setup(CATEGORY_ID category);
	void Initialize();
	void Update();
	void Draw();
	void Finalize();

private:

	aqua::CSprite			m_GaugeSprite;
	aqua::CSprite			m_GaugeMAXSprite;
	aqua::CSprite			m_2GaugeSprite;
	aqua::CSprite			m_2GaugeMAXSprite;
	
	aqua::CTimer			m_CostTimer;

	float					m_cost;

	CATEGORY_ID				m_category;

	IPlayer* m_1Ppointer;
	IPlayer* m_2Ppointer;
};