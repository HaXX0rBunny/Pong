#include "ResourceManager.h"
std::unique_ptr<ResourceManager> ResourceManager::Instance_ = nullptr;
ResourceManager::~ResourceManager()
{
    Clear();
}

FileExt ResourceManager::GetFileExt(const std::string& filename)
{
    std::string ext = filename.substr(filename.find_last_of(".") + 1);

    if (ext == "png")
        return FileExt::png;
    if (ext == "jpg")
        return FileExt::jpg;
    if (ext == "mp3")
        return FileExt::mp3;
    if (ext == "wav")
        return FileExt::wav;
    return FileExt::unknown;
}

void ResourceManager::UnloadResource(const std::string& filename)
{
    auto it = container.find(filename);
    if (it != container.end())
    {        
        it->second->Unload();
        delete it->second;
        container.erase(it);
    }
}
void ResourceManager::Clear()
{
    
    for (auto& it : container)
    {
        it.second->Unload();
        delete it.second;
    }
    container.clear();
    delete Instance_;
    Instance_ = nullptr;
}
