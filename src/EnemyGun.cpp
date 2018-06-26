#include "EnemyGun.h"

void EnemyGun::OnCreate () { }

void EnemyGun::OnDelete () { }

void EnemyGun::Update (const orxCLOCK_INFO &_rstInfo) { }

void EnemyGun::Fire () {
  // append an EnemyBulletObject to its own ChildList
  orxOBJECT *bullet;
  orxVECTOR speedVector = orxVECTOR_0;

  bullet = (orxOBJECT*)orxObject_CreateFromConfig("EnemyBulletObject");

  orxObject_SetParent(bullet, this->GetOrxObject());

  speedVector.fY = -20.0f;

  orxObject_SetSpeed(bullet, &speedVector);
}
