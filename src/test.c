#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// 1
// поиск существующего символа в строке 1+
// поиск не существующего симовла в строке 2+
// поиск в пустой строке 3+
// поиск в строке где есть в середине \0 4+
// поиск в строке символа \0 5 10 11+
// поиск русской буквы 6 6_2+
// поиск сущ символа при малом n 7+
// поиск сущ символа при n=позиции символа 8+
// проверка на ячейку памяти 9+
// позиция \0 10 11+
START_TEST(test_s21_memchr) {
  // Arrange
  void *s1 = "1234567890";
  char c1 = '4';
  size_t n1 = 10;
  void *answer1_string = NULL;
  void *answer1_s21 = NULL;

  void *s2 = "1234567890";
  char c2 = 'a';
  size_t n2 = 10;
  void *answer2_string = NULL;
  void *answer2_s21 = NULL;

  void *s3 = "";
  char c3 = '4';
  size_t n3 = 10;
  void *answer3_string = NULL;
  void *answer3_s21 = NULL;

  void *s4 = "123\04567890";
  char c4 = '4';
  size_t n4 = 10;
  void *answer4_string = NULL;
  void *answer4_s21 = NULL;

  void *s5 = "123\04567890";
  char c5 = '\0';
  size_t n5 = 10;
  void *answer5_string = NULL;
  void *answer5_s21 = NULL;

  void *s7 = "1234567890";
  char c7 = '4';
  size_t n7 = 2;
  void *answer7_string = NULL;
  void *answer7_s21 = NULL;

  void *s8 = "1234567890";
  char c8 = '4';
  size_t n8 = 4;
  void *answer8_string = NULL;
  void *answer8_s21 = NULL;

  void *s9 = "1234567890";
  char c9 = '4';
  size_t n9 = 10;
  void *answer9_string = NULL;
  void *answer9_s21 = NULL;

  void *s10 = "1234567890";
  char c10 = '\0';
  size_t n10 = 15;
  void *answer10_string = NULL;
  void *answer10_s21 = NULL;

  void *s11 = "1234\0567890";
  char c11 = '\0';
  size_t n11 = 15;
  void *answer11_string = NULL;
  void *answer11_s21 = NULL;
  // Act
  answer1_string = memchr(s1, c1, n1);
  answer1_s21 = s21_memchr(s1, c1, n1);

  answer2_string = memchr(s2, c2, n2);
  answer2_s21 = s21_memchr(s2, c2, n2);

  answer3_string = memchr(s3, c3, n3);
  answer3_s21 = s21_memchr(s3, c3, n3);

  answer4_string = memchr(s4, c4, n4);
  answer4_s21 = s21_memchr(s4, c4, n4);

  answer5_string = memchr(s5, c5, n5);
  answer5_s21 = s21_memchr(s5, c5, n5);

  answer7_string = memchr(s7, c7, n7);
  answer7_s21 = s21_memchr(s7, c7, n7);

  answer8_string = memchr(s8, c8, n8);
  answer8_s21 = s21_memchr(s8, c8, n8);

  answer9_string = memchr(s9, c9, n9);
  answer9_s21 = s21_memchr(s9, c9, n9);

  answer10_string = memchr(s10, c10, n10);
  answer10_s21 = s21_memchr(s10, c10, n10);

  answer11_string = memchr(s11, c11, n11);
  answer11_s21 = s21_memchr(s11, c11, n11);
  // Assert
  ck_assert_ptr_eq(answer1_string, answer1_s21);    // 1
  ck_assert_ptr_eq(answer2_string, answer2_s21);    // 2
  ck_assert_ptr_eq(answer3_string, answer3_s21);    // 3
  ck_assert_ptr_eq(answer4_string, answer4_s21);    // 4
  ck_assert_ptr_eq(answer5_string, answer5_s21);    // 5
  ck_assert_ptr_eq(answer7_string, answer7_s21);    // 7
  ck_assert_ptr_eq(answer8_string, answer8_s21);    // 8
  ck_assert_ptr_eq(answer9_string, answer9_s21);    // 9
  ck_assert_ptr_eq(answer10_string, answer10_s21);  // 10
  ck_assert_ptr_eq(answer11_string, answer11_s21);  // 11
}
END_TEST

// 2
// s1=s2 n>len(s1) 1+
// s1!=s2 n<len(s1) 2+
// s1=s2 n=len(s1) 3+
// s1!=s2 n>len(s1) 4+
// s1!=s2 n=len(s1) 5+
// различие в русской букве 6+
// различие при наличии \0 в одной строке 7+
// различие при \0 в обеих строках 8+
START_TEST(test_s21_memcmp) {
  // Arrange
  void *s1_1 = "asdf";
  void *s2_1 = "asdf";
  size_t n1 = 6;
  int answer1_string;
  int answer1_s21;

  void *s1_2 = "asdf";
  void *s2_2 = "asdg";
  size_t n2 = 2;
  int answer2_string;
  int answer2_s21;

  void *s1_3 = "asdf";
  void *s2_3 = "asdf";
  size_t n3 = 4;
  int answer3_string;
  int answer3_s21;

  void *s1_4 = "asdf";
  void *s2_4 = "asdg";
  size_t n4 = 6;
  int answer4_string;
  int answer4_s21;

  void *s1_5 = "asdf";
  void *s2_5 = "asdg";
  size_t n5 = 4;
  int answer5_string;
  int answer5_s21;

  void *s1_7 = "asdf";
  void *s2_7 = "as\0dg";
  size_t n7 = 15;
  int answer7_string;
  int answer7_s21;
  // Act
  answer1_string = memcmp(s1_1, s2_1, n1);
  answer1_s21 = s21_memcmp(s1_1, s2_1, n1);

  answer2_string = memcmp(s1_2, s2_2, n2);
  answer2_s21 = s21_memcmp(s1_2, s2_2, n2);

  answer3_string = memcmp(s1_3, s2_3, n3);
  answer3_s21 = s21_memcmp(s1_3, s2_3, n3);

  answer4_string = memcmp(s1_4, s2_4, n4);
  answer4_s21 = s21_memcmp(s1_4, s2_4, n4);

  answer5_string = memcmp(s1_5, s2_5, n5);
  answer5_s21 = s21_memcmp(s1_5, s2_5, n5);

  answer7_string = memcmp(s1_7, s2_7, n7);
  answer7_s21 = s21_memcmp(s1_7, s2_7, n7);
  // Assert
  ck_assert_int_eq(answer1_string, answer1_s21);  // 1
  ck_assert_int_eq(answer2_string, answer2_s21);  // 2
  ck_assert_int_eq(answer3_string, answer3_s21);  // 3
  ck_assert_int_eq(answer4_string, answer4_s21);  // 4
  ck_assert_int_eq(answer5_string, answer5_s21);  // 5
  ck_assert_int_eq(answer7_string, answer7_s21);  // 7
}
END_TEST

// 3
// dst=5 src=4 n=5 1+
// dst=5 src=4 n=4 2+
// dst=5 src=6 n=6 3+
// dst=5 src=10 n=4 4+
// dst=5 src=0 n=5 5+
// проверка возврата. memcpy возвращает dst 6+
// dst=5 src=11 и есть \0 в середине n=10 7+
// проверку перекрытия по памяти 8+
START_TEST(test_s21_memcpy) {
  // Arrange
  char dest1_string[1024] = "1 str";
  char dest1_s21[1024] = "1 str";
  void *src1 = "2asd";
  size_t n1 = 5;
  void *answer1_string = NULL;
  void *answer1_s21 = NULL;

  char dest2_string[1024] = "1 str";
  char dest2_s21[1024] = "1 str";
  void *src2 = "2asd";
  size_t n2 = 4;
  void *answer2_string = NULL;
  void *answer2_s21 = NULL;

  char dest3_string[1024] = "1 str";
  char dest3_s21[1024] = "1 str";
  void *src3 = "2asdfg";
  size_t n3 = 6;
  void *answer3_string = NULL;
  void *answer3_s21 = NULL;

  char dest4_string[1024] = "1 str";
  char dest4_s21[1024] = "1 str";
  void *src4 = "2asdfghjkl";
  size_t n4 = 4;
  void *answer4_string = NULL;
  void *answer4_s21 = NULL;

  char dest5_string[1024] = "1 str";
  char dest5_s21[1024] = "1 str";
  void *src5 = "";
  size_t n5 = 5;
  void *answer5_string = NULL;
  void *answer5_s21 = NULL;

  char dest7_string[1024] = "1 str";
  char dest7_s21[1024] = "1 str";
  void *src7 = "2asd\0fghjkl";
  size_t n7 = 10;
  void *answer7_string = NULL;
  void *answer7_s21 = NULL;

  // Act
  answer1_string = memcpy(dest1_string, src1, n1);
  answer1_s21 = s21_memcpy(dest1_s21, src1, n1);

  answer2_string = memcpy(dest2_string, src2, n2);
  answer2_s21 = s21_memcpy(dest2_s21, src2, n2);

  answer3_string = memcpy(dest3_string, src3, n3);
  answer3_s21 = s21_memcpy(dest3_s21, src3, n3);

  answer4_string = memcpy(dest4_string, src4, n4);
  answer4_s21 = s21_memcpy(dest4_s21, src4, n4);

  answer5_string = memcpy(dest5_string, src5, n5);
  answer5_s21 = s21_memcpy(dest5_s21, src5, n5);

  answer7_string = memcpy(dest7_string, src7, n7);
  answer7_s21 = s21_memcpy(dest7_s21, src7, n7);

  // Assert
  ck_assert_mem_eq(answer1_string, answer1_s21, 1024);  // 1
  ck_assert_mem_eq(answer2_string, answer2_s21, 1024);  // 2
  ck_assert_mem_eq(answer3_string, answer3_s21, 1024);  // 3
  ck_assert_mem_eq(answer4_string, answer4_s21, 1024);  // 4
  ck_assert_mem_eq(answer5_string, answer5_s21, 1024);  // 5
  ck_assert_ptr_eq(answer5_s21, dest5_s21);             // 6
  ck_assert_mem_eq(answer7_string, answer7_s21, 1024);  // 7
}
END_TEST

