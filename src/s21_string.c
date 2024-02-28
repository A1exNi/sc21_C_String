#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i;
  unsigned char *res = S21_NULL;
  for (i = 0; i < n && res == S21_NULL; i++) {
    if (*((unsigned char *)str + i) == c) {
      res = (unsigned char *)str + i;
    }
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  s21_size_t i;
  int res = 0;
  unsigned char *prt1 = (unsigned char *)str1;
  unsigned char *prt2 = (unsigned char *)str2;
  s21_size_t len_s1 = s21_strlen(str1) + 1;
  s21_size_t len_s2 = s21_strlen(str2) + 1;
  if (len_s1 < n) n = len_s1;
  if (len_s2 < n) n = len_s2;
  for (i = 0; i < n && !res; i++) {
    if (*prt1 != *prt2) {
      res = *prt1 - *prt2;
    }
    prt1++;
    prt2++;
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *buff = calloc(n, sizeof(s21_size_t));
  unsigned char *prt = (unsigned char *)src;
  s21_size_t i;
  for (i = 0; i < n; i++) {
    buff[i] = *prt;
    prt++;
    if (*prt == '\0') buff[i + 1] = *prt;
  }
  dest = s21_memcpy(dest, buff, n);
  free(buff);
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n; i++) {
    ((unsigned char *)str)[i] = c;
  }
  return (void *)str;
}

char *s21_strcat(char *dest, const char *src) {
  char *prt = dest + s21_strlen(dest);
  while (*src != '\0') {
    *prt++ = *src++;
  }
  *prt = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *prt = dest + s21_strlen(dest);
  while (*src != '\0' && n--) {
    *prt++ = *src++;
  }
  *prt = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  char *prt = (char *)str;
  while (*prt != '\0' && res == S21_NULL) {
    if (*prt == c) {
      res = prt;
    }
    prt++;
  }
  if (*prt == '\0' && res == S21_NULL && *prt == c) res = prt;
  return res;
}

int s21_strcmp(const char *str1, const char *str2) {
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  s21_size_t n = (str1_len > str2_len) ? str1_len : str2_len;
  return s21_memcmp(str1, str2, n);
}

int s21_strncmp(const char *s1, const char *s2, s21_size_t n) {
  return s21_memcmp(s1, s2, n);
}

