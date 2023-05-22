#pragma once
#include"..\ui_compornent.h"

class CFinishMessage :public IUiCompornent
{
public:
	CFinishMessage(aqua::IGameObject* parent);
	~CFinishMessage() = default;
	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	enum class STATE
	{
		START_IN,
		WAIT,
	};


	aqua::CSprite	m_Sprite;
	aqua::CTimer	m_WaitTimer;
	STATE			m_State;

	static const std::string m_object_name;

	float			   m_ElapsedTime;		//経過時間
	static const float  m_wait_time;        //! 待機時間
	static const float m_easing_limit;		//イージングの制限時間
	static const float m_view_limit;		//メッセージ表示の制限時間
	static const float m_min_scale;			//最小拡大率
	static const float m_max_scale;			//最大拡大率



};