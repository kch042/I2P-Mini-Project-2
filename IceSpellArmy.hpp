#ifndef IceSpellArmy_HPP
#define IceSpellArmy_HPP

#include "Army.hpp"

class IceSpellArmy: public Army {
public:   
    IceSpellArmy(int x, int y);
    void CreateBullet(Engine::Point pt) override;
	void Update(float deltaTime) override;
};


#endif