// cpp_data_types_demo.cpp

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

int main() {
    // --- Integer Types ---
    int score = 95;
    // long long global_population = 7900000000;
    long global_population = 8023489238123321342;

    std::cout << "--- Integer Types ---\n";
    std::cout << "Player score: " << score << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Max int value: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Global population: " << global_population << std::endl;

    // // --- Floating-Point Types ---
    // double pi = 3.1415926535;
    // float gravity = 9.8f;

    // std::cout << "\n--- Floating Point Types ---\n";
    // std::cout << "The value of pi is approx: " << pi << std::endl;
    // std::cout << std::fixed << std::setprecision(10);
    // std::cout << "A more precise pi: " << pi << std::endl;
    // std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;

    // // --- Character Type ---
    // char grade = 'A';
    // char symbol = '#';

    // std::cout << "\n--- Character Type ---\n";
    // std::cout << "Your grade is: " << grade << std::endl;
    // std::cout << "ASCII value of '" << grade << "': " << static_cast<int>(grade) << std::endl;

    // // --- Boolean Type ---
    // bool is_ready = true;

    // std::cout << "\n--- Boolean Type ---\n";
    // if (is_ready) {
    //     std::cout << "The system is ready." << std::endl;
    // }
    // std::cout << "is_ready as integer: " << is_ready << std::endl;

    // // --- Type Modifiers ---
    // unsigned int positive_only = 4000000000;

    // std::cout << "\n--- Type Modifiers ---\n";
    // std::cout << "Positive only value: " << positive_only << std::endl;
    // std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
    // std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;

    // // --- std::string Usage ---
    // std::string first_name = "Bjarne";
    // std::string last_name = "Stroustrup";
    // std::string full_name = first_name + " " + last_name + " (Creator of C++)";

    // std::cout << "\n--- std::string ---\n";
    // std::cout << full_name << std::endl;
    // std::cout << "Length of name: " << full_name.length() << std::endl;

    // // --- auto Keyword ---
    // auto an_integer = 42;
    // auto a_double = 3.14159;
    // auto a_string = std::string("Hello, auto!");

    // std::cout << "\n--- auto Keyword ---\n";
    // std::cout << "Size of an_integer: " << sizeof(an_integer) << std::endl;
    // std::cout << a_string << std::endl;

    // // --- const Qualifier ---
    // const double PI = 3.14159;
    // double radius = 5.0;
    // double circumference = 2 * PI * radius;

    // std::cout << "\n--- const Qualifier ---\n";
    // std::cout << "Circumference: " << circumference << std::endl;

    // // --- Type Casting ---
    // double value = 97.56;
    // int integer_part = static_cast<int>(value);
    // char character_part = static_cast<char>(integer_part);

    // std::cout << "\n--- Type Casting ---\n";
    // std::cout << "Original double: " << value << std::endl;
    // std::cout << "Casted to int: " << integer_part << std::endl;
    // std::cout << "Integer casted to char: " << character_part << std::endl;

    return 0;
}
