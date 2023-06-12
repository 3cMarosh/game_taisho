//ゲームメインシーン
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
	aqua::CSprite m_Result_BackGround;	//ゲームメイン背景のスプライト
	aqua::CTimer	m_ResultTime;		//ゲームメインシーンのタイマー

	static const float m_result_time;
	static const std::string m_object_name;
};
