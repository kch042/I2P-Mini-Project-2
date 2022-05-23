#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "FastCannonBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Army.hpp"

class Defense;

//Bullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* defenseParent);
FastCannonBullet::FastCannonBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* parent) :
    Bullet("play/bullet-8.png", 700, 2.5, position, forwardDirection, rotation, parent) {
}

void
FastCannonBullet::Update(float deltaTime) {
    Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();

    for (auto& it : scene->ArmyGroup->GetObjects()) {
        Army* army= dynamic_cast<Army*>(it);
        if (!army->Visible)
            continue;
        if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, army->Position, army->CollisionRadius)) {
            // slow down the enemy
            army->slowFactor = 0.5;
            
            army->Hit(damage);
            getPlayScene()->BulletGroup->RemoveObject(objectIterator);
            return;
        }
    }
	// Check if out of boundary.
    if (Position.x < 0 || Position.x > PlayScene::GetClientSize().x || Position.y < 0 || Position.y > PlayScene::GetClientSize().y)
        getPlayScene()->BulletGroup->RemoveObject(objectIterator);
}