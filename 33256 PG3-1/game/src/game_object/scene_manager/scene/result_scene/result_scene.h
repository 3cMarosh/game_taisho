//�Q�[�����C���V�[��
#pragma once
#include"aqua.h"
#include"..\scene.h"

class CResultScene
	:public IScene
{
public:

	CResultScene(aqua::IGameObject* parent);
	~CResultScene(void);
	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;
	float GetTime();

private:


	aqua::CSprite m_ResultSprite;
	aqua::CSprite m_Result_BackGround;	//�Q�[�����C���w�i�̃X�v���C�g
	aqua::CTimer	m_ResultTime;		//�Q�[�����C���V�[���̃^�C�}�[

	static const float m_result_time;
	static const std::string m_object_name;
};
