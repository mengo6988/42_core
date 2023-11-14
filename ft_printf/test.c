#include "ft_printf.h"

int main(void)
{
	printf("main\n");
	printf("%-5x\n", 20);
	printf("%-#5x\n", 20);
	printf("test\n");
	ft_printf("%-5x\n", 20);
	ft_printf("%-#5x\n", 20);
	return (0);
}
