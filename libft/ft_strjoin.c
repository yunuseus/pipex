/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:32:58 by yalp              #+#    #+#             */
/*   Updated: 2024/10/15 12:39:27 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;
	char	*str;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	c = 0;
	str = malloc((a + b) * sizeof(char) + 1);
	if (!str)
		return (0);
	while (c < a)
	{
		str[c] = s1[c];
		c++;
	}
	c = 0;
	while (c < b)
	{
		str[a + c] = s2[c];
		c++;
	}
	str[a + c] = '\0';
	return (str);
}
