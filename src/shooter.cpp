#define __SCROLL_IMPL__
#include "shooter.h"
#undef __SCROLL_IMPL__

#include "Hero.h"
#include "Turret.h"
#include "EnemyGun.h"

Hero *hero;

void ShooterGame::BindObjects () {
  ScrollBindObject<Hero> ("HeroObject");
  ScrollBindObject<Turret> ("TurretObject");
  ScrollBindObject<EnemyGun> ("EnemyGunObject");
}

orxSTATUS ShooterGame::Bootstrap () const {
  orxResource_AddStorage(
      orxCONFIG_KZ_RESOURCE_GROUP,
      "../data/config",
      orxFALSE
  );

  orxConfig_Load("shooter.ini");

  // The return status is set to orxSTATUS_FAILURE.
  // This effectively stops Orx from continuing to look for a default config,
  // after the Bootstrap function has completed. If orxSTATUS_SUCCESS is returned,
  // Orx will still try and load the default config located next to the executable
  return orxSTATUS_FAILURE;
}

orxSTATUS ShooterGame::Init () {
  orxSTATUS result = orxSTATUS_SUCCESS;

  hero = (Hero*)CreateObject("HeroObject");
  (Turret*)CreateObject("TurretObject");

  // its probably better to have a Scene object that gets created and
  // calls update on each of its children, etc...
  // could also have a SceneList object

  // Scene
  //   bool: active
  //   bool: isActive()
  return result;
}

orxSTATUS ShooterGame::Run () {
  orxSTATUS result = orxSTATUS_SUCCESS;

  if (orxInput_IsActive("Quit")) {
    result = orxSTATUS_FAILURE;
  }

  return result;
}

void ShooterGame::Exit () {

}

int main(int argc, char **argv) {
  ShooterGame::GetInstance().Execute(argc, argv);
  return EXIT_SUCCESS;
}
