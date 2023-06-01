#pragma once
#include"aqua.h"
class IPlayer
	:public aqua::IGameObject
{
public:
	IPlayer(aqua::IGameObject* parent ,const std::string& name);
	~IPlayer(void) = default;
	virtual void Initialize(void) = 0;
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Finalize(void);

	virtual void InPut(void) = 0;
	virtual void Move(void);
	aqua::CVector2 GetCenterPosition(void);

protected:
	aqua::CSprite m_CharacterSprite;
	float                     m_move_speed;

	
};