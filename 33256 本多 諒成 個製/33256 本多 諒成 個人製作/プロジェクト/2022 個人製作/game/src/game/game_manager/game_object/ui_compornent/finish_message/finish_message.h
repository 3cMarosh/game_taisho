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

	float			   m_ElapsedTime;		//�o�ߎ���
	static const float  m_wait_time;        //! �ҋ@����
	static const float m_easing_limit;		//�C�[�W���O�̐�������
	static const float m_view_limit;		//���b�Z�[�W�\���̐�������
	static const float m_min_scale;			//�ŏ��g�嗦
	static const float m_max_scale;			//�ő�g�嗦



};