// 4
// dst=5 src=4 n=5 1+
// dst=5 src=4 n=4 2+
// dst=5 src=6 n=6 3+
// dst=5 src=10 n=4 4+
// dst=5 src=0 n=5 5+
// проверка возврата. memmove возвращает dst 6+
// dst=5 src=11 и есть \0 в середине n=10 7+
// проверку перекрытия по памяти 8+
START_TEST(test_s21_memmove) {
  // Arrange
  char dest1_string[1024] = "1 str";
  char dest1_s21[1024] = "1 str";
  void *src1 = "2asd";
  size_t n1 = 5;
  void *answer1_string = NULL;
  void *answer1_s21 = NULL;

  char dest2_string[1024] = "1 str";
  char dest2_s21[1024] = "1 str";
  void *src2 = "2asd";
  size_t n2 = 4;
  void *answer2_string = NULL;
  void *answer2_s21 = NULL;

  char dest3_string[1024] = "1 str";
  char dest3_s21[1024] = "1 str";
  void *src3 = "2asdfg";
  size_t n3 = 6;
  void *answer3_string = NULL;
  void *answer3_s21 = NULL;

  char dest4_string[1024] = "1 str";
  char dest4_s21[1024] = "1 str";
  void *src4 = "2asdfghjkl";
  size_t n4 = 4;
  void *answer4_string = NULL;
  void *answer4_s21 = NULL;

  char dest5_string[1024] = "1 str";
  char dest5_s21[1024] = "1 str";
  void *src5 = "";
  size_t n5 = 5;
  void *answer5_string = NULL;
  void *answer5_s21 = NULL;

  char dest7_string[1024] = "1 str";
  char dest7_s21[1024] = "1 str";
  void *src7 = "2asd\0fghjkl";
  size_t n7 = 10;
  void *answer7_string = NULL;
  void *answer7_s21 = NULL;

  char dest8_string[11] = "1234567890";
  char dest8_s21[11] = "1234567890";
  size_t n8 = 3;
  void *answer8_string = NULL;
  void *answer8_s21 = NULL;

  // Act
  answer1_string = memmove(dest1_string, src1, n1);
  answer1_s21 = s21_memmove(dest1_s21, src1, n1);

  answer2_string = memmove(dest2_string, src2, n2);
  answer2_s21 = s21_memmove(dest2_s21, src2, n2);

  answer3_string = memmove(dest3_string, src3, n3);
  answer3_s21 = s21_memmove(dest3_s21, src3, n3);

  answer4_string = memmove(dest4_string, src4, n4);
  answer4_s21 = s21_memmove(dest4_s21, src4, n4);

  answer5_string = memmove(dest5_string, src5, n5);
  answer5_s21 = s21_memmove(dest5_s21, src5, n5);

  answer7_string = memmove(dest7_string, src7, n7);
  answer7_s21 = s21_memmove(dest7_s21, src7, n7);

  answer8_string = memmove(&dest8_string[4], &dest8_string[3], n8);
  answer8_s21 = s21_memmove(&dest8_s21[4], &dest8_s21[3], n8);
  // Assert
  ck_assert_mem_eq(answer1_string, answer1_s21, 1024);  // 1
  ck_assert_mem_eq(answer2_string, answer2_s21, 1024);  // 2
  ck_assert_mem_eq(answer3_string, answer3_s21, 1024);  // 3
  ck_assert_mem_eq(answer4_string, answer4_s21, 1024);  // 4
  ck_assert_mem_eq(answer5_string, answer5_s21, 1024);  // 5
  ck_assert_ptr_eq(answer5_s21, dest5_s21);             // 6
  ck_assert_mem_eq(answer7_string, answer7_s21, 1024);  // 7
  ck_assert_str_eq(answer8_string, answer8_s21);        // 8
  ck_assert_str_eq(dest8_string, dest8_s21);            // 8
}
END_TEST

// 5
// src[11]=10 n=10 1+
// src[11]=10 n=11 - через check не потестить из-за перекрытия \0
// src=10 n=5 2+
// src=10 n=15 - Abort 6
// в src есть русская буква 3+
// возвращает указатель на src 4+
// запись в пустую строку 5+
START_TEST(test_s21_memset) {
  // Arrange
  char dest1_string[11] = "1234567890";
  char dest1_s21[11] = "1234567890";
  char ch1 = 'a';
  size_t n1 = 10;
  void *answer1_string = NULL;
  void *answer1_s21 = NULL;

  char dest2_string[11] = "1234567890";
  char dest2_s21[11] = "1234567890";
  char ch2 = 'a';
  size_t n2 = 5;
  void *answer2_string = NULL;
  void *answer2_s21 = NULL;

  char dest3_string[12] = "12ф4567890";
  char dest3_s21[12] = "12ф4567890";
  char ch3 = 'a';
  size_t n3 = 5;
  void *answer3_string = NULL;
  void *answer3_s21 = NULL;

  char dest5_string[12] = "";
  char dest5_s21[12] = "";
  char ch5 = 'a';
  size_t n5 = 5;
  void *answer5_string = NULL;
  void *answer5_s21 = NULL;
  // Act
  answer1_string = memset(dest1_string, ch1, n1);
  answer1_s21 = s21_memset(dest1_s21, ch1, n1);

  answer2_string = memset(dest2_string, ch2, n2);
  answer2_s21 = s21_memset(dest2_s21, ch2, n2);

  answer3_string = memset(dest3_string, ch3, n3);
  answer3_s21 = s21_memset(dest3_s21, ch3, n3);

  answer5_string = memset(dest5_string, ch5, n5);
  answer5_s21 = s21_memset(dest5_s21, ch5, n5);
  // Assert
  ck_assert_str_eq(answer1_string, answer1_s21);      // 1 1024 или 11?
  ck_assert_mem_eq(answer2_string, answer2_s21, 11);  // 2 1024 или 11?
  ck_assert_mem_eq(answer3_string, answer3_s21, 11);  // 3 1024 или 11?
  ck_assert_ptr_eq(answer3_s21, dest3_s21);           // 4
  ck_assert_mem_eq(answer5_string, answer5_s21, 5);   // 5 1024 или 5?
}
END_TEST

// 6
// в полную строку полную строку 1+
// в пустую строку полную строку 2+
// в полную строку пустую строку 3+
// в пустую строку пустую строку 4+
// в строку с \0 полную строку 5+
// в полную строку строку с \0 6+
START_TEST(test_s21_strcat) {
  // Arrange
  char s1_1_string[1024] = "1 str";
  char s1_1_s21[1024] = "1 str";
  char *s2_1 = "2 str";
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char s1_2_string[1024] = "";
  char s1_2_s21[1024] = "";
  char *s2_2 = "2 str";
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char s1_3_string[1024] = "1 str";
  char s1_3_s21[1024] = "1 str";
  char *s2_3 = "";
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char s1_4_string[1024] = "";
  char s1_4_s21[1024] = "";
  char *s2_4 = "";
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char s1_5_string[1024] = "1 st\0r";
  char s1_5_s21[1024] = "1 st\0r";
  char *s2_5 = "2 str";
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char s1_6_string[1024] = "1 str";
  char s1_6_s21[1024] = "1 str";
  char *s2_6 = "2 s\0r";
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;
  // Act
  answer1_string = strcat(s1_1_string, s2_1);
  answer1_s21 = s21_strcat(s1_1_s21, s2_1);

  answer2_string = strcat(s1_2_string, s2_2);
  answer2_s21 = s21_strcat(s1_2_s21, s2_2);

  answer3_string = strcat(s1_3_string, s2_3);
  answer3_s21 = s21_strcat(s1_3_s21, s2_3);

  answer4_string = strcat(s1_4_string, s2_4);
  answer4_s21 = s21_strcat(s1_4_s21, s2_4);

  answer5_string = strcat(s1_5_string, s2_5);
  answer5_s21 = s21_strcat(s1_5_s21, s2_5);

  answer6_string = strcat(s1_6_string, s2_6);
  answer6_s21 = s21_strcat(s1_6_s21, s2_6);
  // Assert
  ck_assert_str_eq(answer1_string, answer1_s21);  // 1
  ck_assert_str_eq(answer2_string, answer2_s21);  // 2
  ck_assert_str_eq(answer3_string, answer3_s21);  // 3
  ck_assert_str_eq(answer4_string, answer4_s21);  // 4
  ck_assert_str_eq(answer5_string, answer5_s21);  // 5
  ck_assert_str_eq(answer6_string, answer6_s21);  // 6
}
END_TEST

