#pragma once
#include"aqua.h"
 
enum class CATEGORY_ID
{
	PLAYER1,
	PLAYER2
};

class IPlayer
	:public aqua::IGameObject
{
public:
	IPlayer(aqua::IGameObject* parent ,const std::string& name);
	~IPlayer(void) = default;

	virtual void Update(void);
	virtual void Draw(void);
	virtual void Finalize(void);
	int Getcost();

	aqua::CVector2 GetCenterPosition(void);
	CATEGORY_ID GetCategory(void);
protected:

	aqua::CSprite m_CharacterSprite;
	float         m_move_speed;
	int				m_attack_cost;

	CATEGORY_ID   m_category;
	
};