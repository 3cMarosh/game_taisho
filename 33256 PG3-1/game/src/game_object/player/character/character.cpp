#include "character.h"
#include"..\..\burret_manager\burret_manager.h"
#include"game_object/player/IPlayer.h"

const float CCharacter::m_friction = 0.95f;


CCharacter::CCharacter(aqua::IGameObject* parent)
	:IPlayer(parent,"Character")
{
}

void CCharacter::Initialize(void)
{
	m_CharaSprite.Create("data\\character.png");
	m_CharaSprite.position = aqua::CVector2(150.0f, 350.0f);
}

void CCharacter::Update(void)
{
}

void CCharacter::Draw(void)
{
}


void CCharacter::Finalize(void)
{
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
		m_bullet_manager->Create(BULLET_ID::NORMAL, GetCenterPosition());
	}
}

void CCharacter::Move(void)
{
}

