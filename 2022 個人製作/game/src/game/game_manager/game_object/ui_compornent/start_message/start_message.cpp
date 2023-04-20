#include "start_message.h"

const std::string CStartMessage::m_object_name = "StartMessage";

const float CStartMessage::m_wait_time = 1.5f;
const float CStartMessage::m_easing_limit = 0.5f;
const float CStartMessage::m_view_limit = 1.0f;
const float CStartMessage::m_min_scale = 0.0f;
const float CStartMessage::m_max_scale = 1.2f;


CStartMessage::CStartMessage(aqua::IGameObject* parent)
	:IUiCompornent(parent, m_object_name)
	, m_ElapsedTime(0.0)
{
}

void CStartMessage::Initialize(void)
{
	//�^�C�}�[�ݒ�
	m_WaitTimer.Setup(m_wait_time);


	m_Sprite.Create("data\\start.png");

	m_Sprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_Sprite.GetTextureHeight() / 2.0f;
	m_Sprite.anchor.x = (float)m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.anchor.y = (float)m_Sprite.GetTextureHeight() / 2.0f;
	m_Sprite.scale = aqua::CVector2::ZERO;



}

void CStartMessage::Update(void)
{
	//���Ԃ��v��
	m_ElapsedTime += aqua::GetDeltaTime();

	if (m_ElapsedTime > m_view_limit)
	{
		DeleteObject();

		//�����ɃT�E���h�̏���

	}
	float time = m_ElapsedTime > m_easing_limit ? m_easing_limit : m_ElapsedTime;
	float scale = abs(aqua::easing::InBack(time, m_easing_limit, m_min_scale, m_max_scale));
	m_Sprite.scale = aqua::CVector2(scale, scale);


	//�ݒ肵�����ԂɂȂ�����
	if (m_WaitTimer.Finished())
	{
		DeleteObject();

	}

	return;


}

void CStartMessage::Draw(void)
{
	m_Sprite.Draw();
}

void CStartMessage::Finalize(void)
{
	m_Sprite.Delete();
}
