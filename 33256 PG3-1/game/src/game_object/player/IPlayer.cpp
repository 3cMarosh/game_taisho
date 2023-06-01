#include "IPlayer.h"

IPlayer::IPlayer(aqua::IGameObject* parent,const std::string& name)
	:aqua::IGameObject(parent,name)
	,m_move_speed(0)
{
}


void IPlayer::Update(void)
{
	InPut();
	Move();
}

void IPlayer::Draw(void)
{
	m_CharacterSprite.Draw();
}

void IPlayer::Finalize(void)
{
	m_CharacterSprite.Delete();
}


void IPlayer::Move(void)
{
	m_CharacterSprite.position.y += m_move_speed;
}

aqua::CVector2 IPlayer::GetCenterPosition(void)
{
	aqua::CVector2 v;

	v.x = m_CharacterSprite.position.x + m_CharacterSprite.GetTextureWidth() / 2.0f;
	v.y = m_CharacterSprite.position.y + m_CharacterSprite.GetTextureHeight() / 2.0f;
	return v;

}
