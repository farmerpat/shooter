#ifndef __SHOOTER_H_
#define __SHOOTER_H_

#define __NO_SCROLLED__
#include <Scroll.h>

class ShooterGame : public Scroll<ShooterGame> {
  public:
  private:
    virtual void BindObjects ();
    virtual orxSTATUS Bootstrap () const;
    virtual orxSTATUS Init ();
    virtual orxSTATUS Run ();
    virtual void Exit();
    virtual void CameraUpdate(const orxCLOCK_INFO &_rstInfo);
    virtual void OnStartGame ();
    virtual void OnStopGame ();
    virtual void OnPauseGame (orxBOOL);

};

#endif
