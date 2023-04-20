#pragma once

#include "../effect.h"


class CNotes2Effect : public IEffect
{
public:
	CNotes2Effect(aqua::IGameObject* parent);
	~CNotes2Effect() = default;

	void Initialize(const aqua::CVector2& position) override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
};
