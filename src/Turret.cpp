#include "Turret.h"

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
