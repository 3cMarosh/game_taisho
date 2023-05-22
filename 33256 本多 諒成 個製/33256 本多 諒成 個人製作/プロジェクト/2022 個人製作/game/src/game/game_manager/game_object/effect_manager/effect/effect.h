#pragma once
#include"aqua.h"

class IEffect : public aqua::IGameObject
{
public:
	IEffect(aqua::IGameObject* parent, const std::string& object_name);

	virtual ~IEffect() = default;

	virtual void Initialize(const aqua::CVector2& position);

protected:
	aqua::CVector2	m_Position;
	aqua::CSprite m_Sprite;

private:
	void Initialize(void)override;

	static const std::string m_object_category;
};