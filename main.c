#include "ft_printf.h"

int main()
{
	int i = 110923;
	char c = 'a';
	char *ptr = &c;
	char *s = "It's getting somewhere :)";
	int hex = -123456789;

	ft_printf("%d\n", ft_printf("%d: Adress of char %c: %p\n%d in lowercase hexadecimal: %x\n%d in uppercase hexadecimal: %X\n%s\n", i ,c, ptr, hex, hex, hex, hex, s));
	printf("%d\n", printf("%d: Adress of char %c: %p\n%d in lowercase hexadecimal: %x\n%d in uppercase hexadecimal: %X\n%s\n", i ,c, ptr, hex, hex, hex, hex, s));
	return(0);
}
