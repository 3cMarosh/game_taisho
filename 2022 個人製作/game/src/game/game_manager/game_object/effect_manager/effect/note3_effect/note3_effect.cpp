#include "note3_effect.h"

/*
 *  �R���X�g���N�^
 */
CNotes3Effect::CNotes3Effect(aqua::IGameObject* parent)
	: IEffect(parent, "NotesEffect")
{
}

/*
 *  ������
 */
void CNotes3Effect::Initialize(const aqua::CVector2& position)
{
	m_Sprite.Create("data\\Shiro1.png");
	m_Sprite.position = aqua::CVector2(0.0f,360.0f);
}

/*
 *  �X�V
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
 *  �`��
 */
void CNotes3Effect::Draw()
{
	m_Sprite.Draw();
}

/*
 *  ���
 */
void CNotes3Effect::Finalize()
{
	m_Sprite.Delete();
}
