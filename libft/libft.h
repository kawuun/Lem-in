/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:33:54 by skavunen          #+#    #+#             */
/*   Updated: 2017/08/22 18:35:38 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define A(x) ((x) < 0 ? -(x) : (x))
# include <wchar.h>
# include <fcntl.h>

typedef struct	s_arg
{
	int		just;
	int		sign;
	int		flag;
	int		width;
	int		prec;
	int		size;
	int		sharp;
	char	conv;
}				t_arg;

# define BIT7 127
# define BIT11 2047
# define BIT16 65535
# define BIT21 2097151
# define BIT26 67108863
# define BIT31 2147483647
# define BUFF_SIZE 1

typedef struct	s_files
{
	char	*text;
	int		file;
	int		last;
}				t_files;

int				get_next_line(int fd, char **line);
char			*ft_chjoin(char const *str, char ch);
char			*ft_strreverse(const char *s);
int				ft_max(int *s, size_t len);
int				ft_isnegative(int n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcpy(char *dst, const char *src);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstpushback(t_list **list, void *content, size_t size);

int				g_wr;
int				ft_printf(const char *src, ...);
void			ft_putstr_f(const char *src);
char			*ft_strcnew(int size, char c);
int				ft_flags(const char*src, int i, t_arg *arg);
int				ft_width(const char *src, int i, t_arg *arg, va_list ap);
int				ft_sizemod(const char *src, int i, t_arg *arg);
int				ft_start(va_list ap, const char *src, int i);
int				ft_checkconv(t_arg *arg);
int				ft_howmanyc(const char *src, int i, char c, t_arg *arg);
int				ft_prec(const char *src, int i, t_arg *arg, va_list ap);
void			ft_undefbeh(t_arg *arg);
void			ft_mkprint(t_arg *arg, va_list ap);
char			*ft_strnew(size_t size);
char			*ft_ucharmod(t_arg *arg);
void			ft_charmod(char *s, t_arg *arg, int un);
char			*ft_addwidth(char *s, t_arg *arg, int len, char c);
char			*ft_addprec(char *s, int count, char ch);
char			*ft_itoa_base(unsigned long long value, int base, int flag);
void			ft_addto(char *d, t_arg *arg);
void			ft_six(t_arg *arg, va_list ap);
void			ft_eight(t_arg *arg, va_list ap);
void			ft_uten(t_arg *arg, va_list ap);
size_t			ft_len_num(unsigned long long value, int base);
char			*ft_itoaspec(intmax_t value);
int				ft_tolower(int c);
char			*ft_lower_case(char *str);
void			ft_putchar_f(int c);
void			ft_pointer(t_arg *arg, va_list ap);
int				ft_prechelp(char *s, char *c);
char			*ft_widthhelp(char *s, t_arg *arg, int len, char c);
char			*ft_precjoin(char *d, int i, char ch);
char			*ft_signhelp(char *s, t_arg *arg);
char			*ft_itoaspec(intmax_t value);
void			f_ten(intmax_t value, char *str, intmax_t base, int *i);
int				ft_take_wlen(const uint32_t symbol);
char			*ft_parse_wchar(const uint32_t symbol, int p);
void			ft_wputstr(char **d);
void			ft_widestr(wchar_t *d, t_arg *arg);
void			ft_place_char(int size, char c);
int				ft_check_len_wch(char **data);

#endif
