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
	float   GetGroundLine(void) const;
	float   GetGravity(void) const;

private:
	
	static const float      m_ground_line;
	static const float      m_gravity;
	aqua::CSprite           m_Main_BackGround;
	aqua::CSprite           m_Main_BackGround1;
	aqua::CSprite			m_Sky_Notes1; 
	aqua::CSprite			m_Sky_Notes2;
	aqua::CSprite			m_Sky_Notes3;
	aqua::CSprite			m_Sky_Notes4;
	aqua::CSprite			m_TextSprite;
	aqua::CLabel	        m_text;

	int                     m_back;
	int                     m_back1;

};