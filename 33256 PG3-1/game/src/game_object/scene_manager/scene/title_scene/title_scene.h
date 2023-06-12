//ゲームメインシーン
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


	aqua::CSprite m_Title_Sprite;
	aqua::CSprite m_Title_message;
	aqua::CSprite m_Title_BackGround;	//ゲームメイン背景のスプライト
	aqua::CTimer	m_TitleTime;		//ゲームメインシーンのタイマー

	static const float m_title_time;
	static const std::string m_object_name;
};