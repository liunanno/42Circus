/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:18:33 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 18:58:30 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../push_swap.h"
# include "../gnl/get_next_line.h"

void	do_moves(t_listx **stack_a, t_listx **stack_b, char *str);
void	do_moves2(t_listx **stack_a, t_listx **stack_b, char *str);
int		okorko(t_listx **stack_a);

#endif
