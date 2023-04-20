#include "notes_effect.h"

const float CNotesEffect::m_fade_speed = 200.0f;

/*
 *  �R���X�g���N�^
 */
CNotesEffect::CNotesEffect(aqua::IGameObject* parent)
	: IEffect(parent, "NotesEffect")
{
}

/*
 *  ������
 */
void CNotesEffect::Initialize(const aqua::CVector2& position)
{
	m_Sprite.Create("data\\ef.png");
	m_Sprite.position = aqua::CVector2(0.0f,120.0f);
	m_FadeSpeed = 0.0f;
	m_Sprite.scale = aqua::CVector2(0.1f, 0.1f);
}

/*
 *  �X�V
 */
void CNotesEffect::Update()
{
	//int alpha = m_Sprite.color.alpha;
	//m_FadeSpeed = aqua::DegToRad(m_fade_speed) * aqua::GetDeltaTime();
	//alpha = (int)(abs(sin(m_FadeSpeed)) * (float)aqua::CColor::MAX_COLOR);
	//m_Sprite.color.alpha = (unsigned char)alpha;

	m_Sprite.color.alpha--;
	if (m_Sprite.color.alpha <= 0)
	{
		IGameObject::DeleteObject();
	}
}

/*
 *  �`��
 */
void CNotesEffect::Draw()
{
	m_Sprite.Draw();
}

/*
 *  ���
 */
void CNotesEffect::Finalize()
{
	m_Sprite.Delete();
}
