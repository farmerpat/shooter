#ifndef __ENEMY_GUN_
#define __ENEMY_GUN_

#include "shooter.h"

class EnemyGun : public ScrollObject {
  private:
    virtual void OnCreate ();
    virtual void OnDelete ();
    virtual void Update (const orxCLOCK_INFO &_rstInfo);

  public:
    // might consider giving this a parameter or two...
    // e.g. shot direction...
    void Fire (float firingSpeed = 5.0f);
};

#endif
