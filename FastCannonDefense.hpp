#ifndef FastCannonDefense_hpp
#define FastCannonDefense_hpp

#include "Defense.hpp"

class FastCannonDefense: public Defense {
public:
    FastCannonDefense(float x, float y);
    void CreateBullet(Engine::Point pt) override;
};

#endif /* FastCannonDefense_hpp */