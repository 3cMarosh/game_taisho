#include "normal_bullet.h"
#include"..\Ibullet.h"

const int CNormalBullet::m_max_life = 1;

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
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character");
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character2");
}

void CNormalBullet::Update(void)
{
	IBullet::Update();

	aqua::CVector2 BulletCenter =
	{
		m_bullet_sprite.position.x + m_bullet_sprite.GetTextureWidth()/2.0f,
		m_bullet_sprite.position.y + m_bullet_sprite.GetTextureHeight()/2.0f
	};

	if ((BulletCenter - m_Character_p->GetCenterPosition()).Length() <= 16.0f)
	{
		m_bullet_sprite.Delete();
	}

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

