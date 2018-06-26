#include "FixedTurret.h"
//#include "EnemyGun.h"

int globCounter = 0;
int globFrameDelay = 100;

void FixedTurret::OnCreate () {
  this->m_firingPattern = (orxSTRING)orxConfig_GetString("FiringPattern");
  this->m_mountPosition = (orxSTRING)orxConfig_GetString("MountPosition");
  this->m_mountBorder = (orxSTRING)orxConfig_GetString("MountBorder");

  if (orxString_Compare(m_firingPattern, "consecutive") == 0) {
    this->consecutivePatternGunToFire = 0;
  }

  if (orxString_Compare(m_mountBorder, "top") == 0) {
    if (orxString_Compare(m_mountPosition, "center") == 0) {
      orxFLOAT rot = 180.0 * orxMATH_KF_DEG_TO_RAD;
      orxVECTOR size;
      this->GetSize(size);

      //orxVECTOR pos = { 512 + (size.fX / 2), 115, 0 };
      orxVECTOR pos = { 512.0f + (size.fX), 115.0f, 0.0f };

      this->SetRotation(rot, orxFALSE);
      this->SetPosition(pos);

    }
  }
}

void FixedTurret::OnDelete () { }

void FixedTurret::Update (const orxCLOCK_INFO &_rstInfo) {
  // use a proper clock for this...
  if (globCounter >= globFrameDelay) {
    // try making a firing pattern or something...how to implement

    globCounter = 0;

    if (orxString_Compare(m_firingPattern, "consecutive") == 0) {
      if (this->consecutivePatternGunToFire == 0) {
        this->FireGunZero();
        this->consecutivePatternGunToFire = 1;

      } else if (this->consecutivePatternGunToFire == 1) {
        this->FireGunOne();
        this->consecutivePatternGunToFire = 2;

      } else if (this->consecutivePatternGunToFire == 2) {
        this->FireGunTwo();
        this->consecutivePatternGunToFire = 3;

      } else if (this->consecutivePatternGunToFire == 3) {
        this->FireGunThree();
        this->consecutivePatternGunToFire = 0;

      }
    } else if (orxString_Compare(m_firingPattern, "concurrent") == 0) {
        this->FireGunZero();
        this->FireGunOne();
        this->FireGunTwo();
        this->FireGunThree();

    }
  } else {
    globCounter++;

  }
}

void FixedTurret::setFiringPattern (std::string newPattern) {
  // error-check this
  this->m_firingPattern = (orxCHAR*)newPattern.c_str();
}

void FixedTurret::setMountPosition (std::string newMountPosition) {
  this->m_mountPosition = (orxCHAR*)newMountPosition.c_str();
}

void FixedTurret::setMountBorder (std::string newMountBorder) {
  this->m_mountBorder = (orxCHAR*)newMountBorder.c_str();
}

orxBOOL FixedTurret::OnCollide (
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal
) {

  orxLOG("\nFixedTurret collision!");

  return true;
}