#include "shooter.h"

class EnemyGun : public ScrollObject {
  private:
    virtual void OnCreate ();
    virtual void OnDelete ();
    virtual void Update (const orxCLOCK_INFO &_rstInfo);

  public:
    // might consider giving this a parameter or two...
    // e.g. shot direction...
    void Fire (float firingSpeed = 20.0f);
};
