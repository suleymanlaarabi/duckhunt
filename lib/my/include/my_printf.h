/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** my_printf
*/

#ifndef INCLUDED_MY_PRINTF_H
    #define INCLUDED_MY_PRINTF_H
    #include <stdarg.h>
    #define ST_OR_NBR(x) (st_v != -1 ? st_v : my_getnbr(&params.specifier[x]))

// -- SECTION DEF --
typedef struct ca_params {
    char const *str;
    int *total;
    int *skip;
    char *specifier;
    int specifier_len;
} ca_params_t;

typedef void (*printer_func_t)(va_list args, ca_params_t params);
typedef void (*specifier_func_t)(ca_params_t params);

typedef struct {
    char *flag;
    printer_func_t func;
} flag_data_t;

typedef struct {
    char c;
    long value;
} padding_value_t;
// -- END SECTION --

// -- SECTION SPECIFIER FUNCTION --
int get_double_mag(double n);
void left_adjustement_specifier(ca_params_t params);
int specifier_not_has(ca_params_t params, char c);
int get_precision_specifier(ca_params_t params, va_list args);
padding_value_t get_padding_specifier(ca_params_t params);
// -- END SECTION --

// -- SECTION CORE FUNCTION --
int print_all_part(double n, int precision);
int get_plus_specifier(ca_params_t params);
void process_specifier(ca_params_t params);
void skip_check(ca_params_t params, va_list args);
int my_printf(char const *format, ...);
int validate_flag(
    char const *str,
    flag_data_t *flags,
    ca_params_t params,
    va_list args);
void skip_check(
    ca_params_t params,
    va_list args);
int dbl_percent_case(char const *str, int *skip);
short has_specifier(ca_params_t params);
void update_neg(int *number, int *is_neg);
padding_value_t get_padding_info(ca_params_t params, va_list args);
int get_space_count(
    padding_value_t *info,
    int number);
// -- END SECTION --

// -- SECTION PRINTER --
void print_hexa_upper(va_list args, ca_params_t params);
void print_char(va_list args, ca_params_t params);
void print_number(va_list args, ca_params_t params);
void print_str(va_list args, ca_params_t params);
void print_float(va_list args, ca_params_t params);
void print_long_number(va_list args, ca_params_t params);
void print_uint(va_list args, ca_params_t params);
void print_hexa(va_list args, ca_params_t params);
void print_long_hexa(va_list args, ca_params_t params);
void print_percent(va_list args, ca_params_t params);
void print_octal(va_list args, ca_params_t params);
void print_float_upper(va_list args, ca_params_t params);
void print_pointer(va_list args, ca_params_t params);
void print_exp(va_list args, ca_params_t params);
void print_exp_upper(va_list args, ca_params_t params);
void put_total(va_list args, ca_params_t params);
// -- END SECTION --

#endif
