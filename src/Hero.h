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
    void updateHealthBar ();

    orxFLOAT m_movementSpeed;
    ScrollObject *m_herosGun;
    int m_hp = 100;
    orxOBJECT *m_herosHealthBar;

  public:
    int getHeath ();
};
