#include "main.h"

/**
 * _printf - prints and input into standard output
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
int sum = 0;
va_list ap;
char *p, *start;

params_t params = PARAMS_INIT;

va_start(ap, format);

/* checking for NULL char */
if (!format || (format[0] == '%' && !format[1]))
{
return (-1);
}
if (format[0] == '%' && format[1] == ' ' && !format[2])
{
return (-1);
}
for (p = (char *)format; *p; p++)
{
init_params(&params, ap);

/*check for the % specifier */
if (*p != '%')
{
sum += putchar(*p);
continue;
}
start = p;
p++;

/*flag character while char at p*/
while (get_flag(p, &params))
{
p++;
}
p = get_width(p, &params, ap);
p = get_precision(p, &params, ap);
if (get_modifier(p, &params))
{
p++;
}
if (!get_specifier(p))
{
sum += print_from_to(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
}
else
{
sum += get_print_func(p, ap, &params);
}
}
putchar(BUF_FLUSH);
va_end(ap);
return (sum);
}
