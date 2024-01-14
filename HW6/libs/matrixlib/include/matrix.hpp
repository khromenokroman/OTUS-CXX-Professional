#pragma once

#include <map>
#include <limits>
#include <numeric>
#include <string>

/// @brief Шаблонный класс разреженной N-мерной матрицы, заполненной значениями по умолчанию
/// @tparam T тип значений
/// @tparam defaultValue значение по умолчанию
/// @tparam Dimension размерность матрицы, по умолчанию равна 2
template <typename T, T defaultValue, std::size_t Dimension = 2>
class Matrix
{
public:
    /// @brief Тип внутреннего хранилища данных
    using Storage = std::map<std::size_t, Matrix<T, defaultValue, Dimension - 1>>;

    /// @brief Возвращает количество ячеек, содержащих элементы, отличные от значения по умолчанию,
    /// под которые выделена память
    /// @return 
    constexpr std::size_t size() const
    {
        std::size_t res {0};
        for (auto &&pair : m_data)
            res += pair.second.size();

        return res;
    }

    /// @brief Прокси-класс для доступа к i-му измерению матрицы без прямого доступа к хранимому типу
    /// @remarks Используется для скрытия реализации структуры данных и сохранения инвариантности
    class ItemProxy
    {
    public:

        /// @brief Тип прокси-класса для следующего измерения матрицы
        using IndexValueProxy = typename Matrix<T, defaultValue, Dimension - 1>::ItemProxy;

        /// @brief Конструктор прокси класса 
        /// @param dataPtr указатель на хранилище данных конкретного измерения
        /// @param index индекс в хранилище, при обращении к которому создаётся данный обект
        ItemProxy(Storage *dataPtr, std::size_t index) noexcept: m_dataPtr{dataPtr}, m_index {index}
        {}

        ItemProxy(const ItemProxy &) = delete;

        /// @brief Конструктор перемещения
        /// @param Перемещаемый прокси-объект 
        ItemProxy(ItemProxy &&) noexcept = default;

        /// @brief Деструктор
        ~ItemProxy()
        {
            // 1.Для неконстантной матрицы при обращении к несуществующему элементу и размерности происходит выделение
            // памяти. После удаления этого прокси-объекта, если для данной размерности нет элементов, эти данные удаляются
            // 2.Для константной матрицы никаких выделений памяти при обращении к несуществующим элементам никакая память не выделяется
            if (m_dataPtr != nullptr) {
                const auto it = m_dataPtr->find(m_index);
                if ((it != m_dataPtr->cend()) && (it->second.size() == 0))
                    m_dataPtr->erase(it);
            }
        }

        /// @brief Константный оператор доступа по индексу, который возвращает прокси-объект для следующей размерности
        /// @param index Индекс текущей размерности
        /// @return прокси-объект для следующей размерности
        IndexValueProxy operator[](std::size_t index) const
        {
            if (m_dataPtr == nullptr)
                return IndexValueProxy(nullptr, index);

            const auto it = m_dataPtr->find(index);
            if (it == m_dataPtr->cend())
                return IndexValueProxy(nullptr, index);

            return (*m_dataPtr)[m_index][index];
        }

        /// @brief Модифицирующий оператор доступа по индексу, который возвращает прокси-объект для следующей размерности
        /// @param index Индекс текущей размерности
        /// @return Прокси-объект для следующей размерности
        auto operator[](std::size_t index)
        {
            return (*m_dataPtr)[m_index][index];
        }

    private:
        Storage *m_dataPtr {nullptr};
        std::size_t m_index;
    };

    /// @brief Оператор доступа по индексу для текущей размерности матрицы
    /// @param index Текущий индекс размерности
    /// @return Прокси-объект для доступа к данным текущей размерности
    ItemProxy operator[](std::size_t index)
    {
        return ItemProxy(std::addressof(m_data), index);
    }

private:
    Storage m_data;
};

