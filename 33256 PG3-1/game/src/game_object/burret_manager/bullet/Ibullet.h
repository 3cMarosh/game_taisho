#pragma once
#include"aqua.h"
class IBullet
	:public aqua::IGameObject
{
public:
	IBullet(aqua::IGameObject* parent,const std::string& bullet_name);
	~IBullet(void) = default;

	void SetUp(aqua::CVector2 position);

protected:
	aqua::CVector2 m_b_position;
};