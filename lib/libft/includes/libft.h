/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:43:46 by mguerra           #+#    #+#             */
/*   Updated: 2022/07/12 23:23:10 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* CHAR FUNCTIONS */
int			ft_has_char(char *s, char c);
int			ft_has_non_printable_char(char *s);
int			ft_indexof(char *s, char c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
int			ft_iswhitespace(char c);
int			ft_tolower(int c);
int			ft_toupper(int c);

/* FD FUNCTIONS */
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

/* MEM FUNCTIONS */
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);

/* MATRIX FUNCTIONS */
size_t		ft_matrix_len(char **s);
void		ft_free_matrix(char **s);
void		print_matrix(char **s);

/* NUMBER FUNCTIONS */
int			ft_max_factor(unsigned long long n, int divisor);

/* STR FUNCTIONS */
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strndup(const char *s, size_t n);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_atoi(const char *nptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			is_numeric(char *str);
long int	ft_atol(const char *nptr);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strreplace(char *search, char *replace, char *str);
int			ft_strcmp(const char *s1, const char *s2);

/* LINKED LIST FUNCTIONS */
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **alst, t_list *lst);
void		ft_lstadd_front(t_list **alst, t_list *lst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
char		**ft_lst_to_matrix(t_list *lst);
void		print_lst(t_list *lst, char *name);

/* GARBAGE COLLECTOR FUNCTIONS */

typedef struct s_gc_list
{
	void				*content;
	int					group;
	struct s_gc_list	*next;
}	t_gc_list;

typedef struct s_gc
{
	int			setup;
	t_gc_list	*head;
}	t_gc;

char		**gc_split(const char *s, char c);
char		*gc_itoa(int n);
char		*gc_strdup(const char *s);
char		*gc_strjoin(const char *s1, const char *s2);
char		*gc_strnjoin(const char *s1, const char *s2, int len);
char		*gc_strmapi(const char *s, char (*f)(unsigned int, char));
char		*gc_strndup(const char *s, size_t n);
char		*gc_strtrim(const char *s1, const char *set);
char		*gc_substr(const char *s, unsigned int start, size_t len);
t_gc		*get_gc(void);
t_list		*gc_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*gc_lstnew(void *content);
char		**gc_lst_to_matrix(t_list *lst);
void		gc_clear_group(int group);
void		gc_lstadd_back(t_gc_list **alst, t_gc_list *lst);
void		*gc_calloc(size_t nmemb, size_t size);
void		*gc_malloc(size_t size);
void		*gc_malloc_group(size_t size, int group);
void		gc_clear(void);
char		*gc_strreplace(char *search, char *replace, char *str);

typedef struct s_clist
{
	char			*content;
	struct s_clist	*next;
}				t_clist;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*gc_get_next_line(int fd);
void		gc_generate_line(char **line, t_clist *stash);
int			gc_found_newline(t_clist *stash);
t_clist		*gc_ft_lst_get_last(t_clist *stash);
void		gc_generate_line(char **line, t_clist *stash);
void		gc_free_stash(t_clist *stash);
#endif
