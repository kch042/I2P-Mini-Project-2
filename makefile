CXX = g++
CXXFLAGS = -std=c++11 `pkg-config --cflags allegro-5`

LDFLAGS = -lm -Wall -Wextra
LDLIBS = -L/usr/local/lib \
-lallegro\
-lallegro_acodec\
-lallegro_audio\
-lallegro_color\
-lallegro_dialog\
-lallegro_font\
-lallegro_image\
-lallegro_main\
-lallegro_memfile\
-lallegro_physfs\
-lallegro_primitives\
-lallegro_ttf\
-lallegro_video

# missing: Enemy.o FireBullet.o LaserBullet.o LaserTurret.o MachineGunTurret.o MissileBullet.o MissileTurret.o PlaneEnemy.o SoldierEnemy.o  TankEnemy.o Turret.o TurretButton.o
OUT = td
OBJS = Allegro5Exception.o AudioHelper.o Bullet.o Collider.o DirtyEffect.o ExplosionEffect.o GameEngine.o Group.o IControl.o Image.o ImageButton.o IObject.o IScene.o Label.o LOG.o LoseScene.o Plane.o PlayScene.o Point.o Resources.o Slider.o  Sprite.o StageSelectScene.o  WinScene.o main.o\
Army.o ArcherArmy.o ArcherBullet.o ArmyBullet.o ArmyButton.o ArmySelectScene.o CannonBullet.o CannonDefense.o Defense.o\
Role.o Setting_Scene.o Start_Scene.o WallDefense.o BombArmy.o ShootEffect.o

.PHONY: all clean

all: $(OBJS)
	$(CXX) -o $(OUT) $(OBJS) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OUT) $(OBJS)
