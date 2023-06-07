#include "character2.h"
#include"..\..\burret_manager\burret_manager.h"
#include"game_object/player/IPlayer.h"

const float CCharacter2::m_friction = 0.95f;
const int	CCharacter2::m_max_life = 1;


CCharacter2::CCharacter2(aqua::IGameObject* parent)
	:IPlayer(parent,"Character2")
	,m_move_speed(0)
{
}

void CCharacter2::Initialize(void)
{
	m_CharacterSprite.Create("data\\character.png");
	m_CharacterSprite.position = aqua::CVector2(800.0f, 350.0f);
	m_bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
	m_category = CATEGORY_ID::PLAYER2;
	m_Life = m_max_life;
}

void CCharacter2::Update(void)
{
	Input();
	Move();
}

void CCharacter2::Input(void)
{
	if (m_CharacterSprite.position.y < 0)
	{
		m_CharacterSprite.position.y = 0;
	}
	if (m_CharacterSprite.position.y > 1216)
	{
		m_CharacterSprite.position.y = 1216;
	}


	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::P))
	{
		m_move_speed = -1;
	}
	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::L))
	{
		m_move_speed = +1;
	}

	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::O))
	{
		m_bullet_manager->Create(BULLET_ID::NORMAL, GetCenterPosition(),m_category);
	}
	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::K))
	{
		m_bullet_manager->Create(BULLET_ID::CURVE, GetCenterPosition(),m_category);
	}
	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::M))
	{
		m_bullet_manager->Create(BULLET_ID::CLEAR, GetCenterPosition(),m_category);
	}
}


void CCharacter2::Move(void)
{
	m_CharacterSprite.position.y += m_move_speed;
}

aqua::CVector2 CCharacter2::GetCenterPosition()
{
	return
	{
		m_CharacterSprite.position.x + m_CharacterSprite.GetTextureWidth()/2.0f,
		m_CharacterSprite.position.y + m_CharacterSprite.GetTextureHeight() / 2.0f,
	};
}