char *s21_strcpy(char *dest, const char *src) {
  char *copy = dest;
  while (*src != '\0') {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = *src;
  return copy;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *copy = dest;
  for (unsigned long i = 0; i < n; i++) {
    if (*src != '\0') {
      *dest = *src;
      src++;
      dest++;
    } else {
      *dest = *src;
    }
  }
  return copy;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  unsigned long length = 0;
  int true_false = 1, length_str2 = 0;
  while (true_false && *str1 != '\0') {
    while (*str2 != '\0' && true_false) {
      if (*str2 != *str1) {
        length_str2++;
        str2++;
      } else {
        true_false = 0;
      }
    }
    if (true_false) {
      for (int i = 0; i < length_str2; i++) {
        str2--;
      }
      length_str2 = 0;
      str1++;
      length++;
    }
  }
  return length;
}

char *s21_strerror(int errnum) {
#if defined(__APPLE__)
  int s21_error_num = 106;
  char err[50] = "Unknown error: ";
  char s21_errors[][48] = {"Undefined error: 0",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "Device not configured",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource deadlock avoided",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Resource busy",
                           "File exists",
                           "Cross-device link",
                           "Operation not supported by device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Result too large",
                           "Resource temporarily unavailable",
                           "Operation now in progress",
                           "Operation already in progress",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol family",
                           "Address already in use",
                           "Can't assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Socket is already connected",
                           "Socket is not connected",
                           "Can't send after socket shutdown",
                           "Too many references: can't splice",
                           "Operation timed out",
                           "Connection refused",
                           "Too many levels of symbolic links",
                           "File name too long",
                           "Host is down",
                           "No route to host",
                           "Directory not empty",
                           "Too many processes",
                           "Too many users",
                           "Disc quota exceeded",
                           "Stale NFS file handle",
                           "Too many levels of remote in path",
                           "RPC struct is bad",
                           "RPC version wrong",
                           "RPC prog. not avail",
                           "Program version wrong",
                           "Bad procedure for program",
                           "No locks available",
                           "Function not implemented",
                           "Inappropriate file type or format",
                           "Authentication error",
                           "Need authenticator",
                           "Device power is off",
                           "Device error",
                           "Value too large to be stored in data type",
                           "Bad executable (or shared library)",
                           "Bad CPU type in executable",
                           "Shared library version mismatch",
                           "Malformed Mach-o file",
                           "Operation canceled",
                           "Identifier removed",
                           "No message of desired type",
                           "Illegal byte sequence",
                           "Attribute not found",
                           "Bad message",
                           "EMULTIHOP (Reserved)",
                           "No message available on STREAM",
                           "ENOLINK (Reserved)",
                           "No STREAM resources",
                           "Not a STREAM",
                           "Protocol error",
                           "STREAM ioctl timeout",
                           "Operation not supported on socket",
                           "Policy not found",
                           "State not recoverable",
                           "Previous owner died",
                           "Interface output queue is full"};
#elif defined(__linux__)
  int s21_error_num = 133;
  char err[50] = "Unknown error ";
  char s21_errors[][51] = {"Success",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "No such device or address",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource temporarily unavailable",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Device or resource busy",
                           "File exists",
                           "Invalid cross-device link",
                           "No such device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Numerical result out of range",
                           "Resource deadlock avoided",
                           "File name too long",
                           "No locks available",
                           "Function not implemented",
                           "Directory not empty",
                           "Too many levels of symbolic links",
                           "Unknown error 41",
                           "No message of desired type",
                           "Identifier removed",
                           "Channel number out of range",
                           "Level 2 not synchronized",
                           "Level 3 halted",
                           "Level 3 reset",
                           "Link number out of range",
                           "Protocol driver not attached",
                           "No CSI structure available",
                           "Level 2 halted",
                           "Invalid exchange",
                           "Invalid request descriptor",
                           "Exchange full",
                           "No anode",
                           "Invalid request code",
                           "Invalid slot",
                           "Unknown error 58",
                           "Bad font file format",
                           "Device not a stream",
                           "No data available",
                           "Timer expired",
                           "Out of streams resources",
                           "Machine is not on the network",
                           "Package not installed",
                           "Object is remote",
                           "Link has been severed",
                           "Advertise error",
                           "Srmount error",
                           "Communication error on send",
                           "Protocol error",
                           "Multihop attempted",
                           "RFS specific error",
                           "Bad message",
                           "Value too large for defined data type",
                           "Name not unique on network",
                           "File descriptor in bad state",
                           "Remote address changed",
                           "Can not access a needed shared library",
                           "Accessing a corrupted shared library",
                           ".lib section in a.out corrupted",
                           "Attempting to link in too many shared libraries",
                           "Cannot exec a shared library directly",
                           "Invalid or incomplete multibyte or wide character",
                           "Interrupted system call should be restarted",
                           "Streams pipe error",
                           "Too many users",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol",
                           "Address already in use",
                           "Cannot assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Transport endpoint is already connected",
                           "Transport endpoint is not connected",
                           "Cannot send after transport endpoint shutdown",
                           "Too many references: cannot splice",
                           "Connection timed out",
                           "Connection refused",
                           "Host is down",
                           "No route to host",
                           "Operation already in progress",
                           "Operation now in progress",
                           "Stale file handle",
                           "Structure needs cleaning",
                           "Not a XENIX named type file",
                           "No XENIX semaphores available",
                           "Is a named type file",
                           "Remote I/O error",
                           "Disk quota exceeded",
                           "No medium found",
                           "Wrong medium type",
                           "Operation canceled",
                           "Required key not available",
                           "Key has expired",
                           "Key has been revoked",
                           "Key was rejected by service",
                           "Owner died",
                           "State not recoverable",
                           "Operation not possible due to RF-kill",
                           "Memory page has hardware error"};
#endif
  char answ[60] = {0};
  char num[20] = {0};
  char n[20] = {0};
  char *answer = answ;
#if defined(__APPLE__)
  if (errnum == 0) {
    s21_strcpy(answ, s21_errors[errnum]);
  }
#elif defined(__linux__)
  if (errnum == 0) {
    s21_strcpy(num, int_to_char(errnum, n));
    s21_strcat(s21_strcpy(answ, err), num);
  }
#endif
  if (errnum > 0 && errnum <= s21_error_num) {
    s21_strcpy(answ, s21_errors[errnum]);
  } else if (errnum < 0 || errnum > s21_error_num) {
    s21_strcpy(num, int_to_char(errnum, n));
    s21_strcat(s21_strcpy(answ, err), num);
  }
  return answer;
}

s21_size_t s21_strlen(const char *str) {
  unsigned long length = 0;
  while (*str != '\0') {
    length++;
    str++;
  }
  return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 1, length_str2 = 0;
  char *answ = S21_NULL;
  while (*str1 != '\0' && flag) {
    while (*str2 != '\0' && flag) {
      if (*str1 != *str2) {
        str2++;
        length_str2++;
      } else {
        flag = 0;
      }
    }
    if (flag) {
      str1++;
      for (int i = 0; i < length_str2; i++) {
        str2--;
      }
      length_str2 = 0;
    }
  }
  if (flag == 0) {
    answ = (char *)str1;
  }
  return answ;
}

char *s21_strrchr(const char *str, int c) {
  int flag = 1, length = 1;
  char *answ_ptr = S21_NULL;
  while (*str != '\0') {
    str++;
    length++;
  }
  while (length != 0 && flag) {
    if (*str == c) {
      flag = 0;
    } else {
      str--;
      length--;
    }
  }
  if (*str == c) {
    flag = 0;
  }
  if (flag == 1) {
    answ_ptr = S21_NULL;
  } else {
    answ_ptr = (char *)str;
  }
  return answ_ptr;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t answ = 0, example = 0;
  int length = 0;
  int flag_one = 1, flag_two = 1;
  while (*str1 != '\0' && (flag_one || flag_two)) {
    while (*str2 != '\0' && flag_two) {
      if (*str1 == *str2) {
        answ++;
        flag_two = 0;
      } else {
        str2++;
        length++;
      }
    }
    if (answ == 0 || example == answ) {
      flag_one = 0;
      flag_two = 0;
    } else {
      for (int i = 0; i < length; i++) {
        str2--;
      }
      length = 0;
      flag_two = 1;
      str1++;
    }
    example = answ;
  }
  return answ;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  s21_size_t l_haystack = s21_strlen(haystack);
  s21_size_t l_needle = s21_strlen(needle);
  if (*needle == '\0') {
    result = (char *)(haystack);
    l_needle = 1;
  }
  s21_size_t l_z = l_haystack + l_needle + 1;
  char *buf_str = calloc(l_z + 1, sizeof(char));
  buf_str = s21_strcat(buf_str, needle);
  buf_str = s21_strcat(buf_str, "#");
  buf_str = s21_strcat(buf_str, haystack);
  // заменяем # на \0
  buf_str[l_needle] = '\0';
  int *z = calloc(l_z, sizeof(int));
  z[0] = l_z;
  int l = 0;
  int r = 0;
  for (int i = 1; i < (int)l_z; i++) {
    z[i] = MAX(0, MIN(z[i - l], r - i));
    while (buf_str[i + z[i]] == buf_str[z[i]] && i + z[i] < (int)l_z) z[i]++;
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  int index = -1;
  for (s21_size_t i = 0; i < l_z && index == -1; i++) {
    if (z[i] == (int)l_needle) index = i;
  }
  if (index != -1) result = (char *)haystack + (index - l_needle - 1);
  free(buf_str);
  free(z);
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *answer = S21_NULL;
  static s21_size_t l = 0;
  static char *end_str;
  if (str && str[0] != '\0') {
    end_str = str + s21_strlen(str);
    // пропускаем символы разделителя
    s21_size_t l_delim = strspn(str, delim);
    l = s21_strcspn(str + l_delim, delim);
    if (l > 0) {
      str[l + l_delim] = '\0';
      l++;
      answer = str + l_delim;
    }
  } else {
    if (answer && answer + l < end_str) {
      // пропускаем символы разделителя
      s21_size_t l_delim = strspn(answer + l, delim);
      // answer - адрес начала строки; l - предыдущее смещение по этой строке
      // l_delim - количество символов разделителя, которые игнорируем
      s21_size_t new_l = s21_strcspn(answer + l + l_delim, delim);
      if (new_l > 0) {
        answer[l + l_delim + new_l] = '\0';
        answer = answer + l + l_delim;
        l = new_l + 1;
      } else {
        answer = S21_NULL;
      }
    } else {
      answer = S21_NULL;
    }
  }
  return answer;
}

void *s21_to_upper(const char *str) {
  char *res = S21_NULL;
  if (str) {
    res = (char *)malloc(s21_strlen(str) + 1 * sizeof(char));
    if (res) {
      s21_strcpy(res, str);
      for (char *tmp_str = res; *tmp_str; tmp_str++) {
        if (*tmp_str >= 'a' && *tmp_str <= 'z') {
          *tmp_str += 'A' - 'a';
        }
      }
    }
  }
  return res;
}

void *s21_to_lower(const char *str) {
  char *res = S21_NULL;
  if (str) {
    res = (char *)malloc(s21_strlen(str) + 1 * sizeof(char));
    if (res) {
      s21_strcpy(res, str);
      for (char *tmp_str = res; *tmp_str; tmp_str++) {
        if (*tmp_str >= 'A' && *tmp_str <= 'Z') {
          *tmp_str += 'a' - 'A';
        }
      }
    }
  }
  return res;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t len_src = 0;
  s21_size_t len_str = 0;
  if (src) len_src = s21_strlen(src);
  if (str) len_str = s21_strlen(str);
  char *res = malloc((len_src + len_str + 1) * sizeof(char));
  if (len_src < start_index || !src || !str) {
    res = S21_NULL;
  } else {
    char *prt;
    char *sec = (char *)src;
    for (prt = res; *sec || *str; prt++) {
      if (sec == src + start_index && *str)
        *prt = *(str++);
      else
        *prt = *(sec++);
    }
    *prt = 0;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *answer = S21_NULL;
  if (src && trim_chars) {
    s21_size_t len_start = s21_strspn(src, trim_chars);

    int len_str = s21_strlen(src);
    char *buf = calloc(len_str + 1, sizeof(char));
    int j = 0;
    for (int i = len_str - 1; i >= 0; i--) {
      buf[j++] = src[i];
    }
    s21_size_t len_end = s21_strspn(buf, trim_chars);
    free(buf);
    answer = calloc(len_str - len_start - len_end + 1, sizeof(char));
    answer =
        s21_strncpy(answer, src + len_start, len_str - len_start - len_end);
  }
  if (src && !trim_chars) {
    s21_size_t len_answer = s21_strlen(src);
    answer = calloc(len_answer + 1, sizeof(char));
    answer = s21_strcpy(answer, src);
  }

  return answer;
}

char *int_to_char(int a, char *num) {
  int b = a;
  int len = -1;
  if (a * -1 > 0) {
    num[0] = '-';
    len += 1;
    b *= -1;
    a *= -1;
  }
  while (a != 0) {
    a = a / 10;
    len++;
  }
  while (b != 0) {
    num[len] = b % 10 + '0';
    b = b / 10;
    len--;
  }
  return num;
}

int s21_sscanf(const char *restrict s, const char *restrict format, ...) {
  va_list ap;
  va_start(ap, format);

  int len_s = s21_strlen(s);
  char *buf_s = calloc(len_s + 1, sizeof(char));
  buf_s = s21_strcpy(buf_s, s);
  char *buff_s = buf_s;

  char *buf_f = (char *)format;

  DATA data = {0};
  // проверяем пустая ли строка для возврата ошибки
  s21_size_t len = s21_strlen(buf_s);
  s21_size_t len2 = s21_strspn(buf_s, " \t\n\f\r\v");
  if (len == len2) {
    data.stop = 1;
    buf_f = del_spaces(buf_f, &data);
    if (buf_f[0] != '\0') data.empty = 1;
  }
  while (buf_f && !data.stop) {
    data.number = 0;
    data.width = 0;
    data.double_w = 0;

    processing_percent(&buf_s, &buf_f, &data);

    processing_asterisk(&buf_f, &data);

    processing_number(&buf_f, &data);

    processing_lenght(&buf_f, &data);

    processing_asterisk(&buf_f, &data);

    processing_main(&buf_s, &buf_f, &data, ap, buff_s);
  }
  va_end(ap);
  if (data.empty) data.number_read = -1;
  free(buff_s);
  return data.number_read;
}

void processing_percent(char **buf_s, char **buf_f, DATA *data) {
  //не спецификатор
  if (*buf_f[0] != '%') {
    data->no_spec = 1;
    if (*buf_f[0] == *buf_s[0]) {
      (*buf_s)++;
      (*buf_f)++;
    } else {
      s21_size_t lspaces = s21_strspn(*buf_f, " \t\n\f\r\v");
      if (!lspaces) {
        data->stop = 1;
      } else {
        *buf_f = *buf_f + lspaces;
        *buf_s = del_spaces(*buf_s, data);
      }
    }
  } else {
    (*buf_f)++;
    // обработка %%
    if (*buf_f[0] == '%' && *buf_s[0] == '%') {
      (*buf_s)++;
      (*buf_f)++;
      data->no_spec = 1;
    } else {
      data->no_spec = 0;
    }
  }
}

void processing_asterisk(char **buf_f, DATA *data) {
  if (*buf_f[0] == '*' && !data->no_spec) {
    data->skip = 1;
    s21_size_t lstar = s21_strspn(*buf_f, "*");
    *buf_f += lstar;
  }
}

void processing_number(char **buf_f, DATA *data) {
  if (S21_IS_NUMERIC(*buf_f[0]) && !data->no_spec) {
    s21_size_t len = s21_strlen(*buf_f);
    *buf_f = scan_num(*buf_f, &data->number, len);
  }
}

void processing_lenght(char **buf_f, DATA *data) {
  if ((*buf_f[0] == 'h' || *buf_f[0] == 'l') && !data->no_spec) {
    data->width = *buf_f[0];
    (*buf_f)++;
    if (!data->double_w && data->width == *buf_f[0]) {
      data->double_w = 1;
      (*buf_f)++;
    }
  }
  if (*buf_f[0] == 'L' && !data->no_spec) {
    data->width = *buf_f[0];
    (*buf_f)++;
  }
}

void processing_main(char **buf_s, char **buf_f, DATA *data, va_list ap,
                     const char *restrict s) {
  char ch = *buf_f[0];
  if (!data->no_spec) {
    if (ch == 'c') *buf_s = scan_c(ap, *buf_s, data);
    if (ch == 'd' || ch == 'i') {
      *buf_s = scan_d(ap, *buf_s, data, ch);
      if (*buf_s == S21_NULL) data->stop = 1;
    }
    if (ch == 'e' || ch == 'E' || ch == 'f' || ch == 'g' || ch == 'G') {
      char *old = *buf_s;
      *buf_s = scan_e(ap, *buf_s, data);
      if (*buf_s == old) data->stop = 1;
    }
    if (ch == 'o' || ch == 'x' || ch == 'X')
      *buf_s = scan_o(ap, *buf_s, data, ch);
    if (ch == 's') *buf_s = scan_s(ap, *buf_s, data);
    if (ch == 'u') {
      *buf_s = scan_u(ap, *buf_s, data);
      if (*buf_s == S21_NULL) data->stop = 1;
    }
    if (ch == 'p') {
      *buf_s = scan_p(ap, *buf_s, data);
      if (*buf_s == S21_NULL) data->stop = 1;
    }
    if (ch == 'n') {
      if (!data->skip) {
        if (data->width == 'h' && !data->double_w) {
          short int *p = va_arg(ap, short int *);
          *p = *buf_s - s + data->del_char;
        } else {
          if (data->width == 'h' && data->double_w) {
            char *p = va_arg(ap, char *);
            *p = *buf_s - s + data->del_char;
          } else {
            if (data->width == 'l' && !data->double_w) {
              long int *p = va_arg(ap, long int *);
              *p = *buf_s - s + data->del_char;
            } else {
              if (data->width == 'l' && data->double_w) {
                long long int *p = va_arg(ap, long long int *);
                *p = *buf_s - s + data->del_char;
              } else {
                int *p = va_arg(ap, int *);
                *p = *buf_s - s + data->del_char;
              }
            }
          }
        }
      }
    }
    (*buf_f)++;
    data->skip = 0;
  }
}

char *scan_num(char *buf_f, int *number, s21_size_t n) {
  s21_size_t l = s21_strspn(buf_f, "1234567890");  // поменять на s21
  if (l < n) n = l;                                // Это нужно?
  write_num(buf_f, number, n);
  return buf_f + n;
}

void write_num(char *buf_f, int *number, s21_size_t n) {
  char *dst = calloc(sizeof(char), n + 1);
  dst = s21_strncpy(dst, buf_f, n);
  *number = s21_strtoll(dst, S21_NULL, 10);
  free(dst);
}

char *scan_c(va_list ap, char *buf_s, DATA *data) {
  // удаляем пробельные символы кроме " " и "\t"
  s21_size_t lbuf = s21_strspn(buf_s, "\n\f\r\v");
  data->del_char += lbuf;
  if (lbuf != 0) buf_s = s21_strcpy(buf_s, &buf_s[lbuf]);

  if (data->number == 0) data->number = 1;
  if (!data->skip) {
    char *p = va_arg(ap, char *);
    *p = buf_s[0];
    (data->number_read)++;
  }
  return buf_s + data->number;
}

char *scan_d(va_list ap, char *buf_s, DATA *data, char ch) {
  int base = 0;
  if (ch == 'd') base = 10;
  char *endptr;

  s21_size_t len_str = s21_strlen(buf_s);
  char *buf = S21_NULL;
  long long int result;
  if (data->number != 0 && (int)len_str > data->number) {
    buf = calloc(len_str + 1, sizeof(char));
    buf = s21_strncpy(buf, buf_s, data->number);
    result = s21_strtoll(buf, &endptr, base);
    if (buf != endptr) {
      endptr = buf_s + (endptr - buf);
    } else {
      endptr = buf_s;
    }
    free(buf);
  } else {
    result = s21_strtoll(buf_s, &endptr, base);
  }

  if (!data->skip && (buf_s != endptr)) {
    if (data->width == 'h' && !data->double_w) {
      short int *p = va_arg(ap, short int *);
      *p = result;
    } else {
      if (data->width == 'h' && data->double_w) {
        char *p = va_arg(ap, char *);
        *p = result;
      } else {
        if (data->width == 'l' && !data->double_w) {
          long int *p = va_arg(ap, long int *);
          *p = result;
        } else {
          if (data->width == 'l' && data->double_w) {
            long long int *p = va_arg(ap, long long int *);
            *p = result;
          } else {
            int *p = va_arg(ap, int *);
            *p = result;
          }
        }
      }
    }
    (data->number_read)++;
  }
  return endptr;
}

char *scan_e(va_list ap, char *buf_s, DATA *data) {
  char *endptr;
  s21_size_t len_str = s21_strlen(buf_s);
  char *buf = S21_NULL;
  long double result;
  if (data->number != 0 && (int)len_str > data->number) {
    buf = calloc(len_str + 1, sizeof(char));
    buf = s21_strncpy(buf, buf_s, data->number);
    result = s21_strtold(buf, &endptr);
    if (buf != endptr) {
      endptr = buf_s + (endptr - buf);
    } else {
      endptr = buf_s;
    }
    free(buf);
  } else {
    result = s21_strtold(buf_s, &endptr);
  }

  if (!data->skip && (buf_s != endptr)) {
    if (data->width == 'l' && !data->double_w) {
      double *p = va_arg(ap, double *);
      *p = result;
    } else {
      if (data->width == 'L') {
        long double *p = va_arg(ap, long double *);
        *p = result;
      } else {
        float *p = va_arg(ap, float *);
        *p = result;
      }
    }
    data->number_read++;
  }
  return endptr;
}

char *scan_o(va_list ap, char *buf_s, DATA *data, char ch) {
  int base = 8;
  if (ch == 'x' || ch == 'X') base = 16;
  char *endptr;
  s21_size_t len_str = s21_strlen(buf_s);
  char *buf = S21_NULL;
  unsigned long long int result;
  if (data->number != 0 && (int)len_str > data->number) {
    buf = calloc(len_str + 1, sizeof(char));
    buf = s21_strncpy(buf, buf_s, data->number);
    result = s21_strtoll(buf, &endptr, base);
    if (buf != endptr) {
      endptr = buf_s + (endptr - buf);
    } else {
      endptr = buf_s;
    }
    free(buf);
  } else {
    result = s21_strtoll(buf_s, &endptr, base);
  }

  if (!data->skip && (buf_s != endptr)) {
    if (data->width == 'h' && !data->double_w) {
      unsigned short int *p = va_arg(ap, unsigned short int *);
      *p = result;
    } else {
      if (data->width == 'h' && data->double_w) {
        unsigned char *p = va_arg(ap, unsigned char *);
        *p = result;
      } else {
        if (data->width == 'l' && !data->double_w) {
          unsigned long int *p = va_arg(ap, unsigned long int *);
          *p = result;
        } else {
          if (data->width == 'l' && data->double_w) {
            unsigned long long int *p = va_arg(ap, unsigned long long int *);
            *p = result;
          } else {
            unsigned int *p = va_arg(ap, unsigned int *);
            *p = result;
          }
        }
      }
    }
    (data->number_read)++;
  }
  return endptr;
}

char *scan_s(va_list ap, char *buf_s, DATA *data) {
  buf_s =
      del_spaces(buf_s, data);  // удаляем пробельные символы в начале строки
  // определяем длину новой строки
  char *brk = s21_strpbrk(buf_s, " \t\n\f\r\v");
  s21_size_t len_new_s = 0;
  if (brk) {
    len_new_s = brk - buf_s;
  } else {
    len_new_s = s21_strlen(buf_s);
  }
  if ((int)len_new_s < data->number || data->number == 0)
    data->number = len_new_s;
  // копируем строку
  if (!data->skip && len_new_s) {
    if (data->width == 'l' && !data->double_w) {
      wchar_t *p = va_arg(ap, wchar_t *);
      for (int i = 0; i < data->number; i++) {
        p[i] = buf_s[i];
      }
      p[data->number] = '\0';
    } else {
      char *p = va_arg(ap, char *);
      p = s21_strncpy(p, buf_s, data->number);
      p[data->number] = '\0';
    }
    (data->number_read)++;
  }
  return buf_s + data->number;
}

char *scan_u(va_list ap, char *buf_s, DATA *data) {
  char *endptr;
  unsigned result = s21_strtoll(buf_s, &endptr, 10);
  if (!data->skip && (buf_s != endptr)) {
    unsigned *p = va_arg(ap, unsigned *);
    *p = result;
    (data->number_read)++;
  }
  return endptr;
}

char *scan_p(va_list ap, char *buf_s, DATA *data) {
  int base = 16;
  char *endptr;
  s21_size_t len_str = s21_strlen(buf_s);
  char *buf = S21_NULL;
  unsigned long long int result;
  if (data->number != 0 && (int)len_str > data->number) {
    buf = calloc(len_str + 1, sizeof(char));
    buf = s21_strncpy(buf, buf_s, data->number);
    result = s21_strtoll(buf, &endptr, base);
    if (buf != endptr) {
      endptr = buf_s + (endptr - buf);
    } else {
      endptr = buf_s;
    }
    free(buf);
  } else {
    result = s21_strtoll(buf_s, &endptr, base);
  }
  if (!data->skip && (buf_s != endptr)) {
    long long *p = va_arg(ap, long long *);
    *p = result;
    (data->number_read)++;
  }
  return endptr;
}

char *del_spaces(char *str, DATA *data) {
  s21_size_t lbuf = s21_strspn(str, " \t\n\f\r\v");
  data->del_char += lbuf;
  str = s21_strcpy(str, &str[lbuf]);
  return str;
}

long double s21_strtold(const char *restrict nptr, char **restrict endptr) {
  int shift = 0;
  int base = 0;
  long double result = 0;
  char *av_char = "x0123456789abcdfeABCDFE";
  // int stop_sign = 0;
  // int stop_sys = 0;
  s21_size_t no_error = 1;

  // игнорирование пробелов
  while (s21_isspace(nptr[shift])) shift++;

  // определение знака
  int sign = det_sign(nptr[shift], &shift);

  // определение системы счисления
  base = det_base(nptr, shift, &av_char, base);

  // проверка на допустимые символы
  no_error = s21_strspn(&nptr[shift], av_char);

  // ситуация ".3 "
  if (!S21_IS_NUMERIC(nptr[shift]) && nptr[shift] != '.') {
    no_error = 0;
  }

  // целая часть
  if (no_error != 0) {
    long long bresult = 0;
    det_int(nptr, av_char, &shift, base, sign, &bresult);
    result += bresult;
    if (sign == -1 && result > -1) {
      result *= sign;
    }
  }

  // дробная часть
  if (nptr[shift] == '.') {
    shift++;
    no_error = 1;
  }
  s21_size_t len_num = s21_strspn(&nptr[shift], av_char);
  // если после . нет допустимых символов
  for (s21_size_t i = 1; i < len_num + 1; i++) {
    int num = trans_ch16(nptr[shift]);
    result += (num / powl(base, i)) * sign;
    shift++;
  }

  // экспанента
  processing_exp(&result, nptr, &shift, &base, av_char);

  // infinity
  char *sbuf = NULL;
  sbuf = s21_to_lower(&nptr[shift]);
  processing_inf(&result, &sbuf, &shift, &no_error, sign);

  // nan
  processing_nan(&result, &sbuf, &shift, &no_error);
  free(sbuf);
  // определяем смещение строки
  if (endptr != S21_NULL) {
    if (no_error == 0) {
      *endptr = (char *)nptr;
    } else {
      *endptr = (char *)&nptr[shift];
    }
  }

  // определение переполнения
  if ((sign == 1 && result < 0) || (sign == -1 && result > 0)) {
    errno = ERANGE;
    result = HUGE_VALL;
  }

  return result;
}

void processing_exp(long double *result, const char *restrict nptr, int *shift,
                    int *base, char *av_char) {
  long double exp = 1;
  if (*base == 10 && nptr[*shift] == 'e') {
    exp = 10;
    (*shift)++;
  }
  if (*base == 16 && nptr[*shift] == 'p') {
    exp = 2;
    (*shift)++;
  }
  if (exp != 1) {
    int sign_e = det_sign(nptr[*shift], shift);
    long long exp_result = 0;
    det_int(nptr, av_char, shift, *base, 1, &exp_result);
    if (sign_e == 1) *result *= powl(exp, exp_result);
    if (sign_e == -1) *result /= powl(exp, exp_result);
  }
}

void processing_inf(long double *result, char **sbuf, int *shift,
                    s21_size_t *no_error, int sign) {
  char *len_inf = S21_NULL;
  if (*result == 0) {
    len_inf = s21_strstr(*sbuf, "infinity");
    if (len_inf == S21_NULL) {
      len_inf = s21_strstr(*sbuf, "inf");
      if (len_inf == *sbuf) *shift += 3;
    } else {
      if (len_inf == *sbuf) *shift += 8;
    }
    if (len_inf == *sbuf) {
      *result = INFINITY * sign;
      *no_error = 1;
    }
  }
}

void processing_nan(long double *result, char **sbuf, int *shift,
                    s21_size_t *no_error) {
  if (*result == 0) {
    char *len_nan = s21_strstr(*sbuf, "nan");
    if (len_nan == *sbuf) {
      *shift += 3;
      *result = NAN;
      *no_error = 1;
    }
  }
}

int det_base(const char *restrict nptr, int shift, char **av_char, int base) {
  if (base == 0) {
    if (nptr[shift] == '0') {
      if (nptr[shift + 1] == 'x' || nptr[shift + 1] == 'X') {
        base = 16;
      } else {
        if (nptr[shift + 1] == '.') {
          base = 10;
        } else {
          base = 8;
        }
      }
    } else {
      base = 10;
    }
  }
  if (base != 0) {
    if (base == 8) {
      *av_char = "01234567";
    }
    if (base == 10) {
      *av_char = "0123456789";
    }
    if (base == 16) {
      // проверяем что число начинается с 0x
      if (nptr[shift] == '0') {
        if (nptr[shift + 1] == 'x' || nptr[shift + 1] == 'X') {
          *av_char = "xX0123456789abcdfeABCDFE";
        }
      } else {
        *av_char = "0123456789abcdfeABCDFE";
      }
    }
  }
  return base;
}

long long s21_strtoll(const char *restrict str, char **restrict endptr,
                      int base) {
  int shift = 0;
  long long result = 0;
  char *av_char = "x0123456789abcdfeABCDFE";
  // int stop_sign = 0;
  // int stop_sys = 0;
  s21_size_t avlen = 0;

  // игнорирование пробелов
  while (s21_isspace(str[shift])) shift++;

  // определение знака
  int sign = det_sign(str[shift], &shift);

  // определение системы счисления
  base = det_base(str, shift, &av_char, base);

  // проверка на допустимые символы
  avlen = s21_strspn(&str[shift], av_char);

  // расчет целой части
  if (avlen != 0) {
    det_int(str, av_char, &shift, base, sign, &result);
  }

  // определяем смещение строки
  if (endptr != NULL) {
    if (avlen == 0) {
      *endptr = (char *)str;
    } else {
      *endptr = (char *)&str[shift];
    }
  }

  // определение переполнения
  if ((sign == 1 && result < 0) || (sign == -1 && result > 0)) {
    errno = ERANGE;
    result = LLONG_MAX;
  }

  return result;
}

void det_int(const char *str, char *av_char, int *shift, int base, int sign,
             long long *result) {
  s21_size_t len_num = s21_strspn(&str[*shift], av_char);
  if (len_num != 0) {
    for (int i = len_num - 1; i >= 0; i--) {
      int num = trans_ch16(str[*shift]);
      *result += sign * num * powl(base, i);
      (*shift)++;
    }
  }
}

int trans_ch16(char c) {
  int result = 0;
  if (c >= '0' && c <= '9') result = c - 48;
  if (c == 'a' || c == 'A') result = 10;
  if (c == 'b' || c == 'B') result = 11;
  if (c == 'c' || c == 'C') result = 12;
  if (c == 'd' || c == 'D') result = 13;
  if (c == 'e' || c == 'E') result = 14;
  if (c == 'f' || c == 'F') result = 15;
  return result;
}

int det_sign(char c, int *shift) {
  int result = 1;
  if (c == '+') {
    result = 1;
    (*shift)++;
  } else {
    if (c == '-') {
      result = -1;
      (*shift)++;
    }
  }
  return result;
}

int s21_isspace(int c) {
  return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
          c == ' ');
}

// надо сократить могут предраться
int s21_sprintf(char *str, const char *format, ...) {
  FORMAT spec_init = {0};
  va_list(input);
  va_start(input, format);
  char *specificators;
  int i = 0;
  int start_i = 0;  //откуда начали считать спецификатор
  int j = 0;
  int size = 0;
  // char position;
  int spec_try = 0;
  while (format[i] != '\0') {
    if (format[i] == '%') {
      // зануляем спецификаторы
      s21_set_zeroes(&spec_init);
      size = 0;
      spec_try++;
      start_i = j;
      i++;
      // проверяем спецификатор ли
      while (!S21_IS_SPEC(format[i])) {
        i++;
        size++;
      }
      i = i - size;
      // переменная для флагов и т.д. НЕ СПЕЦИФИКАТОРЫ
      specificators = (char *)calloc(size + 2, sizeof(char));
      int l = 0;
      while (!S21_IS_SPEC(format[i]) && format[i]) {
        specificators[l] = format[i];
        l++;
        i++;
      }
      specificators[l] = format[i];

      parsing_format(specificators, &spec_init);

      if (specificators[size] == '%' && spec_init.error != -1) {
        str[j++] = '%';
        str[j] = '\0';
        j--;
      }

      if (specificators[size] == 'c' && spec_init.error != -1) {
        char ch_argument = va_arg(input, int);
        char *ch_put_it = calloc(sizeof(char), 2);
        ch_put_it[0] = ch_argument;
        char *gayka;
        put_width(&gayka, ch_put_it, &spec_init);
        for (s21_size_t count = 0; count < s21_strlen(gayka); count++) {
          str[j] = gayka[count];
          j++;
        }
        str[j] = '\0';
        if (ch_argument != '\0') j--;

        l = 0;
        size = 0;
        free(gayka);
      }

      if ((specificators[size] == 'd' || specificators[size] == 'i') &&
          spec_init.error != -1) {
        spec_init.is_signed = 1;
        long long int argument;
        if (spec_init.length == 'l') {
          argument = va_arg(input, long int);
        } else {
          if (spec_init.double_len != 0) {
            argument = va_arg(input, long long int);
          } else {
            argument = va_arg(input, int);
          }
        }
        if_u(str, &spec_init, start_i, argument);
        j = s21_strlen(str) - 1;
        l = 0;
        size = 0;
      }

      if (specificators[size] == 'f') {
        char *str1 = S21_NULL;
        str1 = (char *)calloc(1000, 1);
        if (str1) {
          switch (spec_init.length) {
            case 'l': {
              if (spec_init.double_len) {
                str1 =
                    s21_f_to_str(str1, va_arg(input, long double), spec_init);
              } else {
                str1 = s21_f_to_str(str1, va_arg(input, double), spec_init);
              }
              break;
            }
            default: {
              double u_number = va_arg(input, double);
              str1 = s21_f_to_str(str1, u_number, spec_init);
            }
          }
        }
        s21_uns_precision(str1, spec_init);
        s21_width_flag(str1, spec_init);
        s21_strcpy(&str[j], str1);
        free(str1);
        j = strlen(str) - 1;
        l = 0;
      }

      if (specificators[size] == 's' && spec_init.error != -1) {
        char *argument;
        if (spec_init.length == 'l') {
          wchar_t *w_arg = va_arg(input, wchar_t *);
          int size = 0;
          char *buf = S21_NULL;
          for (wchar_t *ptr = w_arg; *ptr != '\0'; ptr++) {
            buf = realloc(buf, size + 1);
            buf[size++] = *ptr;
          }
          buf[size] = '\0';
          argument = buf;
        } else {
          argument = va_arg(input, char *);
        }

        s21_size_t len_arg = 0;
        if (argument == S21_NULL) {
          len_arg = 6;
        } else {
          len_arg = s21_strlen(argument);
        }
        if (spec_init.precision < (int)len_arg && spec_init.point)
          len_arg = spec_init.precision;

        char *ch_put_it = calloc(sizeof(char), len_arg + 1);
        if (argument == S21_NULL) {
          ch_put_it = s21_strncpy(ch_put_it, "(null)", len_arg);
        } else {
          ch_put_it = s21_strncpy(ch_put_it, argument, len_arg);
        }
        char *gayka = S21_NULL;
        put_width(&gayka, ch_put_it, &spec_init);
        for (s21_size_t count = 0; count < s21_strlen(gayka); count++) {
          str[j] = gayka[count];
          j++;
        }
        str[j] = '\0';
        j--;
        size = 0;
        l = 0;
        if (spec_init.length == 'l') free(argument);
        free(gayka);
      }

      if (specificators[size] == 'u' && spec_init.error != -1) {
        long long unsigned argument;
        if (spec_init.length == 'l') {
          argument = va_arg(input, long unsigned);
        } else {
          if (spec_init.double_len != 0) {
            argument = va_arg(input, long long unsigned);
          } else {
            if (spec_init.length == 'h') {
              argument = va_arg(input, long unsigned);
              argument = (short unsigned)argument;
            } else {
              argument = va_arg(input, unsigned);
            }
          }
        }
        if_u(str, &spec_init, start_i, argument);
        j = s21_strlen(str) - 1;
        l = 0;
        size = 0;
      }

      free(specificators);
    } else {
      if (spec_init.error == -1) {
        for (int k = start_i; k <= start_i + size + 1; k++) {
          str[k] = format[k];
        }
      }
      str[j] = format[i];
    }
    i++;
    j++;
  }
  //успешно
  if (str[j] != '\0') str[j] = '\0';
  va_end(input);
  return j;
}

void parsing_format(char *spec_str, FORMAT *fformat) {
  int i = 0;
  while (spec_str[i] != '\0') {
    if (spec_str[i] == '.') {     //если точка
      if (fformat->point == 0) {  // и в структуре зн 0
        fformat->point = 1;
      } else {
        fformat->error = -1;  // если две точки подряд - ошибка
      }
    }
    // если длина
    if (S21_IS_LENGTH(spec_str[i])) {
      if (fformat->length != 0) {
        if (fformat->double_len == 0 && fformat->length == spec_str[i]) {
          fformat->double_len = 1;
        } else {
          fformat->error = -1;
        }
      } else {
        if (spec_str[i] == 'L') {
          fformat->length = 'l';
          fformat->double_len = 1;
        } else {
          fformat->length = spec_str[i];
        }
      }
    }
    // если число для расчета ширины
    if (S21_IS_NUMERIC(spec_str[i])) {
      if (fformat->point != 1) {
        fformat->width = fformat->width * 10 + (spec_str[i] - '0');
      } else {
        fformat->precision = fformat->precision * 10 + (spec_str[i] - '0');
      }
    }

    // проверка на флаги
    if (S21_IS_FLAG(spec_str[i])) {
      if ((fformat->width != 0 || fformat->point != 0 ||
           fformat->length != 0) &&
          i > 0) {
        fformat->error = -1;
      } else {
        switch (spec_str[i]) {
          case '-':
            fformat->minus = 1;
            break;
          case '+':
            fformat->plus = 1;
            break;
          case ' ':
            fformat->space = 1;
            break;
          case '#':
            fformat->sharp = 1;
            break;
          case '0':
            fformat->zero = 1;
            break;
        }
      }
    }
    if (i == 0 && spec_str[i] == '0') {
      fformat->zero = 1;
    }
    i++;
  }
}

void s21_set_zeroes(FORMAT *fformat) {
  fformat->spec = 0;
  fformat->space = 0;
  fformat->minus = 0;
  fformat->plus = 0;
  fformat->point = 0;
  fformat->width = 0;
  fformat->length = 0;
  fformat->double_len = 0;
  fformat->precision = 0;
  fformat->zero = 0;
  fformat->sharp = 0;
  fformat->error = 0;
  fformat->is_signed = 0;
}

int if_u(char *result_str, FORMAT *fformat, int start,
         long long unsigned put_it) {
  int size_int = s21_uintlen(put_it, fformat);  // длина не учитывает знак
  int size_ch =
      det_size_signed(put_it, fformat, size_int);  // длина учитывает знак

  char *ch_put_it;
  ch_put_it = (char *)calloc(size_ch + 1, sizeof(char));
  uput_to_ch(ch_put_it, put_it, fformat, size_ch, size_int);
  char *gayka;
  put_width(&gayka, ch_put_it, fformat);
  for (s21_size_t j = 0; j < s21_strlen(gayka); j++) {
    result_str[start] = gayka[j];
    start++;
  }
  result_str[start] = '\0';
  free(gayka);
  return start;
}

int det_size_signed(long long unsigned put_it, FORMAT *fformat, int size_int) {
  int size_ch = 0;
  if (fformat->is_signed) {
    // long long int buf_num = put_it;
    if ((long long int)put_it < 0) size_ch++;
  }
  if ((fformat->plus || fformat->space) && !size_ch && fformat->is_signed)
    size_ch++;
  if (fformat->precision > size_int) {
    size_ch += fformat->precision;
  } else {
    size_ch += size_int;
  }
  return size_ch;
}

char *s21_f_to_str(char *str, long double number, FORMAT fformat) {
  if (fformat.precision <= 0 && fformat.point == 0) fformat.precision = 6;
  if (fformat.precision == 0 && fformat.point != 0) fformat.precision = 0;
  // printf("precision: %d  point: %d\n", fformat.precision, fformat.point);
  char num1_str[1000] = "", *p1 = S21_NULL;
  p1 = num1_str;
  char num2_str[1000] = "", *p2 = S21_NULL;
  p2 = num2_str;
  long double mantis, right = 0.0L, pow = 1L, pow_t = 1.0L;
  int sign = s21_check_sign_flags(&fformat, number);
  if (fpclassify(number) < 4) {
    // printf("fpclassify\n");
    s21_d_class_to_str(num1_str, number, fformat);
    if (sign < 0 && fpclassify(number) != 1) s21_strcat(str, "-");
    s21_strcat(str, num1_str);
    fformat.zero = 0;
    if (fpclassify(number) == 2 && fformat.sharp && !fformat.precision) {
      s21_strcat(str, ".");
    }
  } else {
    number = s21_round(number, fformat.precision);
    mantis = modfl(fabsl(number), &right);
    while (truncl(right / pow) > 0) {
      int digit;
      digit = (int)truncl(fmodl(truncl(right), pow * (long double)10L) / (pow));
      *(p1++) = (char)(digit + '0');

      pow *= 10L;
    }

    if (sign < 0) *(p1++) = '-';
    *p1 = '\0';

    for (int i = 0; i < fformat.precision; i++) pow_t *= 10;

    mantis = roundl(mantis * pow_t);
    // printf("mantis: %Lf\n", mantis);
    pow = 1.0L;

    while (pow < pow_t) {
      int digit;
      digit =
          (int)truncl(fmodl(truncl(mantis), pow * (long double)10L) / (pow));
      *(p2++) = (char)(digit + '0');
      pow *= 10L;
    }

    *p2 = '\0';
    if (fformat.plus) {
      s21_strcat(str, "+");
    }
    if (fformat.space) {
      s21_strcat(str, " ");
    }
    // printf("str: %s\n", str);
    s21_reverse_u_str(num1_str);
    if (s21_strlen(num1_str) == 0) s21_strcat(str, "0");
    s21_strcat(str, num1_str);
    // printf("str: %s\n", str);
    if (fformat.precision > 0 || fformat.sharp == 1) {
      // printf("prec: %d\n", fformat.precision);
      s21_strcat(str, ".");
    }

    // printf("str: %s\n", str);
    if (fformat.precision > 0) {
      s21_reverse_u_str(num2_str);
      s21_strcat(str, num2_str);
    }
    // printf("str в конце: %s\n", str);
  }
  return str;
}

char *s21_uns_precision(char *str, FORMAT fformat) {
  char *num_str = (char *)calloc(400 + fformat.width + fformat.precision, 1);
  fformat.precision = fformat.precision == -1 ? 1 : fformat.precision;
  if (num_str) {
    s21_size_t str_len = s21_strlen(str);
    int shift;
    char *p = S21_NULL;
    char *s = S21_NULL;
    p = num_str;
    s = str;
    if (fformat.zero == 1) {
      fformat.precision = (fformat.precision > fformat.width)
                              ? fformat.precision
                              : fformat.width;
    }
    fformat.precision =
        fformat.precision > (int)str_len ? fformat.precision : (int)str_len;
    for (int i = 0; i < fformat.precision; i++) {
      if (i >= fformat.precision - ((int)str_len))
        *(p++) = *(s++);
      else
        *(p++) = '0';
    }
    shift = fformat.spec == 'x' && fformat.sharp == 1 ? 32 : 0;
    if (fformat.sharp == 1 && fformat.spec == (char)('X' + shift)) {
      if (!(str_len == 1 && *str == '0')) {
        s21_reverse_u_str(num_str);
        *(p++) = (char)('X' + shift);
        *(p++) = '0';
        s21_reverse_u_str(num_str);
      }
    }
    *p = '\0';
    s21_strcpy(str, num_str);
    free(num_str);
  }
  return str;
}

char *s21_width_flag(char *str, FORMAT fformat) {
  int str_len = (int)s21_strlen(str);
  if (fformat.width > (int)str_len) {
    char *tmp_str = (char *)calloc(str_len + fformat.width + 10, 1);
    if (tmp_str) {
      for (int i = 0; i < fformat.width; i++) {
        if (fformat.minus == 1) {
          if (i < str_len) {
            tmp_str[i] = str[i];
          } else {
            tmp_str[i] = ' ';
          }
        } else {
          if (i < fformat.width - str_len) {
            tmp_str[i] = ' ';
          } else {
            tmp_str[i] = str[i - (fformat.width - str_len)];
          }
        }
      }
      tmp_str[fformat.width] = '\0';
      str = s21_strcpy(str, tmp_str);
      free(tmp_str);
    }
  }
  return str;
}

int s21_check_sign_flags(FORMAT *fformat, long double number) {
  int sign = 1;
  if (signbit(number) == 0) {
    fformat->space = fformat->plus ? 0 : fformat->space;
  } else {
    sign = -1;
    fformat->plus = 0;
    fformat->space = 0;
  }
  return sign;
}

char *s21_d_class_to_str(char *str, long double x, FORMAT fformat) {
  switch (fpclassify(x)) {
    case FP_NAN:
      s21_strcat(str, "nan");
      break;
    case FP_INFINITE:
      s21_strcat(str, "inf");
      break;
    case FP_ZERO:
      if (fformat.plus) {
        s21_strcat(str, "+");
      }
      if (fformat.space) {
        s21_strcat(str, " ");
      }
      s21_strcat(str, "0");
      if (fformat.precision > 0) {
        s21_strcat(str, ".");
        while (fformat.precision--) s21_strcat(str, "0");
      }
      break;
  }
  return str;
}

long double s21_round(long double x, int tolerance) {
  long double right = 0.0;
  long double x1 = modfl(fabsl(x), &right);
  int mul = 0;
  int sign = signbit(x) == 0 ? 1 : -1;
  for (int i = 0; i < tolerance; i++) mul--;

  if (roundl(x1 / powl(10, mul)) > truncl(x1 / powl(10, mul))) {
    x = x + (5 * powl(10, mul - 1)) * sign;
  }
  if (tolerance <= 6 && x1 > 0) {
    x = x / powl(10, mul);
    x = powl(10, mul) * truncl(x);
  }
  return x;
}

char *s21_reverse_u_str(char *str) {
  s21_size_t str_len = s21_strlen(str);
  char ch;
  for (s21_size_t i = 0; i < str_len / 2; i++) {
    ch = str[i];
    str[i] = str[str_len - 1 - i];
    str[str_len - 1 - i] = ch;
  }
  return str;
}

int uput_to_ch(char *ch, long long unsigned num, FORMAT *fformat, int size_ch,
               int size_int) {
  if (fformat->is_signed) {
    long long int buf_num = num;

    if ((long long int)num == LONG_MIN)
      buf_num -= 1;  // условие для обработки LONG_MIN
    buf_num = llabs(buf_num);
    for (int i = size_ch - 1; buf_num > 0; i--) {
      ch[i] = (buf_num % 10) + '0';
      buf_num = buf_num / 10;
    }
    if ((long long int)num == LONG_MIN)
      ch[size_ch - 1] = '8';  // условие для обработки LONG_MIN
    if ((long long int)num < 0) {
      ch[0] = '-';
    } else if (fformat->plus) {
      ch[0] = '+';
    } else if (fformat->space) {
      ch[0] = ' ';
    }
  } else {
    long long unsigned buf_num = num;
    for (int i = size_ch - 1; buf_num > 0; i--) {
      ch[i] = (buf_num % 10) + '0';
      buf_num = buf_num / 10;
    }
    if (fformat->plus) {
      // ch[0] = '+';
    } else if (fformat->space) {
      // ch[0] = ' ';
    }
  }
  // f=%3.d v=0 str="   "   f=%3d v=0 str="  0"
  if (num == 0 && (!fformat->point || fformat->precision > fformat->width))
    ch[size_ch - 1] = '0';

  if (fformat->precision > size_int) {
    int count = 0;  // если по нулевому индексу не \0 нужно начинать с индекса 1
    if (ch[0] != '\0') count = 1;
    for (int i = count; i < size_ch - size_int; i++) {
      ch[i] = '0';
    }
  }

  return size_ch;
}

void put_width(char **str1, char *str, FORMAT *fformat) {
  char *space_str;
  int length = s21_strlen(str);

  int is_null = 0;  // переменная для NULL
  if (length == 6) {
    if (str == s21_strstr(str, "(null)")) is_null = 1;
  }

  if (is_null) {
    if (fformat->point && fformat->width > fformat->precision) length = 0;
  }
  if (fformat->width > length) {
    *str1 = (char *)calloc(fformat->width + 1, sizeof(char));
    space_str = (char *)calloc(fformat->width - length + 1, sizeof(char));
    for (int i = 0; i < fformat->width - length; i++) {
      if (fformat->zero != 0) {
        if (str[i] == '-' && i == 0) {
          str[i] = '0';
          space_str[i] = '-';
        } else {
          space_str[i] = '0';
        }
      } else {
        space_str[i] = ' ';
      }
    }

    if (is_null) {
      if (fformat->point) str[0] = '\0';
    }

    if (fformat->minus != 0) {
      *str1 = s21_strcat(*str1, str);
      *str1 = s21_strcat(*str1, space_str);
    } else {
      *str1 = s21_strcat(*str1, space_str);
      *str1 = s21_strcat(*str1, str);
    }
    free(space_str);
    free(str);
  } else {
    if (is_null) {
      if (fformat->point && fformat->width == 0 && fformat->precision == 0)
        str[0] = '\0';
    }
    *str1 = str;
  }
}

int s21_uintlen(long long unsigned num, FORMAT *fformat) {
  int i = 0;
  if (fformat->is_signed) {
    long long int buf_num = num;
    if (buf_num == 0) i++;
    while (buf_num != 0) {
      buf_num = buf_num / 10;
      i++;
    }
  } else {
    if (num == 0) i++;
    while (num != 0) {
      num = num / 10;
      i++;
    }
  }
  return i;
}