// 7
// в полную строку полную строку 1+
// в пустую строку полную строку 2+
// в полную строку пустую строку 3+
// в пустую строку пустую строку 4+
// в строку с \0 полную строку 5+
// в полную строку строку с \0 6+
// str1=5 str2=5 n=5 1+
// str1=5 str2=5 n=3 7
// str1=5 str2=5 n=15 8
START_TEST(test_s21_strncat) {
  // Arrange
  char s1_1_string[1024] = "1 str";
  char s1_1_s21[1024] = "1 str";
  char *s2_1 = "2 str";
  size_t n1 = 5;
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char s1_2_string[1024] = "";
  char s1_2_s21[1024] = "";
  char *s2_2 = "2 str";
  size_t n2 = 5;
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char s1_3_string[1024] = "1 str";
  char s1_3_s21[1024] = "1 str";
  char *s2_3 = "";
  size_t n3 = 5;
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char s1_4_string[1024] = "";
  char s1_4_s21[1024] = "";
  char *s2_4 = "";
  size_t n4 = 5;
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char s1_5_string[1024] = "1 st\0r";
  char s1_5_s21[1024] = "1 st\0r";
  char *s2_5 = "2 str";
  size_t n5 = 5;
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char s1_6_string[1024] = "1 str";
  char s1_6_s21[1024] = "1 str";
  char *s2_6 = "2 s\0r";
  size_t n6 = 5;
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;

  char s1_7_string[1024] = "1 str";
  char s1_7_s21[1024] = "1 str";
  char *s2_7 = "2 str";
  size_t n7 = 3;
  char *answer7_string = NULL;
  char *answer7_s21 = NULL;

  char s1_8_string[1024] = "1 str";
  char s1_8_s21[1024] = "1 str";
  char *s2_8 = "2 str";
  size_t n8 = 15;
  char *answer8_string = NULL;
  char *answer8_s21 = NULL;
  // Act
  answer1_string = strncat(s1_1_string, s2_1, n1);
  answer1_s21 = s21_strncat(s1_1_s21, s2_1, n1);

  answer2_string = strncat(s1_2_string, s2_2, n2);
  answer2_s21 = s21_strncat(s1_2_s21, s2_2, n2);

  answer3_string = strncat(s1_3_string, s2_3, n3);
  answer3_s21 = s21_strncat(s1_3_s21, s2_3, n3);

  answer4_string = strncat(s1_4_string, s2_4, n4);
  answer4_s21 = s21_strncat(s1_4_s21, s2_4, n4);

  answer5_string = strncat(s1_5_string, s2_5, n5);
  answer5_s21 = s21_strncat(s1_5_s21, s2_5, n5);

  answer6_string = strncat(s1_6_string, s2_6, n6);
  answer6_s21 = s21_strncat(s1_6_s21, s2_6, n6);

  answer7_string = strncat(s1_7_string, s2_7, n7);
  answer7_s21 = s21_strncat(s1_7_s21, s2_7, n7);

  answer8_string = strncat(s1_8_string, s2_8, n8);
  answer8_s21 = s21_strncat(s1_8_s21, s2_8, n8);
  // Assert
  ck_assert_str_eq(answer1_string, answer1_s21);  // 1
  ck_assert_str_eq(answer2_string, answer2_s21);  // 2
  ck_assert_str_eq(answer3_string, answer3_s21);  // 3
  ck_assert_str_eq(answer4_string, answer4_s21);  // 4
  ck_assert_str_eq(answer5_string, answer5_s21);  // 5
  ck_assert_str_eq(answer6_string, answer6_s21);  // 6
  ck_assert_str_eq(answer7_string, answer7_s21);  // 7
  ck_assert_str_eq(answer8_string, answer8_s21);  // 8
}
END_TEST

// 8
// поиск существующего символа в строке 1+
// поиск не существующего симовла в строке 2+
// поиск в пустой строке 3+
// поиск в строке где есть в середине \0 4+
// поиск в строке символа \0 5 10+
// поиск русской буквы 6 6_2+
// проверить позицию \0 10 11+
// проверка на ячейку памяти 9+
// когда в строке несколько искомых символов 12+
START_TEST(test_s21_strchr) {
  // Arrange
  char s1[1024] = "1234567890";
  char c1 = '4';
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char s2[1024] = "1234567890";
  char c2 = 'a';
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char s3[1024] = "";
  char c3 = '4';
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char s4[1024] = "123\04567890";
  char c4 = '4';
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char s5[1024] = "123\04567890";
  char c5 = '\0';
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char s6[1024] = "123ф4567890";
  char c6 = -47;
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;

  char s6_2[1024] = "123ф4567890";
  char c6_2 = -124;
  char *answer6_2_string = NULL;
  char *answer6_2_s21 = NULL;

  char s9[1024] = "1234567890";
  char c9 = '4';
  char *answer9_string = NULL;
  char *answer9_s21 = NULL;

  char s10[1024] = "1234567890";
  char c10 = '\0';
  char *answer10_string = NULL;
  char *answer10_s21 = NULL;

  char s11[1024] = "1234\0567890";
  char c11 = '\0';
  char *answer11_string = NULL;
  char *answer11_s21 = NULL;

  char s12[1024] = "12345647890";
  char c12 = '4';
  char *answer12_string = NULL;
  char *answer12_s21 = NULL;
  // Act
  answer1_string = strchr(s1, c1);
  answer1_s21 = s21_strchr(s1, c1);

  answer2_string = strchr(s2, c2);
  answer2_s21 = s21_strchr(s2, c2);

  answer3_string = strchr(s3, c3);
  answer3_s21 = s21_strchr(s3, c3);

  answer4_string = strchr(s4, c4);
  answer4_s21 = s21_strchr(s4, c4);

  answer5_string = strchr(s5, c5);
  answer5_s21 = s21_strchr(s5, c5);

  answer6_string = strchr(s6, c6);
  answer6_s21 = s21_strchr(s6, c6);

  answer6_2_string = strchr(s6_2, c6_2);
  answer6_2_s21 = s21_strchr(s6_2, c6_2);

  answer9_string = strchr(s9, c9);
  answer9_s21 = s21_strchr(s9, c9);

  answer10_string = strchr(s10, c10);
  answer10_s21 = s21_strchr(s10, c10);

  answer11_string = strchr(s11, c11);
  answer11_s21 = s21_strchr(s11, c11);

  answer12_string = strchr(s12, c12);
  answer12_s21 = s21_strchr(s12, c12);
  // Assert
  ck_assert_str_eq(answer1_string, answer1_s21);      // 1
  ck_assert_ptr_eq(answer2_string, answer2_s21);      // 2
  ck_assert_ptr_eq(answer3_string, answer3_s21);      // 3
  ck_assert_ptr_eq(answer4_string, answer4_s21);      // 4
  ck_assert_str_eq(answer5_string, answer5_s21);      // 5
  ck_assert_str_eq(answer6_string, answer6_s21);      // 6
  ck_assert_str_eq(answer6_2_string, answer6_2_s21);  // 6_2
  ck_assert_ptr_eq(answer9_string, answer9_s21);      // 9
  ck_assert_ptr_eq(answer10_string, answer10_s21);    // 10
  ck_assert_ptr_eq(answer11_string, answer11_s21);    // 11
  ck_assert_ptr_eq(answer12_string, answer12_s21);    // 12
}
END_TEST

// 9
// s1=s2 1+
// s1!=s2 2+
// различие в русской букве 6+
// различие при наличии \0 в одной строке 7+
// различие при \0 в обеих строках 8+
START_TEST(test_s21_strcmp) {
  // Arrange
  char *s1_1 = "asdf";
  char *s2_1 = "asdf";
  int answer1_string;
  int answer1_s21;

  char *s1_2 = "asdf";
  char *s2_2 = "asdg";
  int answer2_string;
  int answer2_s21;

  char *s1_7 = "asdf";
  char *s2_7 = "as\0dg";
  int answer7_string;
  int answer7_s21;

  char *s1_8 = "as\0df";
  char *s2_8 = "as\0dg";
  int answer8_string;
  int answer8_s21;
  // Act
  answer1_string = strcmp(s1_1, s2_1);
  answer1_s21 = s21_strcmp(s1_1, s2_1);

  answer2_string = strcmp(s1_2, s2_2);
  answer2_s21 = s21_strcmp(s1_2, s2_2);

  answer7_string = strcmp(s1_7, s2_7);
  answer7_s21 = s21_strcmp(s1_7, s2_7);

  answer8_string = strcmp(s1_8, s2_8);
  answer8_s21 = s21_strcmp(s1_8, s2_8);
  // Assert
  ck_assert_int_eq(answer1_string, answer1_s21);  // 1
  ck_assert_int_eq(answer2_string, answer2_s21);  // 2
  ck_assert_int_eq(answer7_string, answer7_s21);  // 7
  ck_assert_int_eq(answer8_string, answer8_s21);  // 8
}
END_TEST

// 10
// s1=s2 n>len(s1) 1+
// s1!=s2 n<len(s1) 2+
// s1=s2 n=len(s1) 3+
// s1!=s2 n>len(s1) 4+
// s1!=s2 n=len(s1) 5+
// различие в русской букве 6+
// различие при наличии \0 в одной строке 7+
// различие при \0 в обеих строках 8+
START_TEST(test_s21_strncmp) {
  // Arrange
  char *s1_1 = "asdf";
  char *s2_1 = "asdf";
  size_t n1 = 6;
  int answer1_string;
  int answer1_s21;

  char *s1_2 = "asdf";
  char *s2_2 = "asdg";
  size_t n2 = 2;
  int answer2_string;
  int answer2_s21;

  char *s1_3 = "asdf";
  char *s2_3 = "asdf";
  size_t n3 = 4;
  int answer3_string;
  int answer3_s21;

  char *s1_4 = "asdf";
  char *s2_4 = "asdg";
  size_t n4 = 6;
  int answer4_string;
  int answer4_s21;

  char *s1_5 = "asdf";
  char *s2_5 = "asdg";
  size_t n5 = 4;
  int answer5_string;
  int answer5_s21;

  char *s1_7 = "asdf";
  char *s2_7 = "as\0dg";
  size_t n7 = 15;
  int answer7_string;
  int answer7_s21;

  char *s1_8 = "as\0df";
  char *s2_8 = "as\0dg";
  size_t n8 = 15;
  int answer8_string;
  int answer8_s21;
  // Act
  answer1_string = strncmp(s1_1, s2_1, n1);
  answer1_s21 = s21_strncmp(s1_1, s2_1, n1);

  answer2_string = strncmp(s1_2, s2_2, n2);
  answer2_s21 = s21_strncmp(s1_2, s2_2, n2);

  answer3_string = strncmp(s1_3, s2_3, n3);
  answer3_s21 = s21_strncmp(s1_3, s2_3, n3);

  answer4_string = strncmp(s1_4, s2_4, n4);
  answer4_s21 = s21_strncmp(s1_4, s2_4, n4);

  answer5_string = strncmp(s1_5, s2_5, n5);
  answer5_s21 = s21_strncmp(s1_5, s2_5, n5);

  answer7_string = strncmp(s1_7, s2_7, n7);
  answer7_s21 = s21_strncmp(s1_7, s2_7, n7);

  answer8_string = strncmp(s1_8, s2_8, n8);
  answer8_s21 = s21_strncmp(s1_8, s2_8, n8);
  // Assert
  ck_assert_int_eq(answer1_string, answer1_s21);  // 1
  ck_assert_int_eq(answer2_string, answer2_s21);  // 2
  ck_assert_int_eq(answer3_string, answer3_s21);  // 3
  ck_assert_int_eq(answer4_string, answer4_s21);  // 4
  ck_assert_int_eq(answer5_string, answer5_s21);  // 5
  ck_assert_int_eq(answer7_string, answer7_s21);  // 7
  ck_assert_int_eq(answer8_string, answer8_s21);  // 8
}
END_TEST

