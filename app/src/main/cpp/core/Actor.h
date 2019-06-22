//
// Created by kumar on 6/22/2019.
//

#ifndef __ACTOR__
#define __ACTOR__



class Actor{
protected:
    int x,y;
    bool alive;
    bool visible;
public:
    Actor(int x, int y): x(x), y(y){

    }

    bool IsAlive() {
        return alive;
    }

    bool IsVisible(){
        return visible;
    }
};

#endif // __ACTOR__
