#pragma once

#include "aqua.h"

enum class ENEMY_ID
{
	SKY,

};

struct ENEMY_DATA
{
	ENEMY_ID Enemy;
	float  CreateInterval;
};


class CEnemyManager : public aqua::IGameObject
{
public:
	CEnemyManager(aqua::IGameObject* parent);	//! コンストラクタ
	~CEnemyManager() = default;					//! デストラクタ

	void Initialize(void)override;
	void Update() override;
	void Draw() override;

	void Create(ENEMY_ID id);

private:

	std::vector<ENEMY_DATA>m_Enemy_Table;

};
