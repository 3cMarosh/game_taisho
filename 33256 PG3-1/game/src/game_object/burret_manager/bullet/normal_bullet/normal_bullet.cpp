#include "normal_bullet.h"
#include"..\Ibullet.h"

CNormalBullet::CNormalBullet(aqua::IGameObject* parent)
	:IBullet(parent,"NormalBullet")
	,m_normal_cost(0)
	,m_NormalFlag(false)
{
}

void CNormalBullet::Initialize(void)
{
	m_bullet_sprite.Create("data\\abe.png");
	m_bullet_sprite.position = m_b_position;
	m_bullet_speed ;
}

void CNormalBullet::Update(void)
{
	IBullet::Update();

	m_bullet_sprite.position.x += cos(aqua::DegToRad(m_angle));
	m_bullet_sprite.position.y += sin(aqua::DegToRad(m_angle));

	m_normal_cost = +1;

	if (m_bullet_cost < 2)
	{
		m_NormalFlag = true;
	}
}

void CNormalBullet::Draw(void)
{
	m_bullet_sprite.Draw();
}

void CNormalBullet::Finlalize(void)
{
	m_bullet_sprite.Delete();
}

void CNormalBullet::SetUp(aqua::CVector2 position)
{
		
}
