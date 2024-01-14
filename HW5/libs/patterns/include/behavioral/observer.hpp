#pragma once

#include <memory>

namespace patterns {

/// @brief Интерфейс класса наблюдателя
class IObserver: public std::enable_shared_from_this<IObserver>
{
public:
    /// @brief деструктор
    virtual ~IObserver() = default;

    /// @brief Обработчик события от наблюдаемого объекта
    virtual void notifyHandler() = 0;
};
        
template <typename Derived>
class Observer: public IObserver
{
public:
    void notifyHandler() override final
    {
        static_cast<Derived *>(this)->handler();
    }    
};

}