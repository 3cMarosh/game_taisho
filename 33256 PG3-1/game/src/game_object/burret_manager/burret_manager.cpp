#include "burret_manager.h"
#include"bullet/Ibullet.h"
#include"bullet/normal_bullet/normal_bullet.h"
#include"bullet/curve_bullet/curve_bullet.h"
#include"bullet/clear_bullet/clear_bullet.h"


CBulletManager::CBulletManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BulletManager")
	{
	}

void CBulletManager::Initialize(void)
{
}

void CBulletManager::Update(void)
{
	IGameObject::Update();
}

void CBulletManager::Draw(void)
{
	IGameObject::Draw();
}

void CBulletManager::Finalize(void)
{
	IGameObject::Finalize();
}

void CBulletManager::Create(BULLET_ID bullet,aqua::CVector2 create_position,CATEGORY_ID category)
{
	IBullet* b = nullptr;

	switch (bullet)
	{
	case BULLET_ID::NORMAL:b = aqua::CreateGameObject<CNormalBullet>(this);
		break;
	case BULLET_ID::CURVE:b = aqua::CreateGameObject<CCurveBullet>(this);
		break;
	case BULLET_ID::CLEAR:b = aqua::CreateGameObject<CClearBullet>(this);
		break;
	}
	b->SetUp(create_position,category);


}
