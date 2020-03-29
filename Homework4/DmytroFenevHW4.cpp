#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>

using Comp = bool (*)(int, int);
bool Vniz(int a, int b) { return a > b; }
bool Vverx(int a, int b) { return a < b; }

template <typename T> void sort(T *begin, const T *const end, Comp) {
  if (begin == nullptr || end == nullptr || begin == end) {
    return;
  }
  for (int *it_level1 = begin; it_level1 != end; ++it_level1) {
    for (int *it_level2 = it_level1 + 1; it_level2 != end; ++it_level2) {
      if (Comp()) {
        int tmp = *it_level1;
        *it_level1 = *it_level2;
        *it_level2 = tmp;
      }
    }
  }
}

template <typename T> void printArray(T *array, int n) {
  std::cout << "\t";
  for (int i = 0; i < n; ++i)
    std::cout << "" << array[i] << " ";
  std::cout << std::endl;
}
template <typename T> void quickSort(T *array, int low, int high, int func) {
  int i = low;
  int j = high;
  T pivot = array[(i + j) / 2];
  T temp;

  while (i <= j) {
    if (func == 1) {
      while (array[i] < pivot)
        i++;
      while (array[j] > pivot)
        j--;
    } else {
      while (array[i] > pivot)
        i++;
      while (array[j] < pivot)
        j--;
    }
    if (i <= j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  }
  if (j > low)
    quickSort(array, low, j, func);
  if (i < high)
    quickSort(array, i, high, func);
}

enum { Default, Comparator_Sort = 1, Type_Sorting, Simple_Encryption };

int main() {
  do {
    std::cout << "\n Please, choose the number from the list of TASK N4:"
              << std::endl;
    std::cout << " 1 Comparator Sort" << std::endl;
    std::cout << " 2 Type of Sorting" << std::endl;
    std::cout << " 3 Simple symmetric encryption algorithm" << std::endl;
    std::cout << "   Press any other key to exit" << std::endl;
    int task_option;
    std::cin >> task_option;
    switch (task_option) {
    case Comparator_Sort: {
      std::cout << "1 Bubble Sort" << std::endl;
      std::cout << "2 Quick  Sort" << std::endl;
      int task_option;
      std::cin >> task_option;
      if (task_option == 1) {
        const int kSize{7};
        int array[kSize]{65, -17, 9, -3, 9, 7, 4};
        printArray(array, kSize);
        auto start5 = std::chrono::high_resolution_clock::now();
        std::sort(array, array + kSize, Comp(Vverx));
        printArray(array, kSize);
        auto finish5 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed5 = finish5 - start5;
        std::cout << "\tElapsed time: " << elapsed5.count() << " s\n";
      } else {
        int array[] = {95, 45, -48, -98, -1};
        int n = sizeof(array) / sizeof(array[0]);
        std::cout << "\tBefore Quick Sort :" << std::endl;
        printArray(array, n);
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(array, 0, n - 1, 0);
        std::cout << "\tAfter Quick Sort :" << std::endl;
        printArray(array, n);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "\tElapsed time: " << elapsed.count() << " s\n";
      }
      break;
    }
    case Type_Sorting: {
      std::cout << "1 Integer" << std::endl;
      std::cout << "2 Double " << std::endl;
      int task_option;
      std::cin >> task_option;
      if (task_option == 1) {
        const int kSize{7};
        int array1[kSize]{32, 7, 9, 3, 5, 2, 4};
        auto start = std::chrono::high_resolution_clock::now();
        std::sort(array1, array1 + kSize, Comp(Vniz));
        for (auto var : array1) {
          std::cout << var << " ";
        }
        std::cout << std::endl;
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "\tElapsed time: " << elapsed.count() << " s\n";

        int array2[] = {95, 45, 48, -98, -1};
        int n = sizeof(array2) / sizeof(array2[0]);
        std::cout << "\tBefore Quick Sort :" << std::endl;
        printArray(array2, n);
        auto start1 = std::chrono::high_resolution_clock::now();
        quickSort(array2, 0, n - 1, 0);
        std::cout << "\tAfter Quick Sort :" << std::endl;
        printArray(array2, n);
        auto finish1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed1 = finish1 - start1;
        std::cout << "\tElapsed time: " << elapsed1.count() << " s\n";
      } else {
        const int kSize{7};
        double array1[kSize]{32.5, 1.7, 9.2, 3.1, 5.9, 2.7, 4.2};
        auto start3 = std::chrono::high_resolution_clock::now();

        std::sort(array1, array1 + kSize, Comp(Vniz));
        for (auto var : array1) {
          std::cout << var << " ";
        }
        std::cout << std::endl;
        auto finish3 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed3 = finish3 - start3;
        std::cout << "\tElapsed time: " << elapsed3.count() << " s\n";

        double array2[] = {95, 45.5, 48.7, -98.5, -1};
        int n = sizeof(array2) / sizeof(array2[0]);
        std::cout << "\tBefore Quick Sort :" << std::endl;
        printArray(array2, n);
        auto start4 = std::chrono::high_resolution_clock::now();
        quickSort(array2, 0, n - 1, 1);
        std::cout << "\tAfter Quick Sort :" << std::endl;
        printArray(array2, n);
        auto finish4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed4 = finish4 - start4;
        std::cout << "\tElapsed time: " << elapsed4.count() << " s\n";
      }
      break;
    }

    case Simple_Encryption: {
      const int Nbukv = 36;
      char Alfavit[Nbukv]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                          'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                          'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0',
                          '1', '2', '3', '4', '5', '6', '7', '8', '9'};
      char Shifr_Alfavit[Nbukv]{}; // Encryption symbol array
      int Ksdviga = 5;             // Shift coding
      int tmp;
      for (int i = 0; i < Nbukv; i++) {
        tmp = (i + Ksdviga) % Nbukv;
        Shifr_Alfavit[i] = Alfavit[tmp];
      }
      const int k_bloka = 10; // Input block size
      char v_isx[k_bloka]{'D', 'I', 'N', 'A', 'M', 'O', 'K', 'I', 'E', 'V'};
      char v_shifr[k_bloka];   // encryption block
      char v_deshifr[k_bloka]; // deshifr block

      for (int j = 0; j < k_bloka; j++) {
        for (int i = 0; i < Nbukv; i++) {
          if (v_isx[j] == Alfavit[i]) {
            v_shifr[j] = Shifr_Alfavit[i];
            break;
          }
        }
      }
      printArray(Alfavit, Nbukv);
      printArray(Shifr_Alfavit, Nbukv);

      printArray(v_isx, k_bloka);
      printArray(v_shifr, k_bloka);
      // deshifr algorithm
      for (int j = 0; j < k_bloka; j++) {
        for (int i = 0; i < Nbukv; i++) {
          if (v_shifr[j] == Shifr_Alfavit[i]) {
            v_deshifr[j] = Alfavit[i];
            break;
          }
        }
      }
      printArray(v_deshifr, k_bloka);
      break;
    }
    default:
      std::cout << " End of Program " << std::endl;
      return 0;
    }
  } while (true);
  return 0;
}
