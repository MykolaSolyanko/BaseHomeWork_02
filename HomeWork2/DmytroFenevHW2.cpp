#include <cmath>
#include <iostream>
#include <string>

int main() {
  int z;
  std::cout << "Zadacha №1, N2, N3, N4, N5\n";
  std::cin >> z;
  int x, xp, xp1;
  int y, y1, yp;
  int n, np, nc;
  int sum, sum1, sum2;
  int l2;
  int k2;
  double k3;
  int sample[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  const int Min = 1;
  const int Max = 50;
  int nElement = 0;
  int chislo;
  const int cmin = -60;
  const int cmax = 90;
  switch (z) {
  case 1:
    n = 1; //число цифр
    std::cout << "\tEnter an integer" << std::endl;
    std::cin >> x;
    xp = x; //сохранение х после подсчета количества цифр
    while ((x /= 10) > 0)
      n++;
    std::cout << "\tNumber of digits=" << n << std::endl;
    y = xp / 10;
    y1 = xp % 10; // number of low order
    sum = y1;
    for (int ii = 1; ii < n; ii++) {
      yp = y / 10;
      y1 = y % 10;
      sum = sum + y1; //сумма цифр
      y = yp;
    }
    std::cout << "\tsum=" << sum << std::endl;
    std::cout << "\tAverage number =" << sum / n << std::endl;
    break;
  case 2:
    n = 6; //число цифр
    np = 1;
    std::cout << "\tEnter six digits" << std::endl;
    std::cin >> x;
    y = x; //сохранение х после подсчета количества цифр
    while ((x /= 10) > 0)
      np++;
    std::cout << np << std::endl;
    while ((np < n) || (np > n)) {
      np = 1;
      std::cout << "\tEnter not six  digits" << std::endl;
      std::cin >> x;
      y = x;
      while ((x /= 10) > 0)
        np++;
    }
    sum1 = 0;
    sum2 = 0;
    for (int ii = 1; ii <= n; ii++) {
      if (ii < 4) {
        yp = y / 10;
        y1 = y % 10;
        sum1 = sum1 + y1;
        y = yp;
      } else {
        yp = y / 10;
        y1 = y % 10;
        sum2 = sum2 + y1;
        y = yp;
      }
    }
    if (sum1 == sum2)
      std::cout << "\tAmount match" << std::endl;
    else
      std::cout << "\tAmounts do not match" << std::endl;
    break;
  case 3:
    // signed long l,xp;
    int L;
    std::cin >> L;
    n = 1;
    xp = abs(L);
    xp1 = xp; //сохранение х после подсчета количества цифр
    while ((xp1 /= 10) > 0)
      n++;
    y = xp;
    for (int ii = 0; ii < n; ii++) {
      yp = y / 10;
      y1 = y % 10;
      sample[ii] = y1;
      y = yp;
    }
    for (int i = 0; i < n; i++) {
      std::cout << "sample=" << sample[i] << std::endl;
    }
    k3 = (pow(10, n));
    k2 = int(k3);
    std::cout << k2 << std::endl;
    l2 = 0;
    for (int i = 0; i < n; i++) {
      k2 = k2 / 10;
      std::cout << k2 << std::endl;
      l2 = l2 + k2 * sample[i];
    }
    if (L < 0)
      l2 = -l2;
    // l1 = sample[0] * 100 + sample[1] * 10 + sample[2];
    std::cout << "number=" << l2 << std::endl;
    break;
  case 4:
    sum = 0;
    nc = 0;
    std::cout << "\tEnter an integer in range...1...50" << std::endl;
    std::cin >> nElement;
    while ((nElement < Min) || (nElement > Max)) {
      std::cout << "\tEnter an integer again in range 1...50" << std::endl;
      std::cin >> nElement;
    }
    for (int i = 0; i < nElement; i++) {
      std::cout << "\tEnter an integer in range...-60...+90" << std::endl;
      std::cin >> chislo;
      while ((chislo < cmin) || (chislo > cmax)) {
        std::cout << "\tEnter an integer again in range -60...+90" << std::endl;
        std::cin >> chislo;
      }
      (chislo % 2 == 0) ? nc++ : sum += chislo;
    }
    std::cout << "\tSum of odd number=" << sum << std::endl;
    break;
  case 5:
    std::cout << "Enter x: ";
    std::cin >> x;
    int sMax = 0; //максимальный делитель
    for (int i = 1; i <= x; i++) {
      if (x % i == 0) {
        int n = 1;
        int xi = i; //сохранение числа после подсчета количества цифр
        while ((xi /= 10) > 0)
          n++;
        int s = 0;
        int yp = i;
        for (int k = 0; k < n; k++) {
          y1 = yp % 10;
          s = s + y1;
          yp = yp / 10;
        }
        std::cout << "\ti=" << i << "\tn=" << n << "\ts=" << s << std::endl;
        if (s > sMax)
          sMax = s;
      }
    }
    std::cout << "sMax=" << sMax << std::endl;
    break;
  }
}
