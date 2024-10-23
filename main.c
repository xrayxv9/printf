#include "ft_printf.h"


int main()
{
	int c = -22222;
	int len;
	int	len2;

	len = ft_printf("f : %d\n", c);
	len2 = printf("p : %d\n", c);
	printf("len1 = %d, len 2 = %d", len, len2);
}
