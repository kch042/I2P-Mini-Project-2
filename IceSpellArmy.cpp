#include "IceSpellArmy.hpp"
#include "DirtyEffect.hpp"
#include "PlayScene.hpp"
#include "Defense.hpp"
#include <cmath>

const float freezeTime = 2;

// FIXME: id
IceSpellArmy::IceSpellArmy(int x, int y) : Army("play/ice-cubes.png", x, y, 0, 2, 0, 0, 3, 0) {
    isSpell = true;
    timeSpan = freezeTime;
    casted = false;
}

// do nothing
void
IceSpellArmy::CreateBullet(Engine::Point pt) {}

// add ice effect (use dirty effect)
void
IceSpellArmy::Update(float deltaTime) {
    PlayScene *scene = getPlayScene();
    if (isPreview) return;

    timeSpan -= deltaTime;
    if (timeSpan <= 0) {
        scene->ArmyGroup->RemoveObject(objectIterator);
        return;
    }

    if (casted) return;

    // Add ice effect to 9 grids.
    // bx, by are coordinate of top left grid for placing ice effect.
    int x = static_cast<int>(floor(Position.x) - PlayScene::BlockSize);
    int y = static_cast<int>(floor(Position.y) - PlayScene::BlockSize);

    Engine::Sprite* sprite;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sprite = new DirtyEffect("play/snowflake.png", freezeTime, x + i*PlayScene::BlockSize, y + j*PlayScene::BlockSize);
            scene->GroundEffectGroup->AddNewObject(sprite);
            sprite->Rotation = 0;
        }
    }

    int bx = static_cast<int>(floor(Position.x));
    int by = static_cast<int>(floor(Position.y));

    // freeze nearby enemy
    // might be improved to let defense detect the existence
    // so the following code is unnecessary.
    for (auto& it : scene->DefenseGroup->GetObjects()) {
        int mx = static_cast<int>(floor(it->Position.x));
        int my = static_cast<int>(floor(it->Position.y));

        Defense *dfs = dynamic_cast<Defense*>(it);
        if (!dfs->Frozen && (abs(bx-mx) <= 1*PlayScene::BlockSize) && (abs(by-my) <= 1*PlayScene::BlockSize)) {
            // defense is the freezing zone
            dfs->Frozen = true;
        }
    }

    casted = true;
}
