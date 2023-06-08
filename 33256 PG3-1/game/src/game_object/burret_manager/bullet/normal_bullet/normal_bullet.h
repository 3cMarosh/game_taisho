#pragma once
#include"aqua.h"
#include"..\Ibullet.h"
class CCharacter;
class CCharacter2;

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

	IPlayer*		m_Character_p;
	IPlayer*		m_2Character_p;
	bool			m_NormalFlag;
	bool			m_DeleteFlag;
	int             m_normal_cost;
	int				m_bullet_life;
	int				m_Life;
	static const int m_max_life;

	aqua::CSprite	m_bullet_sprite;
};