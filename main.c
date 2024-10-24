#include "ft_printf.h"


int main()
{
	char *c = NULL;
	int len;
	int	len2;

	len = ft_printf("f : % p\n", c);
	len2 = printf("p : % p\n", c);
	printf("len1 = %d, len 2 = %d", len, len2);
}
