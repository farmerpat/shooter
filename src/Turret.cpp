#include "Turret.h"

void Turret::OnCreate () {

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
