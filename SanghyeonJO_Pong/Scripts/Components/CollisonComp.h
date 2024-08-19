#pragma once
#include "../Components/EngineComponent.h"
#include <string>
#include "AEAudio.h"


class ColliisionComp : public EngineComponent
{
	ColliisionComp();
	~ColliisionComp();
	virtual void LoadFromJson(const json& data) = 0;
	std::string GetType() {
		return "CollisionComp";
	}
	int CollisionInterSection();

};