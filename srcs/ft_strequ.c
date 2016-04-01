/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:11:27 by tpelago           #+#    #+#             */
/*   Updated: 2016/04/01 16:28:06 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grapiz.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
		return (0);
	return (1);
}