// 11
// dst=5 src=3 1+
// dst=5 src=6 2+
// dst=5 src=5 3+
// dst=0 src=5 4+
// dst=5 src=0 5+
// проверка на запись в строку без нужного размера? почему то нет abort() 6+
// использование статичных и динамичных массивов 7+
// проверка возврата. strcpy возвращает dst 8+
// dst=5 src=7 и есть \0 в середине 9+
START_TEST(test_s21_strcpy) {
  // Arrange
  char dest1_string[1024] = "1 str";
  char dest1_s21[1024] = "1 str";
  char src1[1024] = "2as";
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char dest2_string[1024] = "1 str";
  char dest2_s21[1024] = "1 str";
  char src2[1024] = "2asdfg";
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char dest3_string[1024] = "1 str";
  char dest3_s21[1024] = "1 str";
  char src3[1024] = "2asdf";
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char dest4_string[1024] = "";
  char dest4_s21[1024] = "";
  char src4[1024] = "2asdf";
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char dest5_string[1024] = "1 str";
  char dest5_s21[1024] = "1 str";
  char src5[1024] = "";
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char dest6_string[5] = "1 str";
  char dest6_s21[1024] = "1 strr";
  char src6[1024] = "";
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;

  char *dest7_string = malloc(100);
  char *dest7_s21 = malloc(100);
  char src7[1024] = "2as";
  char *answer7_string = NULL;
  char *answer7_s21 = NULL;

  char dest9_string[1024] = "1 str";
  char dest9_s21[1024] = "1 str";
  char src9[1024] = "2asd\0fg";
  char *answer9_string = NULL;
  char *answer9_s21 = NULL;
  // Act
  answer1_string = strcpy(dest1_string, src1);
  answer1_s21 = s21_strcpy(dest1_s21, src1);

  answer2_string = strcpy(dest2_string, src2);
  answer2_s21 = s21_strcpy(dest2_s21, src2);

  answer3_string = strcpy(dest3_string, src3);
  answer3_s21 = s21_strcpy(dest3_s21, src3);

  answer4_string = strcpy(dest4_string, src4);
  answer4_s21 = s21_strcpy(dest4_s21, src4);

  answer5_string = strcpy(dest5_string, src5);
  answer5_s21 = s21_strcpy(dest5_s21, src5);

  answer6_string = strcpy(dest6_string, src6);
  answer6_s21 = s21_strcpy(dest6_s21, src6);

  answer7_string = strcpy(dest7_string, src7);
  answer7_s21 = s21_strcpy(dest7_s21, src7);

  answer9_string = strcpy(dest9_string, src9);
  answer9_s21 = s21_strcpy(dest9_s21, src9);
  //  printf("%s\n", answer7_string);
  //  printf("%s\n", answer7_s21);
  // Assert
  ck_assert_str_eq(answer1_string, answer1_s21);  // 1
  ck_assert_str_eq(answer2_string, answer2_s21);  // 2
  ck_assert_str_eq(answer3_string, answer3_s21);  // 3
  ck_assert_str_eq(answer4_string, answer4_s21);  // 4
  ck_assert_str_eq(answer5_string, answer5_s21);  // 5
  ck_assert_str_eq(answer6_string, answer6_s21);  // 6
  ck_assert_str_eq(answer7_string, answer7_s21);  // 7
  ck_assert_ptr_eq(dest7_s21, answer7_s21);       // 8
  ck_assert_str_eq(answer9_string, answer9_s21);  // 9
  free(dest7_string);
  free(dest7_s21);
}
END_TEST

// 12
// в строку занести длинную строку, но ограничить длиной первой через n
// dst=5 src=4 n=5 1+
// dst=5 src=4 n=4 2+
// dst=5 src=6 n=6 3+
// dst=5 src=10 n=4 4+
// dst=5 src=0 n=5 5+
// проверка возврата. memcpy возвращает dst 6+
// dst=5 src=11 и есть \0 в середине n=10 7+
START_TEST(test_s21_strncpy) {
  // Arrange
  char dest1_string[1024] = "1 str";
  char dest1_s21[1024] = "1 str";
  char *src1 = "2asd";
  size_t n1 = 5;
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char dest2_string[1024] = "1 str";
  char dest2_s21[1024] = "1 str";
  char *src2 = "2asd";
  size_t n2 = 4;
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char dest3_string[1024] = "1 str";
  char dest3_s21[1024] = "1 str";
  char *src3 = "2asdfg";
  size_t n3 = 6;
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char dest4_string[1024] = "1 str";
  char dest4_s21[1024] = "1 str";
  char *src4 = "2asdfghjkl";
  size_t n4 = 4;
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char dest5_string[1024] = "1 str";
  char dest5_s21[1024] = "1 str";
  char *src5 = "";
  size_t n5 = 5;
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char dest7_string[1024] = "1 str";
  char dest7_s21[1024] = "1 str";
  char *src7 = "2asd\0fghjkl";
  size_t n7 = 10;
  char *answer7_string = NULL;
  char *answer7_s21 = NULL;
  // Act
  answer1_string = strncpy(dest1_string, src1, n1);
  answer1_s21 = s21_strncpy(dest1_s21, src1, n1);

  answer2_string = strncpy(dest2_string, src2, n2);
  answer2_s21 = s21_strncpy(dest2_s21, src2, n2);

  answer3_string = strncpy(dest3_string, src3, n3);
  answer3_s21 = s21_strncpy(dest3_s21, src3, n3);

  answer4_string = strncpy(dest4_string, src4, n4);
  answer4_s21 = s21_strncpy(dest4_s21, src4, n4);

  answer5_string = strncpy(dest5_string, src5, n5);
  answer5_s21 = s21_strncpy(dest5_s21, src5, n5);

  answer7_string = strncpy(dest7_string, src7, n7);
  answer7_s21 = s21_strncpy(dest7_s21, src7, n7);
  // Assert
  ck_assert_str_eq(answer1_string, answer1_s21);  // 1
  ck_assert_str_eq(answer2_string, answer2_s21);  // 2
  ck_assert_str_eq(answer3_string, answer3_s21);  // 3
  ck_assert_str_eq(answer4_string, answer4_s21);  // 4
  ck_assert_str_eq(answer5_string, answer5_s21);  // 5
  ck_assert_ptr_eq(answer5_s21, dest5_s21);       // 6
  ck_assert_str_eq(answer7_string, answer7_s21);  // 7
}
END_TEST

// 13
//
START_TEST(test_s21_strcspn) {
  // Arrange
  char s1_1[1024] = "1234567890";
  char s2_1[1024] = "6";
  size_t answer1_string = 0;
  size_t answer1_s21 = 0;

  char s1_2[1024] = "1234567890";
  char s2_2[1024] = "967";
  size_t answer2_string = 0;
  size_t answer2_s21 = 0;

  char s1_3[1024] = "1234567890";
  char s2_3[1024] = "a";
  size_t answer3_string = 0;
  size_t answer3_s21 = 0;

  char s1_4[1024] = "1234\0567890";
  char s2_4[1024] = "9";
  size_t answer4_string = 0;
  size_t answer4_s21 = 0;

  char s1_5[1024] = "1234\0567890";
  char s2_5[1024] = "96";
  size_t answer5_string = 0;
  size_t answer5_s21 = 0;

  char s1_6[1024] = "1234\0567890";
  char s2_6[1024] = "967";
  size_t answer6_string = 0;
  size_t answer6_s21 = 0;

  char s1_7[1024] = "12345678\090";
  char s2_7[1024] = "7";
  size_t answer7_string = 0;
  size_t answer7_s21 = 0;

  char s1_8[1024] = "1234\0567890";
  char s2_8[1024] = "\0";
  size_t answer8_string = 0;
  size_t answer8_s21 = 0;

  char s1_9[1024] = "1234ф567890";
  char s2_9[1024] = "ф";
  size_t answer9_string = 0;
  size_t answer9_s21 = 0;

  char s1_10[1024] = "1234ф567890";
  char s2_10[1024] = "ф\0";
  size_t answer10_string = 0;
  size_t answer10_s21 = 0;

  char s1_11[1024] = "1234ф567890";
  char s2_11[1024] = "\0ф\0";
  size_t answer11_string = 0;
  size_t answer11_s21 = 0;

  char s1_12[1024] = "1234ф567890";
  char s2_12[1024] = "\0";
  size_t answer12_string = 0;
  size_t answer12_s21 = 0;

  // Act
  answer1_string = strcspn(s1_1, s2_1);
  answer1_s21 = s21_strcspn(s1_1, s2_1);

  answer2_string = strcspn(s1_2, s2_2);
  answer2_s21 = s21_strcspn(s1_2, s2_2);

  answer3_string = strcspn(s1_3, s2_3);
  answer3_s21 = s21_strcspn(s1_3, s2_3);

  answer4_string = strcspn(s1_4, s2_4);
  answer4_s21 = s21_strcspn(s1_4, s2_4);

  answer5_string = strcspn(s1_5, s2_5);
  answer5_s21 = s21_strcspn(s1_5, s2_5);

  answer6_string = strcspn(s1_6, s2_6);
  answer6_s21 = s21_strcspn(s1_6, s2_6);

  answer7_string = strcspn(s1_7, s2_7);
  answer7_s21 = s21_strcspn(s1_7, s2_7);

  answer8_string = strcspn(s1_8, s2_8);
  answer8_s21 = s21_strcspn(s1_8, s2_8);

  answer9_string = strcspn(s1_9, s2_9);
  answer9_s21 = s21_strcspn(s1_9, s2_9);

  answer10_string = strcspn(s1_10, s2_10);
  answer10_s21 = s21_strcspn(s1_10, s2_10);

  answer11_string = strcspn(s1_11, s2_11);
  answer11_s21 = s21_strcspn(s1_11, s2_11);

  answer12_string = strcspn(s1_12, s2_12);
  answer12_s21 = s21_strcspn(s1_12, s2_12);
  // Assert
  ck_assert_int_eq(answer1_string, answer1_s21);
  ck_assert_int_eq(answer2_string, answer2_s21);
  ck_assert_int_eq(answer3_string, answer3_s21);
  ck_assert_int_eq(answer4_string, answer4_s21);
  ck_assert_int_eq(answer5_string, answer5_s21);
  ck_assert_int_eq(answer6_string, answer6_s21);
  ck_assert_int_eq(answer7_string, answer7_s21);
  ck_assert_int_eq(answer8_string, answer8_s21);
  ck_assert_int_eq(answer9_string, answer9_s21);
  ck_assert_int_eq(answer10_string, answer10_s21);
  ck_assert_int_eq(answer11_string, answer11_s21);
  ck_assert_int_eq(answer12_string, answer12_s21);
}
END_TEST

