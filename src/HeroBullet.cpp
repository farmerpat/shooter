#include "HeroBullet.h"
#include "shooter.h"
#include "Scroll.h"

/*
 * consider refactoring by adding Bullet ScrollObject that this and EnemyBullet can be derived from...
 *  it could have a function that does the out of bounds check instead of having the code
 *  duplicated in each respective Update definition
 */

void HeroBullet::OnCreate () {
  // i feel like I should make an attempt to store a pointer instead...
  // this will take lots of memory inside bullet hell
  // ...actually, I bet it is a reference...
  this->_gameInstance = ShooterGame::GetInstance();
}

void HeroBullet::OnDelete () { }

void HeroBullet::Update (const orxCLOCK_INFO &_rstInfo) {
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

void HeroBullet::setDamage (int newDamage) {
  this->m_damage = newDamage;
}

int HeroBullet::getDamage () {
  return this->m_damage;
}
