/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __MY_MATH__
    #define __MY_MATH__
    #define MY_PI 3.14159265359
    #define RAD(x) (x * (MY_PI / 180.0))
    #define DEG(x) (x * (180.0 / MY_PI))
    #define MY_INFINITY (__builtin_inff())
    #define MY_SIGNBIT(x) __builtin_signbit(x)
    #define MY_ISNAN(x) __builtin_isnan(x)
    #define MY_ABS(x) (x > 0 ? x : -x)
    #define MY_IS_NEG(x) (x > 0 ? 0 : 1)


// -- SECTION DEF --
typedef struct {
    double value;
    long exp;
} exp_data_t;
// -- END SECTION --

// -- SECTION PROTOTYPE AVAILABLE --
long my_float_fact(int nb);
double my_float_power(double n, double p);
double my_sin(double x);
double my_cos(double x);
double my_float_modulo(double x, double y);
unsigned long round_number(unsigned long num, unsigned long round);
int count_dec_zero(double n);
int decimal_magnitude(double n);
unsigned long lpow10(unsigned long n);
unsigned long get_dec(double n);
double round_double(double n, int round);
// -- END SECTION --

#endif
