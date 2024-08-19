#pragma once
#include "Resource.h"
#include "AEEngine.h"
#include "AEAudio.h"
class MusicResource : public Resource
{
	AEAudio mAudio ;
	AEAudioGroup mGroup;
public:
	MusicResource();

	void Load(const std::string& filename) override;
	void Unload() override;
	void* GetData() const override;
	virtual void update()override;
};