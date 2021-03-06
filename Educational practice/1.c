#include <stdio.h>

// алгоритм нахождения количества единиц в двоичной записи числа
// сложность: O(1), но используется много памяти на массив
 
char arr[256] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
 
char count_ones (unsigned long long n) {
  char w = 0;
  while (n > 0) { // не может быть более 8 итераций
    w += arr[n & 255]; // n % 256
    // логическое умножение на маску 0b11111111
    n = n >> 8;
  }
  return w;
}
 
// ниже используется цикл for
// так по идее требовалось, но так неоптимально
 
// char count_ones (unsigned int n) {
//   char w = 0;
//   for (char i = 0; i < 4; i++) {
//     w += arr[n & 255];
//     n = n >> 8;
//   }
//   return w;
// }

void main () {
  unsigned int n_32 = 0;
  unsigned long long n_64 = 0;
  printf("zero 32: %d\n", count_ones(n_32));
  printf("zero 64: %d\n", count_ones(n_64));
  
  n_32 = 0xffffffff;         // 4294967295
  n_64 = 0xffffffffffffffff; // 1844674407370955161
  printf("test 32: %d\n", count_ones(n_32));
  printf("test 64: %d\n", count_ones(n_64));
 
  n_32 = 42; n_64 = 4242424242424242;
  printf("rand 32: %d\n", count_ones(n_32));
  printf("rand 64: %d\n", count_ones(n_64));
 
}