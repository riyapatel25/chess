#include "subject.h"


void Subject::attach(Observer* ob) {
    observers.emplace_back(ob); 
}

void Subject::detach(Observer* ob) {
    auto it = std::find(observers.begin(), observers.end(), ob);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Subject::notifyObservers() {
    for (auto ob : observers) {
        ob->update();
    }
}

Subject::~Subject() {}
