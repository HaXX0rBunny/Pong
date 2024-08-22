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

#include "../ResourceManager/ResourceManager.h"
#include "../Serializer/Serializer.h"
#include "../GameObject/GOManager.h"

#include "../Components/PlayerComp2.h"
#include "../Components/PlayerComp.h"

void Levels::MainLevel::Init() {
    player = new GameObject();
    TransformComp* playerTransform = new TransformComp(player);
    SpriteComp* playerSprite = new SpriteComp(player);
    RigidbodyComp* playerRigidBody = new RigidbodyComp(player);
    PlayerComp* playerMove = new PlayerComp(player);


    player->AddComponent(playerTransform);
    player->AddComponent(playerSprite);
    player->AddComponent(playerRigidBody);
    player->AddComponent(playerMove);


    playerTransform->SetPos({ -775, 0 });
    playerTransform->SetScale({ 20, 200 });

    player_m = new GameObject();
    TransformComp* playerTransform_m = new TransformComp(player_m);
    SpriteComp* playerSprite_m = new SpriteComp(player_m);
    RigidbodyComp* playerRigidBody_m = new RigidbodyComp(player_m);
    PlayerComp2* playerMove_m = new PlayerComp2(player_m);


    player_m->AddComponent(playerTransform_m);
    player_m->AddComponent(playerSprite_m);
    player_m->AddComponent(playerRigidBody_m);
    player_m->AddComponent(playerMove_m);
  

    playerTransform_m->SetPos({ 775, 0 });
    playerTransform_m->SetScale({ 20, 200 });

    ball = new GameObject();
    TransformComp* planetTransform = new TransformComp(ball);
    SpriteComp* planetSprite = new SpriteComp(ball);
    RigidbodyComp* planetRigid = new RigidbodyComp(ball);

    ball->AddComponent(planetTransform);
    ball->AddComponent(planetSprite);
    ball->AddComponent(planetRigid);

    planetTransform->SetPos({ 0, 0 });
    planetTransform->SetScale({ 40, 40 });
    planetRigid->AddVelocity(600, 0);


    std::cout << "Main level Init" << std::endl;
}

void Levels::MainLevel::Update() {

}

void Levels::MainLevel::Exit() {
    std::cout << "Main level Exit" << std::endl;

    GOManager::Instance()->Clear();

}
