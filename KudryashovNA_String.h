#pragma once
#include <iostream>
class KudryashovNA_String
{
private:
    char* str; ///< ��������� �� ������ �������� ������.
    size_t sz; ///< ����� ������.

public:
    // ������������ � ����������

    /**
     * @brief ����������� �� ���������.
     * ������� ������ ������.
     */
    KudryashovNA_String() : str(nullptr), sz(0) {}

    /**
     * @brief ����������� � �����������.
     * ������� ������ � �������� ������� ��������.
     * @param s ��������� �� ������ ��������.
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
     * @brief ����������� �����������.
     * �������� ���������� ������ ������� ������ � ������.
     * @param other ������ �� ������ ������ ������.
     */
    KudryashovNA_String(const KudryashovNA_String& other) : sz(other.sz) {
        str = new char[sz + 1];
        for (size_t i = 0; i <= sz; ++i) {
            str[i] = other.str[i];
        }
    }

    /**
     * @brief ����������.
     * ����������� ���������� ������������ ������.
     */
    ~KudryashovNA_String() {
        delete[] str;
    }

    // ������

    /**
     * @brief ���������� ����� ������.
     * @return ����� ������.
     */
    size_t length() const {
        return sz;
    }

    /**
     * @brief ������������� �������� ������� � �������� ������ �� �������.
     * @param index ������ ��������.
     * @return ������ �� ������� ������ �� ���������� �������.
     */
    char& operator[](size_t index) {
        return str[index];
    }

    /**
     * @brief ������������� �������� ������� � �������� ������ ��� ����������� ��������.
     * @param index ������ ��������.
     * @return ����������� ������ �� ������� ������ �� ���������� �������.
     */
    const char& operator[](size_t index) const {
        return str[index];
    }

    /**
     * @brief ��������� ���������� ���������� ������ � ����� ������� ������.
     * @param other ������ �� ������, ������� ���������� ��������.
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
     * @brief ���������� ��������� ������.
     * @param start ������� ������ ���������.
     * @param count ���������� �������� � ���������.
     * @return ����� ������ ������, �������������� ���������.
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
     * @brief ���������� ��������� ������������.
     * ����������� �������� ������������ ��� ����������� ����������� ����� ������ � ������.
     * @param other ������ �� ������ ������ ������.
     * @return ������ �� ������� ������ ������ ����� ������������.
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
     * @brief ���������� ��������� ������������.
     * ��������� ���������� ��� ������.
     * @param other ������ �� ������ ������ ������.
     * @return ����� ������ ������, �������������� ������������.
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
     * @brief ���������� ���������� ���������.
     * ����������� ��������� ��� ��������� �����.
     * @param other ������ �� ������ ������ ������.
     * @return ��������� ��������� �����.
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

    // ���������� ���������� �����/������

    /**
     * @brief ���������� ��������� �����.
     * ��������� ������� ������ � ������� ��� �� �����.
     * @param is ����� �����.
     * @param s ������ �� ������ ������.
     * @return ������ �� ����� �����.
     */
    friend std::istream& operator>>(std::istream& is, KudryashovNA_String& s) {
        char buffer[100000];
        is >> buffer;
        s = KudryashovNA_String(buffer);
        return is;
    }

    /**
     * @brief ���������� ��������� ������.
     * ��������� �������� ������ �� ������� ��� � ����.
     * @param os ����� ������.
     * @param s ������ �� ����������� ������ ������.
     * @return ������ �� ����� ������.
     */
    friend std::ostream& operator<<(std::ostream& os, const KudryashovNA_String& s) {
        setlocale(LC_ALL, "ru");
        os << s.str;
        return os;
    }
};

