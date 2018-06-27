#include "EnemyBullet.h"

void EnemyBullet::OnCreate () { }

void EnemyBullet::OnDelete () { }

void EnemyBullet::Update (const orxCLOCK_INFO &_rstInfo) { }

void EnemyBullet::setDamage (int newDamage) {
  this->m_damage = newDamage;
}

int EnemyBullet::getDamage () {
  return this->m_damage;
}
