#include "Turret.h"
#include "EnemyGun.h"

int globCounter = 0;
int globFrameDelay = 100;

void Turret::OnCreate () {
  // assume that there only one type of turret now...
  // a single, top-mounted turret...
  orxFLOAT rot = 180.0 * orxMATH_KF_DEG_TO_RAD;
  orxVECTOR size;
  this->GetSize(size);

  // center it
  //orxVECTOR pos = { 512 + (size.fX / 2), 115, 0 };
  orxVECTOR pos = { 512 + (size.fX), 115, 0 };

  this->SetRotation(rot, orxFALSE);
  this->SetPosition(pos);
}

void Turret::OnDelete () { }

void Turret::Update (const orxCLOCK_INFO &_rstInfo) {
  if (globCounter >= globFrameDelay) {
    globCounter=0;
    this->FireGunZero();
  } else {
    globCounter++;
  }
}

orxBOOL Turret::OnCollide (
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal
) {

  orxLOG("\ncollision!");

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

// there might not need to be separate functions
// for firing each gun
void Turret::FireGunZero () {
  EnemyGun *gunZero = (EnemyGun*)this->GetGunByName("0");

  if (gunZero != orxNULL) {
    gunZero->Fire();

  }
}

void Turret::FireGunOne () {
}

void Turret::FireGunTwo () {
}

void Turret::FireGunThree () {
}
