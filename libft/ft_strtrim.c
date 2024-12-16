/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:28:59 by yalp              #+#    #+#             */
/*   Updated: 2024/10/14 17:09:41 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(s1);
	while (a < b && ft_strchr(set, s1[a]))
		a++;
	while (a < b && ft_strchr(set, s1[b - 1]))
		b--;
	return (ft_substr(s1, a, b - a));
}
