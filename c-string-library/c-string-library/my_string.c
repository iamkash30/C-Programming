#include "my_string.h"
#include <stdlib.h>
#include <math.h>

size_t my_string__strlen(const char *__s) {
    const char *temp = __s;
    while (*temp != '\0') {
           temp++;
    }
    return (temp - __s);
}

char *my_string__strcpy(char *__dst, const char *__src) {
    char *dst = __dst;
    const char *src = __src;
    
    while ((*dst != '\0') || (*src != '\0')) {
        *dst++ = *src++;
    }
    *dst = '\0';
    return __dst;
}

char *my_string__strncpy(char *__dst, const char *__src, size_t __n) {
    char *dst = __dst;
    const char *src = __src;
    
    while (__n != 0 && *src != '\0') {
        *dst++ = *src++;
        __n--;
    }
    *dst = '\0';
    return __dst;
}

char *my_string__strcat(char *__s1, const char *__s2) {
    char *s1 = __s1;
    const char *s2 = __s2;
    
    while (*s1) {
        s1++;
    }
    s1 = my_string__strcpy(s1, s2);
    return __s1;
}

char *my_string__strncat(char *__s1, const char *__s2, size_t __n) {
    char *s1 = __s1;
    const char *s2 = __s2;
    
    while (*s1) s1++;
    
    while (__n != 0 && *s2 != '\0') {
        *s1++ = *s2++;
        __n--;
    }
    return __s1;
}

char *my_string__strchr(const char *__s, int __c) {
    const char *s = __s;
    while (*s != '\0' && *s != __c) {
        s++;
    }
    return (*s == __c) ? (char *)s : NULL;
}

int my_string__strcmp(const char *__s1, const char *__s2) {
    const char *s1 = __s1;
    const char *s2 = __s2;
    unsigned char us1, us2;
    us1 = us2 = '\0';
    
    while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    us1 = *(unsigned char *)s1;
    us2 = *(unsigned char *)s2;
    return (us1 - us2);
}

int my_string__strncmp(const char *__s1, const char *__s2, size_t __n) {
    unsigned char us1, us2;
    us1 = us2 = '\0';
    while (__n > 0 && *__s1 != '\0' && *__s2 != '\0') {
        if (*__s1 != *__s2) {
            break;
        }
        __s1++;
        __s2++;
        __n--;
    }
    us1 = *(unsigned char *)__s1;
    us2 = *(unsigned char *)__s2;
    return (us1 - us2);
}


char *my_string__strstr(const char *__big, const char *__little) {
    const char *big = __big;
    char const *little = __little;
    size_t big_str_length = my_string__strlen(big);
    size_t little_str_length = my_string__strlen(little);
    if (big_str_length < little_str_length)
        return NULL;
    
    while (big_str_length >= little_str_length) {
        if ((*big == *little) && (0 == my_string__strncmp(big, little, little_str_length))) {
            return (char *)big;
        }
        big++;
        big_str_length--;
    }
    return NULL;
}

char *my_string__strtok(char *__str, const char *__sep);


void *my_memmove(void *_dst, const void *_src, size_t _len)
{
    char *dst = (char *)_dst;
    const char *src = (const char *)_src;

    if ((src < dst) && (dst < src + _len)) {
        /* Do a descending copy */
        src = src + _len;
        dst = dst + _len;
        while (0 != _len-- && '\0' != *src) {
            *dst = *src;
            dst--;
            src--;
        }
    } else {
        /* Do a ascending copy */
        while (0 != _len-- && '\0' != *src) {
            *dst++ = *src++;
        }
    }
    return _dst;
}

void *my_memcpy(void *_dst, const void *_src, size_t _len)
{
    char *dst = (char *) _dst;
    const char *src = (const char *)_src;

    while (0 != _len && '\0' != *src) {
        *dst = *src;
        dst++;
        src++;
    }
    return _dst;
}

void *my_memset(void *_b, int _c, size_t _len) {
    unsigned char *b = (unsigned char *)_b;
    unsigned char c = _c;

    while (0 != _len--) {
        *b = c;
        b++;
    }
    return _b;
}

int my_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *us1 = (const unsigned char *)s1;
    const unsigned char *us2 = (const unsigned char *)s2;

    while (n-- > 0) {
        if (*us1 != *us2) {
            return (*us1 - *us2);
        }
        us1++;
        us2++;
    }
    return 0;
}

int my_atoi(const char *string_of_integers) {
    if ('\0' == *string_of_integers) {
        return 0;
    }
    int result = 0;
    const char *str = string_of_integers;
    int sign = 1;

    // Ignore the white space
    while (*str == ' ' || *str == '\n' || *str == '\t') {
        str++;
    }

    // Check sign of a number
    if ((*str == '-') || (*str == '+')) {
        sign = 1 - 2 * (*str == '-');
        str++;
    }

    while ((*str >= '0') && (*str <= '9')) {
        result = (result << 3) + (result << 1) + (*str - '0');
        str++;
    }
    return sign * result;
}

void my_swap_char(char *c1, char *c2) {
    char t = *c1;
    *c1 = *c2;
    *c2 = t;
}

void my_reverse_cstring(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        my_swap_char(&str[start], &str[end]);
        start++;
        end--;
    }
}

char* my_itoa(int num, char *str_to_return, int base) {
    bool is_negative = false;
    int i = 0;
    // In standard itoa(), negative numbers are handled only
    // with base 10. Otherwise, numbers are considered unsigned
    if (num < 0 && base == 10) {
        is_negative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str_to_return[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (true == is_negative) {
        str_to_return[i++] = '-';
    }

    // Append string terminator at the end
    str_to_return[i] = '\0';

    // Reverse the string
    my_reverse_cstring(str_to_return, i);

    return str_to_return;
}
