#include "AudioComponent.h"
#include "AEEngine.h"
#include "AEAudio.h"



AudioComp::AudioComp()
{
	mGroup = AEAudioCreateGroup();
	mAudio = AEAudioLoadSound("");
	volume = 0.5f;
	pitch = 1;

	loop = false;
	Playing = false;
}

AudioComp::AudioComp(GameObject* own)
{
	mGroup= AEAudioCreateGroup();
	mAudio= AEAudioLoadSound("");;
	volume = 0.5f;
	pitch = 1;

	loop = false;
	Playing = false;
}

AudioComp::~AudioComp()
{
	//Manager<AudioComp>::getptr()->RemovePtr(this);
	AEAudioUnloadAudio(mAudio);
	AEAudioUnloadAudioGroup(mGroup);
}

void AudioComp::Update()
{
	//Do NOT Copy this
	
	if (!Playing)
	{
		Play();
	}
	
}
void AudioComp::SetAudio(std::string s)
{
	mAudio = AEAudioLoadMusic(s.c_str());
}

void AudioComp::SetAudio(AEAudio* audio)
{
	mAudio = *audio;
}

void AudioComp::Play()
{
	int loops = loop ? -1 : 0;
	AEAudioPlay(mAudio, mGroup, volume, pitch, loops);
	Playing = true;
}

bool AudioComp::IsPlaying() const
{
	return Playing;
}
#include "../GameObject/GOManager.h"
void AudioComp::LoadFromJson(const json& data)
{
}

json AudioComp::SaveToJson()
{
	nlohmann::json j;
	j["Type"] = GetType();
	// Add other necessary fields for saving audio state
	return j;
}

BaseRTTI* AudioComp::CreateAudioComp()
{
	BaseRTTI* out = new AudioComp(GOManager::Instance()->GetLastObj());
	return out;
}
