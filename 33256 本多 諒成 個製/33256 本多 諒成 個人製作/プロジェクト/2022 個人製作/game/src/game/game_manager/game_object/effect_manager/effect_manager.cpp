#include "effect_manager.h"
#include "effect/attack_effect/attack_effect.h"

/*
 *  �R���X�g���N�^
 */
CEffectManager::CEffectManager(aqua::IGameObject* parent)
	: IGameObject(parent, "EffectManager")
{
}

/*
 *  �X�V
 */
void CEffectManager::Update()
{
	IGameObject::Update();
}
				
/*
 *  �`��
 */
void CEffectManager::Draw()
{
	IGameObject::Draw();
}

/*
 *  �G�t�F�N�g�𐶐�
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
