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

    orxSTRING m_firingPattern;
    orxSTRING m_mountPosition;
    orxSTRING m_mountBorder;
    int consecutivePatternGunToFire = -1;

  public:
    void setFiringPattern (std::string);
    void setMountPosition (std::string);
    void setMountBorder (std::string);
};
