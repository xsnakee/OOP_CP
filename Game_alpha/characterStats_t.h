#pragma once
class characterStats_t
{
public:
	float HP;
	float stdHP;

	float AP;
	float stdAP;

	float stamina;
	float stdStamina;

	float atackPower;
	float stdAtackPower;

	float physDef;
	float stdPhysDef;

	float magDef;
	float stdMagDef;

	float speed;
	float stdSpeed;

	float castSpeed;
	float damageRand;

	float attackMultiple;
	float defMulttiple;
	float attackRang;
	characterStats_t();
	virtual ~characterStats_t();
};

