#pragma once
#include"aqua.h"
#include"..\scene.h"


class CTitleScene final
	:public IScene
{
public:
	CTitleScene(aqua::IGameObject* parent);
	~CTitleScene(void) = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;


private:
	aqua::CSprite m_TitleBGSprite;	//ƒ^ƒCƒgƒ‹”wŒi
	aqua::CSprite m_StartSprite;	//PushZKey
	aqua::CTimer m_TitleTimer;
	aqua::CLabel m_tLabel;
	static const float m_fade_speed;
	float m_FadeSpeed;

	//STATE m_TitleState;
};