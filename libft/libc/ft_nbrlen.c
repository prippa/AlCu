/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:43:17 by prippa            #+#    #+#             */
/*   Updated: 2018/01/28 15:45:24 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbrlen(long long int nbr)
{
	int len;

	len = 1;
	if (nbr == -2147483648)
	{
		len++;
		nbr = nbr / 10;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}