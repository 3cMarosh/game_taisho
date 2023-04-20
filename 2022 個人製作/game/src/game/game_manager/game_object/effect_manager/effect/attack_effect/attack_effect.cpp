#include "attack_effect.h"

/*
 *  コンストラクタ
 */
CAttackEffect::CAttackEffect(aqua::IGameObject* parent)
	: IEffect(parent, "AttackEffect")
{
}

/*
 *  初期化
 */
void CAttackEffect::Initialize(const aqua::CVector2& position)
{
	m_Sprite.Create("data\\damage.png");
}

/*
 *  更新
 */
void CAttackEffect::Update()
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
void CAttackEffect::Draw()
{
	m_Sprite.Draw();
}

/*
 *  解放
 */
void CAttackEffect::Finalize()
{
	m_Sprite.Delete();
}