// 14
START_TEST(test_s21_strerror) {
  // Arrange
  // Act
  // Assert
  for (int i = 0; i < sys_nerr; i++) {
    char *answer_string = strerror(i);
    char *answer_s21 = s21_strerror(i);
    ck_assert_str_eq(answer_string, answer_s21);
  }
}
END_TEST

// 15
// обычная строка 1
// строка с русской буквой 2
// пустая строка
// строка с \0
START_TEST(test_s21_strlen) {
  // Arrange
  char s1[1024] = "1234567890";
  size_t answer1_string = 0;
  size_t answer1_s21 = 0;

  char s2[1024] = "1234567890ф";
  size_t answer2_string = 0;
  size_t answer2_s21 = 0;

  char s3[1024] = "";
  size_t answer3_string = 0;
  size_t answer3_s21 = 0;

  char s4[1024] = "1234567890\0";
  size_t answer4_string = 0;
  size_t answer4_s21 = 0;

  char s5[1024] = "12345\067890";
  size_t answer5_string = 0;
  size_t answer5_s21 = 0;

  char s6[1024] = "\01234567890";
  size_t answer6_string = 0;
  size_t answer6_s21 = 0;
  // Act
  answer1_string = strlen(s1);
  answer1_s21 = s21_strlen(s1);

  answer2_string = strlen(s2);
  answer2_s21 = s21_strlen(s2);

  answer3_string = strlen(s3);
  answer3_s21 = s21_strlen(s3);

  answer4_string = strlen(s4);
  answer4_s21 = s21_strlen(s4);

  answer5_string = strlen(s5);
  answer5_s21 = s21_strlen(s5);

  answer6_string = strlen(s6);
  answer6_s21 = s21_strlen(s6);
  // Assert
  ck_assert_int_eq(answer1_string, answer1_s21);
  ck_assert_int_eq(answer2_string, answer2_s21);
  ck_assert_int_eq(answer3_string, answer3_s21);
  ck_assert_int_eq(answer4_string, answer4_s21);
  ck_assert_int_eq(answer5_string, answer5_s21);
  ck_assert_int_eq(answer6_string, answer6_s21);
}
END_TEST

// 16
START_TEST(test_s21_strpbrk) {
  // Arrange
  char s1_1[1024] = "1234567890";
  char s2_1[1024] = "6";
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char s1_2[1024] = "1234567890";
  char s2_2[1024] = "976";
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char s1_3[1024] = "1234567890";
  char s2_3[1024] = "a";
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char s1_4[1024] = "1234\0567890";
  char s2_4[1024] = "9";
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char s1_5[1024] = "1234\0567890";
  char s2_5[1024] = "96";
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char s1_6[1024] = "1234\0567890";
  char s2_6[1024] = "976";
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;

  char s1_7[1024] = "123456789\00";
  char s2_7[1024] = "7";
  char *answer7_string = NULL;
  char *answer7_s21 = NULL;

  char s1_8[1024] = "1234\0567890";
  char s2_8[1024] = "\0";
  char *answer8_string = NULL;
  char *answer8_s21 = NULL;

  char s1_9[1024] = "1234ф567890";
  char s2_9[1024] = "ф";
  char *answer9_string = NULL;
  char *answer9_s21 = NULL;

  char s1_10[1024] = "1234ф567890";
  char s2_10[1024] = "ф\0";
  char *answer10_string = NULL;
  char *answer10_s21 = NULL;

  char s1_11[1024] = "1234ф567890";
  char s2_11[1024] = "\0ф\0";
  char *answer11_string = NULL;
  char *answer11_s21 = NULL;

  char s1_12[1024] = "1234ф567890";
  char s2_12[1024] = "\0";
  char *answer12_string = NULL;
  char *answer12_s21 = NULL;
  // Act
  answer1_string = strpbrk(s1_1, s2_1);
  answer1_s21 = s21_strpbrk(s1_1, s2_1);

  answer2_string = strpbrk(s1_2, s2_2);
  answer2_s21 = s21_strpbrk(s1_2, s2_2);

  answer3_string = strpbrk(s1_3, s2_3);
  answer3_s21 = s21_strpbrk(s1_3, s2_3);

  answer4_string = strpbrk(s1_4, s2_4);
  answer4_s21 = s21_strpbrk(s1_4, s2_4);

  answer5_string = strpbrk(s1_5, s2_5);
  answer5_s21 = s21_strpbrk(s1_5, s2_5);

  answer6_string = strpbrk(s1_6, s2_6);
  answer6_s21 = s21_strpbrk(s1_6, s2_6);

  answer7_string = strpbrk(s1_7, s2_7);
  answer7_s21 = s21_strpbrk(s1_7, s2_7);

  answer8_string = strpbrk(s1_8, s2_8);
  answer8_s21 = s21_strpbrk(s1_8, s2_8);

  answer9_string = strpbrk(s1_9, s2_9);
  answer9_s21 = s21_strpbrk(s1_9, s2_9);

  answer10_string = strpbrk(s1_10, s2_10);
  answer10_s21 = s21_strpbrk(s1_10, s2_10);

  answer11_string = strpbrk(s1_11, s2_11);
  answer11_s21 = s21_strpbrk(s1_11, s2_11);

  answer12_string = strpbrk(s1_12, s2_12);
  answer12_s21 = s21_strpbrk(s1_12, s2_12);
  // Assert
  ck_assert_str_eq(answer1_string, answer1_s21);
  ck_assert_str_eq(answer2_string, answer2_s21);
  ck_assert_pstr_eq(answer3_string, answer3_s21);
  ck_assert_str_eq(answer4_string, answer4_s21);
  ck_assert_str_eq(answer5_string, answer5_s21);
  ck_assert_str_eq(answer6_string, answer6_s21);
  ck_assert_str_eq(answer7_string, answer7_s21);
  ck_assert_pstr_eq(answer8_string, answer8_s21);
  ck_assert_str_eq(answer9_string, answer9_s21);
  ck_assert_str_eq(answer10_string, answer10_s21);
  ck_assert_pstr_eq(answer11_string, answer11_s21);
  ck_assert_pstr_eq(answer12_string, answer12_s21);
}
END_TEST

// 17
// поиск существующего символа в строке 1+
// поиск не существующего симовла в строке 2+
// поиск в пустой строке 3+
// поиск в строке где есть в середине \0 4+
// поиск в строке символа \0 5 10+
// поиск русской буквы 6 6_2+
// проверить позицию \0 10 11+
// проверка на ячейку памяти 9+
// когда в строке несколько искомых символов 12+
START_TEST(test_s21_strrchr) {
  // Arrange
  char s1[1024] = "1234567890";
  char c1 = '4';
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char s2[1024] = "1234567890";
  char c2 = 'a';
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char s3[1024] = "";
  char c3 = '4';
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char s4[1024] = "1234567\0890";
  char c4 = '4';
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char s5[1024] = "123\04567890";
  char c5 = '\0';
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char s6[1024] = "123ф4567890";
  char c6 = -47;
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;

  char s6_2[1024] = "123ф4567890";
  char c6_2 = -124;
  char *answer6_2_string = NULL;
  char *answer6_2_s21 = NULL;

  char s9[1024] = "1234567890";
  char c9 = '4';
  char *answer9_string = NULL;
  char *answer9_s21 = NULL;

  char s10[1024] = "1234567890";
  char c10 = '\0';
  char *answer10_string = NULL;
  char *answer10_s21 = NULL;

  char s11[1024] = "1234\0567890";
  char c11 = '\0';
  char *answer11_string = NULL;
  char *answer11_s21 = NULL;

  char s12[1024] = "12345647890";
  char c12 = '4';
  char *answer12_string = NULL;
  char *answer12_s21 = NULL;
  // Act
  answer1_string = strrchr(s1, c1);
  answer1_s21 = s21_strrchr(s1, c1);

  answer2_string = strrchr(s2, c2);
  answer2_s21 = s21_strrchr(s2, c2);

  answer3_string = strrchr(s3, c3);
  answer3_s21 = s21_strrchr(s3, c3);

  answer4_string = strrchr(s4, c4);
  answer4_s21 = s21_strrchr(s4, c4);

  answer5_string = strrchr(s5, c5);
  answer5_s21 = s21_strrchr(s5, c5);

  answer6_string = strrchr(s6, c6);
  answer6_s21 = s21_strrchr(s6, c6);

  answer6_2_string = strrchr(s6_2, c6_2);
  answer6_2_s21 = s21_strrchr(s6_2, c6_2);

  answer9_string = strrchr(s9, c9);
  answer9_s21 = s21_strrchr(s9, c9);

  answer10_string = strrchr(s10, c10);
  answer10_s21 = s21_strrchr(s10, c10);

  answer11_string = strrchr(s11, c11);
  answer11_s21 = s21_strrchr(s11, c11);

  answer12_string = strrchr(s12, c12);
  answer12_s21 = s21_strrchr(s12, c12);
  // Assert
  ck_assert_pstr_eq(answer1_string, answer1_s21);      // 1
  ck_assert_pstr_eq(answer2_string, answer2_s21);      // 2
  ck_assert_pstr_eq(answer3_string, answer3_s21);      // 3
  ck_assert_pstr_eq(answer4_string, answer4_s21);      // 4
  ck_assert_pstr_eq(answer5_string, answer5_s21);      // 5
  ck_assert_pstr_eq(answer6_string, answer6_s21);      // 6
  ck_assert_pstr_eq(answer6_2_string, answer6_2_s21);  // 6_2
  ck_assert_ptr_eq(answer9_string, answer9_s21);       // 9
  ck_assert_ptr_eq(answer10_string, answer10_s21);     // 10
  ck_assert_ptr_eq(answer11_string, answer11_s21);     // 11
  ck_assert_ptr_eq(answer12_string, answer12_s21);     // 12
}
END_TEST

