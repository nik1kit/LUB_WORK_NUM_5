#pragma once
#include <iostream>
class KudryashovNA_String
{
private:
    char* str; ///< Указатель на массив символов строки.
    size_t sz; ///< Длина строки.

public:
    // Конструкторы и деструктор

    /**
     * @brief Конструктор по умолчанию.
     * Создает пустую строку.
     */
    KudryashovNA_String() : str(nullptr), sz(0) {}

    /**
     * @brief Конструктор с параметрами.
     * Создает строку с заданным набором символов.
     * @param s Указатель на массив символов.
     */
    KudryashovNA_String(const char* s) : sz(0) {
        while (s[sz] != '\0') {
            ++sz;
        }
        str = new char[sz + 1];
        for (size_t i = 0; i <= sz; ++i) {
            str[i] = s[i];
        }
    }

    /**
     * @brief Конструктор копирования.
     * Копирует содержимое одного объекта строки в другой.
     * @param other Ссылка на другой объект строки.
     */
    KudryashovNA_String(const KudryashovNA_String& other) : sz(other.sz) {
        str = new char[sz + 1];
        for (size_t i = 0; i <= sz; ++i) {
            str[i] = other.str[i];
        }
    }

    /**
     * @brief Деструктор.
     * Освобождает выделенную динамическую память.
     */
    ~KudryashovNA_String() {
        delete[] str;
    }

    // Методы

    /**
     * @brief Возвращает длину строки.
     * @return Длина строки.
     */
    size_t length() const {
        return sz;
    }

    /**
     * @brief Перегруженный оператор доступа к элементу строки по индексу.
     * @param index Индекс элемента.
     * @return Ссылка на элемент строки по указанному индексу.
     */
    char& operator[](size_t index) {
        return str[index];
    }

    /**
     * @brief Перегруженный оператор доступа к элементу строки для константных объектов.
     * @param index Индекс элемента.
     * @return Константная ссылка на элемент строки по указанному индексу.
     */
    const char& operator[](size_t index) const {
        return str[index];
    }

    /**
     * @brief Добавляет содержимое переданной строки в конец текущей строки.
     * @param other Ссылка на строку, которую необходимо добавить.
     */
    void append(const KudryashovNA_String& other) {
        char* newStr = new char[sz + other.sz + 1];
        for (size_t i = 0; i < sz; ++i) {
            newStr[i] = str[i];
        }
        for (size_t i = 0; i <= other.sz; ++i) {
            newStr[sz + i] = other.str[i];
        }

        delete[] str;
        str = newStr;
        sz += other.sz;
    }

    /**
     * @brief Возвращает подстроку строки.
     * @param start Позиция начала подстроки.
     * @param count Количество символов в подстроке.
     * @return Новый объект строки, представляющий подстроку.
     */
    KudryashovNA_String substr(size_t start, size_t count) const {
        KudryashovNA_String substring;
        substring.str = new char[count + 1];
        for (size_t i = 0; i < count; ++i) {
            substring.str[i] = str[start + i];
        }
        substring.str[count] = '\0';
        substring.sz = count;
        return substring;
    }

    /**
     * @brief Перегрузка оператора присваивания.
     * Перегружает оператор присваивания для копирования содержимого одной строки в другую.
     * @param other Ссылка на другой объект строки.
     * @return Ссылка на текущий объект строки после присваивания.
     */
    KudryashovNA_String& operator=(const KudryashovNA_String& other) {
        if (this != &other) {
            delete[] str;
            sz = other.sz;
            str = new char[sz + 1];
            for (size_t i = 0; i <= sz; ++i) {
                str[i] = other.str[i];
            }
        }
        return *this;
    }

    /**
     * @brief Перегрузка оператора конкатенации.
     * Позволяет объединить две строки.
     * @param other Ссылка на другой объект строки.
     * @return Новый объект строки, представляющий конкатенацию.
     */
    KudryashovNA_String operator+(const KudryashovNA_String& other) const {
        KudryashovNA_String result;
        result.sz = sz + other.sz;
        result.str = new char[result.sz + 1];
        for (size_t i = 0; i < sz; ++i) {
            result.str[i] = str[i];
        }
        for (size_t i = 0; i <= other.sz; ++i) {
            result.str[sz + i] = other.str[i];
        }
        return result;
    }

    /**
     * @brief Перегрузка операторов сравнения.
     * Перегружает операторы для сравнения строк.
     * @param other Ссылка на другой объект строки.
     * @return Результат сравнения строк.
     */
    bool operator==(const KudryashovNA_String& other) const {
        if (sz != other.sz) {
            return false;
        }
        for (size_t i = 0; i < sz; ++i) {
            if (str[i] != other.str[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const KudryashovNA_String& other) const {
        return !(*this == other);
    }

    bool operator<(const KudryashovNA_String& other) const {
        size_t min_sz = std::min(sz, other.sz);
        for (size_t i = 0; i < min_sz; ++i) {
            if (str[i] != other.str[i]) {
                return str[i] < other.str[i];
            }
        }
        return sz < other.sz;
    }

    bool operator>(const KudryashovNA_String& other) const {
        size_t min_sz = std::min(sz, other.sz);
        for (size_t i = 0; i < min_sz; ++i) {
            if (str[i] != other.str[i]) {
                return str[i] > other.str[i];
            }
        }
        return sz > other.sz;
    }

    bool operator<=(const KudryashovNA_String& other) const {
        return !(*this > other);
    }

    bool operator>=(const KudryashovNA_String& other) const {
        return !(*this < other);
    }

    // Перегрузка операторов ввода/вывода

    /**
     * @brief Перегрузка оператора ввода.
     * Позволяет вводить строку с консоли или из файла.
     * @param is Поток ввода.
     * @param s Ссылка на объект строки.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, KudryashovNA_String& s) {
        char buffer[100000];
        is >> buffer;
        s = KudryashovNA_String(buffer);
        return is;
    }

    /**
     * @brief Перегрузка оператора вывода.
     * Позволяет выводить строку на консоль или в файл.
     * @param os Поток вывода.
     * @param s Ссылка на константный объект строки.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const KudryashovNA_String& s) {
        setlocale(LC_ALL, "ru");
        os << s.str;
        return os;
    }
};

