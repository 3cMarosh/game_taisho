#include "effect_manager.h"
#include "effect/attack_effect/attack_effect.h"
#include"effect/notes_effect/notes_effect.h"
#include"effect/note2_effect/note2_effect.h"
#include"effect/note3_effect/note3_effect.h"
#include"effect/note4_effect/note4_effect.h"

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
	case EFFECT_ID::ATTACK:				effect = aqua::CreateGameObject<CAttackEffect>(this);		break;
	case EFFECT_ID::NOTES1:				effect = aqua::CreateGameObject<CNotesEffect>(this);		break;
	case EFFECT_ID::NOTES2:				effect = aqua::CreateGameObject<CNotes2Effect>(this);		break;
	case EFFECT_ID::NOTES3:				effect = aqua::CreateGameObject<CNotes3Effect>(this);		break;
	case EFFECT_ID::NOTES4:				effect = aqua::CreateGameObject<CNotes4Effect>(this);		break;
	}

	if (!effect)
		return;

	effect->Initialize(position);
}
