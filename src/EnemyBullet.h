#include "shooter.h"

class EnemyBullet : public ScrollObject {
  private:
    virtual void OnCreate ();
    virtual void OnDelete ();
    virtual void Update (const orxCLOCK_INFO &_rstInfo);
    int m_damage = 10;

  public:
    void setDamage (int);
    int getDamage ();
};
