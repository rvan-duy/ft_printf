#include "ft_printf.h"

void print_struct(parameters input)
{
    printf("\n* --- STRUCT PARAMETERS --- *\n");
    printf("* len: %d\n", input.len);
    printf("* str: (%s)\n", input.str);
    printf("* flag_minus: %d\n", input.flag_minus);
    printf("* flag_zero: %d\n", input.flag_zero);
    printf("* width: %d\n", input.width);
    printf("* precision: %d\n", input.precision);
    printf("* specifier: %c\n", input.specifier);
    printf("* --- END OF STRUCT --- *\n");
}