#ifndef __FIXED_TURRET_H_
#define __FIXED_TURRET_H_
#include "shooter.h"
#include "Turret.h"
#include <string>

// maybe it makes sense to derrive classes
// based on fixed turret position, border position,
// firing pattern, etc...but it may make more sense
// to create FixedTurret objects, and then set all that stuff
class FixedTurret : public Turret {
  private:
    virtual void OnCreate ();
    virtual void OnDelete ();
    virtual orxBOOL OnCollide (
        ScrollObject *_poCollider,
        const orxSTRING _zPartName,
        const orxSTRING _zColliderPartName,
        const orxVECTOR &_rvPosition,
        const orxVECTOR &_rvNormal
    );
    virtual void Update (const orxCLOCK_INFO &_rstInfo);

    std::string m_firingPattern;
    std::string m_mountPosition;
    std::string m_mountBorder;
    int consecutivePatternGunToFire = -1;
    float m_firingSpeed = -2.0f;
    orxFLOAT m_firingDelay = 1.0f;
    orxFLOAT m_dtElapsed = 0.0f;

  public:
    void setFiringPattern (std::string);
    void setMountPosition (std::string);
    void setMountBorder (std::string);
    void setFiringSpeed (float);
    void setFiringDelay (orxFLOAT);
    orxFLOAT getFiringDelay ();
};

#endif
