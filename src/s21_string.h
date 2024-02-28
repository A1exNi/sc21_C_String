#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_NULL ((void *)0)
#define S21_IS_NUMERIC(ch) ((ch) <= '9' && (ch) >= '0')
#define S21_IS_SPEC(ch)                                                       \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'f' || (ch) == 'U' || \
   (ch) == '%' || (ch) == 'X' || (ch) == 'o' || (ch) == 'p' || (ch) == 'n' || \
   (ch) == 'e' || (ch) == 'E' || (ch) == 'g' || (ch) == 'G' || (ch) == 's' || \
   (ch) == 'u')
#define S21_IS_FLAG(ch) \
  ((ch) == '-' || (ch) == '+' || (ch) == '#' || (ch) == ' ')
#define S21_IS_LENGTH(ch) ((ch) == 'l' || (ch) == 'L' || (ch) == 'h')
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef unsigned long s21_size_t;
typedef struct {
  int spec;
  int space;
  int minus;
  int plus;
  int sharp;
  int zero;
  int point;
  int width;
  int length;
  int double_len;
  int precision;
  int error;
  int is_signed;
} FORMAT;

typedef struct {
  int skip;
  int number;
  int number_read;
  char width;
  int double_w;
  int no_spec;
  int empty;
  int debag;
  int stop;
  int del_char;
} DATA;

void *s21_memchr(const void *str, int ch, s21_size_t n);
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
void *s21_memcpy(void *restrict dst, const void *restrict src, s21_size_t n);
void *s21_memmove(void *dst, const void *src, s21_size_t len);
void *s21_memset(void *b, int c, s21_size_t len);
char *s21_strcat(char *restrict s1, const char *restrict s2);
char *s21_strncat(char *restrict s1, const char *restrict s2, s21_size_t n);
char *s21_strchr(const char *s, int c);
int s21_strcmp(const char *s1, const char *s2);
int s21_strncmp(const char *s1, const char *s2, s21_size_t n);
char *s21_strcpy(char *dst, const char *src);
char *s21_strncpy(char *dst, const char *src, s21_size_t len);
s21_size_t s21_strcspn(const char *s, const char *charset);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *s);
char *s21_strpbrk(const char *s, const char *charset);
char *s21_strrchr(const char *s, int c);
s21_size_t s21_strspn(const char *s, const char *charset);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *restrict str, const char *restrict sep);
int s21_sprintf(char *restrict str, const char *restrict format, ...);
int s21_sscanf(const char *restrict s, const char *restrict format, ...);

void processing_percent(char **buf_s, char **buf_f, DATA *data);
void processing_asterisk(char **buf_f, DATA *data);
void processing_number(char **buf_f, DATA *data);
void processing_lenght(char **buf_f, DATA *data);
void processing_main(char **buf_s, char **buf_f, DATA *data, va_list ap,
                     const char *restrict s);

int skip_c(char *s, char *f);
char *del_spaces(char *str, DATA *data);
char *scan_num(char *buf, int *number, s21_size_t n);
void write_num(char *buf_f, int *number, s21_size_t n);

char *scan_c(va_list ap, char *buf_s, DATA *data);
char *scan_d(va_list ap, char *buf_s, DATA *data, char ch);
char *scan_i(va_list ap, char *buf_s, DATA *data);
char *scan_e(va_list ap, char *buf_s, DATA *data);
char *scan_o(va_list ap, char *buf_s, DATA *data, char ch);
char *scan_s(va_list ap, char *buf_s, DATA *data);
char *scan_u(va_list ap, char *buf_s, DATA *data);
char *scan_x(va_list ap, char *buf_s, DATA *data);
char *scan_p(va_list ap, char *buf_s, DATA *data);
long long s21_strtoll(const char *restrict str, char **restrict endptr,
                      int base);
long double s21_strtold(const char *restrict nptr, char **restrict endptr);
int det_base(const char *restrict nptr, int shift, char **av_char, int base);
void processing_exp(long double *result, const char *restrict nptr, int *shift,
                    int *base, char *av_char);
void processing_inf(long double *result, char **sbuf, int *shift,
                    s21_size_t *no_error, int sign);
void processing_nan(long double *result, char **sbuf, int *shift,
                    s21_size_t *no_error);
int det_sign(char c, int *shift);
void det_int(const char *str, char *av_char, int *shift, int base, int sign,
             long long *result);
// int is_number(char c);
int s21_isspace(int c);
int trans_ch16(char c);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *str, const char *trim_chars);

void num_to_str(long long unsigned num, char *str_num);
void revers(char *str);

void put_width(char **str1, char *str, FORMAT *fformat);
int put_to_ch(char *ch, long long int num, FORMAT *fformat, int size_ch,
              int size_int);
int uput_to_ch(char *ch, long long unsigned num, FORMAT *fformat, int size_ch,
               int size_int);
int det_size_signed(long long unsigned put_it, FORMAT *fformat, int size_int);
int s21_intlen(long long int num, FORMAT *fformat);
int s21_uintlen(long long unsigned num, FORMAT *fformat);
void s21_set_zeroes(FORMAT *fformat);
char *if_c(char ch_argument, int size);
int if_d(char *result_str, FORMAT *fformat, int start, long long int put_it);
int if_s(char *result_str, FORMAT *fformat, char *put_str);
int if_u(char *result_str, FORMAT *fformat, int start,
         long long unsigned put_it);

char *s21_f_to_str(char *str, long double number, FORMAT fformat);
char *s21_uns_precision(char *str, FORMAT fformat);
char *s21_width_flag(char *str, FORMAT fformat);
int s21_check_sign_flags(FORMAT *fformat, long double number);
char *s21_d_class_to_str(char *str, long double x, FORMAT fformat);
char *int_to_char(int a, char *num);
long double s21_round(long double x, int tolerance);
char *s21_reverse_u_str(char *str);

void parsing_format(char *spec_str, FORMAT *fformat);

#endif  // S21_STRING_H_
