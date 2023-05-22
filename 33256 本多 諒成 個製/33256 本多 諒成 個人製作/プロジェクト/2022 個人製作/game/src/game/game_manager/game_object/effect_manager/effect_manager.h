#pragma once

#include "aqua.h"
#include "effect/effect.h"
#include "effect/effect_id.h"

class CEffectManager : public aqua::IGameObject
{
public:
	CEffectManager(aqua::IGameObject* parent);	//! コンストラクタ
	~CEffectManager() = default;				//! デストラクタ

	void Update() override;
	void Draw() override;

	void Create(EFFECT_ID id, const aqua::CVector2& position);
};
