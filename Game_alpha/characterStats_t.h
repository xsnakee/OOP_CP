#pragma once
struct characterStats_t
{
	float HP = 100.f;
	float stdHP = 100.f;

	float MP = 5.f;
	float stdMP = 5.f;

	float stamina = 100.f;
	float stdStamina = 100.f;

	float atackPower = 1.f;
	float stdAtackPower = 1.f;
	
	float physDef = 1.f;
	float stdPhysDef = 1.f;

	float magDef = 1.f;
	float stdMagDef = 1.f;

	float speed = 0.1f;
	float stdSpeed = 0.1f;

	float castSpeed = 1.f;
	float damageRand = 5.f;

	float attackMultiple = 1.f;
	float defMulttiple = 1.f;
	float attackRange = 20.f;


	void resetStats(characterStats_t &stats) {
		stats.HP = stats.stdHP = stats.MP = stats.stdMP = stats.stamina =
			stats.stdStamina = stats.atackPower = stats.stdAtackPower =
			stats.physDef = stats.stdPhysDef = stats.magDef = stats.stdMagDef
			= stats.speed = stats.stdSpeed = stats.castSpeed = stats.damageRand =
			stats.attackMultiple = stats.defMulttiple = stats.attackRange = 0.f;
	}
};

