#ifndef BombArmy_hpp
#define BombArmy_hpp

#include "Army.hpp"
#include <string>

class BombArmy: public Army {
private:
    std::string TargetType;

public:
    BombArmy(float x, float y);
    void Update(float deltaTime) override;
    void CreateBullet(Engine::Point pt) override;
    void Hit(float damage) override;

    void SetTarget();
};

#endif /* BombArmy_hpp */
