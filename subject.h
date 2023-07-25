#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <vector>
#include <algorithm>

using namespace std;

class Subject {
    vector<Observer*> observers;
  public:
    void attach(Observer* ob);
    void detach(Observer* ob);
    void notifyObservers();
    virtual ~Subject() = 0;
};

#endif
