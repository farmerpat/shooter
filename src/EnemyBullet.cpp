#include "EnemyBullet.h"
#include "shooter.h"
#include "Scroll.h"

void EnemyBullet::OnCreate () {
  // i feel like I should make an attempt to store a pointer instead...
  // this will take lots of memory inside bullet hell
  this->_gameInstance = ShooterGame::GetInstance();
}

void EnemyBullet::OnDelete () { }

void EnemyBullet::Update (const orxCLOCK_INFO &_rstInfo) {
  // camera might be better in a different game where cam is not static...
  //ShooterGame game = ShooterGame::GetInstance();
  //orxCAMERA *camera = game.GetMainCamera();
  //orxAABOX *frustum;
  //frustum = orxCamera_GetFrustum(camera, frustum);

  orxAABOX *box = new orxAABOX();
  const orxVIEWPORT *vp = this->_gameInstance.GetMainViewport();
  orxViewport_GetBox(vp, box);

  orxVECTOR bottomRightVector = box->vBR;
  orxVECTOR topLeftVector = box->vTL;

  float minX = topLeftVector.fX;
  float minY = topLeftVector.fY;

  float maxX = bottomRightVector.fX;
  float maxY = bottomRightVector.fY;

  orxVECTOR mySize = orxVECTOR();
  orxVECTOR myPosition = orxVECTOR();

  this->GetPosition(myPosition, orxTRUE);
  this->GetSize(mySize);

  if ((myPosition.fX + mySize.fX) < minX or (myPosition.fY + mySize.fY) < minY or (myPosition.fX - mySize.fX) > maxX or (myPosition.fY - mySize.fY) > maxY) {
    this->SetLifeTime(0.0f);
  }
}

void EnemyBullet::setDamage (int newDamage) {
  this->m_damage = newDamage;
}

int EnemyBullet::getDamage () {
  return this->m_damage;
}
