/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:59:20 by mgarcin           #+#    #+#             */
/*   Updated: 2015/03/04 10:53:24 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** MACROS		==============================================================
*/

# define STD_IN (0)
# define STD_OUT (1)
# define STD_ERR (2)

# ifndef NULL
#  define NULL (0)
# endif

/*
** TYPEDEFS		==============================================================
*/

typedef int				t_fd;
typedef unsigned int	t_size;

typedef struct			s_list
{
	void				*content;
	t_size				content_size;
	struct s_list		*next;
}						t_list;

/*
** PROTOTYPES	==============================================================
*/

void					*ft_memset(void *s, int c, t_size n);
void					ft_bzero(void *s, t_size n);
void					*ft_memcpy(void *dest, const void *src, t_size n);
void					*ft_memccpy(void *dest, const void *src,
									int c, t_size n);
void					*ft_memmove(void *dest, const void *src, t_size n);
void					*ft_memchr(const void *s, int c, t_size n);
int						ft_memcmp(const void *s1, const void *s2, t_size n);
t_size					ft_strlen(const char *str);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *s1, const char *s2);
char					*ft_strncpy(char *s1, const char *s2, t_size n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, t_size n);
t_size					ft_strlcat(char *dst, const char *src, t_size size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, t_size n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, t_size n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(t_size size);
void					ft_memdel(void **ap);
char					*ft_strnew(t_size size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int i, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(const char *s1, const char *s2, t_size n);
char					*ft_strsub(const char *s,
									unsigned int start, t_size len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *s);
char					**ft_strsplit(const char *s, char c);
char					**ft_str_to_wordtab(const char *s);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(const char *s);
void					ft_puterr(char *str);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(const void *content, t_size content_size);
void					ft_lstdelone(t_list **alst,
										void (*del)(void *, t_size));
void					ft_lstdel(t_list **alst, void (*del)(void *, t_size));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char					*ft_realloc(char *str, int size);
void					*ft_realloc_ptr(char *ptr, int old, int new);
char					**ft_realloc_tab(char **tab, int size);
t_fd					xopen(const char *path, int oflag);
void					*xmalloc(int size);
void					xfree(void *ptr);
int						xclose(t_fd fd);
int						xread(t_fd fd, void *ptr, int size);
int						xwrite(t_fd fd, void *ptr, int size);
int						ft_tab_size(char **tab);
void					ft_free_tab(char **tab);
int						match(const char *s1, const char *s2);
char					**get_content(t_fd fd);

#endif
