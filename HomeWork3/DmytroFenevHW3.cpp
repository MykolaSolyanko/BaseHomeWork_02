#include <ctime>
#include <iostream>

int main() {
  enum { FIRST_TASK = 1, SECOND_TASK };
  int task_choise;
  std::cout << "\tTask 1 - Reverse of string\n";
  std::cout << "\tTask 2 - Insert element in massive\n";
  std::cout << "\tEnter number of Task N1, N2\n";
  std::cin >> task_choise;
  switch (task_choise) {
  case FIRST_TASK: {
    int const SIZE{10};
    char arrL[]{"HelloWorld"};
    std::cout << "\tInitial text ---\n"
              << "\t";
    ;
    for (int i = 0; i < 10; i++) {
      std::cout << arrL[i];
    }
    std::cout << "\n";
    srand(time(NULL));
    int arrp[SIZE];
    bool alreadyThere;
    for (int i = 0; i < SIZE;) {
      alreadyThere = false;
      int newRandom = rand() % 10;
      for (int j = 0; j < i; j++) {
        if (arrp[j] == newRandom) {
          alreadyThere = true;
          break;
        }
      }
      if (!alreadyThere) {
        arrp[i] = newRandom;
        i++;
      }
    }
    std::cout << "\tIndexs ---\n"
              << "\t";
    for (int i = 0; i < 10; i++) {
      std::cout << arrp[i];
    }
    std::cout << "\n";
    std::cout << "\tRandom text ---\n"
              << "\t";
    for (int i = 0; i < 10; i++) {
      std::cout << arrL[arrp[i]];
    }
    break;
  }
  case SECOND_TASK: {
    int size = 10; // размер массива // Ввод количества элементов массива
    int const SIZE{10};
    std::cout << "Number of points n =10\n";
    std::cout << "Enter number=\n";
    int a;
    int arr[10]{
        0,
    };
    int arr1[SIZE];
    for (int i = 0; i < size; i++) {
      std::cin >> a;
      arr[i] = a;
      for (int ii = 0; ii < 10; ii++) {
        std::cout << arr[ii];
      }
      std::cout << "\n";
      for (int ik = 0; ik < 10; ik++) {
        arr1[ik] = arr[ik];
      }
      for (int j = 0; j < size - 1; j++) {
        for (int jj = 0; jj < size - j - 1; jj++) {
          if (arr1[jj] > arr1[jj + 1]) { // меняем элементы местами
            int temp = arr1[jj];
            arr1[jj] = arr1[jj + 1];
            arr1[jj + 1] = temp;
          }
        }
      }

      for (int k = 0; k < size; k++) {
        std::cout << arr1[k];
      }
      std::cout << "\n";
    }
    break;
  }
  }
}