// 18
START_TEST(test_s21_strspn) {
  // Arrange
  char s1_1[1024] = "1234567890";
  char s2_1[1024] = "5";
  size_t answer1_string = 0;
  size_t answer1_s21 = 0;

  char s1_2[1024] = "1234567890";
  char s2_2[1024] = "1";
  size_t answer2_string = 0;
  size_t answer2_s21 = 0;

  char s1_3[1024] = "1234567890";
  char s2_3[1024] = "123";
  size_t answer3_string = 0;
  size_t answer3_s21 = 0;

  char s1_4[1024] = "1234567890";
  char s2_4[1024] = "111";
  size_t answer4_string = 0;
  size_t answer4_s21 = 0;

  char s1_5[1024] = "1114567890";
  char s2_5[1024] = "111";
  size_t answer5_string = 0;
  size_t answer5_s21 = 0;

  char s1_6[1024] = "11\014567890";
  char s2_6[1024] = "111";
  size_t answer6_string = 0;
  size_t answer6_s21 = 0;

  char s1_7[1024] = "11\014567890";
  char s2_7[1024] = "111\0";
  size_t answer7_string = 0;
  size_t answer7_s21 = 0;

  char s1_8[1024] = "1114567890";
  char s2_8[1024] = "111\0";
  size_t answer8_string = 0;
  size_t answer8_s21 = 0;

  char s1_9[1024] = "111ф4567890";
  char s2_9[1024] = "111ф";
  size_t answer9_string = 0;
  size_t answer9_s21 = 0;
  // Act
  answer1_string = strspn(s1_1, s2_1);
  answer1_s21 = s21_strspn(s1_1, s2_1);

  answer2_string = strspn(s1_2, s2_2);
  answer2_s21 = s21_strspn(s1_2, s2_2);

  answer3_string = strspn(s1_3, s2_3);
  answer3_s21 = s21_strspn(s1_3, s2_3);

  answer4_string = strspn(s1_4, s2_4);
  answer4_s21 = s21_strspn(s1_4, s2_4);

  answer5_string = strspn(s1_5, s2_5);
  answer5_s21 = s21_strspn(s1_5, s2_5);

  answer6_string = strspn(s1_6, s2_6);
  answer6_s21 = s21_strspn(s1_6, s2_6);

  answer7_string = strspn(s1_7, s2_7);
  answer7_s21 = s21_strspn(s1_7, s2_7);

  answer8_string = strspn(s1_8, s2_8);
  answer8_s21 = s21_strspn(s1_8, s2_8);

  answer9_string = strspn(s1_9, s2_9);
  answer9_s21 = s21_strspn(s1_9, s2_9);
  // Assert
  ck_assert_int_eq(answer1_string, answer1_s21);
  ck_assert_int_eq(answer2_string, answer2_s21);
  ck_assert_int_eq(answer3_string, answer3_s21);
  ck_assert_int_eq(answer4_string, answer4_s21);
  ck_assert_int_eq(answer5_string, answer5_s21);
  ck_assert_int_eq(answer6_string, answer6_s21);
  ck_assert_int_eq(answer7_string, answer7_s21);
  ck_assert_int_eq(answer8_string, answer8_s21);
  ck_assert_int_eq(answer9_string, answer9_s21);
}
END_TEST

// 19
START_TEST(test_s21_strstr) {
  // Arrange
  char s1_1[1024] = "Foo Bar Baz";
  char s2_1[1024] = "Bar";
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char s1_2[1024] = "Foo Bar Bar Baz";
  char s2_2[1024] = "Bar";
  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char s1_3[1024] = "Foo \0Bar Bar Baz";
  char s2_3[1024] = "Bar";
  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char s1_4[1024] = "";
  char s2_4[1024] = "Bar";
  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char s1_5[1024] = "Foo Bar \0Bar Baz";
  char s2_5[1024] = "Bar";
  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char s1_6[1024] = "Foo Bar Bar Baz";
  char s2_6[1024] = "";
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;
  // Act
  answer1_string = strstr(s1_1, s2_1);
  answer1_s21 = s21_strstr(s1_1, s2_1);

  answer2_string = strstr(s1_2, s2_2);
  answer2_s21 = s21_strstr(s1_2, s2_2);

  answer3_string = strstr(s1_3, s2_3);
  answer3_s21 = s21_strstr(s1_3, s2_3);

  answer4_string = strstr(s1_4, s2_4);
  answer4_s21 = s21_strstr(s1_4, s2_4);

  answer5_string = strstr(s1_5, s2_5);
  answer5_s21 = s21_strstr(s1_5, s2_5);

  answer6_string = strstr(s1_6, s2_6);
  answer6_s21 = s21_strstr(s1_6, s2_6);
  // Assert
  ck_assert_pstr_eq(answer1_string, answer1_s21);
  ck_assert_pstr_eq(answer2_string, answer2_s21);
  ck_assert_pstr_eq(answer3_string, answer3_s21);
  ck_assert_pstr_eq(answer4_string, answer4_s21);
  ck_assert_pstr_eq(answer5_string, answer5_s21);
  ck_assert_pstr_eq(answer6_string, answer6_s21);
}
END_TEST

// 20
// проверить смену разделителя
START_TEST(test_s21_strtok) {
  // Arrange
  char s1[1024] = "This;is.a:test\\";
  char sep1[1024] = "\\/:;=-";
  char *answer1_string = NULL;
  char *answer1_s21 = NULL;

  char *answer2_string = NULL;
  char *answer2_s21 = NULL;

  char *answer3_string = NULL;
  char *answer3_s21 = NULL;

  char *answer4_string = NULL;
  char *answer4_s21 = NULL;

  char *answer5_string = NULL;
  char *answer5_s21 = NULL;

  char s6[1024] = "This;is\0.a:test\\";
  char *answer6_string = NULL;
  char *answer6_s21 = NULL;

  char sep7[1024] = "";
  char *answer7_string = NULL;
  char *answer7_s21 = NULL;

  char s8[1024] = "";
  char *answer8_string = NULL;
  char *answer8_s21 = NULL;
  // Act
  answer1_string = strtok(s1, sep1);
  answer1_string = strtok(s1, sep1);
  answer1_s21 = s21_strtok(s1, sep1);
  answer1_s21 = s21_strtok(s1, sep1);

  answer2_string = strtok(s1, sep1);
  answer2_string = strtok(NULL, sep1);
  answer2_s21 = s21_strtok(s1, sep1);
  answer2_s21 = s21_strtok(NULL, sep1);

  answer3_string = strtok(NULL, sep1);
  answer3_s21 = s21_strtok(NULL, sep1);

  answer4_string = strtok(s1, sep1);
  answer4_string = strtok(NULL, sep1);
  answer4_string = strtok(NULL, sep1);
  answer4_string = strtok(NULL, sep1);
  answer4_s21 = s21_strtok(s1, sep1);
  answer4_s21 = s21_strtok(NULL, sep1);
  answer4_s21 = s21_strtok(NULL, sep1);
  answer4_s21 = s21_strtok(NULL, sep1);

  answer5_string = strtok(s1, sep1);
  answer5_string = strtok(NULL, ".");
  answer5_s21 = s21_strtok(s1, sep1);
  answer5_s21 = s21_strtok(NULL, ".");

  answer6_string = strtok(s6, sep1);
  answer6_string = strtok(NULL, ".");
  answer6_string = strtok(NULL, sep1);
  answer6_string = strtok(NULL, sep1);
  answer6_s21 = s21_strtok(s6, sep1);
  answer6_s21 = s21_strtok(NULL, ".");
  answer6_s21 = s21_strtok(NULL, sep1);
  answer6_s21 = s21_strtok(NULL, sep1);

  answer7_string = strtok(s1, sep7);
  answer7_string = strtok(NULL, sep7);
  answer7_s21 = s21_strtok(s1, sep7);
  answer7_s21 = s21_strtok(NULL, sep7);

  answer8_string = strtok(s8, sep1);
  answer8_s21 = s21_strtok(s8, sep1);
  // Assert
  ck_assert_pstr_eq(answer1_string, answer1_s21);
  ck_assert_pstr_eq(answer2_string, answer2_s21);
  ck_assert_pstr_eq(answer3_string, answer3_s21);
  ck_assert_pstr_eq(answer4_string, answer4_s21);
  ck_assert_pstr_eq(answer5_string, answer5_s21);
  ck_assert_pstr_eq(answer6_string, answer6_s21);
  ck_assert_pstr_eq(answer7_string, answer7_s21);
  ck_assert_pstr_eq(answer8_string, answer8_s21);
}
END_TEST

// Все буквы нижнего регистра 1+
// Целевая страка остается неизменной 2+
// Цифры и знаки 3+
// Пустая строка 4+
START_TEST(test_s21_upper) {
  // Arrange
  char *str1 = "qwertyuiopa sdfghjklzxcvbnm";
  char *trg1 = "QWERTYUIOPA SDFGHJKLZXCVBNM";
  void *answer1 = NULL;

  char *str3 = "123,.;:'";
  char *trg3 = "123,.;:'";
  void *answer3 = NULL;

  char *str4 = "";
  char *trg4 = "";
  void *answer4 = NULL;
  // Act
  answer1 = s21_to_upper(str1);
  answer3 = s21_to_upper(str3);
  answer4 = s21_to_upper(str4);
  // Assert
  ck_assert_str_eq(answer1, trg1);                        // 1
  ck_assert_str_eq(str1, "qwertyuiopa sdfghjklzxcvbnm");  // 2
  ck_assert_str_eq(answer3, trg3);                        // 3
  ck_assert_str_eq(answer4, trg4);                        // 4

  free(answer1);
  free(answer3);
  free(answer4);
}
END_TEST

