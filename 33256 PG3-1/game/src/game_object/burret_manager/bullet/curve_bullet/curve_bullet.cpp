#include "curve_bullet.h"
#include"..\Ibullet.h"
#include"game_object/scene_manager/scene_manager.h"


CCurveBullet::CCurveBullet(aqua::IGameObject* parent)
	:IBullet(parent,"CurveBullet")
	,m_CurveFlag(false)
	,m_sin(0)
{
}

void CCurveBullet::Initialize(void)
{
	m_bullet_sprite.Create("data\\bullet.png");
	m_bullet_sprite.position = m_b_position;
	m_bullet_speed ;
	m_Character_p = (IPlayer*)aqua::FindGameObject("Character");
	m_2Character_p = (IPlayer*)aqua::FindGameObject("Character2");
}

void CCurveBullet::Update(void)
{
	m_sin += 2;            
	IBullet::Update();

	aqua::CVector2 BulletCenter =

	{
		m_bullet_sprite.position.x + m_bullet_sprite.GetTextureWidth() / 2.0f,
		m_bullet_sprite.position.y + m_bullet_sprite.GetTextureHeight() / 2.0f
	};

	if ((BulletCenter - m_Character_p->GetCenterPosition()).Length() <= 32.0f && m_bullet_category != CATEGORY_ID::PLAYER1)
	{

		m_bullet_sprite.Delete();
		((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::RESULT);

	}
	if ((BulletCenter - m_2Character_p->GetCenterPosition()).Length() <= 32.0f && m_bullet_category != CATEGORY_ID::PLAYER2)
	{
		m_bullet_sprite.Delete();
		((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::RESULT);

	}

	m_bullet_sprite.position.x += cos(aqua::DegToRad(m_angle));
	m_bullet_sprite.position.y += sin(aqua::DegToRad(m_sin));

}

void CCurveBullet::Draw(void)
{
	m_bullet_sprite.Draw();
}

void CCurveBullet::Finlalize(void)
{
	m_bullet_sprite.Delete();
}

void CCurveBullet::SetUp(aqua::CVector2 position)
{
}
