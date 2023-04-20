#include"effect.h"

const std::string IEffect::m_object_category = "Effect";

IEffect::IEffect(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent, object_name, m_object_category)
	, m_Position(aqua::CVector2::ZERO)
{

}

void IEffect::Initialize(const aqua::CVector2& position)
{
	m_Position = position;
}

void IEffect::Initialize(void)
{
}

