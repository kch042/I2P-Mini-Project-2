#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include <tuple>

#include "IScene.hpp"
#include "Point.hpp"

#define MAX_ARMY_AMOUNT 6
#define WALL_SIZE 4

class Defense;
class Army;
namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
}  // namespace Engine

class PlayScene final : public Engine::IScene {
private:
	enum TileType {
		TILE_DIRT,
		TILE_FLOOR,
        TILE_WALL,
        TILE_CANNON,
		TILE_OCCUPIED,
		TILE_FAST_CANNON,  // Spec1: add a new defense
	};
	ALLEGRO_SAMPLE_ID bgmId;
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> deathBGMInstance;
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
protected:
	int SpeedMult;
    // Enemy Amounts
    int armyAmount[MAX_ARMY_AMOUNT];
    // Total enemies;
    int totalArmy;

	// Total spells
	// Note that normal army and spell are of Army class
	// and they are managed together in playscene
	// For now, the only purpose of totalSpell is for
	// "indexing" the spell.
	// spell id: totalArmy+0, totalArmy+1, ..., totalArmy+totalSpell-1
	int totalSpell;
public:
    bool mute;
	static bool DebugMode;
	static const std::vector<Engine::Point> directions;
	static const int MapWidth, MapHeight;
	static const int BlockSize;
	static const float DangerTime;

	// cheat keyboard sequences to destroy all walls
	static const std::vector<int> code;

	int MapId;
    Engine::Point corners[WALL_SIZE];
    std::vector<Engine::Point> brokenWall[WALL_SIZE];
	float ticks;
	float deathCountDown;
	// Map tiles.
	Group* TileMapGroup;
	Group* GroundEffectGroup;
	Group* DebugIndicatorGroup;
	Group* BulletGroup;
    Group* DefenseGroup;
    Group* WallGroup;
    Group* ArmyGroup;
	Group* EffectGroup;
	Group* UIGroup;
    std::string ArmyImage[MAX_ARMY_AMOUNT];
    Engine::Label *UIArmyAmount[MAX_ARMY_AMOUNT];
	Engine::Image* imgTarget;
    Army* preview;
	std::vector<std::vector<TileType>> mapState;

	// accumulate the keystrokes by users (to summon the plane to destroy the walls)
    std::list<int> keyStrokes;
	
    static Engine::Point GetClientSize();
	explicit PlayScene() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Draw() const override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void OnMouseUp(int button, int mx, int my) override;
	void OnKeyDown(int keyCode) override;
    // Reduce the enemy amounts when release
    void ReduceAmount(int id);
    // get & set enemy amount
    int GetArmyAmount(int id);
    void SetArmyAmount(int id, int amount);
    // get & set totalEnemy amount
    int GetTotalArmyAmount();
    void SetTotalArmyAmount(int total);
	void SetTotalSpellAmount(int total);
	void ReadMap();
	void ConstructUI();
    void ConstructButton(int id, std::string imageName);
	void UIBtnClicked(int id);
    bool CheckOccupied(int x, int y);
    void ClearMapState(int x, int y);
};
#endif // PLAYSCENE_HPP
