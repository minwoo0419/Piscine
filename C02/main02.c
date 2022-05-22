#include "./ex00/ft_strcpy.c"
#include "./ex01/ft_strncpy.c"
#include "./ex02/ft_str_is_alpha.c"
#include "./ex03/ft_str_is_numeric.c"
#include "./ex04/ft_str_is_lowercase.c"
#include "./ex05/ft_str_is_uppercase.c"
#include "./ex06/ft_str_is_printable.c"
#include "./ex07/ft_strupcase.c"
#include "./ex08/ft_strlowcase.c"
#include "./ex09/ft_strcapitalize.c"
#include "./ex10/ft_strlcpy.c"
#include "./ex11/ft_putstr_non_printable.c"
#include "./ex12/ft_print_memory.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char			dest[100];
	char			dest1[100];
	char			dest2[100];
	char			dest3[100];
	char			*src;
	unsigned int	n1 = 15;
	unsigned int	n2 = 10;
	char			*str;
	char			str1[] = "abcdefghijklmnop";
	char			str2[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	unsigned char	addr[] = {0x42, 0x6f, 0x6e, 0x6a, 0x6f, 0x75, 0x72, 0x20, 0x6c, 0x65, 0x73, 0x20, 0x61, 0x6d, 0x69, 0x6e, 0x63, 0x68, 0x65, 0x73, 0x09, 0x0a, 0x09, 0x63, 0x20, 0x20, 0x65, 0x73, 0x74, 0x20, 0x66, 0x6f, 0x75, 0x09, 0x74, 0x6f, 0x75, 0x74, 0x09, 0x63, 0x65, 0x20, 0x71, 0x75, 0x20, 0x6f, 0x6e, 0x20, 0x70, 0x65, 0x75, 0x74, 0x20, 0x66, 0x61, 0x69, 0x72, 0x65, 0x20, 0x61, 0x76, 0x65, 0x63, 0x09, 0x0a, 0x09, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x0a, 0x0a, 0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00};

	src = "Hello World";
	printf("ex00\n");
	printf("%s\n", src);
	printf("%s\n", strcpy(dest2, src));
	printf("%s\n", ft_strcpy(dest, src));
	printf("ex01\n");
	printf("%s\n", src);
	printf("%s\n", ft_strncpy(dest1, src, n1));
	printf("%s\n", strncpy(dest3, src, n1));
	printf("ex02\n");
	str = "abcdefg";
	printf("%d\n", ft_str_is_alpha(str));
	str = "awef1";
	printf("%d\n", ft_str_is_alpha(str));
	printf("ex03\n");
	str = "121321123";
	printf("%d\n", ft_str_is_numeric(str));
	str = "12323sf23";
	printf("%d\n", ft_str_is_numeric(str));
	printf("ex04\n");
	str = "wefweew";
	printf("%d\n", ft_str_is_lowercase(str));
	str = "wefweAA3";
	printf("%d\n", ft_str_is_lowercase(str));
	printf("ex05\n");
	str = "ABCDEWF";
	printf("%d\n", ft_str_is_uppercase(str));
	str = "AEVEWwefw2";
	printf("%d\n", ft_str_is_uppercase(str));
	printf("ex06\n");
	str = "wefA23./";
	printf("%d\n", ft_str_is_printable(str));
	str = "wefew\n";
	printf("%d\n", ft_str_is_printable(str));
	printf("ex07\n");
	printf("%s\n", str1);
	printf("%s\n", ft_strupcase(str1));
	printf("ex08\n");
	printf("%s\n", str1);
	printf("%s\n", ft_strlowcase(str1));
	printf("ex09\n");
	printf("%s\n", str2);
	printf("%s\n", ft_strcapitalize(str2));
	printf("ex10\n");
	printf("%s\n", src);
	printf("%d\n", ft_strlcpy(dest2, src, n2));
	printf("%s\n", dest2);
	printf("ex11\n");
	str = "Coucou\ntu vas bien ?";
	printf("%s\n", str);
	ft_putstr_non_printable(str);
	printf("\nex12\n");
	ft_print_memory(addr, 92);
	return (0);
}
