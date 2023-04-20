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
	float GetTime();

private:

	//void GameStart(void);
	//void GamePlay(void);
	//void GameFinish(void);



	aqua::CLabel m_gamemain_Label;
	aqua::CSprite m_Main_BackGround;	//ゲームメイン背景のスプライト
	aqua::CSprite m_Sky_Notes;			//空の音符のスプライト
	aqua::CTimer	m_GameMainTime;		//ゲームメインシーンのタイマー
	
	static const float m_game_main_time;
	static const std::string m_object_name;
	//STATE m_State;
};