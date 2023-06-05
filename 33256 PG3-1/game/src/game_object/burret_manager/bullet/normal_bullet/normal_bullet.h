#pragma once
#include"aqua.h"
#include"..\Ibullet.h"
class CNormalBullet
	:public IBullet
{
public:
	CNormalBullet(aqua::IGameObject* parent);
	~CNormalBullet(void) = default;

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finlalize(void);
	void SetUp(aqua::CVector2 position);
private:
	bool			m_NormalFlag;
	int             m_normal_cost;
	aqua::CSprite  m_bullet_sprite;
};