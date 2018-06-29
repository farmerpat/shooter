#include "Hero.h"
#include "EnemyBullet.h"
#include <string>

void Hero::OnCreate () {
  m_movementSpeed = orxConfig_GetFloat("MovementSpeed");
  this->m_herosGun = this->GetOwnedChild();
  this->m_herosGun->Enable(orxFALSE);
  this->m_herosHealthBar = orxObject_CreateFromConfig("HerosHealthBar");
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

  // this seems more ineffecient than keeping track
  // or whether or not we need to do this (e.g. healthHasChanged flag),
  // and then doing it
  this->updateHealthBar();

  if (this->m_alive && (this->getHeath() <= 0)) {
    this->explode();

  }
}

void Hero::updateHealthBar () {
  /*
  // first param is resource group name, second param is resource name,
  // they are both strings
  orxSTRING resourceGroup = "Texture";
  orxSTRING resourceName = "Health90.png";

  //const orxSTRING fileName = orxResource_Locate(resourceGroup, resourceName);
  //orxLOG("fileName: %s", fileName);

  const orxSTRING fileName = "file:/home/pconnelly/hacks/orx/shooter/data/texture/Health90.png";

  // bool == true will keep texture in cache after all referenches die
  orxTEXTURE *texture = orxTexture_CreateFromFile (fileName, orxTRUE);

  //orxTEXTURE *texture = orxTexture_CreateFromFile (fileName, orxFALSE);
  orxGRAPHIC *healthBarGraphic = orxObject_GetWorkingGraphic(this->m_herosHealthBar);
  orxGraphic_SetData(healthBarGraphic, (orxSTRUCTURE*) texture);
  */

  // is it bad to include string just for this,
  // instead of using orxSTRING?
  std::string fileName;

  if (this->getHeath() >= 100) {
    fileName = "Health100.png";

  } else if (this->getHeath() >= 90) {
    fileName = "Health90.png";

  } else if (this->getHeath() >= 80) {
    fileName = "Health80.png";

  } else if (this->getHeath() >= 70) {
    fileName = "Health70.png";

  } else if (this->getHeath() >= 60) {
    fileName = "Health60.png";

  } else if (this->getHeath() >= 50) {
    fileName = "Health50.png";

  } else if (this->getHeath() >= 40) {
    fileName = "Health40.png";

  } else if (this->getHeath() >= 30) {
    fileName = "Health30.png";

  } else if (this->getHeath() >= 20) {
    fileName = "Health20.png";

  } else if (this->getHeath() >= 10) {
    fileName = "Health10.png";

  } else {
    fileName = "Health0.png";

  }

  orxConfig_PushSection("HerosHealthBarGraphic");
  orxSTRING field = "Texture";
  const orxSTRING textureOriginalValue = orxConfig_GetString(field);
  orxConfig_SetString("Texture", (orxCHAR*)fileName.c_str());

  orxObject_Delete(this->m_herosHealthBar);

  this->m_herosHealthBar = orxObject_CreateFromConfig("HerosHealthBar");
  orxConfig_PopSection();

}

int Hero::getHeath () {
  return this->m_hp;
}

int Hero::getLives () {
  return this->m_lives;
}

bool Hero::isAlive () {
  return this->m_alive;
}

void Hero::explode () {
  // check the number of lives before killing him off completely...
  this->m_alive = false;

  orxLOG("exploding hero!");

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

    // destroy bullet and its children
    bullet->Enable(orxFALSE, orxTRUE);

    if (this->m_hp < 0) {
      this->m_hp = 0;
    }
  }

  return orxTRUE;
}
