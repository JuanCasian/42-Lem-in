/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:49:22 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/13 18:16:34 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H

# define FT_LIBFT_H
# define BUFF_SIZE 4096
# define BUFF_SIZE_IN 1
# define FDS 65535
# define NFLAGS 5
# define NLENS 6

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <wchar.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_info
{
	int		flags[NFLAGS];
	int		width;
	int		lens[NLENS];
	int		preci;
	char	speci;
	va_list	*args;
	char	**str;
	int		count;
	char	*res;
	wchar_t	*wres;
}					t_info;

enum				e_flags
{
	Fminus,
	Fplus,
	Fspace,
	Fhash,
	Fzero
};

enum				e_lengths
{
	Lhh,
	Lh,
	Ll,
	Lll,
	Lj,
	Lz
};

void				ft_putchar(char c);
size_t				ft_strlen(char *str);
int					ft_strcmp(char *str1, char *str2);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *hs, const char *ned);
char				*ft_strnstr(const char *hs, const char *ned, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strinit(char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_count_words(char *str);
int					ft_is_space(char c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrev(char *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_printlist(t_list *my_list);
t_list				*ft_samplelist(size_t len);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_filetostr(int fd);
void				*ft_remalloc(void *ptr, size_t size, size_t curr);
char				*ft_strndup(char *str, int len);
int					get_next_line(const int fd, char **line);
wchar_t				*ft_wstrdup(wchar_t *wstr);
int					ft_wchar_len(wchar_t wc);
int					ft_wstrlen(wchar_t *wstr);
char				*ft_straddprefix(char *prefix, char *str);
char				*ft_straddsuffix(char *suffix, char *str);
wchar_t				*ft_wstraddsuffix(wchar_t *suffix, wchar_t *str);
wchar_t				*ft_wstraddprefix(wchar_t *prefix, wchar_t *str);
void				print_error(void);
wchar_t				*ft_wstrnew(size_t	size);
int					ft_putwchar(wchar_t wc);
char				*ft_utoabaselonglong(unsigned long long int n,
		unsigned long long int base);
void				ft_strtoupper(char **str);
char				*ft_itoalonglong(long long int n);
int					ft_printf(char *format, ...);
void				initialize_struct(t_info *info, char **str, va_list *args);
void				check_for_flags(t_info *info);
void				check_for_width(t_info *info);
void				check_for_preci(t_info *info);
void				check_for_lengths(t_info *info);
void				check_for_speci(t_info *info);
void				reinit_structure(t_info *info);
void				reinit_lengths(t_info *info);
int					is_flag(char c);
int					is_width(char c);
int					is_preci(char c);
int					is_length(char c);
int					is_speci(char c);
void				prepare_str(t_info *info);
void				prepare_percentage(t_info *info);
void				prepare_address(t_info *info);
void				prepare_hexadecimal(t_info *info);
void				prepare_undecimal(t_info *info);
void				prepare_octal(t_info *info);
void				prepare_binary(t_info *info);
void				prepare_signed(t_info *info);
void				prepare_char(t_info *info);
int					ft_countcharsrepetition(char *str, char c);
int					get_next_line_sin(const int fd, char **line);

#endif
