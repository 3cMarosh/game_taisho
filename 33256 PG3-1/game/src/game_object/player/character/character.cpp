#include "character.h"
#include"..\..\burret_manager\burret_manager.h"
#include"game_object/player/IPlayer.h"

const float CCharacter::m_friction = 0.95f;
const int	CCharacter::m_max_life = 1;


CCharacter::CCharacter(aqua::IGameObject* parent)
	:IPlayer(parent,"Character")
	,m_move_speed(0)
{
}

void CCharacter::Initialize(void)
{
	m_CharacterSprite.Create("data\\character.png");
	m_CharacterSprite.position = aqua::CVector2(150.0f, 350.0f);
	m_bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
	m_category = CATEGORY_ID::PLAYER1;
	m_Life = m_max_life;
}

void CCharacter::Update(void)
{
	Input();
	Move();
}

void CCharacter::Input(void)
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
	(aqua::keyboard::KEY_ID::UP))
	{
		m_move_speed = -1;
	}
	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::DOWN))
	{
		m_move_speed = +1;
	}

	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::Q))
	{
		m_bullet_manager->Create(BULLET_ID::NORMAL, GetCenterPosition(),m_category);
	}
	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::A))
	{
		m_bullet_manager->Create(BULLET_ID::CURVE, GetCenterPosition(), m_category);
	}
}

void CCharacter::Move(void)
{
	m_CharacterSprite.position.y += m_move_speed;
}

aqua::CVector2 CCharacter::GetCenterPosition()
{
	return
	{
		m_CharacterSprite.position.x + m_CharacterSprite.GetTextureWidth()/2.0f,
		m_CharacterSprite.position.y + m_CharacterSprite.GetTextureHeight()/2.0f,
	};
}

