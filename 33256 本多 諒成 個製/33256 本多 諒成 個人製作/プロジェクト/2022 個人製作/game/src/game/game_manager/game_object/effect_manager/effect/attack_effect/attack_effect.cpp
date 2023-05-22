#include "attack_effect.h"

/*
 *  �R���X�g���N�^
 */
CAttackEffect::CAttackEffect(aqua::IGameObject* parent)
	: IEffect(parent, "AttackEffect")
{
}

/*
 *  ������
 */
void CAttackEffect::Initialize(const aqua::CVector2& position)
{
	m_Sprite.Create("data\\result_flame.png");
}

/*
 *  �X�V
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
 *  �`��
 */
void CAttackEffect::Draw()
{
	m_Sprite.Draw();
}

/*
 *  ���
 */
void CAttackEffect::Finalize()
{
	m_Sprite.Delete();
}
