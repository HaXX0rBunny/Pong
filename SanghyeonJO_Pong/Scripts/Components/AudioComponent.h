#pragma once
#include "BaseComponent.h"
#include <string>
#include "AEAudio.h"

class AudioComp : public BaseComponent
{
	AEAudioGroup mGroup;
	AEAudio mAudio;
	float volume = 0.5f;
	float pitch = 1;

	bool loop = false;
	bool Playing = false;
public:
	AudioComp();
	AudioComp(GameObject* own);
	~AudioComp();
	void Update() override;
	static std::string GetType()
	{
		return "AudioComp";
	}
	void SetAudio(std::string s);
	void SetAudio(AEAudio* audio);
	void Play(); // 재생 메서드 추가
	bool IsPlaying() const; // 재생 상태 확인 메서드 추가
	void LoadFromJson(const json& data)override;

	json SaveToJson()override;
	static BaseRTTI* CreateAudioComp();
};
