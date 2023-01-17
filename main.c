#include "./ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("0x%p-", (void *)ULONG_MAX);
	printf("0x%p-", (void *)ULONG_MAX);
}
