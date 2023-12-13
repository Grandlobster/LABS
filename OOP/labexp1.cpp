#include <iostream>
class Complex
{
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex
                                                          &complex)
    {
        os << complex.real << "+" << complex.imag << "i";
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Complex
                                                          &complex)
    {
        std::cout << "Enter real part: ";
        is >> complex.real;
        std::cout << "Enter imaginary part: ";
        is >> complex.imag;
        return is;
    }
};
int main()
{
    Complex c1, c2, result;
    std::cout << "Enter the first complex number\n";
    std::cin >> c1;
    std::cout << "Enter the second complex number\n";
    std::cin >> c2;
    result = c1 + c2;
    std::cout << "Sum: " << result << "\n";
    result = c1 * c2;
    std::cout << "Product: " << result << "\n";
    return 0;
}