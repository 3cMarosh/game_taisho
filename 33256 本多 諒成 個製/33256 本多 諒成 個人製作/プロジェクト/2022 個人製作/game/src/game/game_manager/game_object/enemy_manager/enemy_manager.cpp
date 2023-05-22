#include "enemy_manager.h"
#include"enemy/enemy_sky/enemy_sky.h"
#include"..\scene_manager\scene\game_main_scene\game_main_scene.h"

CEnemyManager::CEnemyManager(aqua::IGameObject* parent)
	:IGameObject(parent ,"EnemyManager")
{
}

void CEnemyManager::Initialize(void)
{
	aqua::CCSVLoader csv;
	csv.Load("data\\enemy.csv");

	for (int i = 0; i < csv.GetRows(); ++i)
	{
		ENEMY_DATA Enemy_Data;
		Enemy_Data.Enemy = (ENEMY_ID)csv.GetInteger(i, 0);
		Enemy_Data.CreateInterval = csv.GetFloat(i, 1);
		m_Enemy_Table.push_back(Enemy_Data);
	}

	csv.Unload();
}

void CEnemyManager::Update()
{
	IGameObject::Update();

	if (!m_Enemy_Table.empty())
	{
		if (m_Enemy_Table[0].CreateInterval < ((CGameMainScene*)aqua::FindGameObject("GameMainScene"))->GetTime())
		{
			Create(ENEMY_ID::SKY);
			m_Enemy_Table.erase(m_Enemy_Table.begin());

			
		}
	}
}

void CEnemyManager::Draw()
{
	IGameObject::Draw();
}

void CEnemyManager::Create(ENEMY_ID id)
{
	IEnemy* Enemy = nullptr;

	switch (id)
	{
	case ENEMY_ID::SKY: Enemy = aqua::CreateGameObject<CEnemySky>(this);
		break;
	}

	Enemy->Initialize();
}

