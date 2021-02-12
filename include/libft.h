/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 17:44:08 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/12 14:31:46 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h> // size_t

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(char *nptr);
int					ft_isdigit(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
char				*ft_strndup(const char *s, size_t n);

#endif
