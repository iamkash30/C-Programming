#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

char *my_string__strcat(char *__s1, const char *__s2);
char *my_string__strchr(const char *__s, int __c);
int my_string__strcmp(const char *__s1, const char *__s2);
int my_string__strncmp(const char *__s1, const char *__s2, size_t __n);
char *my_string__strcpy(char *__dst, const char *__src);
char *my_string__strncpy(char *__dst, const char *__src, size_t __n);
size_t my_string__strlen(const char *__s);
char *my_string__strncat(char *__s1, const char *__s2, size_t __n);
char *my_string__strstr(const char *__big, const char *__little);
char *my_string__strtok(char *__str, const char *__sep);

void *my_memmove(void *_dst, const void *_src, size_t _len);
void *my_memcpy(void *_dst, const void *_src, size_t _len);
char *my_itoa(int num, char *str_to_return, int base);
