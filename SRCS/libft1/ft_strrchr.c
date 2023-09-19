/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomez-g <mgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:38:01 by manuelgomez       #+#    #+#             */
/*   Updated: 2023/08/24 10:11:38 by mgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *str, int character)
{
    int        i;

    i = ft_strlen(str);
    while (i >= 0)
    {
        if (str[i] == (char)character)
            return ((char *)str + i);
        i--;
    }
    return (0);
}

/*La función strrchr() en C se utiliza para buscar la última aparición de un 
carácter específico en una cadena de caracteres. */
