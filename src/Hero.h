#include "shooter.h"

class Hero : public ScrollObject {
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

    orxFLOAT m_movementSpeed;
    ScrollObject *herosGun;
};
