#pragma once
#include"aqua.h"

class CStage :public aqua::IGameObject
{
public:
	CStage(aqua::IGameObject* parent);
	~CStage(void) = default;
	void    Initialize(void) override;
	void	Update(void)override;
	void    Draw(void) override;
	void    Finalize(void) override;

private:


	aqua::CSprite           m_Main_BackGround;
	aqua::CSprite			m_1PGuage;
	aqua::CSprite			m_2PGuage;


	aqua::CLabel	        m_text;

	int                     m_back;
	int                     m_back1;

};