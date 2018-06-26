#include "Turret.h"
#include "EnemyGun.h"

void Turret::OnCreate () { }

void Turret::OnDelete () { }

void Turret::Update (const orxCLOCK_INFO &_rstInfo) { }

orxBOOL Turret::OnCollide (
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal
) {

  orxLOG("\nTurret collision!");

  return true;
}

ScrollObject* Turret::GetGunByName (const std::string name) {
  // consider adding error checking to make sure that name is
  // "Zero", "One", "Two", or "Three"
  ScrollObject *child;

  std::string fullName = "EnemyGunObject";
  fullName.append(name);

  for (child = this->GetOwnedChild(); child; child = child->GetOwnedSibling()) {
    if (orxString_Compare(child->GetModelName(), (orxCHAR*)fullName.c_str()) == 0) {
      return child;
    }
  }

  return orxNULL;
}

// these four fns could be one function that takes the name
void Turret::FireGunZero (float firingSpeed) {
  EnemyGun *gunZero = (EnemyGun*)this->GetGunByName("0");

  if (gunZero != orxNULL) {
    gunZero->Fire(firingSpeed);

  }
}

void Turret::FireGunOne (float firingSpeed) {
  EnemyGun *gunZero = (EnemyGun*)this->GetGunByName("1");

  if (gunZero != orxNULL) {
    gunZero->Fire(firingSpeed);
  }
}

void Turret::FireGunTwo (float firingSpeed) {
  EnemyGun *gunZero = (EnemyGun*)this->GetGunByName("2");

  if (gunZero != orxNULL) {
    gunZero->Fire(firingSpeed);
  }
}

void Turret::FireGunThree (float firingSpeed) {
  EnemyGun *gunZero = (EnemyGun*)this->GetGunByName("3");

  if (gunZero != orxNULL) {
    gunZero->Fire(firingSpeed);
  }
}
