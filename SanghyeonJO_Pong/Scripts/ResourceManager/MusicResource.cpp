#include "MusicResource.h"

MusicResource::MusicResource()
{
   
    mAudio = AEAudioLoadSound("");
    mGroup =  AEAudioCreateGroup();
  
}

void MusicResource::Load(const std::string& filename)
{
    mAudio = AEAudioLoadMusic(filename.c_str());
    mGroup = AEAudioCreateGroup();
    if (!&mAudio)
    {
        data = nullptr;
        return;
    }
    data = &mAudio;
    counter++;
}
void MusicResource::Unload()
{
    if (data)
    {
        AEAudioUnloadAudio(mAudio);
        AEAudioUnloadAudioGroup(mGroup);
        data = nullptr;
        counter--;
    }
}
void* MusicResource::GetData() const
{
	return data;
}

void MusicResource::update()
{
}
