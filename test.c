/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:06:19 by anbaya            #+#    #+#             */
/*   Updated: 2024/12/10 15:21:58 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
    int fd = open("txt.txt", O_RDWR | O_CREAT);

    char *str = get_next_line(fd);
    printf("%s",str);
    free(str);
    str = get_next_line(fd);
    printf("%s",str);
    free(str);
    str = get_next_line(fd);
    printf("%s",str);
    free(str);
    close(fd);
    str = get_next_line(fd);
    printf("%s",str);
    free(str);
    close(fd);
}