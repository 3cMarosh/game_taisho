#include "note2_effect.h"

/*
 *  �R���X�g���N�^
 */
CNotes2Effect::CNotes2Effect(aqua::IGameObject* parent)
	: IEffect(parent, "NotesEffect")
{
}

/*
 *  ������
 */
void CNotes2Effect::Initialize(const aqua::CVector2& position)
{
	m_Sprite.Create("data\\Shiro1.png");
	m_Sprite.position = aqua::CVector2(0.0f,240.0f);
}

/*
 *  �X�V
 */
void CNotes2Effect::Update()
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
void CNotes2Effect::Draw()
{
	m_Sprite.Draw();
}

/*
 *  ���
 */
void CNotes2Effect::Finalize()
{
	m_Sprite.Delete();
}
