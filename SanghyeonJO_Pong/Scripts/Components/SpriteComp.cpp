#include "SpriteComp.h"
#include "AEEngine.h"
#include "TransformComp.h"
#include "../GameObject/GameObject.h"

SpriteComp::SpriteComp(GameObject* owner)
	: GraphicsComponent(owner), mTex(nullptr)
{

	mColor = { 0, 0, 0 };
}
SpriteComp::~SpriteComp()
{
	if (mTex)
	{
		AEGfxTextureUnload(mTex);
	}
}
void SpriteComp::Update()
{
	AEGfxMeshStart();
	AEGfxTriAdd(-0.5f, -0.5f, 0x0000000, 0, 1,
                0.5f, -0.5f, 0x0000000, 1, 1,
                -0.5f, 0.5f, 0x0000000, 0, 0);
    AEGfxTriAdd(0.5f, -0.5f, 0x0000000, 1, 1,
                0.5f, 0.5f, 0x0000000, 1, 0,
                -0.5f, 0.5f, 0x0000000, 0, 0);
	AEGfxVertexList* mesh = AEGfxMeshEnd();

	//set renderer mod
	//AEGfxSetRenderMod(AE_GFX_RM_COLOR);
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	//set color to multiply
	//AEGfxSetColorToMultiply(mColor.r / 255.f, mColor.g / 255.f, mColor.b / 255.f, 1);
	//AEGfxSetColorToAdd(0, 0, 0, 0);
	////	AEGfxSetColorToMultiply(mColor.r/255.f, mColor.g / 255.f, mColor.b / 255.f,1);
	AEGfxSetColorToMultiply(1, 1, 1, 1);
	////Set color to add
	////AEGfxSetColorToAdd(1,0,0, 0);
	AEGfxSetColorToAdd(mColor.r / 255.f, mColor.g / 255.f, mColor.b / 255.f, 0.f);
	//Set blend Mod
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	//Set Transparency
	AEGfxSetTransparency(1);
	//Set texture
	if (mTex)
	{
		AEGfxTextureSet(mTex, 0, 0);
	}

	//set transform

	//Get the transform from my owner transform comp
	 TransformComp* transform = own->GetComponent<TransformComp>();
    if (transform)
    {
        AEMtx33 matrix = transform->GetMatrix();
        AEGfxSetTransform(matrix.m);
    }
	//call Drawmesh
	AEGfxMeshDraw(mesh, AE_GFX_MDM_TRIANGLES);


	AEGfxMeshFree(mesh);

	//AEGfxMeshStart();
}
void SpriteComp::SetTexture(const std::string& filepath)
{
	if (mTex != nullptr)
		AEGfxTextureUnload(mTex);

	mTex = AEGfxTextureLoad(filepath.c_str());
}
void SpriteComp::SetTexture(AEGfxTexture* Rsc)
{
	if (mTex != nullptr)
		AEGfxTextureUnload(mTex);

	mTex = Rsc;
}
#include "../GameObject/GOManager.h"
void SpriteComp::LoadFromJson(const json& data)
{
}

json SpriteComp::SaveToJson()
{
	nlohmann::json j;
	j["Type"] = GetType();
	// Add other necessary fields for saving audio state
	return j;
}

BaseRTTI* SpriteComp::CreateSpriteComp()
{
	BaseRTTI* out = new SpriteComp(GOManager::Instance()->GetLastObj());
	return out;
}
