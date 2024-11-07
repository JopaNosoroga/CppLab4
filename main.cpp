#include "Lab4.h"
#include <vector>

int main() {
  int choice;
  std::cout << "Число 0 выйти,  1 решить уравнение, 2 увеличить коэффициенты "
               "на 1, 3 уменьшить на 1"
            << '\n';
  std::cout << " 4 неявное приведение к double, 5 явное приведение к bool"
            << '\n';
  std::cout
      << "6 проверка равенства уравнений, 7 проверка неравенства уравнений"
      << '\n';
  std::cout << "8 проверка конструктора с одинаковыми коэффициентами, 9 "
               "проверка конструктора, когда есть числа до создания объекта."
            << '\n';
  do {
    std::cout << "Введите число того что хотите проверить: ";
    std::cin >> choice;
    switch (choice) {
    case 0:
      break;
    case 1: {
      QadraticEquation equation("true");
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
      QadraticEquation equation("true");
      ++equation;
      std::cout << "Коэффициенты после прибавления 1: " << '\n';
      equation.input();
      break;
    }
    case 3: {
      QadraticEquation equation("true");
      --equation;
      std::cout << "Коэффициенты после минус 1: " << '\n';
      equation.input();
      break;
    }

    case 4: {
      QadraticEquation equation("true");
      double discr = equation;
      std::cout << "Неявное приведение к double. Дискриминант: " << discr
                << '\n';
      break;
    }
    case 5: {
      QadraticEquation equation("true");
      bool ask{static_cast<bool>(equation)};
      std::cout
          << "Явное преобразование в bool. Если есть решения то 1 иначе 0: "
          << ask << '\n';
      break;
    }
    case 6: {
      QadraticEquation equation("true");
      QadraticEquation equation2("true");
      bool ask = equation == equation2;
      std::cout << "Если коэффициенты уравнений равны то 1 иначе 0: " << ask
                << '\n';
      break;
    }
    case 7: {
      QadraticEquation equation("true");
      QadraticEquation equation2("true");
      bool ask = equation != equation2;
      std::cout << "Если коэффициенты уравнений равны то 0 иначе 1: " << ask
                << '\n';
      break;
    }
    case 8: {
      double x;
      std::cout << "Введите какие коэффициенты будут у уравнения: ";
      std::cin >> x;
      QadraticEquation equation(x);
      std::cout << "Вот такие коэффициенты при использования конструктора с "
                   "одинаковыми коэффициентами: ";
      equation.input();
      break;
    }

    case 9: {
      double a, b, c;
      std::cout << "Введите первое число: ";
      std::cin >> a;
      std::cout << "Введите второе число: ";
      std::cin >> b;
      std::cout << "Введите второе число:";
      std::cin >> c;
      QadraticEquation equation(a, b, c);
      std::cout << "Пример как создаётся уравнение конструктором, который "
                   "принимает 3 коэффициента а не ввод: ";
      equation.input();
      break;
    }
    default:
      std::cout << "Ошибка ввода!";
    }
  } while (choice != 0);

  return 0;
}
