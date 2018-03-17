#pragma once
class skills_t
{
	bool self;
public:
	skills_t();
	~skills_t();
	virtual bool castSkill() = 0;
};