// Все буквы нижнего регистра 1+
// Целевая страка остается неизменной 2+
// Цифры и знаки 3+
// Пустая строка 4+
START_TEST(test_s21_lower) {
  // Arrange
  char *trg1 = "qwertyuiopa sdfghjklzxcvbnm";
  char *str1 = "QWERTYUIOPA SDFGHJKLZXCVBNM";
  void *answer1 = NULL;

  char *str3 = "123,.;:'";
  char *trg3 = "123,.;:'";
  void *answer3 = NULL;

  char *str4 = "";
  char *trg4 = "";
  void *answer4 = NULL;
  // Act
  answer1 = s21_to_lower(str1);
  answer3 = s21_to_lower(str3);
  answer4 = s21_to_lower(str4);
  // Assert
  ck_assert_str_eq(answer1, trg1);                        // 1
  ck_assert_str_eq(str1, "QWERTYUIOPA SDFGHJKLZXCVBNM");  // 2
  ck_assert_str_eq(answer3, trg3);                        // 3
  ck_assert_str_eq(answer4, trg4);                        // 4

  free(answer1);
  free(answer3);
  free(answer4);
}
END_TEST

// вставка в середину 1+
// вставка в конец 2+
// вставка в начало 3+
// вставка за пределы 4+
// вставка пустой строки
START_TEST(test_s21_insert) {
  // Arrange
  char *src1 = "asdfg";
  char *str1 = "12";
  char *trg1 = "asd12fg";
  size_t s_inx1 = 3;
  void *answer1 = NULL;

  char *src2 = "asdfg";
  char *str2 = "12";
  char *trg2 = "asdfg12";
  size_t s_inx2 = 5;
  void *answer2 = NULL;

  char *src3 = "asdfg";
  char *str3 = "12";
  char *trg3 = "12asdfg";
  size_t s_inx3 = 0;
  void *answer3 = NULL;

  char *src6 = "asdfg";
  char *str6 = "";
  char *trg6 = "asdfg";
  size_t s_inx6 = 3;
  void *answer6 = NULL;
  // Act
  answer1 = s21_insert(src1, str1, s_inx1);
  answer2 = s21_insert(src2, str2, s_inx2);
  answer3 = s21_insert(src3, str3, s_inx3);
  answer6 = s21_insert(src6, str6, s_inx6);
  // Assert
  ck_assert_str_eq(answer1, trg1);  // 1
  ck_assert_str_eq(answer2, trg2);  // 2
  ck_assert_str_eq(answer3, trg3);  // 3
  ck_assert_ptr_ne(answer6, trg6);  // 6

  free(answer1);
  free(answer2);
  free(answer3);
  free(answer6);
}
END_TEST

//
START_TEST(test_s21_trim) {
  // Arrange
  char *src1 = "** as* df **";
  char *trim_ch1 = "*";
  char *trg1 = " as* df ";
  void *answer1 = NULL;

  char *src2 = "** as* df **";
  char *trim_ch2 = "* ";
  char *trg2 = "as* df";
  void *answer2 = NULL;
  // Act
  answer1 = s21_trim(src1, trim_ch1);
  answer2 = s21_trim(src2, trim_ch2);
  // Assert
  ck_assert_str_eq(answer1, trg1);
  ck_assert_str_eq(answer2, trg2);

  free(answer1);
  free(answer2);
}
END_TEST

