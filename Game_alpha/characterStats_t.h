#pragma once
struct characterStats_t
{
	float HP = 100.f;
	float stdHP = 100.f;

	float MP = 5.f;
	float stdMP = 5.f;

	float atackPower = 1.f;
	float stdAtackPower = 1.f;
	
	float physDef = 1.f;
	float stdPhysDef = 1.f;

	float magDef = 1.f;
	float stdMagDef = 1.f;

	float speed = 0.1f;
	float stdSpeed = 0.1f;

	int castSpeed = 1;
	int attackSpeed = 1;

	float damageRand = 5.f;

	float attackRange = 20.f;

	void resetStats() {
		HP = stdHP = MP = stdMP = atackPower = 
			stdAtackPower = physDef = stdPhysDef = magDef =
			stdMagDef = speed = stdSpeed = 0.f;
	}

	void defaultStats() {
		HP = stdHP;
		MP = stdMP;
		atackPower = stdAtackPower;
		physDef = stdPhysDef;
		magDef = stdMagDef;
		speed = stdSpeed;
	}
};

