#include "character.h"
#include"..\effect_manager\effect_manager.h"
#include"..\enemy_manager\enemy\enemy_sky\enemy_sky.h"
const float CCharacter::m_friction = 0.95f;


CCharacter::CCharacter(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Character")
{
}

void CCharacter::Initialize(void)
{
	m_CharaSprite.Create("data\\barr.png");
	m_CharaSprite.position.x = 150.0f;
	m_CharaSprite.GetTextureHeight();
	m_CharaSprite.GetTextureWidth();

	m_Enemy_p = (CEnemy*)aqua::FindGameObject("EnemySky");
}

void CCharacter::Update(void)
{
	Input();
}

void CCharacter::Draw(void)
{
	m_CharaSprite.Draw();
}

void CCharacter::Finalize(void)
{
	m_CharaSprite.Delete();
}

void CCharacter::Input(void)
{
	//if(aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::A))
}

void CCharacter::Output(void)
{
}

aqua::CVector2 CCharacter::GetCenterPosition()
{
	return
	{
		m_CharaSprite.position.x + m_CharaSprite.GetTextureWidth(),
		m_CharaSprite.position.y + m_CharaSprite.GetTextureHeight()
	};
}
