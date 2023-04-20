#pragma once

#include"aqua.h"
class IUiCompornent :public aqua::IGameObject
{
public:
	IUiCompornent(aqua::IGameObject* parent, const std::string& object_name);
	virtual~IUiCompornent() = default;

private:
	static const std::string    m_ui_category;


};
