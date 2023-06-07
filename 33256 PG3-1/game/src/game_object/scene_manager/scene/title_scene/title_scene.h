//�Q�[�����C���V�[��
#pragma once
#include"aqua.h"
#include"..\scene.h"

class CTitleScene
	:public IScene
{
public:

	CTitleScene(aqua::IGameObject* parent);
	~CTitleScene(void);
	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;
	float GetTime();

private:


	aqua::CLabel m_Title_Label;
	aqua::CSprite m_Title_BackGround;	//�Q�[�����C���w�i�̃X�v���C�g
	aqua::CTimer	m_TitleTime;		//�Q�[�����C���V�[���̃^�C�}�[

	static const float m_title_time;
	static const std::string m_object_name;
};