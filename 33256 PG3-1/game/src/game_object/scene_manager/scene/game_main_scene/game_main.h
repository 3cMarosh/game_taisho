//ゲームメインシーン
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
	aqua::CSprite m_Main_BackGround;	//ゲームメイン背景のスプライト
	aqua::CTimer	m_GameMainTime;		//ゲームメインシーンのタイマー

	static const float m_game_main_time;
	static const std::string m_object_name;
};