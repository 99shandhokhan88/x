/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:46:00 by vzashev           #+#    #+#             */
/*   Updated: 2024/05/02 23:06:03 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Function: my_exit
 * -------------------
 * Exits the shell with the specified exit status,
 * or with the default status if no argument is provided.
 *
 * inputs: An array containing the command and its arguments.
 * s_hell: A pointer to the shell structure.
 */

void	my_exit(char **inputs, t_mini *s_hell)
{
	g_exit = 0;
	if (inputs[1])
	{
		if (is_number(inputs[1]))
		{
			if (inputs[2])
				return (print_error("Error: exit: wrong arguments!\n", 2));
			g_exit = my_atoi(inputs[1]);
			if (g_exit > 255)
				g_exit = 255;
			else if (g_exit < 0)
				g_exit = 255;
		}
		else
			print_error("Error: exit: numeric argument required!\n", 2);
	}
	///free(inputs);
	free_shell(s_hell);
	free_inputs(inputs);
	//free_envv(inputs);
	//free_envv(s_hell->envv);
	exit(g_exit);
}
