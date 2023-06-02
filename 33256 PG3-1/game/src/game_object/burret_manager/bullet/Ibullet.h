#pragma once
#include"aqua.h"
#include"game_object/player/IPlayer.h"
class IBullet
	:public aqua::IGameObject
{
public:
	IBullet(aqua::IGameObject* parent,const std::string& bullet_name);
	~IBullet(void) = default;

	void Update(void);
	void SetUp(aqua::CVector2 position,CATEGORY_ID category);

protected:
	aqua::CVector2  m_b_position;
	aqua::CVector2  m_bullet_speed;
	aqua::CSprite   m_bullet_sprite;
	float m_angle;
};