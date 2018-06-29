// these should probably be added to all the header files...
#ifndef __TURRET_H_
#define __TURRET_H_
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
    void FireGunZero (float firingSpeed = 20.0f);
    void FireGunOne (float firingSpeed = 20.0f);
    void FireGunTwo (float firingSpeed = 20.0f);
    void FireGunThree (float firingSpeed = 20.0f);
    int m_hp = 100;

  public:
    int getHeath ();
};

#endif
