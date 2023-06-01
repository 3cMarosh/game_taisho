#include "normal_bullet.h"
#include"..\Ibullet.h"

CNormalBullet::CNormalBullet(aqua::IGameObject* parent)
	:IBullet(parent,"NormalBullet")
{
}

void CNormalBullet::Initialize(void)
{
	m_bullet_sprite.Create("data\\abe.png");
	m_bullet_sprite.position = m_b_position;
}

void CNormalBullet::Update(void)
{
	m_bullet_sprite.position.x += 3.0f;
	if (m_bullet_sprite.position.x >= 1280.0f)
	{
		m_bullet_sprite.Delete();
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
