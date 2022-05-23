#ifndef TankArmy_HPP
#define TankArmy_HPP

#include "Army.hpp"

class TankArmy : public Army {
public:   
    TankArmy(int x, int y);

	void Update(float deltaTime);
	void CreateBullet(Engine::Point pt) override;
};


#endif