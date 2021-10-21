//
// Created by enzor on 18/10/2021.
//

#ifndef REDES_M2_SUBJECT_H
#define REDES_M2_SUBJECT_H
#include <vector>
#include "Observer.h"

template <typename ... Args>
class Subject
{
public:
    virtual ~Subject() = default;
    virtual void register_observer(Observer<Args...>& observer)
    {
        observers.push_back(observer);
    }

protected:

    virtual void notify_observers(Args ... args)
    {
        for(Observer<Args...>& obs : observers)
        {
            obs.notify((args)...);
        }
    }

    std::vector<std::reference_wrapper<Observer<Args...>>> observers;
};
#endif //REDES_M2_SUBJECT_H
