#include "clear_bullet.h"

CClearBullet::CClearBullet(aqua::IGameObject* parent)
	:IBullet(parent,"ClearBullet")
	,m_ClearFlag(false)
	,m_clear_cost(0)
{
}

void CClearBullet::Initialize(void)
{
	m_bullet_sprite.Create("data\\eba.png");
	m_bullet_sprite.position = m_b_position;
	m_bullet_speed;
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character");
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character2");
}

void CClearBullet::Update(void)
{
	IBullet::Update();

	aqua::CVector2 BulletCenter =
	{
		m_bullet_sprite.position.x + m_bullet_sprite.GetTextureWidth() / 2.0f,
		m_bullet_sprite.position.y + m_bullet_sprite.GetTextureHeight() / 2.0f
	};

	if ((BulletCenter - m_Character_p->GetCenterPosition()).Length() <= 32.0f)
	{
		m_bullet_sprite.Delete();
	}
	
	m_bullet_sprite.position.x += cos(aqua::DegToRad(m_angle));
	m_bullet_sprite.position.y += sin(aqua::DegToRad(m_angle));

	m_clear_cost = +1;

		if (m_bullet_cost < 3)
		{
			m_ClearFlag = true;
		}
}

void CClearBullet::Draw(void)
{
	m_bullet_sprite.Draw();
}

void CClearBullet::Finlalize(void)
{
	m_bullet_sprite.Delete();
}

void CClearBullet::SetUp(aqua::CVector2 position)
{
}
