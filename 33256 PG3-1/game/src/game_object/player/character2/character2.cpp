#include "character2.h"
#include"..\..\burret_manager\burret_manager.h"
#include"game_object/player/IPlayer.h"

const float CCharacter2::m_friction = 0.95f;


CCharacter2::CCharacter2(aqua::IGameObject* parent)
	:IPlayer(parent,"Character2")
{
}

void CCharacter2::Initialize(void)
{
	m_CharaSprite.Create("data\\character.png");
	m_CharaSprite.position = aqua::CVector2(800.0f, 350.0f);
	m_CharaSprite.GetTextureHeight();
	m_CharaSprite.GetTextureWidth();
	m_bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
}

void CCharacter2::Update(void)
{
}

void CCharacter2::Draw(void)
{
}


void CCharacter2::Finalize(void)
{
}

void CCharacter2::Input(void)
{
	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::O))
	{
		m_move_speed = -1;
	}
	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::L))
	{
		m_move_speed = +1;
	}

	if (aqua::keyboard::Trigger
	(aqua::keyboard::KEY_ID::SPACE))
	{
		m_bullet_manager->Create(BULLET_ID::NORMAL, GetCenterPosition());
	}
}

void CCharacter2::Move(void)
{
}

