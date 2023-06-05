#include "character.h"
#include"..\..\burret_manager\burret_manager.h"
#include"game_object/player/IPlayer.h"

const float CCharacter::m_friction = 0.95f;


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
}

void CCharacter::Update(void)
{
	
	Input();
	Move();
}

void CCharacter::Input(void)
{
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
	(aqua::keyboard::KEY_ID::SPACE))
	{
		m_bullet_manager->Create(BULLET_ID::NORMAL, GetCenterPosition(),m_category);
	}
}

void CCharacter::Move(void)
{
	m_CharacterSprite.position.y += m_move_speed;
}

