#include "effect_manager.h"
#include "effect/attack_effect/attack_effect.h"

/*
 *  コンストラクタ
 */
CEffectManager::CEffectManager(aqua::IGameObject* parent)
	: IGameObject(parent, "EffectManager")
{
}

/*
 *  更新
 */
void CEffectManager::Update()
{
	IGameObject::Update();
}
				
/*
 *  描画
 */
void CEffectManager::Draw()
{
	IGameObject::Draw();
}

/*
 *  エフェクトを生成
 */
void CEffectManager::Create(EFFECT_ID id, const aqua::CVector2& position)
{
	IEffect* effect = nullptr;

	switch (id)
	{
	case EFFECT_ID::ATTACK:				effect = aqua::CreateGameObject<CAttackEffect>(this);			break;
	}

	if (!effect)
		return;

	effect->Initialize(position);
}