START_TEST(test_s21_sprintf) {
  char MESSAGE_1[500] = "Hello, World!!";
  char MESSAGE_2[500] = "Hello, World!!";

  char TEST_c = '5';
  int TEST_d = -21475;
  int TEST_i = -50000;
  double TEST_f = -50.4324;
  char TEST_s[20] = "FLAMES";
  int TEST_u = -3857;
  sprintf(MESSAGE_1, "|%c|%d|%i|%f|%s|%u|%%|", TEST_c, TEST_d, TEST_i, TEST_f,
          TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|%d|%i|%f|%s|%u|%%|", TEST_c, TEST_d, TEST_i,
              TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #1.1 - FAILED!");

  sprintf(MESSAGE_1, "|%-15c|%-15d|%-15i|%-15f|%-15s|%-15u|", TEST_c, TEST_d,
          TEST_i, TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%-15c|%-15d|%-15i|%-15f|%-15s|%-15u|", TEST_c,
              TEST_d, TEST_i, TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #2.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|%+d|%+i|%+f|%s|%u|%%|", TEST_c, TEST_d, TEST_i,
          TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|%+d|%+i|%+f|%s|%u|%%|", TEST_c, TEST_d, TEST_i,
              TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #3.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|% d|% i|% f|%s|%u|%%|", TEST_c, TEST_d, TEST_i,
          TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|% d|% i|% f|%s|%u|%%|", TEST_c, TEST_d, TEST_i,
              TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #4.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|%d|%i|%f|%s|%u|%%|", TEST_c, TEST_d, TEST_i, TEST_f,
          TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|%d|%i|%f|%s|%u|%%|", TEST_c, TEST_d, TEST_i,
              TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #5.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|%15d|%15i|%15f|%s|%15u|", TEST_c, TEST_d, TEST_i,
          TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|%15d|%15i|%15f|%s|%15u|", TEST_c, TEST_d, TEST_i,
              TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #6.1 - FAILED!");

  sprintf(MESSAGE_1, "|%15c|%15d|%15i|%15f|%15s|%15u|%%|", TEST_c, TEST_d,
          TEST_i, TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%15c|%15d|%15i|%15f|%15s|%15u|%%|", TEST_c, TEST_d,
              TEST_i, TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #7.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|%.2d|%.2i|%.2f|%.2s|%.2u|%%|", TEST_c, TEST_d, TEST_i,
          TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|%.2d|%.2i|%.2f|%.2s|%.2u|%%|", TEST_c, TEST_d,
              TEST_i, TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #8.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|%.15d|%.15i|%.15f|%.15s|%.15u", TEST_c, TEST_d,
          TEST_i, TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|%.15d|%.15i|%.15f|%.15s|%.15u", TEST_c, TEST_d,
              TEST_i, TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #9.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|%.d|%.i|%.f|%.s|%.u|%%|", TEST_c, TEST_d, TEST_i,
          TEST_f, TEST_s, TEST_u);
  s21_sprintf(MESSAGE_2, "|%c|%.d|%.i|%.f|%.s|%.u|%%|", TEST_c, TEST_d, TEST_i,
              TEST_f, TEST_s, TEST_u);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #10.1 - FAILED!");

  short int TEST_ii = -10000;
  short int TEST_uu = -3857;
  sprintf(MESSAGE_1, "|%c|%hd|%hi|%f|%s|%hu|%%|", TEST_c, SHRT_MIN, TEST_ii,
          TEST_f, TEST_s, TEST_uu);
  s21_sprintf(MESSAGE_2, "|%c|%hd|%hi|%f|%s|%hu|%%|", TEST_c, SHRT_MIN, TEST_ii,
              TEST_f, TEST_s, TEST_uu);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #11.1 - FAILED!");

  long int TEST_iii = -50000;
  long int TEST_uuu = -3857;
  sprintf(MESSAGE_1, "|%c|%ld|%li|%f|%s|%lu|%%|", TEST_c, LONG_MIN, TEST_iii,
          TEST_f, TEST_s, TEST_uuu);
  s21_sprintf(MESSAGE_2, "|%c|%ld|%li|%f|%s|%lu|%%|", TEST_c, LONG_MIN,
              TEST_iii, TEST_f, TEST_s, TEST_uuu);

  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #12.1 - FAILED!");
}
END_TEST

// SSCANF
START_TEST(test_s21_sscanf) {
  char a, b, c;  // chars
  char a1, b1, c1;
  s21_sscanf("abcdefABCDEF", "%c %*c %c %c   ", &a, &b, &c);
  sscanf("abcdefABCDEF", "%c %*c %c %c   ", &a1, &b1, &c1);

  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);

  s21_sscanf("ab", "%2c", &c);
  sscanf("ab", "%2c", &c1);
  ck_assert_int_eq(c, c1);

  int x, y, z = 0;  // ints
  int x1, y1, z1 = 0;
  s21_sscanf("+12 -23 .54", "%3d %d%d", &x, &y, &z);
  sscanf("+12 -23 .54", "%3d %d %d", &x1, &y1, &z1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(y, y1);
  ck_assert_int_eq(z, z1);

  s21_sscanf("+0775 1-0x1324--123", " %i %*i %i-  %i", &x, &y, &z);
  sscanf("+0775 1-0x1324--123", " %i %*i %i- %i", &x1, &y1, &z1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(y, y1);
  ck_assert_int_eq(z, z1);

  unsigned short usx, usx1;
  unsigned int ux, ux1;
  unsigned long ulx, ulx1;
  unsigned long long ullx, ullx1;
  s21_sscanf("0 +2112 -12324", "%o %lo %llo", &ux, &ulx, &ullx);
  sscanf("0 +2112 -12324", "%o %lo %llo", &ux1, &ulx1, &ullx1);
  ck_assert_int_eq(ux, ux1);
  ck_assert_int_eq(ulx, ulx1);
  ck_assert_int_eq(ullx, ullx1);

  s21_sscanf("0 0x211a 12324 0x1", "%x %lx %llx %hx", &ux, &ulx, &ullx, &usx);
  sscanf("0 0x211a 12324 0x1", "%x %lx %llx %hx", &ux1, &ulx1, &ullx1, &usx1);
  ck_assert_int_eq(usx, usx1);
  ck_assert_int_eq(ux, ux1);
  ck_assert_int_eq(ulx, ulx1);
  ck_assert_int_eq(ullx, ullx1);

  x = 0, x1 = 0;  // errors
  s21_sscanf("a21", "%d", &x);
  sscanf("a21", "%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("a21", "b%d", &x);
  sscanf("a21", "b%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("--a21", "%d", &x);
  sscanf("--a21", "%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("-21", "%1d", &x);
  sscanf("-21", "%1d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("-21", "%%%1d", &x);
  sscanf("-21", "%%%1d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("-21   ", "%d %d", &x, &y);
  sscanf("-21   ", "%d %d", &x1, &y1);
  ck_assert_int_eq(x, x1);

  float fx, fx1;  // floats
  double lfx, lfx1;
  long double llfx, llfx1;
  s21_sscanf("1 2 -123232.001 .995123 999.99.1", "%*E %*G %g %le %Lf", &fx,
             &lfx, &llfx);
  sscanf("1 2 -123232.001 .995123 999.99.1", "%*E %*G %g %le %Lf", &fx1, &lfx1,
         &llfx1);
  // printf("%f %lf %Lf\n%f %lf %Lf\n", fx, lfx, llfx, fx1, lfx1, llfx1);
  ck_assert_double_eq(fx, fx1);
  ck_assert_double_eq(lfx, lfx1);
  ck_assert_double_eq(llfx, llfx1);

  char str[100], str1[100];  // strings
  char p_str[100], p_str1[100];
  s21_sscanf("abc\n\r\t%%cba\faaa?.123", "%*s %%%s%s%n", str, str1, &x);
  sscanf("abc\n\r\t%%cba\faaa?.123", "%*s %%%s%s%n", p_str, p_str1, &x1);
  ck_assert_msg(strcmp(str, p_str) == 0, "str fail");
  ck_assert_msg(strcmp(str1, p_str1) == 0, "str1 fail");
  ck_assert_int_eq(x, x1);

  void *addr1 = S21_NULL, *addr2 = S21_NULL, *addr3 = S21_NULL;
  void *paddr1 = NULL, *paddr2 = NULL, *paddr3 = NULL;
  s21_sscanf("0x1abcd -0xfffffffff +0xffffffffffffffffffaaa", "%p %n%p %p",
             &addr1, &x, &addr2, &addr3);
  sscanf("0x1abcd -0xfffffffff +0xffffffffffffffffffaaa", "%p %n%p %p", &paddr1,
         &x1, &paddr2, &paddr3);

  float af1 = 0, af2 = 0, bf1 = 0, bf2 = 0, cf1 = 0, cf2 = 0, df1 = 0, df2 = 0;

  const char strf[] =
      "nAN           INF                   -0.1111         1e-10";
  const char fstr[] = "%G %G %G %G";

  int res1 = s21_sscanf(strf, fstr, &af1, &bf1, &cf1, &df1);
  int res2 = sscanf(strf, fstr, &af2, &bf2, &cf2, &df2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(af1);
  ck_assert_float_nan(af2);
  ck_assert_ldouble_eq(bf1, bf2);
  ck_assert_ldouble_eq(cf1, cf2);
  ck_assert_ldouble_eq(df1, df2);

  const char strf2[] = "-inF InF inF INF";

  res1 = s21_sscanf(strf2, fstr, &af1, &bf1, &cf1, &df1);
  res2 = sscanf(strf2, fstr, &af2, &bf2, &cf2, &df2);
  ck_assert_ldouble_eq(bf1, bf2);
  ck_assert_ldouble_eq(cf1, cf2);
  ck_assert_ldouble_eq(df1, df2);

  long double al1 = 0, al2 = 0, bl1 = 0, bl2 = 0, cl1 = 0, cl2 = 0, dl1 = 0,
              dl2 = 0;
  const char strf3[] = "1.4441 1.31e3 -3.31e-2 0.444e-1";

  res1 = s21_sscanf(strf3, "%LG %LG %LG %LG", &al1, &bl1, &cl1, &dl1);
  res2 = sscanf(strf3, "%LG %LG %LG %LG", &al2, &bl2, &cl2, &dl2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(al1, al2);
  ck_assert_ldouble_eq(bl1, bl2);
  ck_assert_ldouble_eq(cl1, cl2);
  ck_assert_ldouble_eq(dl1, dl2);
}
END_TEST

Suite *root_suite(void) {
  Suite *s;
  TCase *tc_memchr, *tc_memcpy, *tc_memcmp, *tc_memmove, *tc_memset, *tc_strcat,
      *tc_strncat, *tc_strchr, *tc_strcmp, *tc_strncmp, *tc_strcpy, *tc_strncpy,
      *tc_strcspn, *tc_strerror, *tc_strlen, *tc_strpbrk, *tc_strrchr,
      *tc_strspn, *tc_strstr, *tc_strtok, *tc_upper, *tc_lower, *tc_insert,
      *tc_trim, *tc_sprintf, *tc_sscanf;
  ;
  s = suite_create("Root");
  // 1
  tc_memchr = tcase_create("MEMCHR");
  tcase_add_test(tc_memchr, test_s21_memchr);
  // 2
  tc_memcmp = tcase_create("MEMCMP");
  tcase_add_test(tc_memcmp, test_s21_memcmp);
  // 3
  tc_memcpy = tcase_create("MEMCPY");
  tcase_add_test(tc_memcpy, test_s21_memcpy);
  // 4
  tc_memmove = tcase_create("MEMMOVE");
  tcase_add_test(tc_memmove, test_s21_memmove);
  // 5
  tc_memset = tcase_create("MEMSET");
  tcase_add_test(tc_memset, test_s21_memset);
  // 6
  tc_strcat = tcase_create("STRCAT");
  tcase_add_test(tc_strcat, test_s21_strcat);
  // 7
  tc_strncat = tcase_create("STRNCAT");
  tcase_add_test(tc_strncat, test_s21_strncat);
  // 8
  tc_strchr = tcase_create("STRCHR");
  tcase_add_test(tc_strchr, test_s21_strchr);
  // 9
  tc_strcmp = tcase_create("STRCMP");
  tcase_add_test(tc_strcmp, test_s21_strcmp);
  // 10
  tc_strncmp = tcase_create("STRNCMP");
  tcase_add_test(tc_strncmp, test_s21_strncmp);
  // 11
  tc_strcpy = tcase_create("STRCPY");
  tcase_add_test(tc_strcpy, test_s21_strcpy);
  // 12
  tc_strncpy = tcase_create("STRNCPY");
  tcase_add_test(tc_strncpy, test_s21_strncpy);
  // 13
  tc_strcspn = tcase_create("STRCSPN");
  tcase_add_test(tc_strcspn, test_s21_strcspn);
  // 14
  tc_strerror = tcase_create("STRERROR");
  tcase_add_test(tc_strerror, test_s21_strerror);
  // 15
  tc_strlen = tcase_create("STRLEN");
  tcase_add_test(tc_strlen, test_s21_strlen);
  // 16
  tc_strpbrk = tcase_create("STRPBRK");
  tcase_add_test(tc_strpbrk, test_s21_strpbrk);
  // 17
  tc_strrchr = tcase_create("STRRCHR");
  tcase_add_test(tc_strrchr, test_s21_strrchr);
  // 18
  tc_strspn = tcase_create("STRSPN");
  tcase_add_test(tc_strspn, test_s21_strspn);
  // 19
  tc_strstr = tcase_create("STRSTR");
  tcase_add_test(tc_strstr, test_s21_strstr);
  // 20
  tc_strtok = tcase_create("STRTOK");
  tcase_add_test(tc_strtok, test_s21_strtok);
  // UPPER
  tc_upper = tcase_create("\033[31mUPPER\033[0m");
  tcase_add_test(tc_upper, test_s21_upper);
  // LOWER
  tc_lower = tcase_create("\033[31mLOWER\033[0m");
  tcase_add_test(tc_lower, test_s21_lower);
  // INSERT
  tc_insert = tcase_create("\033[31mINSERT\033[0m");
  tcase_add_test(tc_insert, test_s21_insert);
  // TRIM
  tc_trim = tcase_create("\033[31mTRIM\033[0m");
  tcase_add_test(tc_trim, test_s21_trim);
  // SPRINTF
  tc_sprintf = tcase_create("SPRINTF");
  tcase_add_test(tc_sprintf, test_s21_sprintf);

  // SSCANF
  tc_sscanf = tcase_create("SSCANF");
  tcase_add_test(tc_sprintf, test_s21_sscanf);
  //!!!!!!!!!!!!!!!!!!!!!
  // Здесь закоментить ненуные тесты
  //!!!!!!!!!!!!!!!!!!!!!
  // 1
  suite_add_tcase(s, tc_memchr);
  // 2
  suite_add_tcase(s, tc_memcmp);
  // 3
  suite_add_tcase(s, tc_memcpy);
  // 4
  suite_add_tcase(s, tc_memmove);
  // 5
  suite_add_tcase(s, tc_memset);
  // 6
  suite_add_tcase(s, tc_strcat);
  // 7
  suite_add_tcase(s, tc_strncat);
  // 8
  suite_add_tcase(s, tc_strchr);
  // 9
  suite_add_tcase(s, tc_strcmp);
  // 10
  suite_add_tcase(s, tc_strncmp);
  // 11
  suite_add_tcase(s, tc_strcpy);
  // 12
  suite_add_tcase(s, tc_strncpy);
  // 13
  suite_add_tcase(s, tc_strcspn);
  // 14
  suite_add_tcase(s, tc_strerror);
  // 15
  suite_add_tcase(s, tc_strlen);
  // 16
  suite_add_tcase(s, tc_strpbrk);
  // 17
  suite_add_tcase(s, tc_strrchr);
  // 18
  suite_add_tcase(s, tc_strspn);
  // 19
  suite_add_tcase(s, tc_strstr);
  // 20
  suite_add_tcase(s, tc_strtok);
  // UPPER
  suite_add_tcase(s, tc_upper);
  // LOWER
  suite_add_tcase(s, tc_lower);
  // INSERT
  suite_add_tcase(s, tc_insert);
  // TRIM
  suite_add_tcase(s, tc_trim);
  // SPRINTF
  suite_add_tcase(s, tc_sprintf);
  // SSCANF
  suite_add_tcase(s, tc_sscanf);
  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;
  s = root_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
