#pragma once

#include <list>
#include "observer.hpp"

namespace patterns {

class Observable
{
public:
    void addObserver(std::weak_ptr<IObserver> &&obs)
    {
        m_observers.push_back(std::forward<decltype(obs)>(obs));
    }

protected:
    template <typename ... Args>
    void notityEvent(Args ...args)
    {
        for (auto &&observer : m_observers)
        {
            auto sho = observer.lock();
            if (sho)
                sho->notifyHandler(std::forward<Args>(args)...);
        }
        
    }

private:
    std::list<std::weak_ptr<IObserver>> m_observers;
};

}
