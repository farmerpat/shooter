// these should probably be added to all the header files...
#ifndef TURRET_H
#define TURRET_H
#include "shooter.h"
#include <string>

// add a turret bullet child
// add a hero bullet object?
// scenes?
class Turret : public ScrollObject {
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

  protected:
    ScrollObject* GetGunByName (const std::string);
    void FireGunZero ();
    void FireGunOne ();
    void FireGunTwo ();
    void FireGunThree ();
};

#endif
