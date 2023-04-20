#pragma once

#include "../effect.h"


class CNotes3Effect : public IEffect
{
public:
	CNotes3Effect(aqua::IGameObject* parent);
	~CNotes3Effect() = default;

	void Initialize(const aqua::CVector2& position) override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
};
