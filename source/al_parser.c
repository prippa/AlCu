/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:45:24 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 14:46:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	al_init_fd(char *file_name)
{
	int fd;

	fd = 0;
	if (!file_name)
		return (fd);
	else if ((fd = open(file_name, O_RDONLY)) == -1 || read(fd, NULL, 0) == -1)
		return (-1);
	return (fd);
}

static int	al_valid_line(char *str)
{
	long long int n;

	if (!ft_isstrdigit(str))
		return (-1);
	n = ft_atoi_max(str);
	if (n < 1 || n > 10000)
		return (-1);
	return ((int)n);
}

static void	al_show_instruction(void)
{
	ft_clear();
	ft_putstr("\tManual board initialization mode\n\n->");
}

int			al_parser(t_alum1 *al, char *file_name)
{
	int fd;
	int catch_error;
	int n;

	if ((fd = al_init_fd(file_name)) == -1)
		return (-1);
	if (!file_name)
		al_show_instruction();
	while ((catch_error = get_next_line(fd, &al->buf)) > 0)
	{
		if (!ft_strcmp(al->buf, ""))
			break ;
		if ((n = al_valid_line(al->buf)) == -1)
			return (-1);
		if ((al_stack_push(&al->stk, n)) == -1)
			return (-1);
		ft_str_free(&al->buf);
		if (!file_name)
			ft_putstr("->");
	}
	if (catch_error == -1 || !al->stk)
		return (-1);
	return (1);
}
