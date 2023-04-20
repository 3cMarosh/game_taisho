#pragma once

#include "aqua.h"
#include "effect/effect.h"
#include "effect/effect_id.h"

class CEffectManager : public aqua::IGameObject
{
public:
	CEffectManager(aqua::IGameObject* parent);	//! �R���X�g���N�^
	~CEffectManager() = default;				//! �f�X�g���N�^

	void Update() override;
	void Draw() override;

	void Create(EFFECT_ID id, const aqua::CVector2& position);
};
