#pragma once
#include "../ComponentManager/GraphicsManager.h"
#include "GraphicsComponent.h"
#include "AEEngine.h"
#include "AEGraphics.h"
#include "AEMath.h"
class SpriteComp : public GraphicsComponent
{
	
	//mesh of points (quad)
	//All mye bjects have the same quad;
	// so i will not make it a member variable
	//text coords uv // Maybe later
	//color
public:
	struct Color
	{
		unsigned char r = 255;
		unsigned char g = 255;
		unsigned char b = 255;
	};
private:
	Color mColor;
	//texture
	AEGfxTexture* mTex;
	//Render mode?
	//Blend mode?
	//Transparency

public:
	SpriteComp(GameObject* owner);
	~SpriteComp();
	void Update() override;
	//draw

	//Gettors/Settors
	Color& Getcolor() { return mColor; };
	void SetTexture(const std::string& filepath);
	void SetTexture(AEGfxTexture* Rsr);
	static std::string GetType()
	{
		return "SpriteComp";
	}
	void LoadFromJson(const json& data)override;

	json SaveToJson()override ;
	static BaseRTTI* CreateSpriteComp();
};