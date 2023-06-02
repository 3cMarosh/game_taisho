#include "Ibullet.h"

IBullet::IBullet(aqua::IGameObject* parent,  const std::string& bullet_name)
	:aqua::IGameObject(parent,bullet_name)
	,m_angle(0)
{
}

void IBullet::Update(void)
{
	if (m_bullet_sprite.position.x >= 1280.0f)
	{
		m_bullet_sprite.Delete();
	}
	if (m_bullet_sprite.position.x <= 0.0f)
	{
		m_bullet_sprite.Delete();
	}

}

void IBullet::SetUp(aqua::CVector2 position,CATEGORY_ID category)
{
	m_b_position = position;

	
	if (category == CATEGORY_ID::PLAYER2)
	{
		m_angle = 180.0f;
	}
	Initialize();

}
