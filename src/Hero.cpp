#include "Hero.h"
#include "EnemyBullet.h"

void Hero::OnCreate () {
  m_movementSpeed = orxConfig_GetFloat("MovementSpeed");
  this->m_herosGun = this->GetOwnedChild();
  this->m_herosGun->Enable(orxFALSE);
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
    this->m_herosGun->Enable(orxTRUE);
  } else {
    this->m_herosGun->Enable(orxFALSE);
  }

  SetSpeed(speed, false);
}

int Hero::getHeath () {
  return this->m_hp;
}

orxBOOL Hero::OnCollide (
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal
) {

  // _poCollider is the object that hit us
  // _zPartName is the body part of our that was hit
  // _zColliderPartName is the body part of the object that hit us
  // presumably, _rvPosition is the point of collision
  // and _rvNormal is the normal of the collision

  const orxSTRING colliderName = _poCollider->GetModelName();

  if (orxString_Compare(colliderName, "EnemyBulletObject") == 0) {
    EnemyBullet *bullet = (EnemyBullet*)_poCollider;

    // take damage
    this->m_hp -= bullet->getDamage();

    // show effect...

    // destroy bullet
    bullet->Enable(orxFALSE);

    orxLOG("new hp: %d", this->m_hp);

    if (this->m_hp < 0) {
      this->m_hp = 0;
    }
  }

  return orxTRUE;
}
