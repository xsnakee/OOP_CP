#include "characterStats_t.h"



characterStats_t::characterStats_t()
{
	HP = stdHP = 100.F;
	AP = stdAP = 5.F;
	stamina = stdStamina = 100.f;
	atackPower = stdAtackPower = 1.f;
	physDef = stdPhysDef = 1.f;
	magDef = stdMagDef = 1.f;
	speed = stdSpeed = 0.f;
	castSpeed = 1.f;
	damageRand = 5.f;
	attackMultiple = 1.f;
	defMulttiple = 1.f;
	attackRang = 20.f;
}


characterStats_t::~characterStats_t()
{
}
