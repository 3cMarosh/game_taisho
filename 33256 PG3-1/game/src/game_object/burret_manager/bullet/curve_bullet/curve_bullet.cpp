#include "curve_bullet.h"
#include"..\Ibullet.h"

const int CCurveBullet::m_max_life = 1;

CCurveBullet::CCurveBullet(aqua::IGameObject* parent)
	:IBullet(parent,"CurveBullet")
	,m_CurveFlag(false)
	,m_curve_cost(0)
{
}

void CCurveBullet::Initialize(void)
{
	m_bullet_sprite.Create("data\\bea.png");
	m_bullet_sprite.position = m_b_position;
	m_bullet_speed;
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character");
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character2");

}

void CCurveBullet::Update(void)
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

	m_curve_cost = +1;

	if (m_bullet_cost < 2)
	{
		m_CurveFlag = true;
	}

}

void CCurveBullet::Draw(void)
{
	m_bullet_sprite.Draw();

}

void CCurveBullet::Finlalize(void)
{
	m_bullet_sprite.Delete();
}

void CCurveBullet::SetUp(aqua::CVector2 position)
{
}
