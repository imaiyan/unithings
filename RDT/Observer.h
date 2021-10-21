//
// Created by enzor on 18/10/2021.
//

#ifndef REDES_M2_OBSERVER_H
#define REDES_M2_OBSERVER_H

template <typename ... Args>
class Subject;

template <typename ... Args>
class Observer
{
    friend class Subject<Args...>;
public:
    virtual ~Observer() = default;

    virtual void notify(Args ... args) = 0;
};
#endif //REDES_M2_OBSERVER_H
