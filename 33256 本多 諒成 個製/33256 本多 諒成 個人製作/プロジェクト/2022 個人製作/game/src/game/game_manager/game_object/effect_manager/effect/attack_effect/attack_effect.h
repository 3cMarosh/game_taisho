#pragma once

#include "../effect.h"


class CAttackEffect : public IEffect
{
public:
	CAttackEffect(aqua::IGameObject* parent);
	~CAttackEffect() = default;

	void Initialize(const aqua::CVector2& position) override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
};
