#include "MainLevel.h"
#include "GameStateManager.h"
#include "GoalLevel.h"
#include <iostream>
#include "../Components/PlayerComp.h"
#include "../Components/RigidbodyComp.h"
#include "../Components/AudioComponent.h"
#include "../GameObject/GameObject.h"
#include "../Components/transformcomp.h"
#include "../Components/SpriteComp.h"
#include "../Components/PlayerComp.h"
#include "../ResourceManager/ResourceManager.h"
#include "../Serializer/Serializer.h"
#include "../GameObject/GOManager.h"
void Levels::MainLevel::Init()
{
 
    player = new GameObject();
    TransformComp* playerTransform = new TransformComp(player);
    SpriteComp* playerSprite = new SpriteComp(player);
    RigidbodyComp* playerRigidBody = new RigidbodyComp(player);
    AudioComp* playerAudio = new AudioComp(player);
    PlayerComp* playerMove = new PlayerComp(player);


    ResourceManager* RsrMgr = ResourceManager::Instance();
    TextResource* TextRsr = RsrMgr->Get<TextResource>("../../Assets/ame.png");
    TextResource* planetTextRsr = RsrMgr->Get<TextResource>("../../Assets/hos.png");
    MusicResource* AudioRsr = RsrMgr->Get<MusicResource>("../../Assets/bouken.mp3");

    playerSprite->SetTexture(static_cast<AEGfxTexture*>(TextRsr->GetData()));
    playerAudio->SetAudio(static_cast<AEAudio*>(AudioRsr->GetData()));

    player->AddComponent(playerTransform);
    player->AddComponent(playerSprite);
    player->AddComponent(playerRigidBody);
    player->AddComponent(playerAudio);
    player->AddComponent(playerMove);
    playerTransform->SetPos({ 100, 100 });
    playerTransform->SetScale({ 200, 200 });

    
    planet = new GameObject();
    TransformComp* planetTransform = new TransformComp(planet);
    SpriteComp* planetSprite = new SpriteComp(planet);

    planetSprite->SetTexture(static_cast<AEGfxTexture*>(planetTextRsr->GetData()));

    planet->AddComponent(planetTransform);
    planet->AddComponent(planetSprite);
//    RsrMgr.Clear();

    Serializer *s= Serializer::Instance();
    s->LoadLevel("test.json");
   
    std::cout << "Main level Init" << std::endl;
    
}

void Levels::MainLevel::Update()
{
	//std::cout << "Main level Update" << std::endl;
    TransformComp* trs = planet->GetComponent<TransformComp>();
    SpriteComp* spr = planet->GetComponent<SpriteComp>();
    AudioComp* audio = player->GetComponent<AudioComp>();
    
    if (trs)
    {
        trs->SetPos({ trs->GetPos().x +1, trs->GetPos().y });
        std::cout << trs->GetPos().x << "\n";
        if (trs->GetPos().x > 800)
            trs->SetPos({ -800, 0 });
        if (counter % 10 == 0)
        {
            trs->SetRot(trs->GetRot() + 0.5f);
        }
        trs->SetScale({ trs->Getscale().x * 1.01f, trs->Getscale().y * 1.01f });
          
    }
    AEGfxMeshStart();
   /* if (spr)
    {
        SpriteComp::Color& c = spr->Getcolor();
        if (counter < 255)
        {
            c.r--;
            c.g++;
            c.b++;
        }
        else
        {
            c.r++;
            c.g--;
            c.b--;
        }
    }*/

    if (!audio->IsPlaying())
    {
 
        audio->Play();
        
    }
	//If goal was reached changed level

	//counter++;
	//if (counter >= 100)
	//{
	//	//Changer to goal
	//	GSM::GameStateManager::GetGSMPtr()->ChangeLevel(new GoalLevel);
	//}

}

void Levels::MainLevel::Exit()
{
	std::cout << "Main level Exit" << std::endl;
    Serializer* s = Serializer::Instance();
    s->SaveLevel("test.json");

	delete player;
	delete planet;

}