#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	int		i;
	int		prec;
	int		nonprint;
	int		j;
	int		k;
	int		n;
	unsigned int u;
	long	l;
	unsigned long	ul;
	long long ll;
	unsigned long long ull;
	float	f;
	double	d;
	long double	ld;
	long double	ld1;
	long double	ld2;
	double	ld3;
	double	ld4;
	// char	*s = "fucko";
	// char	*ss = NULL;

	i = 75;
	u = 111;
	prec = 5;
	nonprint = 15;
	j = -75;
	k = 500111222;
	i = 75;
	l = -5123123123;
	ul = 5123123123;
	ll = -9223372036854775807;
	ull = 18446744073709551615U;
	d = 15.69;
	n = 0;
	f  = 2345.1349999999;
	d  = 2345.111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999;
	ld = 12.14567511111111122222222223333333333444444444455555555556666666666777777777788888888889999999999;
	ld1 = 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000009999999999;
	ld2 = 142515.111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999;
	ld3 = 42.2456456456;
	ld4 = 1300000;

	ft_printf("%d", n);
	//ft_printf("ft {%*d}\n", -5, 42);
	//printf("lc {%*d}\n", -5, 42);
	//ft_printf("ft {%0*d}\n", -5, 42);
	//printf("lc {%0*d}\n", -5, 42);
	// ft_printf("ft {%05.*d}", -15, 42);
	// printf("lc {%05.*d}", -15, 42);
	// ft_printf("%.110Lf\n", ld1);
	// printf("%.110Lf\n", ld1);
	// ft_printf("ft %10x\n", 42);
	// printf("lc %10x\n", 42);
	// ft_printf("ft %p\n", NULL);
	// ft_printf("ft %.p\n", NULL);
	// ft_printf("ft %.0p\n", NULL);
	// ft_printf("ft %.x\n", 0);
	// ft_printf("ft %.0p\n", NULL);
	// printf("lc %p\n", NULL);
	// printf("lc %.p\n", NULL);
	// printf("lc %.x\n", 0);
	// printf("lc %.0p\n", NULL);


	/* asterisk */
	// ft_printf("ft %.*f\n", 3, ld3);
	// ft_printf("ft %.*f\n", -10, ld3); // negative precision
	// ft_printf("ft %.*i\n", -10, i);
	// printf("lc %.*f\n", 3, ld3);
	// printf("lc %.*f\n", -100, ld3);
	// printf("lc %.*i\n", -10, i);

	/* %n */
	// printf("n %i\n", n);
	// printf("123456788\n%5n", &n);
	// printf("n %i\n", n);

	/* feg */
	// ft_printf("ft %f\n", DBL_NAN);

	// ft_printf("ft %g\n", (double)42);
	// ft_printf("ft %G\n", (double)42);
	// printf("lc %g\n", (double)42);
	// printf("lc %G\n", (double)42);
	// ft_printf("f ft %f\n", ld3);
	// ft_printf("f ft %f\n", ld4);
	// ft_printf("e ft %e\n", ld3);
	// ft_printf("e ft %e\n", ld4);
	// ft_printf("g ft %.4g\n", ld3);
	// ft_printf("g ft %.4g\n", ld4);
	// ft_printf("\n");
	// printf("f ls %f\n", ld3);
	// printf("f ls %f\n", ld4);
	// printf("e ls %e\n", ld3);
	// printf("e ls %e\n", ld4);
	// printf("g ls %.4g\n", ld3);
	// printf("g ls %.4g\n", ld4);

	// ft_printf("ft %.20f\n", 1.5);
	// ft_printf("float rounding ft %.2f\n", 23.679);
	// ft_printf("float rounding ft %.2f\n", 99.99999);
	// ft_printf("float rounding ft %f\n", 573.924);
	// ft_printf("float ft %f\n", f);
	// ft_printf("float ft %#.f\n", f);
	// ft_printf("float ft %.10f\n", f);
	// ft_printf("float ft %020.10f\n", f);
	// ft_printf("float ft %020.10f\n", -f);
	// ft_printf("float ft % 20.10f\n", f);
	// ft_printf("float ft %# 20.10f\n", f);
	// ft_printf("float ft %#-20.10f\n", f);
	// ft_printf("float ft %#+20.10f\n", f);
	// printf("\n");
	// printf("ls %.20f\n", 1.5);
	// printf("float rounding lc %.2f\n", 23.679);
	// printf("float rounding lc %.2f\n", 99.99999);
	// printf("float ls %f\n", f);
	// printf("float ls %#.f\n", f);
	// printf("float ls %.10f\n", f);
	// printf("float ls %020.10f\n", f);
	// printf("float ls %020.10f\n", -f);
	// printf("float ls % 20.10f\n", f);
	// printf("float ls %# 20.10f\n", f);
	// printf("float ls %#-20.10f\n", f);
	// printf("float ls %#+20.10f\n", f);
	// printf("ls %#+20.10e\n", f);
	// printf("ls %#+20.10g\n", f);

	// printf("ls %f\n", f);
	// printf("ls %.10f\n", f);
	// printf("f %.0f\n", f);
	// printf("f %.f\n", f);

	// ft_printf("ft e %.Le\n", ld3);
	// ft_printf("ft e %#.Le\n", ld3);
	// ft_printf("ft e %#.5Le\n", ld3);
	// ft_printf("ft e % 20.Le\n", ld3);
	// ft_printf("ft e %020.0Le\n", ld3);
	// ft_printf("ft e %+20.Le\n", ld3);
	// printf("lf e %.Le\n", ld3);
	// printf("lf e %#.Le\n", ld3);
	// printf("lf e %#.5Le\n", ld3);
	// printf("lf e % 20.Le\n", ld3);
	// printf("lf e %020.0Le\n", ld3);
	// printf("lf e %+20.Le\n", ld3);


	/* char, string, % */
	// ft_printf("ft %20s\n", NULL);
	// printf("ls %20s\n", NULL);
	// ft_printf("%s\n", s);
	// ft_printf("%5.4s\n", s);
	// ft_printf("%-5.4s\n", s);
	// ft_printf("%s\n", ss);
	// ft_printf("%5c\n", i);
	// ft_printf("%c\n", 0);
	// ft_printf("%%");
	// ft_printf("ft %%\n");
	// ft_printf("ft %%d\n");
	// ft_printf("ft %5%f\n");
	// ft_printf("ft %-5%\n");
	// ft_printf("ft %05%\n");
	// ft_printf("ft %-05%\n");
	// printf("\n");
	// printf("%5.4s\n",s);
	// printf("%s\n", ss);
	// printf("%5c\n", i);
	// printf("lc %%\n");
	// printf("lc %5%\n");
	// printf("lc %-5%\n");
	// printf("lc %05%\n");
	// printf("lc %-05%\n");
	// printf("\n");

	/* binary */
	// ft_printf("%b\n", 255);
	// ft_printf("%15b\n", 255);
	// ft_printf("%15.12b\n", 255);
	// ft_printf("%015b\n", 255);
	// ft_printf("%-15.b\n", 255);

	/* apostrophe */
	// ft_printf("%'i\n", 123);
	// ft_printf("%'i\n", 1123);
	// ft_printf("%'i\n", 123123);
	// ft_printf("%i\n", 5123123);
	// ft_printf("%'i\n", 5123123);
	// ft_printf("%15i\n", 5123123);
	// ft_printf("%'15i\n", 5123123);
	// ft_printf("%15.13i\n", 5123123);
	// ft_printf("%'15.13i\n", 5123123);
	// ft_printf("%15.i\n", 5123123);
	// ft_printf("%'15.i\n", 5123123);
	// ft_printf("%015.i\n", 5123123);
	// ft_printf("%0'15.i\n", 5123123);
	// ft_printf("%015i\n", 5123123);
	// ft_printf("%0'15i\n", 5123123);
	// ft_printf("%-15.i\n", 5123123);
	// ft_printf("%-'15.i\n", 5123123);
	// ft_printf("\n");
	// ft_printf("%'u\n", 123);
	// ft_printf("%'u\n", 1123);
	// ft_printf("%'u\n", 123123);
	// ft_printf("%u\n", 5123123);
	// ft_printf("%'u\n", 5123123);
	// ft_printf("%15u\n", 5123123);
	// ft_printf("%'15u\n", 5123123);
	// ft_printf("%15.13u\n", 5123123);
	// ft_printf("%'15.13u\n", 5123123);
	// ft_printf("%15.u\n", 5123123);
	// ft_printf("%'15.u\n", 5123123);
	// ft_printf("%015.u\n", 5123123);
	// ft_printf("%0'15.u\n", 5123123);
	// ft_printf("%015u\n", 5123123);
	// ft_printf("%0'15u\n", 5123123);
	// ft_printf("%-15.u\n", 5123123);
	// ft_printf("%-'15.u\n", 5123123);
	// ft_printf("%f\n", 5123123.555666);
	// ft_printf("%'f\n", 5123123.555666);

	/* int lengths */
	// ft_printf("%i%i%li%lli", i, j, l, ll);
	// printf("\n");
	// ft_printf("%u%lu%llu", u, ul, ull);
	// printf("\n");
	// ft_printf("%o%lo%llo", u, ul, ull);
	// printf("\n");
	// ft_printf("%x%lx%llx", u, ul, ull);
	// printf("\n");
	// ft_printf("%X%lX%llX", u, ul, ull);
	// printf("\n");
	/* lengths out of range */
	// ft_printf("ft %hhi, %hhi, %hi, %hi\n", (char)-129, (char)128, (short)32768, (short)-32769);
	// printf("lc %hhi, %hhi, %hi, %hi\n", (char)-129, (char)128, (short)32768, (short)-32769);

	/* signed int options */
	// ft_printf("ft %d\n", 5555);
	// ft_printf("ft %9d\n", 5555);
	// ft_printf("ft %09i\n", i);
	// ft_printf("ft %-9i\n", i);
	// ft_printf("ft %-09i\n", i); // 0 is ignored
	// ft_printf("ft %+i\n", i);
	// ft_printf("ft % i\n", i);
	// ft_printf("ft % +i\n", i); // ' ' is ignored
	// ft_printf("ft % 9i\n", i);
	// ft_printf("ft % -9i\n", i);
	// ft_printf("ft % 09i\n", i);
	// ft_printf("ft %.*i\n", prec, i);
	// ft_printf("ft %37.*i\n", prec, i);
	// ft_printf("ft %037.*i\n", prec, i);
	// ft_printf("ft %-39.*i\n", prec, i);
	// ft_printf("ft %-039.*i\n", prec, i); // 0 is ignored
	// ft_printf("ft %+.*i\n", prec, i);
	// ft_printf("ft % .*i\n", prec, i);
	// ft_printf("ft % +.*i\n", prec, i); // ' ' is ignored
	// ft_printf("ft % 39.*i\n", prec, i);
	// ft_printf("ft % -39.*i\n", prec, i);
	// ft_printf("ft % 039.*i\n", prec, i);

	/* zero precision */
	// ft_printf("ft %.0i\n", 0);
	// ft_printf("ft %.0o\n", 5);
	// ft_printf("ft %.0o\n", 0);
	// ft_printf("ft %.0x\n", 0);
	// ft_printf("ft %x\n", 0);

	/* octal options */
	// int r = 0;
	// ft_printf("%2i ft %o\n", ++r, u);
	// ft_printf("%2i ft %#o\n", ++r, u);
	// ft_printf("%2i ft %9o\n", ++r, u);
	// ft_printf("%2i ft %#9o\n", ++r, u);
	// ft_printf("%2i ft %09o\n", ++r, u);
	// ft_printf("%2i ft %#09o\n", ++r, u);
	// ft_printf("%2i ft %-9o\n", ++r, u);
	// ft_printf("%2i ft %#-9o\n", ++r, u);
	// ft_printf("%2i ft %.o\n", ++r, u);
	// ft_printf("%2i ft %#.o\n", ++r, u);
	// ft_printf("%2i ft %.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %9.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#9.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %09.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#09.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %-9.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#-9.*o\n", ++r, prec, u);
	// ft_printf("\n");

	/* zero precision */
	// printf("lc %.0i\n", 0);
	// printf("lc %.0o\n", 5);
	// printf("lc %.0o\n", 0);
	// printf("lc %.0x\n", 0);
	// printf("lc %x\n", 0);
	// printf("lc %x\n", 0);

	// r = 0;
	// printf("%2i lc %o\n", ++r, u);
	// printf("%2i lc %#o\n", ++r, u);
	// printf("%2i lc %9o\n", ++r, u);
	// printf("%2i lc %#9o\n", ++r, u);
	// printf("%2i lc %09o\n", ++r, u);
	// printf("%2i lc %#09o\n", ++r, u);
	// printf("%2i lc %-9o\n", ++r, u);
	// printf("%2i lc %#-9o\n", ++r, u);
	// printf("%2i lc %.o\n", ++r, u);
	// printf("%2i lc %#.o\n", ++r, u);
	// printf("%2i lc %.*o\n", ++r, prec, u);
	// printf("%2i lc %#.*o\n", ++r, prec, u);
	// printf("%2i lc %9.*o\n", ++r, prec, u);
	// printf("%2i lc %#9.*o\n", ++r, prec, u);
	// printf("%2i lc %09.*o\n", ++r, prec, u);
	// printf("%2i lc %#09.*o\n", ++r, prec, u);
	// printf("%2i lc %-9.*o\n", ++r, prec, u);
	// printf("%2i lc %#-9.*o\n", ++r, prec, u);

	/* pointers */
	// ft_printf("ft %p\n", NULL);
	// ft_printf("ft %p\n", &i);
	// ft_printf("ft %20p\n", &i);
	// ft_printf("ft %-20p\n", &i);
	// printf("lc %p\n", NULL);
	// printf("lc %p\n", &i);
	// printf("lc %20p\n", &i);
	// printf("lc %-20p\n", &i);




	// printf("\n");
	// ft_printf("ft %i\n", j);
	// ft_printf("ft %0i\n", j);
	// ft_printf("ft %9i\n", j);
	// ft_printf("ft %09i\n", j);
	// ft_printf("ft %-9i\n", j);
	// ft_printf("\n");
		// ft_printf("%+i\n", j);
		// ft_printf("% i\n", j);
		// ft_printf("%.8i\n", j);
		// ft_printf("%7.8i\n", j);
	// printf("lc %i\n", j);
	// printf("lc %0i\n", j);
	// printf("lc %9i\n", j);
	// printf("lc %09i\n", j);
	// printf("lc %-9i\n", j);
		// printf("%+i\n", j);
		// printf("% i\n", j);
		// printf("%.8i\n", j);
		// printf("%7.8i\n", j);

	// printf("%lu\n", 125L);

	/* string options */
	// ft_printf("%s\n", s);
	// ft_printf("%10s\n", s);
	// ft_printf("%-10s\n", s);
	// ft_printf("%.2s\n", s);
	// ft_printf("%10.2s\n", s);
	// ft_printf("%-10.2s\n", s);
	// ft_printf("\n");
	// printf("%s\n", s);
	// printf("%10s\n", s);
	// printf("%-10s\n", s);
	// printf("%.2s\n", s);
	// printf("%10.2s\n", s);
	// printf("%-10.2s\n", s);

	/* char options */
	// ft_printf("%c\n", i);
	// ft_printf("%10c\n", nonprint);
	// ft_printf("%10c\n", i);
	// ft_printf("%-9c\n", i);
	// ft_printf("%lc\n", i);
	// ft_printf("\n");
	// printf("%c\n", i);
	// printf("%10c\n", nonprint);
	// printf("%10c\n", i);
	// printf("%-9c\n", i);
	// printf("%lc\n", i);

	/* float options */
	// printf("%f\n", d);
	// printf("%#f\n", d);
	// printf("%0f\n", d);
	// printf("%15f\n", d);
	// printf("%015f\n", d);
	// printf("%-15f\n", d);
	// printf("%+f\n", d);
	// printf("% f\n", d);
	// printf("%.12f\n", d);
	// printf("%30.12f\n", d);
	// printf("%030.12f\n", d);
	// printf("%-30.12f\n", d);

	/* exp options */
	// printf("%e\n", d);
	// printf("%.10e\n", d);


	// ft_printf("%*.*c\n", 33, 44, i);
	// printf("%*.*i\n", 10, 5, i);
	// printf("%1$*3$.*1$i, %2$*1$i, %3$*2$i\n", 10, 5, i);
	// ft_printf("%*.*i\n", 10, 5, i);

	// printf("%p\n", &i);
	// printf("\n");
	// printf("%s\n", s);
	// printf("%i\n", i);
	// printf("%o\n", i);
	// printf("%u\n", i);
	// printf("%x\n", i);
 	// printf("%#x\n", i);
 	// printf("%##x\n", i);
	// printf("%X\n", i);
	// printf("%f\n", d);
	// printf("\n");

	// printf("--specified precision--\n");
	// printf("%.4s\n", s);
	// printf("%.4i\n", i);
	// printf("%.4o\n", i);
	// printf("%.4u\n", i);
	// printf("%.4x\n", i);
	// printf("%.4X\n", i);
	// printf("%.4f\n", d);
	// printf("\n");

	// printf("--unspecified precision--\n");
	// printf("%.s\n", s);
	// printf("%.i\n", i);
	// printf("%.o\n", i);
	// printf("%.u\n", i);
	// printf("%.x\n", i);
	// printf("%.X\n", i);
	// printf("%.f\n", d);
	// printf("%.0f\n", d);

	// printf("--positive padding--\n");
	// printf("%14s\n", s);
	// printf("%14i\n", i);
	// printf("%0i\n", i);
	// printf("%i\n", i);
	// printf("%14o\n", i);
	// printf("%14u\n", i);
	// printf("%14x\n", i);
	// printf("%14X\n", i);
	// printf("%14f\n", d);
	// printf("\n");

	// printf("--negative padding--\n");
	// printf("%-14s\n", s);
	// printf("%-14i\n", i);
	// printf("%-14o\n", i);
	// printf("%-14u\n", i);
	// printf("%-14x\n", i);
	// printf("%-14X\n", i);
	// printf("%-14f\n", d);
	// printf("\n");

	// printf("--positive padding with 0--\n");
	// printf("%014i\n", i);
	// printf("%014o\n", i);
	// printf("%014u\n", i);
	// printf("%014x\n", i);
	// printf("%014X\n", i);
	// printf("%014f\n", d);
	// printf("\n");

	// printf("-- space and + --\n");
	// printf("%i\n", i);
	// printf("%i\n", j);
	// printf("% i\n", i);
	// printf("% i\n", j);
	// printf("%+i\n", i);
	// printf("%+i\n", j);
	// printf("\n");

	// printf("-- # --\n");
	// printf("%o\n", i);
	// printf("%#o\n", i);
	// printf("%o\n", j);
	// printf("%#o\n", j);
	// printf("%x\n", i);
	// printf("%#x\n", i);
	// printf("%x\n", j);
	// printf("%#x\n", j);
	// printf("%.f\n", d);
	// printf("%#.f\n", d);
	// printf("\n");

	// printf("-- lengths: hh & h --\n");
	// printf("%hhi\n", (char)255);
	// printf("%hhu\n", (unsigned char)255);
	// printf("%hi\n", (short)255);
	// printf("-- lengths: ll --\n");
	// printf("%lli\n", l);
	// printf("-- lengths: ull --\n");
	// printf("%llu\n", ul);
	// printf("\n");
}
