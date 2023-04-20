#include "note4_effect.h"

/*
 *  コンストラクタ
 */
CNotes4Effect::CNotes4Effect(aqua::IGameObject* parent)
	: IEffect(parent, "NotesEffect")
{
}

/*
 *  初期化
 */
void CNotes4Effect::Initialize(const aqua::CVector2& position)
{
	m_Sprite.Create("data\\Shiro1.png");
	m_Sprite.position = aqua::CVector2(0.0f,480.0f);
}

/*
 *  更新
 */
void CNotes4Effect::Update()
{

	m_Sprite.color.alpha--;
	if (m_Sprite.color.alpha <= 0)
	{
		IGameObject::DeleteObject();
	}
}

/*
 *  描画
 */
void CNotes4Effect::Draw()
{
	m_Sprite.Draw();
}

/*
 *  解放
 */
void CNotes4Effect::Finalize()
{
	m_Sprite.Delete();
}
