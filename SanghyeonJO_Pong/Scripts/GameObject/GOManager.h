#pragma once
#include <list>
#include "GameObject.h"
class GOManager
{
	~GOManager();
	GOManager()=default;
	GOManager(const GOManager& other) = delete;
	const GOManager& operator=(const GOManager& other) = delete;
	std::list<GameObject*> allObj;
	static std::unique_ptr<GOManager> Instance_;
public:
	static GOManager* Instance() {
		if (!Instance_) {
			Instance_ = std::make_unique<GOManager>();
		}
		return Instance_.get();
	}
	std::list<GameObject*> AllObj();
	void AddObj(GameObject* obj);
	void RemoveObj(GameObject* obj);
	void Clear();
	GameObject* GetLastObj();

};