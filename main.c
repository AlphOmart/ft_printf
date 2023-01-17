#include "./ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	ft_printf("0x%p-\n", (void *)ULONG_MAX);
	printf("0x%p-\n", (void *)ULONG_MAX);
}
