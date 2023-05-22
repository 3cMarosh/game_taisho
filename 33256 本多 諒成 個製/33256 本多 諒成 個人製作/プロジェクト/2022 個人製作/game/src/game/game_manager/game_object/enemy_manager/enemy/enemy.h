#pragma once
#include"aqua.h"
class IEnemy 
	:public aqua::IGameObject
{
public:
	IEnemy(IGameObject*, std::string name);
	~IEnemy() = default;

	void Initialize(void);
	void UPdate(void);
	void Draw(void);
	void Finalize(void);
		
};