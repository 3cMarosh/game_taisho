#include "note3_effect.h"

/*
 *  コンストラクタ
 */
CNotes3Effect::CNotes3Effect(aqua::IGameObject* parent)
	: IEffect(parent, "NotesEffect")
{
}

/*
 *  初期化
 */
void CNotes3Effect::Initialize(const aqua::CVector2& position)
{
	m_Sprite.Create("data\\Shiro1.png");
	m_Sprite.position = aqua::CVector2(0.0f,360.0f);
}

/*
 *  更新
 */
void CNotes3Effect::Update()
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
void CNotes3Effect::Draw()
{
	m_Sprite.Draw();
}

/*
 *  解放
 */
void CNotes3Effect::Finalize()
{
	m_Sprite.Delete();
}
