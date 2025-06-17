/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:06:17 by xzhang            #+#    #+#             */
/*   Updated: 2023/10/29 15:20:05 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

/* ft_putx_fd functions */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

/* ft_isx functions */
int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);

/* ft_tox functions */
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ft_strx functions */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* ft_memx functions */
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* other functions */
char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/* Bonus ft_lst linkedlist functions */
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*  ft_prinft  */
int		ft_itoa2(int n);
int		ft_pinthex(unsigned int n, char c);
int		ft_ppointer(unsigned long n);
int		ft_printf(const char *str, ...);
int		ft_putchar2(char c);
int		ft_putstr2(char *s);
size_t	ft_strlen2(const char *s);
int		ft_uitoa(unsigned int n);

/*   get_next_line   */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

size_t	ft_strlen1(char *s);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_substr1(char *s, unsigned int start, size_t len);
char	*addtmptostr(char *str, char *tmp);
char	*ft_movestr(char *str);
char	*ft_readline(char *fullstr);
char	*ft_readfile(int fd, char *str);

#endif
