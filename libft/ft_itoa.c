/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:03:21 by allopez           #+#    #+#             */
/*   Updated: 2021/10/06 16:09:21 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_is_neg(int *nb, int *neg)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*neg = 1;
	}
	else
		*neg = 0;
}

static int	len_init(int nb)
{
	int	len;

	len = 2;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	int		i;
	int		len;
	int		neg;
	char	*dest;

	itoa_is_neg(&nb, &neg);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	i = nb;
	len = len_init(nb);
	len += neg;
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (0);
	if (neg)
		dest[0] = '-';
	dest[--len] = '\0';
	while (len--)
	{
		dest[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
		dest[0] = '-';
	return (dest);
}
