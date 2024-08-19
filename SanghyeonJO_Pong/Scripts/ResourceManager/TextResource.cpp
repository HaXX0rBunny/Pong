#include "TextResource.h"
#include "AEEngine.h"
void TextResource::Load(const std::string& filename)
{
    AEGfxTexture* texture = AEGfxTextureLoad(filename.c_str());
    if (!texture)
    {
        data = nullptr;
        return;
    }
    data = texture;
    counter++;

}

void TextResource::Unload()
{
    if (data!=nullptr)
    {
        AEGfxTextureUnload(static_cast<AEGfxTexture*> (data));
        data = nullptr;
        counter--;
    }
}

void* TextResource::GetData() const
{
    return data;
}

void TextResource::update()
{
}
