/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __LIB_MY__
    #define __LIB_MY__
    #define UNUSED(x) (void)(x)
    #include "my_getnbr.h"
    #include <stdbool.h>

int get_and_write(char *path);
void my_str_each_line(char *str, void (*func)(char *, char *), char *include);
typedef struct start_end_info {
    int start;
    int end;
} start_end_info_t;
start_end_info_t my_str_include(char const *src, char const *str);
detect_info_t get_info(char const *str);
short is_alpha(char c);
struct info_param {
    int length;
    char *str;
    char *copy;
    char **word_array;
};
int get_color(
    unsigned char red,
    unsigned char green,
    unsigned char blue);
struct info_param *my_params_to_array(int ac, char **av);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char *const *tab);
char *concat_params(int argc, char **argv);
char *my_strdup(char const *src);
long int rev_nbr(long int n, long int factor);
int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(long n);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putline(char const *str);
int my_strlen(char const *str);
long my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int print_count(int n, char c);
unsigned long long my_compute_power_rec(
    unsigned long long nb, unsigned long long p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_compute_factorial_it(int nb);
int my_compute_factorial_rec(int nb);
int my_compute_power_it(int n, int p);
unsigned long my_compute_lpow(unsigned long n, unsigned long p);
short detect_neg(char n, short *is_neg);
short detect_number(char n);
unsigned long count_zero(unsigned long n);
long int my_pow(long int n, long int p);
int count_word(char const *str);
short detect_alphanum(char c);
int is_num(char c);
int my_str_include_before(
    char const *src,
    char const *str,
    char before);
bool my_str_include_char(char const *src, char c);
char *my_strndup(char const *src, int n);
char *my_strcat_nobuffer(const char *str1, const char *str2);
char *my_strcat_nobuffer_sep(const char *str1, const char *str2, char sep);
char *int_to_str(long n);

#endif
