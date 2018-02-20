/*
** EPITECH PROJECT, 2017
** header
** File description:
** lib
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr(char *str);
char *my_strcat_malloc(char *dest, char *src);
char **my_str_to_word_array(char *str);
int my_strncmp(char const *str1, char const *str2, int n);
int my_str_isalpha(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_revstr(char *str);
void my_memset(char *buffer, int size);
int my_array_size(char **array);
char *int_to_str(int nb);
char *clear_str(char *str);
#endif
