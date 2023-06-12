//�Q�[�����C���V�[��
#pragma once
#include"aqua.h"
#include"..\scene.h"



class CGameMainScene
	:public IScene
{
public:

	CGameMainScene(aqua::IGameObject* parent);
	~CGameMainScene(void);
	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;
	float GetTime();

private:


	aqua::CLabel m_gamemain_Label;
	aqua::CSprite m_Main_BackGround;	//�Q�[�����C���w�i�̃X�v���C�g
	aqua::CTimer	m_GameMainTime;		//�Q�[�����C���V�[���̃^�C�}�[

	static const float m_game_main_time;
	static const std::string m_object_name;
};