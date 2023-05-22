#include "finish_message.h"

const std::string CFinishMessage::m_object_name = "FinishMessage";

const float CFinishMessage::m_wait_time = 1.5f;
const float CFinishMessage::m_easing_limit = 0.5f;
const float CFinishMessage::m_view_limit = 1.0f;
const float CFinishMessage::m_min_scale = 0.0f;
const float CFinishMessage::m_max_scale = 1.2f;



CFinishMessage::CFinishMessage(aqua::IGameObject* parent)
	:IUiCompornent(parent,m_object_name)
	, m_ElapsedTime(0.0f)
{
}

void CFinishMessage::Initialize(void)
{
	//タイマー設定
	m_WaitTimer.Setup(m_wait_time);


	m_Sprite.Create("data\\finish.png");

	m_Sprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_Sprite.GetTextureHeight() / 2.0f;
	m_Sprite.anchor.x = (float)m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.anchor.y = (float)m_Sprite.GetTextureHeight() / 2.0f;
	m_Sprite.scale = aqua::CVector2::ZERO;

	
}

void CFinishMessage::Update(void)
{
	//タイマー更新
	m_WaitTimer.Update();


	//時間を計測
	m_ElapsedTime += aqua::GetDeltaTime();

	if (m_ElapsedTime > m_view_limit)
	{

		//ここにサウンドの処理

	}
	float time = m_ElapsedTime > m_easing_limit ? m_easing_limit : m_ElapsedTime;
	float scale = abs(aqua::easing::InBack(time, m_easing_limit, m_min_scale, m_max_scale));
	m_Sprite.scale = aqua::CVector2(scale, scale);


	//設定した時間になったら
	if (m_WaitTimer.Finished())
	{
		DeleteObject();
	}

	return;


}

void CFinishMessage::Draw(void)
{
	m_Sprite.Draw();
}

void CFinishMessage::Finalize(void)
{
	m_Sprite.Delete();
}
