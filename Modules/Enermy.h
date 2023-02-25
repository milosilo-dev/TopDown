#ifndef __ENERMY_H__
#define __ENERMY_H__

#include "Entity.h"
class Enermy{
    public:
        Entity self = Entity();
        int iSecret;
        int Health;
        bool swi;
        void init();
        void frame();
        void moveAI();
        void kill();
};
#endif