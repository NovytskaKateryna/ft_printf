/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:34:39 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/24 15:34:41 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "includes/ft_printf.h" 
#include <limits.h>
#include <signal.h>
#include <wchar.h>
#include <locale.h>
#include <fcntl.h>
#include "libft/libft.h"

// static void pointer_valueLargerThanMinWidth_zeroFlag()
// {
// 	int my_ret;
// 	int f_ret;
	
// 	my_ret = ft_printf("{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);
// 	f_ret = printf("{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
// }

int	main(int ac, char **av)
{
	int my_ret;
	int f_ret;
	void *ch;
	// 

	// fd = open(av[1], O_RDONLY);
	// while (get_next_line(fd, &line))
	// 	ft_printf("%s\n", line);

 	
	setlocale(LC_ALL, "");                       //sets or reads location dependent information.
	ch = (void*)malloc(sizeof(void));            
//	printf("\nMY PRINTF:\n");
	// printf("negative digits:\n");
	// my_ret = ft_printf("12d:    |%12i|", -45);
	// printf("    12d:    |%12i|\n", -45);
	// my_ret = ft_printf("012d:   |%012i|", -45);
	// printf("    012d:   |%012i|\n", -45);
	// my_ret = ft_printf(" 012d:  |% 012i|", -45);
	// printf("     012d:  |% 012i|\n", -45);
	// my_ret = ft_printf("+12d:   |%+12d|", -45);
	// printf("    +12d:   |%+12d|\n", -45);
	// my_ret = ft_printf("+012d:  |%+012d|", -45);
	// printf("    +012d:  |%+012d|\n", -45);
	// my_ret = ft_printf("-12d:   |%-12d|", -45);
	// printf("    -12d:   |%-12d|\n", -45);
	// my_ret = ft_printf("- 12d:  |%- 12d|", -45);
	// printf("    - 12d:  |%- 12d|\n", -45);
	// my_ret = ft_printf("-+12d:  |%-+12d|", -45);
	// printf("    -+12d:  |%-+12d|\n", -45);
	// my_ret = ft_printf("12.4d:  |%12.4d|", -45);
	// printf("    12.4d:  |%12.4d|\n", -45);
	// my_ret = ft_printf("-12.4d: |%-12.4d|", -45);
	// printf("    -12.4d: |%-12.4d|\n", -45);
	
	// printf("positive digits:\n");
	// my_ret = ft_printf("12d:    |%12d|", 45);
	// printf("    12d:    |%12d|\n", 45);
	// my_ret = ft_printf("012d:   |%012d|", 45);
	// printf("    012d:   |%012d|\n", 45);
	// my_ret = ft_printf(" 012d:  |% 012d|", 45);
	// printf("     012d:  |% 012d|\n", 45);
	// my_ret = ft_printf("+12d:   |%+12d|", 45);
	// printf("    +12d:   |%+12d|\n", 45);
	// my_ret = ft_printf("+012d:  |%+012d|", 45);
	// printf("    +012d:  |%+012d|\n", 45);
	// my_ret = ft_printf("-12d:   |%-12d|", 45);
	// printf("    -12d:   |%-12d|\n", 45);
	// my_ret = ft_printf("- 12d:  |%- 12d|", 45);
	// printf("    - 12d:  |%- 12d|\n", 45);
	// my_ret = ft_printf("-+12d:  |%-+12d|", 45);
	// printf("    -+12d:  |%-+12d|\n", 45);
	// my_ret = ft_printf("12.4d:  |%12.4d|", 45);
	// printf("    12.4d:  |%12.4d|\n", 45);
	// my_ret = ft_printf("-12.4d: |%-12.4d|", 45);
	// printf("    -12.4d: |%-12.4d|\n", 45);

	// printf("\nMY PRINTF:\n");
	// printf("negative digits:\n");
	// my_ret = ft_printf("14u:    |%14u|", -45);
	// printf("    14u:    |%14u|\n", -45);
	// my_ret = ft_printf("014u:   |%014u|", -45);
	// printf("    014u:   |%014u|\n", -45);
	// my_ret = ft_printf("#14u:  	|%#14u|", -45);
	// printf("    #14u:   |%#14u|\n", -45);
	// my_ret = ft_printf("#014u:  |%#014u|", -45);
	// printf("    #014u:  |%#014u|\n", -45);
	// my_ret = ft_printf("-14u:  	|%-14u|", -45);
	// printf("    -14u:   |%-14u|\n", -45);
	// my_ret = ft_printf("-#14u:  |%-#14u|", -45);
	// printf("    -#14u:  |%-#14u|\n", -45);
	// my_ret = ft_printf("14.4u:  |%14.4u|", -45);
	// printf("    14.4u:  |%14.4u|\n", -45);
	// my_ret = ft_printf("-14.4u: |%-14.4u|", -45);
	// printf("    -14.4u: |%-14.4u|\n", -45);
	
	// printf("positive digits:\n");
	// my_ret = ft_printf("14u:    |%14u|", 45);
	// printf("    14u:    |%14u|\n", 45);
	// my_ret = ft_printf("014u:   |%014u|", 45);
	// printf("    014u:   |%014u|\n", 45);
	// my_ret = ft_printf("#14u:  	|%#14u|", 45);
	// printf("    #14u:   |%#14u|\n", 45);
	// my_ret = ft_printf("#014u:  |%#014u|", 45);
	// printf("    #014u:  |%#014u|\n", 45);
	// my_ret = ft_printf("-14u:  	|%-14u|", 45);
	// printf("    -14u:   |%-14u|\n", 45);
	// my_ret = ft_printf("-#14u:  |%-#14u|", 45);
	// printf("    -#14u:  |%-#14u|\n", 45);
	// my_ret = ft_printf("14.4u:  |%14.4u|", 45);
	// printf("    14.4u:  |%14.4u|\n", 45);
	// my_ret = ft_printf("-14.4u: |%-14.4u|", 45);
	// printf("    -14.4u: |%-14.4u|\n", 45);

	// printf("\nMY PRINTF:\n");
	// printf("positive digits:\n");
	// my_ret = ft_printf("14o:    |%14o|", 45);
	// printf("    14o:    |%14o|\n", 45);
	// my_ret = ft_printf("014o:   |%014o|", 45);
	// printf("    014o:   |%014o|\n", 45);
	// my_ret = ft_printf("#14o:  	|%#14o|", 45);
	// printf("    #14o:   |%#14o|\n", 45);
	// my_ret = ft_printf("#014o:  |%#014o|", 45);
	// printf("    #014o:  |%#014o|\n", 45);
	// my_ret = ft_printf("-14o:  	|%-14o|", 45);
	// printf("    -14o:   |%-14o|\n", 45);
	// my_ret = ft_printf("-#14o:  |%-#14o|", 45);
	// printf("    -#14o:  |%-#14o|\n", 45);
	// my_ret = ft_printf("14.4o:  |%14.4o|", 45);
	// printf("    14.4o:  |%14.4o|\n", 45);
	// my_ret = ft_printf("-#14.4o:|%-#14.4o|", 45);
	// printf("    -#14.4o:|%-#14.4o|\n", 45);

	// printf("negative digits:\n");
	// my_ret = ft_printf("14o:    |%14o|", -45);
	// printf("    14o:    |%14o|\n", -45);
	// my_ret = ft_printf("014o:   |%014o|", -45);
	// printf("    014o:   |%014o|\n", -45);
	// my_ret = ft_printf("#14o:  	|%#14o|", -45);
	// printf("    #14o:   |%#14o|\n", -45);
	// my_ret = ft_printf("#014o:  |%#014o|", -45);
	// printf("    #014o:  |%#014o|\n", -45);
	// my_ret = ft_printf("-14o:  	|%-14o|", -45);
	// printf("    -14o:   |%-14o|\n", -45);
	// my_ret = ft_printf("-#14o:  |%-#14o|", -45);
	// printf("    -#14o:  |%-#14o|\n", -45);
	// my_ret = ft_printf("14.4o:  |%14.4o|", -45);
	// printf("    14.4o:  |%14.4o|\n", -45);
	// my_ret = ft_printf("-#14.4o:|%-14.4o|", -45);
	// printf("    -#14.4o:|%-14.4o|\n", -45);

	// printf("\nMY PRINTF:\n");
	// printf("positive digits:\n");
	// my_ret = ft_printf("12x:    |%12x|", 45);
	// printf("    12x:    |%12x|\n", 45);
	// my_ret = ft_printf("012x:   |%012x|", 45);
	// printf("    012x:   |%012x|\n", 45);
	// my_ret = ft_printf("#12X:  	|%#12X|", 45);
	// printf("    #12X:   |%#12X|\n", 45);
	// my_ret = ft_printf("#012X:  |%#012X|", 45);
	// printf("    #012X:  |%#012X|\n", 45);
	// my_ret = ft_printf("-12x:  	|%-12x|", 45);
	// printf("    -12x:   |%-12x|\n", 45);
	// my_ret = ft_printf("-#12x:  |%-#12x|", 45);
	// printf("    -#12x:  |%-#12x|\n", 45);
	// my_ret = ft_printf("12.4x:  |%12.4x|", 45);
	// printf("    12.4x:  |%12.4x|\n", 45);
	// my_ret = ft_printf("-#12.4x:|%-#12.4x|", 45);
	// printf("    -#12.4x:|%-#12.4x|\n", 45);

	// printf("negative digits:\n");
	// my_ret = ft_printf("12x:    |%12x|", -45);
	// printf("    12x:    |%12x|\n", -45);
	// my_ret = ft_printf("012x:   |%012x|", -45);
	// printf("    012x:   |%012x|\n", -45);
	// my_ret = ft_printf("#12X:  	|%#12X|", -45);
	// printf("    #12X:   |%#12X|\n", -45);
	// my_ret = ft_printf("#012X:  |%#012X|", -45);
	// printf("    #012X:  |%#012X|\n", -45);
	// my_ret = ft_printf("-12x:  	|%-12x|", -45);
	// printf("    -12x:   |%-12x|\n", -45);
	// my_ret = ft_printf("-#12x:  |%-#12x|", -45);
	// printf("    -#12x:  |%-#12x|\n", -45);
	// my_ret = ft_printf("12.4x:  |%12.4x|", -45);
	// printf("    12.4x:  |%12.4x|\n", -45);
	// my_ret = ft_printf("-#12.4x:|%-#12.4x|", -45);
	// printf("    -#12.4x:|%-#12.4x|\n", -45);


	// printf("\nMY PRINTF:\n");
	// printf("chars:\n");
	// my_ret = ft_printf("12c:    |%12c|", '*');
	// printf("    12c:    |%12c|\n", '*');
	// my_ret = ft_printf("012c:   |%012c|", '*');
	// printf("    012c:   |%012c|\n", '*');
	// my_ret = ft_printf("-12c:  	|%-12c|", '*');
	// printf("    -12c:   |%-12c|\n", '*');

	// printf("\nMY PRINTF:\n");
	// printf("strings:\n");
	// my_ret = ft_printf("12s:    |%12s|", "longish");
	// printf("    12s:    |%12s|\n", "longish");
	// my_ret = ft_printf("012s:   |%012s|", "longish");
	// printf("    012s:   |%012s|\n", "longish");
	// my_ret = ft_printf("-12s:  	|%-12s|", "longish");
	// printf("    -12s:   |%-12s|\n", "longish");
	// my_ret = ft_printf("12.5s:  |%12.5s|", "longish");
	// printf("    12.5s:  |%12.5s|\n", "longish");

	// printf("\nMY PRINTF:\n");
	// printf("strings:\n");
	// my_ret = ft_printf("p:    |%p|", ch);
	// printf("    p:    |%p|\n", ch);


	// printf("\nMY PRINTF:\n");
	// my_ret = ft_printf("ldld:  |%ld%ld|", 0, 42);
	// printf("                          ldld:  |%ld%ld|\n", 0, 42);
	// my_ret = ft_printf("ld:    |%ld|", (long)INT_MAX + 1);
	// printf("                   ld:    |%ld|\n", (long)INT_MAX + 1);
	// my_ret = ft_printf("ld:    |%ld|", (long)INT_MIN - 1);
	// printf("                  ld:    |%ld|\n", (long)INT_MIN - 1);
	// my_ret = ft_printf("ld:    |%ld|", LONG_MAX);
	// printf("          ld:    |%ld|\n", LONG_MAX);
	// my_ret = ft_printf("ld:    |%ld|", LONG_MIN);
	// printf("         ld:    |%ld|\n", LONG_MIN);
	// my_ret = ft_printf("lili:  |%li%li|", 0, 42);
	// printf("                          lili:  |%li%li|\n", 0, 42);
	// my_ret = ft_printf("li:    |%li|", (long)INT_MAX + 1);
	// printf("                   li:    |%li|\n", (long)INT_MAX + 1);
	// my_ret = ft_printf("li:    |%li|", (long)INT_MIN - 1);
	// printf("                  li:    |%li|\n", (long)INT_MIN - 1);
	// my_ret = ft_printf("li:    |%li|", LONG_MAX);
	// printf("          li:    |%li|\n", LONG_MAX);
	// my_ret = ft_printf("li:    |%li|", LONG_MIN);
	// printf("         li:    |%li|\n", LONG_MIN);
	// my_ret = ft_printf("lu,lu: |%lu, %lu|", 0, ULONG_MAX);
	// printf("      lu,lu: |%lu, %lu|\n", 0, ULONG_MAX);
	// my_ret = ft_printf("lo,lo: |%lo, %lo|", 0, ULONG_MAX);
	// printf("    lo,lo: |%lo, %lo|\n", 0, ULONG_MAX);
	// my_ret = ft_printf("lx,lx: |%lx, %lx|", 0, ULONG_MAX);
	// printf("          lx,lx: |%lx, %lx|\n", 0, ULONG_MAX);
	// my_ret = ft_printf("lX,lX: |%lX, %lX|", 0, ULONG_MAX);
	// printf("          lX,lX: |%lX, %lX|\n", 0, ULONG_MAX);

	// my_ret = ft_printf("lc,lc: |%C, %C|", L'暖', L'ح');
	// printf("              lc,lc: |%C, %C|\n", L'暖', L'ح');
	// my_ret = ft_printf("ls,ls: |%ls, %ls|", L"暖炉", L"لحم خنزير");
	// printf("    ls,ls: |%ls, %ls|\n", L"暖炉", L"لحم خنزير");

	//my_ret = ft_printf("%ls\n", L"пріветікі!");

	// my_ret = ft_printf("lO,lO: |%lO, %lO|", 0, USHRT_MAX);
	// printf("    lO,lO; |%lO, %lO|\n", 0, USHRT_MAX);
	// my_ret = ft_printf("lU,lU: |%lU, %lU|", 0, USHRT_MAX);
	// printf("    lU,lU: |%lU, %lU|\n", 0, USHRT_MAX);
	// my_ret = ft_printf("lD,lD: |%lD, %lD|", 0, USHRT_MAX);
	// printf("    lD,lD: |%lD, %lD|\n", 0, USHRT_MAX);

	//01
	// my_ret = ft_printf("%s", "abc");
	// printf("          %s\n", "abc");
	// my_ret = ft_printf("|111%s333|", "222");
	// f_ret = printf("|111%s333|\n", "222");
	//printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%s333", "222");
	// printf("       %s333\n", "222");
	// my_ret = ft_printf("111%s", "222");
	// f_ret = printf("111%s", "222");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|{%s}|", 0);
	// f_ret = printf("|{%s}|", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|{%s}|", "");
	// f_ret = printf("|{%s}|", "");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//02
	// my_ret = ft_printf("111%s333%s555", "222", "444");
	// printf("       111%s333%s555\n", "222", "444");
	// my_ret = ft_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	// printf("       111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	// my_ret = ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	// printf("       %s%s%s%s%s\n", "1", "2", "3", "4", "5");

	//03
	// my_ret = ft_printf("%d", 42);
	// printf("     %d\n", 42);
	// my_ret = ft_printf("%d", -42);
	// printf("     %d\n", -42);
	// my_ret = ft_printf("before %d after", 42);
	// printf("     before %d after\n", 42);
	// my_ret = ft_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	// printf("     %d%d%d%d%d\n", 1, -2, 3, -4, 5);
	// my_ret = ft_printf("a%db%dc%dd", 1, -2, 3);
	// printf("     a%db%dc%dd\n", 1, -2, 3);
	// my_ret = ft_printf("%d", INT_MAX);
	// printf("     %d\n", INT_MAX);
	// my_ret = ft_printf("%d", INT_MIN);
	// printf("     %d\n", INT_MIN);

	//04
	// int i;
	// unsigned long l;
	// char *str;

	// my_ret = ft_printf("%p", &i);
	// f_ret = printf("%p\n", &i);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%p", &l);
	// f_ret = printf("%p\n", &l);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%p", &str);
	// f_ret = printf("%p\n", &str);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%p", &strlen);
	// f_ret = printf("%p\n", &strlen);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%p", 0);
	// f_ret = printf("%p\n", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//05
	// my_ret = ft_printf("%%");
	// printf("    %%\n");
	// my_ret = ft_printf("aa%%bb");
	// printf("    aa%%bb\n");
	// my_ret = ft_printf("%%%%%%%%%%");
	// printf("    %%%%%%%%%%\n");
	// my_ret = ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	// printf("    .%%.%%.%%.%%.%%.%%.%%.%%.\n");
	// my_ret = ft_printf("%");
	// printf("    % \n");
	// my_ret = ft_printf("% Zoooo");
	// f_ret = printf("% Zoooo");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%}");
	// printf("    {%}\n");
	// my_ret = ft_printf("{% %}");
	// f_ret = printf("{% %}");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//06
	// my_ret = ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	// f_ret = printf("%s%p%d%d%p%s%p%p%s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//07
	// my_ret = ft_printf("%S", L"米");
	// f_ret = printf("%S", L"米");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%S", L"我是一只猫。");
	// f_ret = printf("%S", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	// L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	// f_ret = printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	// L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|a%Sb%sc%S|", L"我", "42", L"猫");
	// f_ret = printf("|a%Sb%sc%S|", L"我", "42", L"猫");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%S}", NULL);
	// printf("       {%S}\n", NULL);

	//08
	// my_ret = ft_printf("%D", 0L);
	// printf("     %D\n", 0L);
	// my_ret = ft_printf("%D", 1L);
	// printf("     %D\n", 1L);
	// my_ret = ft_printf("%D", -1L);
	// printf("     %D\n", -1L);
	// my_ret = ft_printf("%D", 42L);
	// printf("     %D\n", 42L);
	// my_ret = ft_printf("%D", LONG_MAX);
	// printf("     %D\n", LONG_MAX);
	// my_ret = ft_printf("%D", LONG_MIN);
	// printf("     %D\n", LONG_MIN);
	// my_ret = ft_printf("Coucou les %D!", 42);
	// printf("     Coucou les %D!\n", 42);

	//09
	// my_ret = ft_printf("%i", 42);
	// printf("    %i\n", 42);
	// my_ret = ft_printf("%i", -42);
	// printf("    %i\n", -42);
	// my_ret = ft_printf("before %i after", 42);
	// printf("    before %i after\n", 42);
	// my_ret = ft_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	// printf("    %i%i%i%i%i\n", 1, -2, 3, -4, 5);
	// my_ret = ft_printf("a%ib%ic%id", 1, -2, 3);
	// printf("    a%ib%ic%id\n", 1, -2, 3);
	
	//10
	// my_ret = ft_printf("%o", 42);
	// printf("        %o\n", 42);
	// my_ret = ft_printf("before %o after", 42);
	// printf("        before %o after\n", 42);
	// my_ret = ft_printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
	// printf("       %o%o%o%o%o\n", 1, 100, 999, 42, 999988888);
	// my_ret = ft_printf("a%ob%oc%od", 0, 55555, 100000);
	// printf("       a%ob%oc%od\n", 0, 55555, 100000);

	//11
	// my_ret = ft_printf("%O", 42);
	// printf("     %O\n", 42);
	// my_ret = ft_printf("before %O after", 42);
	// printf("     before %O after\n", 42);
	// my_ret = ft_printf("%O%O%O%O%O", 1, 100, 999, 42, 999988888);
	// printf("     %O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
	// my_ret = ft_printf("a%Ob%Oc%Od", 0, 55555, 100000);
	// printf("      a%Ob%Oc%Od\n", 0, 55555, 100000);
	// my_ret = ft_printf("%O", LONG_MAX);
	// printf("     %O\n", LONG_MAX);

	//12
	// my_ret = ft_printf("%u", 42);
	// printf("   %u\n", 42);
	// my_ret = ft_printf("before %u after", 42);
	// printf("   before %u after\n", 42);
	// my_ret = ft_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	// printf("   %u%u%u%u%u\n", 1, 100, 999, 42, 999988888);
	// my_ret = ft_printf("a%ub%uc%ud", 0, 55555, 100000);
	// printf("   a%ub%uc%ud\n", 0, 55555, 100000);
	// my_ret = ft_printf("%u", UINT_MAX);
	// printf("   %u\n", UINT_MAX);

	//13
	// my_ret = ft_printf("%U", 42);
	// printf("   %U\n", 42);
	// my_ret = ft_printf("%U", ULONG_MAX / 2);
	// printf("   %U\n", ULONG_MAX / 2);
	// my_ret = ft_printf("%U", ULONG_MAX);
	// printf("   %U\n", ULONG_MAX);

	//14
	// my_ret = ft_printf("%x", 42);
	// printf("   %x\n", 42);
	// my_ret = ft_printf("before %x after", 42);
	// printf("   before %x after\n", 42);
	// my_ret = ft_printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	// printf("   %x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	// my_ret = ft_printf("a%xb%xc%xd", 0, 55555, 100000);
	// printf("   a%xb%xc%xd\n", 0, 55555, 100000);
	// my_ret = ft_printf("%x, %x", 0, UINT_MAX);
	// printf("   %x, %x\n", 0, UINT_MAX);

	//15
	// my_ret = ft_printf("%X", 42);
	// printf("    %X\n", 42);
	// my_ret = ft_printf("before %X after", 42);
	// printf("    before %X after\n", 42);
	// my_ret = ft_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	// printf("    %X%X%X%X%X\n", 1, 100, 999, 42, 999988888);
	// my_ret = ft_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	// printf("     a%Xb%Xc%Xd\n", 0, 55555, 100000);
	// my_ret = ft_printf("%X, %X", 0, UINT_MAX);
	// printf("     %X, %X\n", 0, UINT_MAX);

	//16
// 	my_ret = ft_printf("%c", 'c');
// 	printf("    %c\n", 'c');
// 	my_ret = ft_printf("%c%c", '4', '2');
// 	printf("    %c%c\n", '4', '2');
// 	my_ret = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// 		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}');
// 	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// 		%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}');
	// my_ret = ft_printf("%c", 0);
	// f_ret = printf("%c", 0);
	//printf("my_ret->%i f_rt->%i\n", my_ret, f_ret);

	//17
// 	my_ret = ft_printf("%C", 'c');
// 	f_ret = printf("		%C\n", 'c');
// 	my_ret = ft_printf("%C%C", '4', '2');
// 	f_ret = printf("		%C%C\n", '4', '2');
// 	my_ret = ft_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
// %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
// %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
// 	f_ret = printf("		%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
// %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
// %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\n",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
// 	my_ret = ft_printf("%C", L'猫');
// 	f_ret = printf("%C\n", L'猫');
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
// 	my_ret = ft_printf("%C", L'δ');
// 	f_ret = printf("%C\n", L'δ');
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
// 	my_ret = ft_printf("%C", L'요');
// 	f_ret = printf("%C\n", L'요');
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
// 	my_ret = ft_printf("%C", L'莨');
// 	f_ret = printf("%C\n", L'莨');
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
// 	my_ret = ft_printf("|%C|", L'ي');
// 	f_ret = printf("|%C|\n", L'ي');
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
// 	my_ret = ft_printf("%C", 0);
// 	f_ret = printf("%C\n", 0);
// 	printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);


	//18
	char c;
	// my_ret = ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	// printf("		%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	// my_ret = ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	// f_ret = printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);


	//40
	// my_ret = ft_printf("%ld%ld", 0, 42);
	// f_ret = printf("%ld%ld", 0, 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	//41
	// my_ret = ft_printf("%lld%lld", 0, 42);
	// f_ret = printf("     %lld%lld\n", 0, 42);
	// my_ret = ft_printf("%lld", LLONG_MAX);
	// f_ret = printf("      %lld\n", LLONG_MAX);
	// my_ret = ft_printf("%lld", LLONG_MIN);
	// f_ret = printf("      %lld\n", LLONG_MIN);
	// my_ret = ft_printf("%lli%lli", 0, 42);
	// f_ret = printf("     %lli%lli\n", 0, 42);
	// my_ret = ft_printf("%lli", LLONG_MAX);
	// f_ret = printf("      %lli\n", LLONG_MAX);
	// my_ret = ft_printf("%lli", LLONG_MIN);
	// f_ret = printf("      %lli\n", LLONG_MIN);
	// my_ret = ft_printf("%llu, %llu", 0, ULLONG_MAX);
	// f_ret = printf("     %llu, %llu\n", 0, ULLONG_MAX);
	// my_ret = ft_printf("%llo, %llo", 0, ULLONG_MAX);
	// f_ret = printf("       %llo, %llo\n", 0, ULLONG_MAX);
	// my_ret = ft_printf("%llx, %llx", 0, ULLONG_MAX);
	// f_ret = printf("       %llx, %llx\n", 0, ULLONG_MAX);
	// my_ret = ft_printf("%llX, %llX", 0, ULLONG_MAX);
	// f_ret = printf("      %llX, %llX\n", 0, ULLONG_MAX);
	// my_ret = ft_printf("%llO, %llO", 0, USHRT_MAX);
	// f_ret = printf("      %llO, %llO\n", 0, USHRT_MAX);
	// my_ret = ft_printf("%llU, %llU", 0, USHRT_MAX);
	// f_ret = printf("      %llU, %llU\n", 0, USHRT_MAX);
	// my_ret = ft_printf("%llD, %llD", 0, USHRT_MAX);
	// f_ret = printf("   %llD, %llD\n", 0, USHRT_MAX);


	//43
	// my_ret = ft_printf("|%jd%jd|", 0, 42);
	// printf("|%jd%jd|\n", 0, 42);
	// my_ret = ft_printf("|%jd|", LLONG_MAX);
	// printf("|%jd|\n", LLONG_MAX);
	// my_ret = ft_printf("|%jd|", LLONG_MIN);
	// printf("|%jd|\n", LLONG_MIN);
	// my_ret = ft_printf("|%ji%ji|", 0, 42);
	// printf("|%ji%ji|\n", 0, 42);
	// my_ret = ft_printf("|%ji|", LLONG_MAX);
	// printf("|%ji|\n", LLONG_MAX);
	// my_ret = ft_printf("|%ji|", LLONG_MIN);
	// printf("|%ji|\n", LLONG_MIN);
	// my_ret = ft_printf("|%ju, %ju|", 0, ULLONG_MAX);
	// printf("|%ju, %ju|\n", 0, ULLONG_MAX);
	// my_ret = ft_printf("|%jo, %jo|", 0, ULLONG_MAX);
	// printf("|%jo, %jo|\n", 0, ULLONG_MAX);
	// my_ret = ft_printf("|%jx, %jx|", 0, ULLONG_MAX);
	// printf("|%jx, %jx|\n", 0, ULLONG_MAX);
	// my_ret = ft_printf("|%jX, %jX|", 0, ULLONG_MAX);
	// f_ret = printf("|%jX, %jX|\n", 0, ULLONG_MAX);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%jO, %jO|", 0, USHRT_MAX);
	// printf("|%jO, %jO|\n", 0, USHRT_MAX);
	// my_ret = ft_printf("|%jU, %jU|", 0, USHRT_MAX);
	// printf("|%jU, %jU|\n", 0, USHRT_MAX);
	// my_ret = ft_printf("|%jD, %jD|", 0, USHRT_MAX);
	// printf("|%jD, %jD|\n", 0, USHRT_MAX);


	//50
	// my_ret = ft_printf("{%10d}", 42);
	// f_ret = printf("    {%10d}\n", 42);
	// my_ret = ft_printf("{%4d}", 10000);
	// f_ret = printf("    {%4d}\n", 10000);
	// my_ret = ft_printf("{%30d}", 10000);
	// f_ret = printf("    {%30d}\n", 10000);
	// my_ret = ft_printf("{%10d}", -42);
	// f_ret = printf("    {%10d}\n", -42);
	// my_ret = ft_printf("{%3c}", 0);
	// f_ret = printf("{%3c}", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%5p}", 0);
	// f_ret = printf("	{%5p}\n", 0);
	// my_ret = ft_printf("{%-15p}", 0);
	// f_ret = printf("	{%-15p}\n", 0);
	// my_ret = ft_printf("{%-13p}", &strlen);
	// f_ret = printf("	{%-13p}\n", &strlen);
	// my_ret = ft_printf("{%-12p}", &strlen);
	// f_ret = printf("	{%-12p}\n", &strlen);
	// my_ret = ft_printf("{%10R}");
	// f_ret = printf("	{%10R}\n");
	// my_ret = ft_printf("{%S}", L"我是一只猫。");
	// f_ret = printf("{%S}\n", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%030S}", L"我是一只猫。");
	// f_ret = printf("{%030S}\n", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%-30S}", L"我是一只猫。");
	// f_ret = printf("{%-30S}\n", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//52
	// my_ret = ft_printf("{%010d}", 42);
	// printf("{%010d}\n", 42);
	// my_ret = ft_printf("{%010d}", -42);
	// printf("{%010d}\n", -42);
	// my_ret = ft_printf("{%04d}", 10000);
	// printf("{%04d}\n", 10000);
	// my_ret = ft_printf("{%030d}", 10000);
	// printf("{%030d}\n", 10000);
	// my_ret = ft_printf("{%030x}", 0xFFFF);
	// printf("{%030x}\n", 0xFFFF);
	// my_ret = ft_printf("{%030X}", 0xFFFF);
	// f_ret = printf("{%030X}\n", 0xFFFF);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%03c}", 0);
	// f_ret = printf("{%03c}\n", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%05s}", "abc");
	// f_ret = printf("{%05s}\n", "abc");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%030S}", L"我是一只猫。");
	// f_ret = printf("{%030S}\n", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("{%05p}", 0);
	// f_ret = printf("{%05p}\n", 0);
	//printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	//pointer_valueLargerThanMinWidth_zeroFlag();

	//53
	// my_ret = ft_printf("{%-15Z}", 123);
	// f_ret = printf("{%-15Z}", 123);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	// //60
	// my_ret = ft_printf("%#o", 42);
	// f_ret = printf("%#o\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#o", 0);
	// f_ret = printf("%#o\n", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#o", INT_MAX);
	// f_ret = printf("%#o\n", INT_MAX);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#O", 1);
	// f_ret = printf("%#O\n", 1);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#x", 42);
	// f_ret = printf("%#x\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#x", 0);
	// f_ret = printf("%#x\n", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#x", INT_MAX);
	// f_ret = printf("%#x\n", INT_MAX);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#X", 42);
	// f_ret = printf("%#X\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#X", 0);
	// f_ret = printf("%#X\n", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#X", INT_MAX);
	// f_ret = printf("%#X\n", INT_MAX);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("%#c", 0);
	// f_ret = printf("%#c\n", 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//61
	// my_ret = ft_printf("%+d", 42);
	// f_ret = printf("     %+d\n", 42);
	// my_ret = ft_printf("%+d", -42);
	// f_ret = printf("     %+d\n", -42);
	// my_ret = ft_printf("%+i", 42);
	// f_ret = printf("     %+i\n", 42);
	// my_ret = ft_printf("%+i", -42);
	// f_ret = printf("     %+i\n", -42);
	// my_ret = ft_printf("%+c", 0);
	// f_ret = printf("     %+c\n", 0);
	// my_ret = ft_printf("%+C", 0);
	// f_ret = printf("     %+C\n", 0);
	// my_ret = ft_printf("%+o", 0);
	// f_ret = printf("     %+o\n", 0);
	// my_ret = ft_printf("%+o", 42);
	// f_ret = printf("     %+o\n", 42);
	// my_ret = ft_printf("%+O", 0);
	// f_ret = printf("     %+O\n", 0);
	// my_ret = ft_printf("%+O", 42);
	// f_ret = printf("    %+O\n", 42);
	// my_ret = ft_printf("[%+s]", 0);
	// f_ret = printf("    [%+s]\n", 0);
	// my_ret = ft_printf("[%+s]", "(null)");
	// f_ret = printf("    [%+s]\n", "(null)");
	// my_ret = ft_printf("%+O", 1);
	// f_ret = printf("    %+O\n", 1);

	//62
	// my_ret = ft_printf("% d", 9999);
	// f_ret = printf("% d\n", 9999);
	// my_ret = ft_printf("% d", -9999);
	// f_ret = printf("% d\n", -9999);
	// my_ret = ft_printf("% i", 9999);
	// f_ret = printf("% i\n", 9999);
	// my_ret = ft_printf("% i", -9999);
	// f_ret = printf("% i\n", -9999);
	// my_ret = ft_printf("|% u|", 9999);
	// f_ret = printf("|% u|\n", 9999);
	// my_ret = ft_printf("{% c}", 0);
	// f_ret = printf("{% c}\n", 0);
	// my_ret = ft_printf("{% c}", 'a');
	// f_ret = printf("{% c}\n", 'a');
	// my_ret = ft_printf("{% s}", NULL);
	// f_ret = printf("{% s}\n", NULL);
	// my_ret = ft_printf("{% s}", "(null)");
	// f_ret = printf("{% s}\n", "(null)");
	// my_ret = ft_printf("{% s}", "");
	// f_ret = printf("{% s}\n", "");
	// my_ret = ft_printf("{% C}", 0);
	// f_ret = printf("{% C}\n", 0);
	// my_ret = ft_printf("{% C}", L'a');
	// f_ret = printf("{% C}\n", L'a');
	// my_ret = ft_printf("{% S}", NULL);
	// f_ret = printf("{% S}\n", NULL);
	// my_ret = ft_printf("{% S}", L"(null)");
	// f_ret = printf("{% S}\n", L"(null)");
	// my_ret = ft_printf("{% S}", L"");
	// f_ret = printf("{% S}\n", L"");

	//69
	// my_ret = ft_printf("{% +d}", 42);
	// f_ret = printf("       {% +d}\n", 42);
	// my_ret = ft_printf("{%+ d}", 42);
	// f_ret = printf("       {%+ d}\n", 42);
	// my_ret = ft_printf("{%+03d}", 0);
	// f_ret = printf("       {%+03d}\n", 0);
	// my_ret = ft_printf("{% 03d}", 0);
	// f_ret = printf("       {% 03d}\n", 0);
	// my_ret = ft_printf("{%0-3d}", 0);
	// f_ret = printf("       {%0-3d}\n", 0);
	// my_ret = ft_printf("{%+03d}", 12);
	// f_ret = printf("       {%+03d}\n", 12);
	// my_ret = ft_printf("{%+03d}", 123456);
	// f_ret = printf("       {%+03d}\n", 123456);
	// my_ret = ft_printf("{%03.2d}", 0);
	// f_ret = printf("       {%03.2d}\n", 0);
	// my_ret = ft_printf("|%#.O|", 0);
	// f_ret = printf("|%#.O|", 0);
	//printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);


	//70
	// my_ret = ft_printf("|%.4d|", 42);
	// f_ret = printf("|%.4d|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.4d|", 424242);
	// f_ret = printf("|%.4d|\n", 424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.4d|", -424242);
	// f_ret = printf("|%.4d|\n", -424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4d|", 42);
	// f_ret = printf("|%15.4d|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4d|", 424242);
	// f_ret = printf("|%15.4d|\n", 424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%8.4d|", 424242424);
	// f_ret = printf("|%8.4d|\n", 424242424);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4d|", -42);
	// f_ret = printf("|%15.4d|\n", -42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4d|", -424242);
	// f_ret = printf("|%15.4d|\n", -424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%8.4d|", -424242424);
	// f_ret = printf("|%8.4d|\n", -424242424);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15d|", 42);
	// f_ret = printf("|%4.15d|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15d|", 424242);
	// f_ret = printf("|%4.15d|\n", 424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.8d|", 424242424);
	// f_ret = printf("|%4.8d|\n", 424242424);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15d|", -42);
	// f_ret = printf("|%4.15d|\n", -42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15d|", -424242);
	// f_ret = printf("|%4.15d|\n", -424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.8d|", -424242424);
	// f_ret = printf("|%4.8d|\n", -424242424);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.d, %.0d|", 0, 0);
	// f_ret = printf("|%.d, %.0d|\n", 0, 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.10d|", -42);
	// f_ret = printf("|%.10d|\n", -42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.4i|", 42);
	// f_ret = printf("|%.4i|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4i|", 42);
	// f_ret = printf("|%15.4i|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15i|", 42);
	// f_ret = printf("|%4.15i|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.i, %.0i|", 0, 0);
	// f_ret = printf("|%.i, %.0i|\n", 0, 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.4u|", 42);
	// f_ret = printf("|%.4u|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.4u|", 424242);
	// f_ret = printf("|%.4u|\n", 424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4u|", 42);
	// f_ret = printf("|%15.4u|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4u|", 424242);
	// f_ret = printf("|%15.4u|\n", 424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%8.4u|", 424242424);
	// f_ret = printf("|%8.4u|\n", 424242424);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15u|", 42);
	// f_ret = printf("|%4.15u|\n", 42);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15u|", 424242);
	// f_ret = printf("|%4.15u|\n", 424242);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.8u|", 424242424);
	// f_ret = printf("|%4.8u|\n", 424242424);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%.u, %.0u|", 0, 0);
	// f_ret = printf("|%.u, %.0u|\n", 0, 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//72
	// my_ret = ft_printf("|%.4s|", "42");
	// f_ret = printf("			|%.4s|\n", "42");
	// my_ret = ft_printf("|%.4s|", "42 is the answer");
	// f_ret = printf("			|%.4s|\n", "42 is the answer");
	// my_ret = ft_printf("|%15.4s|", "42");
	// f_ret = printf("	|%15.4s|\n", "42");
	// my_ret = ft_printf("|%15.4s|", "I am 42");
	// f_ret = printf("	|%15.4s|\n", "I am 42");
	// my_ret = ft_printf("|%15.4s|", "42 is the answer");
	// f_ret = printf("	|%15.4s|\n", "42 is the answer");
	// my_ret = ft_printf("|%4.15s|", "42");
	// f_ret = printf("			|%4.15s|\n", "42");
	// my_ret = ft_printf("|%4.15s|", "I am 42");
	// f_ret = printf("		|%4.15s|\n", "I am 42");
	// my_ret = ft_printf("|%4.15s|", "42 is the answer");
	//f_ret = printf("	|%4.15s|\n", "42 is the answer");
	// my_ret = ft_printf("|%4.s|", "42");
	// f_ret = printf("			|%4.s|\n", "42");
	// my_ret = ft_printf("|%.4S|", L"我是一只猫。");
	// f_ret = printf("|%.4S|\n", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%15.4S|", L"我是一只猫。");
	// f_ret = printf("|%15.4S|\n", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.15S|", L"我是一只猫。");
	// f_ret = printf("|%4.15S|\n", L"我是一只猫。");
	//  printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.S|", L"我是一只猫。");
	// f_ret = printf("|%4.S|\n", L"我是一只猫。");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%4.1S|", L"Jambon");
	// f_ret = printf("|%4.1S|\n", L"Jambon");
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);

	//73
	// my_ret = ft_printf("|%.c|", 0);
	// f_ret = printf("|%.c|\n", 0);
	// my_ret = ft_printf("|%.5c|", 0);
	// f_ret = printf("|%.5c|\n", 0);
	// my_ret = ft_printf("|%.5c|", 42);
	// f_ret = printf("|%.5c|\n", 42);
	// my_ret = ft_printf("|%.C|", 0);
	// f_ret = printf("|%.C|\n", 0);
	// my_ret = ft_printf("|%.5C|", 0);
	// f_ret = printf("|%.5C|\n", 0);
	// my_ret = ft_printf("|%.5C|", 42);
	// f_ret = printf("|%.5C|\n", 42);

	//74
	// my_ret = ft_printf("|%.0p, %.p|", 0, 0);
	// f_ret = printf("|%.0p, %.p|\n", 0, 0);
	// my_ret = ft_printf("|%.5p|", 0);
	// f_ret = printf("|%.5p|\n", 0);
	// my_ret = ft_printf("|%9.2p|", 1234);
	// f_ret = printf("|%9.2p|\n", 1234);
	// my_ret = ft_printf("|%9.2p|", 1234567);
	// f_ret = printf("|%9.2p|\n", 1234567);
	// my_ret = ft_printf("|%2.9p|", 1234);
	// f_ret = printf("|%2.9p|\n", 1234);
	// my_ret = ft_printf("|%2.9p|", 1234567);
	// f_ret = printf("|%2.9p|\n", 1234567);

	//75
	// my_ret = ft_printf("|%.3%|");
	// f_ret = printf("|%.3%|\n");

	//79
	// my_ret = ft_printf("|%#.o, %#.0o|", 0, 0);
	// f_ret = printf("|%#.o, %#.0o|\n", 0, 0);
	// my_ret = ft_printf("|%#.x, %#.0x|", 10, 10);
	// f_ret = printf("|%#.x, %#.0x|\n", 10, 10);
	// my_ret = ft_printf("|%.p, %.0p|", 0, 0);
	// f_ret = printf("|%.p, %.0p|\n", 0, 0);
	// my_ret = ft_printf("{%05.c}", 0);
	// f_ret = printf("{%05.c}\n", 0);
	// my_ret = ft_printf("{%05.s}", 0);
	// f_ret = printf("{%05.s}\n", 0);
	// my_ret = ft_printf("{%05.%}", 0);
	// f_ret = printf("{%05.%}\n", 0);
	// my_ret = ft_printf("{%05.Z}", 0);
	// f_ret = printf("{%05.Z}\n", 0);
	// my_ret = ft_printf("{%#.5x}", 1);
	// f_ret = printf("{%#.5x}\n", 1);
	// my_ret = ft_printf("|%#.3o|", 1);
	// f_ret = printf("|%#.3o|\n", 1);
	// my_ret = ft_printf("{%05.S}", L"42 c est cool");
	// f_ret = printf("{%05.S}\n", L"42 c est cool");

	//90
	// my_ret = ft_printf("|%hhd - %hhd|", SHRT_MAX - 42,  SHRT_MAX - 4200);
	// f_ret = printf("|%hhd - %hhd|\n", SHRT_MAX - 42,  SHRT_MAX - 4200);
	// my_ret = ft_printf("|%zi|", LLONG_MIN);
	// f_ret = printf("|%zi|\n", LLONG_MIN);
	// my_ret = ft_printf("|%zd|", LLONG_MIN);
	// f_ret = printf("|%zd|\n", LLONG_MIN);
	// my_ret = ft_printf("|% p|%+p|", 42, 42);
	// f_ret = printf("|% p|%+p|\n", 42, 42);

	//92
	// my_ret = ft_printf("|%o, %ho, %hho|", -42, -42, -42);
	// f_ret = printf("|%o, %ho, %hho|\n", -42, -42, -42);
	// my_ret = ft_printf("|%o|", LONG_MAX);
	// f_ret = printf("|%o|\n", LONG_MAX);
	// my_ret = ft_printf("|%O|", LONG_MIN);
	// f_ret = printf("|%O|\n", LONG_MIN);
	// my_ret = ft_printf("|% o|%+o|", 42, 42);
	// f_ret = printf("|% o|%+o|\n", 42, 42);
	// my_ret = ft_printf("|%#.o|", 42);
	// f_ret = printf("|%#.o|\n", 42);
	// my_ret = ft_printf("|% x|%+x|", 42, 42);
	// f_ret = printf("|% x|%+x|\n", 42, 42);
	// my_ret = ft_printf("|% X|%+X|", 42, 42);
	// f_ret = printf("|% X|%+X|\n", 42, 42);


	//basic test
	// my_ret = ft_printf("|%.0%|");
	// f_ret = printf("|%.0%|\n");
	ft_printf("%jx", 4294967295);
	ft_printf("%jx", 4294967296);
	my_ret =  ft_printf("%llx", 9223372036854775808);
	f_ret = printf("%llx", 9223372036854775808);
	// my_ret = ft_printf("|%jx|", -4294967296);
	// f_ret = printf("|%jx|", -4294967296);
	printf("\nmy_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%jx|", -4294967297);
	// f_ret = printf("|%jx|\n", -4294967297);
	// my_ret = ft_printf("|%llx|", 9223372036854775807);
	// f_ret = printf("|%llx|\n", 9223372036854775807);
	// my_ret = ft_printf("|%llx|", 9223372036854775808);
	// f_ret = printf("|%llx|\n", 9223372036854775808);
	// my_ret = ft_printf("|%#llx|", 9223372036854775807);
	// f_ret = printf("|%#llx|\n", 9223372036854775807);
	// my_ret = ft_printf("|@moulitest: %5.x %5.0x|", 0, 0);
	// f_ret = printf("|@moulitest: %5.x %5.0x|\n", 0, 0);
	// printf("my_ret ->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("|%-5.2s is a string|", "this");
	// f_ret = printf("|%-5.2s is a string|\n", "this");
	// my_ret = ft_printf("|%.2c|", NULL);
	// f_ret = printf("|%.2c|\n", NULL);
	// printf("my_ret->%i f_rt->%i\n", my_ret, f_ret);
	// my_ret = ft_printf("@moulitest: %c", 0);
	// f_ret = printf("@moulitest: %c", 0);
	// my_ret = ft_printf("%2c", 0);
	// f_ret = printf("%2c", 0);
	// my_ret = ft_printf("null %c and text", 0);
	// f_ret = printf("null %c and text", 0);
	// my_ret = ft_printf("|% c|", 0);
	// f_ret = printf("|% c|", 0);
	// my_ret = ft_printf("|@moulitest: %#.o %#.0o|", 0, 0);
	// f_ret = printf("|@moulitest: %#.o %#.0o|\n", 0, 0);
	// my_ret = ft_printf("|@moulitest: %5.o %5.0o|", 0, 0);
	// f_ret = printf("|@moulitest: %5.o %5.0o|\n", 0, 0);
	// my_ret = ft_printf("|%0+5d|", 42);
	// f_ret = printf("|%0+5d|\n", 42);
	//  my_ret = ft_printf("|%#08x|", 42);
	//  f_ret = printf("|%#08x|\n", 42);
	// my_ret = ft_printf("|% 10.5d|", 4242);
	// f_ret = printf("|% 10.5d|\n", 4242);
	// my_ret = ft_printf("|%+10.5d|", 4242);
	// f_ret = printf("|%+10.5d|\n", 4242);
	// my_ret = ft_printf("|%-+10.5d|", 4242);
	// f_ret = printf("|%-+10.5d|\n", 4242);
	// my_ret = ft_printf("|%03.2d|", -1);
	// f_ret = printf("|%03.2d|\n", -1);
	// my_ret = ft_printf("@moulitest:| %.d %.0d|", 42, 43);
	// f_ret = printf("@moulitest:| %.d %.0d|\n", 42, 43);
	// my_ret = ft_printf("@moulitest:| %5.d %5.0d|", 0, 0);
	// f_ret = printf("@moulitest:| %5.d %5.0d|\n", 0, 0);


	return (0);
}





