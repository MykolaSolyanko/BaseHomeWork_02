//Cамчук Тарас
//Розвʼязання квадратного рівняння
#include <iostream>
#include <math.h>
//для переклaду повідомлень використвувався translate.google.com.ua
int main()
{
  //запрошення програми//

  //Програма для розвязання квадратного ріняння
  std::cout << "\tA program for solving a square swing" << std::endl;
  //Рівняння має вигляд
  std::cout << "\t The  equation  looks  like  this" << std::endl;
  //a * x ^ 2 + b * x + c = 0
  std::cout << "\t\ta*x^2+b*x+c=0\n"
            << std::endl;
  //,де
  std::cout << "\t,where" << std::endl;
  //a, b і c - коефієнти рівняння
  std::cout << "\t  a, b and c are the coefficients of\n\t    the equation" << std::endl;
  //х - корінь рівнняння
  std::cout << "\t  x is the root of the equation" << std::endl;
  int a, b, c, min_short, max_short;
  //Введіть коефіцієнти
  std::cout << "Enter the coefficients" << std::endl;
  //будемо перевіряти на правильність введення числа
  bool incorrect{true}; //true - неправильне число, false - правильне число

  //вводимо числа//

  min_short = std::numeric_limits<short>::min();
  max_short = std::numeric_limits<short>::max();
  std::cout << "Must be between " << min_short << " and " << max_short << "!" << std::endl;
  //Вводимо коефіцієнт а
  do
  {
    //Виводимо запрошення, що нам потрібно
    std::cout << "a=";
    //Читаємо значання
    std::cin >> a;
    std::cin.clear();
    //перевіряємо чи попадаємо в діапазон
    incorrect = (a < min_short) || (a > max_short);
    if (incorrect)
    {
      //Повідомляємо що вийшли за межі діапазону
      std::cout << "\tYou entered an incorrect number." << std::endl;
      std::cout << "\tMust be between " << min_short << " and " << max_short << "!" << std::endl;
    }
    //в діапазон попали, але а не повинно бути нулем, бо це вже лінійне рівняння
    else if (a == 0)
    {
      // інвормуємо що введено нуль
      std::cout << "\tYou entered an incorrect number." << std::endl;
      std::cout << "\tCan't be zero" << std::endl;
      //введене число не коректне
      incorrect = true;
    }
    //якщо не коректне повторюємо запит
  } while (incorrect);

  //вводимо коефіцієнт b за ти самим алгоритмом що й А, але перевірку на нуль не виконуємо
  do
  {
    std::cout << "b=";
    std::cin >> b;
    std::cin.clear();
    incorrect = (b < min_short) || (b > max_short);
    if (incorrect)
    {
      std::cout << "\tYou entered an incorrect number." << std::endl;
      std::cout << "\tMust be between " << min_short << " and " << max_short << "!" << std::endl;
    }
  } while (incorrect);
  //вводимо коефіцієнт с так же як ввели b 
  do
  {
    std::cout << "c=";
    std::cin >> c;
    std::cin.clear();
    incorrect = (c < min_short) || (c > max_short);
    if (incorrect)
    {
      std::cout << "\tYou entered an incorrect number." << std::endl;
      std::cout << "\tMust be between " << min_short << " and " << max_short << "!" << std::endl;
    }
  } while (incorrect);
  //виводимо рівнняння з коефіцієнтами
  std::cout << "\t\t" << a << "*x^2+" << b << "*x+" << c << "=0" << std::endl;
  //"магічне" 4
  const long digit_4 = 4;
  //обчислюємо дискримінант
  long D = (b * b) - (digit_4 * a * c);
  //аналізуємо дискримінант
  //якщо менше нуля
  if (D < 0)
  {
    //говоримо що рівняння не має реальних розв'язків
    std::cout << "\tThis equation has no real roots." << std::endl;
  }
  //корені рівнння
  double x1, x2;
  //"магічне" 2
  const int digit_2 = 2;
  //Якщо дискримінант рівний нулю
  if (D == 0)
  {
    //маємо один корінь
    std::cout << "\tThis equation has one root." << std::endl;
    //обчислюємо та виводимо його
    x1 = -(b / (digit_2 * a));
    std::cout << "\tx=" << x1 << std::endl;
  }
  //якщо дискримінант більший нуля
  if (D > 0)
  {
    //маємо два можливих корені
    std::cout << "\tThis equation has two roots." << std::endl;
    //обчислюємо та виводимо
    x1 = (-b + sqrt(D)) / (digit_2 * a);
    x2 = (-b - sqrt(D)) / (digit_2 * a);
    std::cout << "\tx=" << x1 << " and x=" << x2 << std::endl;
  }
  //кінець програми
  return 0;
}
//EOF