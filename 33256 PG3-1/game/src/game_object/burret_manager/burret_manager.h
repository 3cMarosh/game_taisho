#pragma once
#include"aqua.h"
#include"game_object/player/IPlayer.h"

enum class BULLET_ID
{
	NORMAL,
	CURVE,
};

class CBulletManager
	:public aqua::IGameObject
{
public:
	CBulletManager(aqua::IGameObject* parent);
	~CBulletManager(void) = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;
	void Create(BULLET_ID bullet,aqua::CVector2 create_position,CATEGORY_ID category);

private:


};