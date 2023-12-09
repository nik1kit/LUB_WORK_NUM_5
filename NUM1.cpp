#include <iostream>
#include "KudryashovNA_String.h"

int main() {
    setlocale(LC_ALL, "RU");
    KudryashovNA_String s;
    std::cout << "Введите строку: ";
    std::cin >> s;  // Используем перегруженный оператор ввода
    std::cout << "Введенная строка: " << s << std::endl;
    std::cout << s.length() << "\n";
    s.append(" kikimora");
    std::cout << s << "\n";

    return 0;
}
