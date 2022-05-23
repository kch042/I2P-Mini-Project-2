#include "TankArmy.hpp"
#include <cmath>

// tank army
// id = 2
// cooldown = INFINITY
TankArmy::TankArmy(int x, int y) : Army("play/enemy-2.png", x, y, 20, INFINITY, 0, 50, 2, 0) {
    //Anchor.y += 8.0f / GetBitmapHeight();
}

void
TankArmy::CreateBullet(Engine::Point) {}

void
TankArmy::Update(float deltaTime) {
    
}

