#pragma once
#include"aqua.h"
#include"..\scene.h"
#include"..\game_main_scene\game_main_scene.h"

class CResultScene final
	:public IScene
{
public:
	CResultScene(aqua::IGameObject* parent);
	~CResultScene(void) = default;

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

private:
	aqua::CSprite m_ResultBGSprite;
	aqua::CLabel m_Result_Label;


};