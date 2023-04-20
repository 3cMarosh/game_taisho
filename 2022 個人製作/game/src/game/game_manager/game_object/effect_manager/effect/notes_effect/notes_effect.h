#pragma once

#include "../effect.h"


class CNotesEffect : public IEffect
{
public:
	CNotesEffect(aqua::IGameObject* parent);
	~CNotesEffect() = default;

	void Initialize(const aqua::CVector2& position) override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	
	static const float		m_fade_speed;
	float					m_FadeSpeed;

};