/// @brief Частичная специализация шаблонного класса разреженной одномерной матрицы, заполненной значениями по умолчанию
/// @tparam T Тип данных
/// @tparam defaultValue Значение по умолчанию
template <typename T, T defaultValue>
class Matrix<T, defaultValue, 1>
{
public:
    /// @brief Алиас на тип структуры хранения данных
    using Storage = std::map<std::size_t, T>;

    /// @brief Количество элементов, под которые выделена память
    /// @return Количество элементов, под которые выделена память
    constexpr std::size_t size() const
    {
        return m_data.size();
    }

    /// @brief Прокси-класс для доступа к последнему измерению матрицы без прямого доступа к хранимому типу
    /// @remarks Используется для скрытия реализации структуры данных и сохранения инвариантности
    class ItemProxy
    {
    public:
        /// @brief Конктруктор прокси-класса
        /// @param dataPtr Указатель на структуру хранения данных. Может быть nullptr, если идёт обращение 
        /// к несуществующему элементу константной матрицы
        /// @param index 
        ItemProxy(Storage *dataPtr, std::size_t index) noexcept: m_dataPtr{dataPtr}, m_index {index}
        {}

        ItemProxy(const ItemProxy &) = delete;

        /// @brief Конструктор перемещения
        /// @param  Перемещаемый объект
        ItemProxy(ItemProxy &&) noexcept = default;
        ~ItemProxy() = default;

        /// @brief Константный оператор доступа по индексу для последней размерности
        /// @param index Индекс размерности для доступа к значнию
        /// @return Возвращает копию значения элемента = dafaultValue, если не задан, иначе установленное значение
        T operator[](std::size_t index) const
        {
            return valueByIndex(index);
        }

        /// @brief Модицицирующий оператор доступа по индексу для последней размерности
        /// @param index Индекс размерности для доступа к значнию
        /// @return Возвращает копию значения элемента равную dafaultValue, если не задан, иначе установленное значение
        T operator[](std::size_t index)
        {
            return valueByIndex(index);
        }

        /// @brief Константный преобразователь прокси-объекта к типу T
        operator T() const
        {
            return valueByIndex(m_index);
        }

        /// @brief  Модифицирующий преобразователь прокси-объекта к типу T
        /// @remarks Используется при сравнении с хранимым значением, получении этого значения
        operator T()
        {
            return valueByIndex(m_index);
        }

        /// @brief Оператор присваивания. Используется для установки значения для элемента, который скрывает данный 
        // прокси-объект. Если устанавливается значение, равное defaultValue, то память под элемент освобождается
        /// @param value Устанавливаемое значение
        /// @return 
        ItemProxy &operator=(T value)
        {
            assert(m_dataPtr != nullptr);

            if (value == defaultValue)
                m_dataPtr->erase(m_index);
            else
                (*m_dataPtr)[m_index] = value;

            return *this;
        }

    private:
        /// @brief Константная функция получения значения по индексу
        /// @param index Индекс
        /// @return 
        T valueByIndex(std::size_t index) const
        {
            if (m_dataPtr == nullptr)
                return defaultValue;

            const auto it = m_dataPtr->find(index);
            if (it == m_dataPtr->cend())
                return defaultValue;

            return (*m_dataPtr)[index];

        }
        Storage *m_dataPtr {nullptr};
        std::size_t m_index;
    };

    /// @brief Константный оператор доступа по индексу
    /// @param index Индекс
    /// @return Значение, которое хранится по индексу index. Возвращается defaultValue 
    /// значение, если память под элемент не выделялась и не было к нему образения
    const T &operator[](std::size_t index) const
    {
        if (m_data == nullptr)
            return defaultValue;

        const auto it = m_data->find(index);
        if (it  == m_data.cend())
            return defaultValue;

        return (*m_data)[index];
    }

    /// @brief Модицирующий оператор доступа по индексу
    /// @param index Индекс размерности
    /// @return Возмращает прокси-объект для доступа к выбранному индексу
    ItemProxy operator[](std::size_t index)
    {
        return ItemProxy(&m_data, index);
    }

private:
    Storage m_data;
};
