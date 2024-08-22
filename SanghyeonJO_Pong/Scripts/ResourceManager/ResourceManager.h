#pragma once
#include <map>
#include <iostream>
#include <string>
#include "TextResource.h"
#include "MusicResource.h"
//Anything that load loads to memory Texture, audio
//Revse textures model.. between obj
//only 1 load
// RsrMgr->get<Texture>(name)//return it exist
							 //loat it and if not than return
							 // Deduce the byte of extension
//Maps ->(key<Stirng>, (resource,resource*))
//RsrMgr->RemoveMe(name)
//->Decrease counter
	//If o
		// Call unload
			// delate
				//remove from map

//class Resource
//{
//	//handle load
//	//handel unload
//	//counter 
//	//virtual fn "getdata"=0;
//
//};
//class TextResource : Resource
//{
//	texture* data;
//	Load(name) override;
//	UnLoad(name) override;
//
//	Getdata(name) override;
//};

enum FileExt
{
	png,
	mp3,
	wav,
	jpg,
	unknown
};

class ResourceManager
{
	static std::unique_ptr<ResourceManager> Instance_;
	ResourceManager() {};
	ResourceManager(const ResourceManager& other) = delete;
	const ResourceManager& operator= (const ResourceManager& other) = delete;

	std::map<std::string, Resource*> container;
	FileExt GetFileExt(const std::string& filename);
public:
	static ResourceManager* Instance()
	{
		if (Instance_ == nullptr)
			Instance_ = std::make_unique<ResourceManager>();
		return Instance_.get();
	}
	
	template <typename T>
	T* Get(const std::string& filename);
	~ResourceManager();
	void UnloadResource(const std::string& filename);
	void Clear();
	//Singleton
	// map to hold names/ resource*
	// 
	//Get<T>(name) templated fn that return T* the data allocated in the resource with that name
		// IF the resource does not exist, load it
		//load a resource on the EXTENSION of the file
			//switch statment, creating an appropiate constructor for the extension

	//Unload(name) fn that removes 1 from the counter of the resource
		//IF the counter is 0, unliad the resource, delete it , and remove from container

	//Fn to unload All resources
};

template<typename T>
inline T* ResourceManager::Get(const std::string& filename)
{
		auto it = container.find(filename);
		if (it != container.end())
		{
			it->second->counter++;
			return static_cast<T*>(it->second);
		}
		Resource* Rsr = nullptr;
		FileExt ext = GetFileExt(filename);
		switch (ext)
		{
		case FileExt::png:
		case FileExt::jpg:
			Rsr = new TextResource();
			if (Rsr == nullptr)
				return nullptr;
			break;
		case FileExt::wav:
		case FileExt::mp3:
			Rsr = new MusicResource();
			if (Rsr == nullptr)
				return nullptr;
			break;
		default:
			std::cout << "FILE LOAD FAILED" << "\n";
			return nullptr;
		}
		if (Rsr)
		{
			Rsr->Load(filename);
			if (Rsr->GetData() == nullptr)
				return nullptr;
			container[filename] = Rsr;
		}
	/*	else
		{
			delete Rsr;
			Rsr = nullptr;
		}*/

	return static_cast<T*>(Rsr);
}
