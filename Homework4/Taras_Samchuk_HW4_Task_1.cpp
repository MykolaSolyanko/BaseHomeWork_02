#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <random>

enum SortType { ST_BOBLE_SORT, ST_SELECTION_SORT, ST_QUICK_SORT, COUNT_ST };

using comparison = std::function<bool(int, int)>;

const size_t k_int_array_size{10};
const int k_min_random_value{10};
const int k_max_random_value{99};

bool More(int a, int b) { return a > b; }
bool Less(int a, int b) { return a < b; }

// RANDOM INIT ARRAY
void rInitArray(int *const array_begin, int const *const array_end) {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin >= array_end) {
    return;  // error
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> GenInt(k_min_random_value,
                                            k_max_random_value);
  for (int *index = array_begin; index <= array_end; index++) {
    *index = GenInt(mt);
  }
  return;  // ok
}
// RANDOM INIT ARRAY
void uInitArray(int *const array_begin, int const *const array_end) {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin >= array_end) {
    return;  // error
  }
  std::cout<<"Start initiating an array"<<std::endl;
  for (int *index = array_begin; index <= array_end; index++) {
    std::cout<<"Enter int value=";
    std::cin>>*index;
  }
  std::cout<<"Array initiation complete"<<std::endl;
  return;  // ok
}

// SHOW ARRAY
void ShowArray(int *const array_begin, int const *const array_end,char OB='{',char CB='}') {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin > array_end) {
    return;  // error
  }
  for (int *index = array_begin; index <= array_end; index++) {
    std::cout << OB << *index << CB;
  }
  std::cout << std::endl;
  return;  // ok
}

void SwapInt(int *const first_ptr, int *const second_ptr) {
  if (first_ptr == nullptr || second_ptr == nullptr ||
      first_ptr == second_ptr) {
    return;  // ERROR
  }
  int tmp_ptr = *first_ptr;
  *first_ptr = *second_ptr;
  *second_ptr = tmp_ptr;
  return;  // OK
}
void BubleSort(int *const array_begin, int const *const array_end,
               comparison comp) {
  if (array_begin == nullptr || array_end == nullptr) {
    return;  // ERROR
  }
  for (int *pass_1 = array_begin; pass_1 <= array_end; ++pass_1) {
    for (int *pass_2 = (array_begin); pass_2 <= array_end; ++pass_2) {
      if (comp(*pass_1, *pass_2)) SwapInt(pass_1, pass_2);
    }
  }
  return;  // OK
}
void SelectSort(int *const array_begin, int const *const array_end,
                comparison comp) {
  if (array_begin == nullptr || array_end == nullptr) {
    return;  // ERROR
  }
  int *remember;

  for (int *first_pass = array_begin; first_pass != array_end; first_pass++) {
    remember = first_pass;
    for (int *second_pass = first_pass + 1; second_pass != array_end;
         second_pass++)
      remember = (comp(*second_pass, *remember)) ? second_pass : remember;
    if (first_pass != remember) {
      SwapInt(first_pass, remember);
    }
  }
  return;  // OK
}

//  Q U I C K   S O R T   F U N C T I O N S   B L O K   B E G I N
int *Separator(int *opening, int *closing, comparison comp) {
  int pilot = *closing;
  int *section = opening;
  for (int *index = opening; index != closing; index++) {
    if (comp(*index, pilot) /* *index <= pilot */) {
      SwapInt(index, section);
      section++;
    }
  }
  SwapInt(closing, section);
  return section;
}
void Quicksort(int *array_begin, int *array_end, comparison comp) {
  if (array_begin < array_end) {
    if (array_begin == nullptr || array_end == nullptr) {
      return;  // ERROR
    }
    int *index = Separator(array_begin, array_end, comp);
    Quicksort(array_begin, index - 1, comp);
    Quicksort(index + 1, array_end, comp);
  }
  return;  // OK
}
//  Q U I C K   S O R T   F U N C T I O N S   B L O K   E N D

int main() {
  using TypeArray = int[k_int_array_size];
  TypeArray SrcArray{0};

  std::cout << "Fill the array with a random number generator." << std::endl;
  auto BeginAt = std::chrono::system_clock::now();
  rInitArray(SrcArray, SrcArray + k_int_array_size);
  ShowArray(SrcArray, SrcArray + k_int_array_size,'[',']');
  auto FinishAt = std::chrono::system_clock::now();
  std::chrono::duration<double> TimeІpent = FinishAt - BeginAt;
  std::cout << "Elapsed time: " << TimeІpent.count() << "s\n";

  std::cout << "Performance comparison of some sorting algorithms\n"
            << std::endl;
  size_t memory_size = sizeof(SrcArray);
  for (int Method = 0; Method < COUNT_ST; Method++) {
    TypeArray Victim;
    BeginAt = std::chrono::system_clock::now();
    memcpy(Victim, SrcArray, memory_size);
    FinishAt = std::chrono::system_clock::now();
    TimeІpent = FinishAt - BeginAt;
    std::cout << "Restore the previous state of the array " << k_int_array_size
              << " elements. Elapsed time: " << TimeІpent.count() << "s\n"
              << std::endl;

    std::cout << "Launching ";
    // auto more = [](int a, int b) { return a > b; };
    switch (Method) {
      case SortType::ST_BOBLE_SORT:

        std::cout << "BOBLESORT" << std::endl;
        BeginAt = std::chrono::system_clock::now();
        BubleSort(Victim, Victim + k_int_array_size, Less);
        FinishAt = std::chrono::system_clock::now();
        break;
      case SortType::ST_SELECTION_SORT:

        std::cout << "SELECTION SORT" << std::endl;
        BeginAt = std::chrono::system_clock::now();
        SelectSort(Victim, Victim + k_int_array_size, Less);
        FinishAt = std::chrono::system_clock::now();
        break;
      case SortType::ST_QUICK_SORT:

        std::cout << "QUICK SORT" << std::endl;
        BeginAt = std::chrono::system_clock::now();
        Quicksort(Victim, Victim + k_int_array_size, Less);
        FinishAt = std::chrono::system_clock::now();
        break;
      default:
        break;
    }
    TimeІpent = FinishAt - BeginAt;
    std::cout << "Elapsed time: " << TimeІpent.count() << "s" << std::endl;
  }
  return 0;
}