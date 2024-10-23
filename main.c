#include "ft_printf.h"


int main()
{
	int c = 42;
	int len;
	int	len2;

	len = ft_printf("j'aime le %d\n", c);
	len2 = printf("j'aime le %d\n", c);
	printf("len1 = %d, len 2 = %d", len, len2);
}
