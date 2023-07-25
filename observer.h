#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer();
};


#endif