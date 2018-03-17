/**
 * Project Untitled
 */


#ifndef _SKILL_T_H
#define _SKILL_T_H

class skill_t {
public: 
    float damage;
    float range;
    float AOE;
    bool penetrate;
    size_t element;
    size_t id;
    bool collision;
    
    void skill_t();
    
    void update();
    
    void trajectory();
};

#endif //_SKILL_T_H