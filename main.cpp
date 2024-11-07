#include "Lab4.h"
#include <vector>

int main() {
  int choice;
  std::cout << "Число 0 выйти,  1 решить уравнение, 2 увеличить коэффициенты "
               "на 1, 3 уменьшить на 1";
  std::cout << " 4 неявное приведение к double, 5 явное приведение к bool";
  std::cout
      << "6 проверка равенства уравнений, 7 проверка неравенства уравнений.";
  do {
    std::cout << "Введите число того что хотите проверить: ";
    std::cin >> choice;
    switch (choice) {
    case 0:
      break;
    case 1: {
      QadraticEquation equation(0);
      std::vector<double> ask = equation.solution();
      if (ask.size() == 0)
        std::cout << "Действительных корней уравнения нет." << '\n';
      else if (ask.size() == 1)
        std::cout << "Уравнение иммет один корень " << ask[0] << '\n';
      else
        std::cout << "Уравнение имеет два корня " << ask[0] << " и " << ask[1]
                  << '\n';
      break;
    }
    case 2: {
      double a, b, c;
      QadraticEquation equation(0);
      ++equation;
      std::cout << "Коэффициенты после прибавления 1: " << '\n';
      equation.input();
      break;
    }
    case 3: {
      QadraticEquation equation(0);
      --equation;
      std::cout << "Коэффициенты после минус 1: " << '\n';
      equation.input();
      break;
    }

    case 4: {
      QadraticEquation equation(0);
      double discr = equation;
      std::cout << "Неявное приведение к double. Дискриминант: " << discr
                << '\n';
      break;
    }
    case 5: {
      QadraticEquation equation(0);
      bool ask{static_cast<bool>(equation)};
      std::cout
          << "Явное преобразование в bool. Если есть решения то 1 иначе 0: "
          << ask << '\n';
      break;
    }
    case 6: {
      QadraticEquation equation(0);
      QadraticEquation equation2(0);
      bool ask = equation == equation2;
      std::cout << "Если коэффициенты уравнений равны то 1 иначе 0: " << ask
                << '\n';
      break;
    }
    case 7: {
      QadraticEquation equation(0);
      QadraticEquation equation2(0);
      bool ask = equation != equation2;
      std::cout << "Если коэффициенты уравнений равны то 0 иначе 1: " << ask
                << '\n';
      break;
    }
    default:
      std::cout << "Ошибка ввода!";
    }
  } while (choice != 0);

  return 0;
}
