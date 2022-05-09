/*
** EPITECH PROJECT, 2021
** My_lib
** File description:
** tool file for my_prinft function
*/

#include <stdarg.h>
#include "my.h"

#ifndef __TOOL__H__
    #define __TOOL__H__

void my_printf(char *string, ...);

int int_function(char *string, int *i, va_list ap);

int flag_character_function(char *string, int i, va_list ap);

int conversion_special_function(char *string, int *i, va_list ap);

int check_occur2(char *string, int *i, va_list ap);

int check_occur3(char *string, int *i, va_list ap);

int check_occur4(char *string, int *i, va_list ap);

int check_zero_flag(char *string, int *i, va_list ap, va_list aq);

void check_size(char *string, int *i, va_list aq);

void cheat_function(char *string, int *i);

void cheat_function2(char *string, int *i);

void help_function2(char *string, int *i, va_list aq);

void help_function(char *string, int *i, va_list aq);

unsigned int my_int_len2(unsigned int nb);

void error_case(char *string, int *i);

void get_size(char *string, int *i, va_list aq);

void get_size_space(char *string, int *i, va_list aq);

int check_sign(char *string, int *i, va_list ap, va_list aq);

int manage_sign(char *string, int *i, va_list ap, va_list aq);

unsigned int convert_in_octal(unsigned int nb);

unsigned int convert_in_unsigned_bin(unsigned int nb);

unsigned int unsigned_function(unsigned int nb);

unsigned int unsigned_function_smallhex(unsigned int nb);

unsigned int unsigned_function_caphex(unsigned int nb);

int non_printable_char_function(char *str);

long hexa_function(long nb);

unsigned short modifier_my_put_nbr(unsigned short nb);

unsigned short modifier_unsigned_function(unsigned short nb);

unsigned short modifier_convert_in_octal(unsigned short nb);

unsigned short modifier_unsigned_function_smallhex(unsigned short nb);

unsigned short modifier_unsigned_function_caphex(unsigned short nb);

unsigned char modifier_my_put_nbr2(unsigned char nb);

unsigned char modifier_unsigned_function2(unsigned char nb);

unsigned char modifier_convert_in_octal2(unsigned char nb);

unsigned char modifier_unsigned_function_smallhex2(unsigned char nb);

unsigned char modifier_unsigned_function_caphex2(unsigned char nb);

unsigned long modifier_my_put_nbr3(unsigned long nb);

unsigned long modifier_unsigned_function3(unsigned long nb);

unsigned long modifier_convert_in_octal3(unsigned long nb);

unsigned long modifier_unsigned_function_smallhex3(unsigned long nb);

unsigned long modifier_unsigned_function_caphex3(unsigned long nb);

unsigned long long modifier_my_put_nbr4(unsigned long long nb);

unsigned long long modifier_unsigned_function4(unsigned long long nb);

unsigned long long modifier_convert_in_octal4(unsigned long long nb);

unsigned long long modifier_unsigned_function_smallhex4(unsigned long long nb);

unsigned long long modifier_unsigned_function_caphex4(unsigned long long nb);

#endif
