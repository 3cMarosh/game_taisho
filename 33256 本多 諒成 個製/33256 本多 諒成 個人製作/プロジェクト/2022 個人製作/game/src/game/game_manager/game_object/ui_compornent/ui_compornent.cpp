#include "ui_compornent.h"

const  std::string IUiCompornent::m_ui_category = "UiCompornent";

IUiCompornent::IUiCompornent(aqua::IGameObject* parent, const std::string& object_name)
	:IGameObject(parent, object_name,m_ui_category)
{
}
