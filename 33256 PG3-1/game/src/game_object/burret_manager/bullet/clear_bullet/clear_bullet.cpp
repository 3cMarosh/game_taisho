#include "clear_bullet.h"
#include"game_object/scene_manager/scene_manager.h"

CClearBullet::CClearBullet(aqua::IGameObject* parent)
	:IBullet(parent,"ClearBullet")
	,m_ClearFlag(false)
{
}

void CClearBullet::Initialize(void)
{
	m_bullet_sprite.Create("data\\bullet.png");
	m_bullet_sprite.position = m_b_position;
	m_bullet_speed;
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character");
	m_2Character_p = (IPlayer*)aqua::FindGameObject("Character2");
}

void CClearBullet::Update(void)
{
	IBullet::Update();

	m_bullet_sprite.color.alpha -=2;
	if (m_bullet_sprite.color.alpha == 255)
	{
		m_bullet_sprite.color.alpha +=3;
	}

	aqua::CVector2 BulletCenter =
	{
		m_bullet_sprite.position.x + m_bullet_sprite.GetTextureWidth() / 2.0f,
		m_bullet_sprite.position.y + m_bullet_sprite.GetTextureHeight() / 2.0f
	};

	if ((BulletCenter - m_Character_p->GetCenterPosition()).Length() <= 32.0f &&m_bullet_category != CATEGORY_ID::PLAYER1 )
	{
		m_bullet_sprite.Delete();
		((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::RESULT);

	}
	if ((BulletCenter - m_2Character_p->GetCenterPosition()).Length() <= 32.0f&& m_bullet_category != CATEGORY_ID::PLAYER2)
	{
		m_bullet_sprite.Delete();
		((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::RESULT);

	}
	
	m_bullet_sprite.position.x += cos(aqua::DegToRad(m_angle));
	m_bullet_sprite.position.y += sin(aqua::DegToRad(m_angle));

}

void CClearBullet::Draw(void)
{
	m_bullet_sprite.Draw();
}

void CClearBullet::Finlalize(void)
{
	m_bullet_sprite.Delete();
}

void CClearBullet::SetUp(aqua::CVector2 position)
{
}
