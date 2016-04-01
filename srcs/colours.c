/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 22:11:25 by tpelago           #+#    #+#             */
/*   Updated: 2016/03/28 13:01:14 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "../includes/grapiz.h"

void	print_darkred(int space)
{
  write(1, "\e[1;31m", 7);
   write(1, "\e[1;107m", 8);
   ft_putchar('R');
  write(1, "\e[0m", 4);
  if (space)
      print_empty();
}

void	print_darkblue(int space)
{
  write(1, "\e[1;34m", 7);
  write(1, "\e[1;107m", 8);
  ft_putchar('B');
  write(1, "\e[0m", 4);
  if (space)
      print_empty();
}

void	ft_print_spaces(int spaces)
{
  while (spaces)
    {
      ft_putchar(' ');
      spaces--;
    }
}

void	print_empty(void)
{
  ft_putchar(' ');
}

void	print_red(int space)
{
  write(1, "\e[1;91m", 7);
  ft_putchar('R');
  write(1, "\e[0m", 4);
  if (space)
      print_empty();
}
void	print_blue(int space)
{
  write(1, "\e[1;94m", 7);
  ft_putchar('B');
  write(1, "\e[0m", 4);
  if (space)
    print_empty();
}

void	padding(int lineno)
{
  if (lineno < 5)
    return;
  ft_print_spaces(lineno - 4);
}
