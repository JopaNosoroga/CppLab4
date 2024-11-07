#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>
class QadraticEquation {
protected:
  double a;
  double b;
  double c;

public:
  // QadraticEquation(int temp) {
  // a = temp;
  // b = temp;
  // c = temp;
  //}

  QadraticEquation(int temp = 0) {
    std::cout << "Введите первый коэффициент: ";
    std::cin >> a;
    std::cout << "Введите второй коэффициент: ";
    std::cin >> b;
    std::cout << "Введите третий коэффициент: ";
    std::cin >> c;
  }

  void input() {
    std::cout << "Первый коэффициент: " << a << " второй коэффициент: " << b
              << " третий коэффициент: " << c << '\n';
  }

  void NewCoefficient(double temp_a, double temp_b, double temp_c) {
    a = temp_a;
    b = temp_b;
    c = temp_c;
  }

  std::vector<double> solution() {
    double discr = b * b - 4 * a * c;
    std::vector<double> ask;
    if (discr > 0) {
      return ask = {((b * -1) + sqrt(discr)) / (2 * a),
                    ((b * -1) - sqrt(discr)) / (2 * a)};
    }
    if (discr == 0)
      return ask = {-(b / (2 * a))};
    return ask;
  }

  QadraticEquation operator++() {
    a++;
    b++;
    c++;
    return *this;
  }

  QadraticEquation operator--() {
    a--;
    b--;
    c--;
    return *this;
  }

  bool operator==(QadraticEquation op2) {
    if (a == op2.a && b == op2.b && c == op2.c)
      return true;
    return false;
  }
  bool operator!=(QadraticEquation op2) {
    if (a == op2.a && b == op2.b && c == op2.c)
      return false;
    return true;
  }

  operator double() const { return b * b - 4 * a * c; }

  operator bool() const {
    if ((b * b - 4 * a * c) >= 0)
      return true;
    return false;
  }
};
