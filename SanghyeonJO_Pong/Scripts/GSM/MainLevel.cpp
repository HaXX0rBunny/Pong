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
	planet = new GameObject();

    TransformComp* planetTransform = new TransformComp(planet);
    SpriteComp* planetSprite = new SpriteComp(planet);
    RigidbodyComp* planetRigid = new RigidbodyComp(planet);

    planet->AddComponent(planetTransform);
    planet->AddComponent(planetSprite);
    planet->AddComponent(planetRigid);
	//    RsrMgr.Clear();
    planetTransform->SetPos({ 0, 0 });
    planetTransform->SetScale({ 40, 40 });
    planetRigid->AddVelocity(600, 0);
    std::cout << "Main level Init" << std::endl;
    
}

void Levels::MainLevel::Update()
{
	//std::cout << "Main level Update" << std::endl;
    TransformComp* trs = planet->GetComponent<TransformComp>();
    SpriteComp* spr = planet->GetComponent<SpriteComp>();
    AudioComp* audio = player->GetComponent<AudioComp>();
    AEGfxMeshStart();
    //if (trs){trs->SetPos({ trs->GetPos().x + 5, trs->GetPos().y });}
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
