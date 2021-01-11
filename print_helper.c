#include "ft_printf.h"

void print_struct(parameters input)
{
    printf("* --- STRUCT PARAMETERS --- *\n");
    printf("* len: %d\n", input.len);
    printf("* str: (%s)\n", input.str);
    printf("* flags: (%s)\n", input.flags);
    printf("* width: %d\n", input.width);
    printf("* precision: %d\n", input.precision);
    printf("* specifier: %c\n", input.specifier);
}