/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../includes/printlib.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:58:15 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/15 15:17:19 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTLIB_H
# define PRINTLIB_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

int		flag1(char c);
void	writeln(int n, char c, int m[13]);
void	nol(int m[13]);
void	di1(char a[21]);
void	signdi(int n, int f1, int f2, int m[13]);
void	print_di1(char a[21], int m[13]);
void	print_di(char a[15], int m[13], int k, int n);
int		itoc(char a[21], int n, int m[13]);
int		type_di(va_list *vl, int m[13]);
int		distrib_types(int *i, char *f, int m[13], va_list *vl);
int		accuracy(int *i, char *f, int m[13], va_list *vl);
int		width(int *i, char *f, int m[13], va_list *vl);
int		flag(int *i, char *f, va_list *vl);
int		ft_printf(char *flags, ...);
int		litoc(char a[21], long int n, int m[13]);
int		type_ldi(va_list *vl, int m[13]);
int		distrib_l(int *i, char *f, int m[13], va_list *vl);
int		distrib_ll(int *i, char *f, int m[13], va_list *vl);
void	print_ldi(char a[15], int m[13], int k, long int n);
void	signldi(long int n, int f1, int f2, int m[13]);
int		llitoc(char a[21], long long int n, int m[13]);
int		type_lldi(va_list *vl, int m[13]);
void	print_lldi(char a[15], int m[13], int k, long long int n);
void	signlldi(long long int n, int f1, int f2, int m[13]);
int		hitoc(char a[21], short int n, int m[13]);
int		type_hdi(va_list *vl, int m[13]);
void	print_hdi(char a[15], int m[13], int k, short int n);
void	signhdi(short int n, int f1, int f2, int m[13]);
int		distrib_h(int *i, char *f, int m[13], va_list *vl);
int		type_x(va_list *vl, int m[13]);
void	signx(int f, int f1, int m[13], unsigned int n);
void	print_x(char a[15], int m[13], int k, unsigned int n);
int		xtoc(char a[21], unsigned int n, int m[13]);
char	paste_x(unsigned int n, int f);
void	print_x1(char a[21], int m[13]);
int		type_lx(va_list *vl, int m[13]);
void	signlx(int f, int f1, int m[13], unsigned long int n);
void	print_lx(char a[15], int m[13], int k, unsigned long int n);
int		lxtoc(char a[21], unsigned long int n, int m[13]);
int		type_llx(va_list *vl, int m[13]);
void	signllx(int f, int f1, int m[13], unsigned long long int n);
void	print_llx(char a[15], int m[13], int k, unsigned long long int n);
int		llxtoc(char a[21], unsigned long long int n, int m[13]);
int		type_hx(va_list *vl, int m[13]);
void	signhx(int f, int f1, int m[13], unsigned short int n);
void	print_hx(char a[15], int m[13], int k, unsigned short int n);
int		hxtoc(char a[21], unsigned short int n, int m[13]);
int		type_o(va_list *vl, int m[13]);
int		otoc(char a[21], unsigned int n, int m[13]);
int		lotoc(char a[21], unsigned long int n, int m[13]);
int		type_lo(va_list *vl, int m[13]);
int		type_llo(va_list *vl, int m[13]);
int		llotoc(char a[21], unsigned long long int n, int m[13]);
int		type_ho(va_list *vl, int m[13]);
int		hotoc(char a[21], unsigned short int n, int m[13]);
void	print_ho(char a[50], int m[13], int k, unsigned short int n);
int		type_hho(va_list *vl, int m[13]);
int		hhotoc(char a[21], unsigned char n, int m[13]);
void	print_hho(char a[50], int m[13], int k, unsigned char n);
int		print_c(int m[13], char n);
int		type_c(va_list *vl, int m[13]);
void	writes(char *s, int m[13]);
void	print_s(int m[13], char *n);
int		type_s(va_list *vl, int m[13]);
void	print_s1(int m[13], char *n, int f);
void	nulls(int m[13]);
int		print_slash(void);
void	fun_m(int m[13]);
int		hhitoc(char a[21], signed char n, int m[13]);
int		type_hhdi(va_list *vl, int m[13]);
void	print_hhdi(char a[15], int m[13], int k, signed char n);
void	signhhdi(signed char n, int f1, int f2, int m[13]);
int		type_hhx(va_list *vl, int m[13]);
void	signhhx(int f, int f1, int m[13], unsigned char n);
void	print_hhx(char a[15], int m[13], int k, unsigned char n);
int		hhxtoc(char a[21], unsigned char n, int m[13]);
int		utoc(char a[21], unsigned int n, int m[13]);
int		type_u(va_list *vl, int m[13]);
void	print_u(char a[15], int m[13], int k);
void	signu(unsigned int n, int f1, int f2, int m[13]);
int		lutoc(char a[21], unsigned long int n, int m[13]);
int		type_lu(va_list *vl, int m[13]);
void	print_lu(char a[15], int m[13], int k);
int		llutoc(char a[21], unsigned long long int n, int m[13]);
void	print_llu(char a[15], int m[13], int k);
int		type_llu(va_list *vl, int m[13]);
int		hutoc(char a[21], unsigned short int n, int m[13]);
int		type_hu(va_list *vl, int m[13]);
void	print_hu(char a[15], int m[13], int k);
int		hhutoc(char a[21], unsigned char n, int m[13]);
int		type_hhu(va_list *vl, int m[13]);
void	print_hhu(char a[15], int m[13], int k);
int		fttoc1(char t[100], int j);
int		fttoc(char t[100], double n, long long r, int m[13]);
void	print_f(char t[100], int m[13], char a[21], double n);
int		type_f(va_list *vl, int m[13]);
void	print_f1(char a[100], int m[13]);
void	signf(double n, int f1, int f2, int m[13]);
void	f1(char a[100]);
int		ftoc(char a[21], long long int n, int m[13]);
void	check_f(int m[13], long long r, double n);
void	pr_inf(int m[13], char a[21], double n);
void	print_d1(char a[21], int m[13]);
int		lfttoc(char t[100], long double n, long long r, int m[13]);
void	print_lf(char t[100], int m[13], char a[21], long double n);
int		type_lf(va_list *vl, int m[13]);
int		lftoc(char a[21], long long int n, int m[13]);
void	signlf(long double n, int f1, int f2, int m[13]);
void	check_lf(int m[13], long long r, long double n);
void	pr_linf(int m[13], char a[21], long double n);
int		distrib_lf(int *i, char *f, int m[13], va_list *vl);
size_t	ft_strlens(char *s);
int		type_p(va_list *vl, int m[13]);
void	print_bon1(char a[50], int m[13]);
void	print_bon(char a[50], int m[13], int k);
int		bon_toc(char a[50], unsigned int n, int m[13], int o);
void	b_mas(char a[50]);
void	type_b(va_list *vl, int m[13], int o);
int		bon_flag(char c);
int		distrib_b(int *i, char *f, int m[13], va_list *vl);
int		check_hlb(char c);
int		hlb(int *i, char *f, int m[13], va_list *vl);
int		csp(va_list *vl, int m[13], char f);
int		check_csp(char c);
int		dioux(va_list *vl, int m[13], char f);
int		check_dioux(char c);
void	print_llo(char a[50], int m[13], int k, unsigned long long int n);
void	print_lo(char a[50], int m[13], int k, unsigned long int n);
void	nil(char a[21]);

#endif
