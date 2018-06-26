#include "Hero.h"

void Hero::OnCreate () {
  m_movementSpeed = orxConfig_GetFloat("MovementSpeed");
  this->herosGun = this->GetOwnedChild();
  this->herosGun->Enable(orxFALSE);
}

void Hero::OnDelete () { }

void Hero::Update (const orxCLOCK_INFO &_rstInfo) {
  orxVECTOR speed = orxVECTOR_0;

  if (orxInput_IsActive("MoveLeft")) {
    // prevent from going out of bounds
    speed.fX = -m_movementSpeed;

  } else if (orxInput_IsActive("MoveRight")) {
    // prevent from going out of bounds
    speed.fX = m_movementSpeed;

  }

  if (orxInput_IsActive("Shoot") && orxInput_HasNewStatus("Shoot")) {
    this->herosGun->Enable(orxTRUE);
  } else {
    this->herosGun->Enable(orxFALSE);
  }

  SetSpeed(speed, false);
}

orxBOOL Hero::OnCollide (
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal
) {

  // this probably bombs because the laser isn't a ScrollObject
  // ...should probably make it one so that we can destroy...
  //const orxSTRING colliderName = _poCollider->GetModelName();

  // take damage or die...
  if (orxString_Compare(_zColliderPartName, "EnemyLaserBodyPart") == 0) {
    orxLOG("\n das laser collision...");
  }

  return orxTRUE;
}
