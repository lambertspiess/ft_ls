/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:24:11 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/12 14:24:14 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define GNL_BUFF 400
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

/*
** stdio functions
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);

void			ft_putstr(const char *s);
void			ft_putstr_fd(char const *s, int fd);

int				ft_nblen(int i);

void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);

void			ft_printmem_ltor(void *data, size_t data_size);
void			ft_printmem_rtol(void *data, size_t data_size);

/*
** stdlib functions
*/

int				ft_free(void *p);
void			ft_frees(int nb, ...);

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);

int				ft_atoi(const char *str);

unsigned int	ft_get_llnbr_size(unsigned long long nb);
char			*ft_lltoa(long long n);
unsigned int	ft_get_nbr_size(unsigned int nb);

char			*ft_itoa(int n);
char			*ft_lltoa(long long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_lltoa_base(long long n, int base);
char			*ft_ulltoa_base(unsigned long long n, int base);
char			*ft_ulltoa_base_caps(unsigned long long n, int base);

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);

void			ft_memdel(void **ap);

void			*ft_mmalloc(int size);
void			*ft_malloc_bzero(size_t size);
void			*ft_malloc_memset(size_t size, char c);

/*
** string functions
*/

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

size_t			ft_strlen(const char *s);
int				ft_istrlen(const char *s);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char const *s1, char const *s2,
				int free_s1, int free_s2);
char			*ft_strnjoin(char *s1, char *s2, int len);

char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strcpy(char *dst, const char *src);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void(*f)(unsigned int, char *));

int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
char			*ft_strcapitalize(char *s);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcat_free(char *dst, char *src, size_t size);

char			*ft_strncpy(char *dst, const char *src, size_t len);

char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *src, int len);

char			*ft_strrev(char *s);

void			ft_strclr(char *s);

/*
** APPEND / PREPEND
*/

char			*ft_prepnchar(char *src, char c, int len);
void			ft_prepnchar_inplace(char **src, char c, int len);
char			*ft_prependstr(char *s1, char *s2);
char			*ft_prependnstr(char *src, char *prep, size_t len);
void			ft_prepnstr_inplace(char **src, char *prep, size_t len);

char			*ft_appstr(char *src, char *app);
char			*ft_appnstr(char *src, char *app, size_t len);
void			ft_appstr_inplace(char **src, char *app);
void			ft_appnstr_inplace(char **src, char *app, size_t len);

char			*ft_appnchar(char *src, char c, int len);
void			ft_appnchar_inplace(char **src, char c, int len);

/*
** BIGNUM
*/

typedef struct	s_bigutil {
	char		*s1;
	char		*s2;
	char		*s3;
	int			ls1;
	int			ls2;
	int			ls3;
	int			lsm;
	int			lim1;
	int			lim2;
	int			i;
	int			j;
	int			k;
	int			top;
	int			bot;
	char		*swap;
	int			sign;
}				t_bigutil;

char			*ft_bigpowten(int exp);
void			ft_rightalign(char *s, int rightshift, int len);
char			*ft_biginit(t_bigutil *n, char *str1, char *str2);
char			*ft_trim_res(char **pres);

char			*ft_notrim_bigadd(char *s1, char *s2);
char			*ft_bigadd(char *s1, char *s2);

char			*ft_notrim_bigsub(char *s1, char *s2);
char			*ft_bigsub(char *s1, char *s2);

char			*ft_biginit_mul(t_bigutil *n, char *str1, char *str2);
void			ft_leftshift(char **s, int lshifts);
char			*ft_singlemul(t_bigutil n, int mul);
char			*ft_bigmul(char *s1, char *s2);
char			*ft_bigmul_free(char *s1, char *s2, int f1, int f2);

char			*ft_bigpow(char *s, int pow);

char			*ft_trimzeroes(char *s, int len);
int				ft_issmallerthan(char *s1, char *s2);
int				ft_isbiggerthan(char *s1, char *s2);

char			*ft_atoa_basetodec(char *s, int base);

/*
** data structures and linked lists
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstinsert(t_list **head, void *cntnt, size_t cntnt_size);
t_list			*ft_lstpop(t_list **p_head, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelnode(t_list **p_head, size_t index);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** misceallenous
*/

int				ft_is_escapable(char c);
size_t			ft_elem_len(char const *s, int begin, char delim);

int				ft_isqrt(int n);
int				get_next_line(const int fd, char **line);

#endif
