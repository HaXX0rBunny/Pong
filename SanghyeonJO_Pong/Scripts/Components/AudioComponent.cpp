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
	auto compData = data.find("compData");
	if (compData != data.end())
	{
		mGroup = AEAudioCreateGroup();
		mAudio = AEAudioLoadSound("");
		auto v = compData->find("Vol");
		volume = v->begin().value();
		auto p = compData->find("Pit");
		pitch = p->begin().value();
		auto l = compData->find("Lp");
		loop = l->begin().value();
		auto py = compData->find("Play");
		Playing = p->begin().value();
	}
	Play();
}

json AudioComp::SaveToJson()
{
	json data;
	data["Type"] = GetType();
	// Add other necessary fields for saving audio state
	json compData;
	compData["Vol"] = {volume};
	compData["Pitch"] = {pitch};
	compData["Lp"] = { loop };
	compData["Play"] = { Playing };
	data["CompData"] = compData;
	return data;
}

BaseRTTI* AudioComp::CreateAudioComp()
{
	BaseRTTI* out = new AudioComp(GOManager::Instance()->GetLastObj());
	return out;
}
