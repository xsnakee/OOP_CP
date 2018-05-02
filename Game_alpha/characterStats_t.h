#pragma once
struct characterStats_t
{
	float HP = 100.f;
	float stdHP = 100.f;

	float MP = 5.f;
	float stdMP = 5.f;

	float attackPower = 1.f;
	float stdattackPower = 1.f;

	float physDef = 1.f;
	float stdPhysDef = 1.f;

	float magDef = 1.f;
	float stdMagDef = 1.f;

	float speed = 0.1f;
	float stdSpeed = 0.1f;

	int castSpeed = 1;
	int attackSpeed = 1;

	float damageRand = 5.f;

	float attackRange = 40.f;
	float visionDistance = 100.f;

	void resetStats() {
		HP = MP = attackPower =
			physDef = magDef = speed = 0.f;
	}

	void defaultStats() {
		HP = stdHP;
		MP = stdMP;
		attackPower = stdattackPower;
		physDef = stdPhysDef;
		magDef = stdMagDef;
		speed = stdSpeed;
	}

	void statMiltipler(float _mult) {
		float speedK = 0.02f;

		HP *= _mult;
		stdHP *= _mult;
		MP *= _mult;
		stdMP *= _mult;
		attackPower *= _mult;
		stdattackPower *= _mult;
		physDef *= _mult;
		stdPhysDef *= _mult;
		magDef *= _mult;
		stdMagDef *= _mult;
		speed += _mult * speedK;
		stdSpeed += _mult * speedK;
	}
};

