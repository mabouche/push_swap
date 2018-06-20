/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:35:43 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/04 14:38:50 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
unsigned int		ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_strchr(const char *s, int c);
int					ft_toupper(int c);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
unsigned long		ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule, const char *aiguille);
char				*ft_strnstr(const char *meule,
					const char *aiguille, size_t len);
int					ft_strncmp(const char *s1,
					const char *s2, size_t size);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s,
					int c, size_t n);
void				*ft_memccpy(void *dest, const void *src,
					int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_strclr(char *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strtrim(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
int					ft_str_is_alpha(char *s);
int					ft_isupper(int c);
int					ft_isblank(int c);
int					ft_str_is_numeric(char *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_str_is_space(const char *s);
char				*ft_strmjoin(const char *s1, const char *s2, int tofree);
void				*ft_memjoin(void const *s1, void const *s2,\
					size_t l1, size_t l2);
char				*ft_itoa_base(long long value, int base);
char				*ft_utoa_base(unsigned long long value, int base);
char				*ft_strndup(const char *s, size_t n);
#endif
