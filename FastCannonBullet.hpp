#ifndef FastCannonBullet_hpp
#define FastCannonBullet_hpp

#include "Bullet.hpp"

class FastCannonBullet : public Bullet {
public:
    explicit FastCannonBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* parent);

    void Update(float deltaTime) override;
};

#endif