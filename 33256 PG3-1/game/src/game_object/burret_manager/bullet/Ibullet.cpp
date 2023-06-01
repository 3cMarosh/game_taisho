#include "Ibullet.h"

IBullet::IBullet(aqua::IGameObject* parent,  const std::string& bullet_name)
	:aqua::IGameObject(parent,bullet_name)
{
}

void IBullet::SetUp(aqua::CVector2 position)
{
	m_b_position = position;
	Initialize();

}
