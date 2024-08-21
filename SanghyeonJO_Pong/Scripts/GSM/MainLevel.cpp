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
#include "../Components/PlayerComp2.h"
void Levels::MainLevel::Init()
{
   
 
    player = new GameObject();
    TransformComp* playerTransform = new TransformComp(player);
    SpriteComp* playerSprite = new SpriteComp(player);
    RigidbodyComp* playerRigidBody = new RigidbodyComp(player);
    PlayerComp* playerMove = new PlayerComp(player);

    player_m = new GameObject();
    TransformComp* playerTransform_m = new TransformComp(player_m);
    SpriteComp* playerSprite_m = new SpriteComp(player_m);
    RigidbodyComp* playerRigidBody_m = new RigidbodyComp(player_m);
    PlayerComp2* playerMove_m = new PlayerComp2(player_m);
    //ping[0] = new GameObject();
    //ping[1] = new GameObject();
    //Wall = new GameObject();
    //TransformComp* PingTransform = new TransformComp(ping[0]);
    //SpriteComp* PingSprite = new SpriteComp(ping[0]);
    //TransformComp* Ping2Transform = new TransformComp(ping[1]);
    //SpriteComp* Ping2Sprite = new SpriteComp(ping[1]);
    player->AddComponent(playerTransform);
    player->AddComponent(playerSprite);
    player->AddComponent(playerRigidBody);
    player->AddComponent(playerMove);

    player_m->AddComponent(playerTransform_m);
    player_m->AddComponent(playerSprite_m);
    player_m->AddComponent(playerRigidBody_m);
    player_m->AddComponent(playerMove_m);
    playerTransform_m->SetPos({ 775, 0 });
    playerTransform_m->SetScale({ 20, 200 });
    playerTransform->SetPos({ -775, 0 });
    playerTransform->SetScale({ 20, 200 });

    ResourceManager* RsrMgr = ResourceManager::Instance();
    //TextResource* TextRsr = RsrMgr->Get<TextResource>("../../Assets/ame.png");
    //TextResource* planetTextRsr = RsrMgr->Get<TextResource>("../../Assets/hos.png");
    //MusicResource* AudioRsr = RsrMgr->Get<MusicResource>("../../Assets/bouken.mp3");

    //playerSprite->SetTexture(static_cast<AEGfxTexture*>(TextRsr->GetData()));
    //playerAudio->SetAudio(static_cast<AEAudio*>(AudioRsr->GetData()));



    planet = new GameObject();
    


    TransformComp* planetTransform = new TransformComp(planet);
    SpriteComp* planetSprite = new SpriteComp(planet);
    //planetSprite->SetTexture(static_cast<AEGfxTexture*>(planetTextRsr->GetData()));

    planet->AddComponent(planetTransform);
    planet->AddComponent(planetSprite);
	//    RsrMgr.Clear();
    planetTransform->SetPos({ 0, 0 });
    planetTransform->SetScale({ 40, 40 });
    //Serializer *s= Serializer::Instance();
    //s->LoadLevel("test.json");
   
    std::cout << "Main level Init" << std::endl;
    
}

void Levels::MainLevel::Update()
{
	//std::cout << "Main level Update" << std::endl;
    TransformComp* trs = planet->GetComponent<TransformComp>();
    SpriteComp* spr = planet->GetComponent<SpriteComp>();
    AudioComp* audio = player->GetComponent<AudioComp>();
    AEGfxMeshStart();
    if (trs)
    {
        trs->SetPos({ trs->GetPos().x + 5, trs->GetPos().y });


    }
    //if (trs)
    //{
    //    trs->SetPos({ trs->GetPos().x +1, trs->GetPos().y });
    //    std::cout << trs->GetPos().x << "\n";
    //    if (trs->GetPos().x > 800)
    //        trs->SetPos({ -800, 0 });
    //    if (counter % 10 == 0)
    //    {
    //        trs->SetRot(trs->GetRot() + 0.5f);
    //    }
    //    trs->SetScale({ trs->Getscale().x * 1.01f, trs->Getscale().y * 1.01f });
    //      
    //}

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
    //Serializer* s = Serializer::Instance();
    //s->SaveLevel("test.json");

    GOManager::Instance()->Clear();

   // ResourceManager::Instance()->Clear();

}
