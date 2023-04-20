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

	m_BarSprite.Create("data\\barr.png");
	m_BarSprite.position = aqua::CVector2(100.0f, 0.0f);
}

void CCharacter::Update(void)
{
	Input();
}

void CCharacter::Draw(void)
{
	m_BarSprite.Draw();
}

void CCharacter::Finalize(void)
{
	m_BarSprite.Delete();
}

void CCharacter::Input(void)
{
}

void CCharacter::Output(void)
{
}

aqua::CVector2 CCharacter::GetCenterPosition()
{
	return
	{
		m_BarSprite.position.x + m_BarSprite.GetTextureWidth(),
		m_BarSprite.position.y + m_BarSprite.GetTextureHeight(),
	};
}
