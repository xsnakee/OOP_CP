#pragma once
struct characterStats_t
{
	float HP = 100.f;
	float stdHP = 100.f;

	float MP = 0.f;
	float stdMP = 100.f;

	float attackPower = 5.f;
	float stdattackPower = 5.f;

	float physDef = 1.f;
	float stdPhysDef = 1.f;

	float magDef = 1.f;
	float stdMagDef = 1.f;

	float speed = 0.1f;
	float stdSpeed = 0.1f;

	float castSpeed = 2.f;
	float attackSpeed = 3.f;

	float damageRand = 5.f;

	float attackRange = 40.f;
	float visionDistance = 300.f;

	void resetStats() {
		HP = MP = attackPower =
			physDef = magDef = speed = 0.f;
	}

	void defaultStats() {
		attackPower = stdattackPower;
		physDef = stdPhysDef;
		magDef = stdMagDef;
		speed = stdSpeed;
	}
	void upStat(characterStats_t &stat) {
		HP += stat.HP;
		MP += stat.MP;
		attackPower += stat.attackPower;
		physDef += stat.physDef;
		magDef += stat.magDef;
		speed += stat.speed;
	}

	void statMiltipler(float _mult = 1.f) {
		float speedK = 0.01f;
		float tempMult = abs(_mult);

		HP *= tempMult;
		stdHP *= tempMult;
		MP *= tempMult;
		stdMP *= tempMult;
		attackPower *= tempMult;
		stdattackPower *= tempMult;
		physDef *= tempMult;
		stdPhysDef *= tempMult;
		magDef *= tempMult;
		stdMagDef *= tempMult;
		attackSpeed *= tempMult;

		if (tempMult > 1.f) {
			speed += speedK * tempMult;
			stdSpeed += speedK * tempMult;
		}
	}
};

