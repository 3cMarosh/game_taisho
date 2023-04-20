#pragma once

#include "../effect.h"


class CNotes4Effect : public IEffect
{
public:
	CNotes4Effect(aqua::IGameObject* parent);
	~CNotes4Effect() = default;

	void Initialize(const aqua::CVector2& position) override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
};
