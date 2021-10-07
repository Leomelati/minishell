/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:11:29 by tguimara          #+#    #+#             */
/*   Updated: 2021/10/07 06:26:20 by lmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include "minishell.h"

static void	handle_interrupt(int sig_num)
{
	(void)sig_num;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	return ;
}

void	handle_signals(void)
{
	// handle "Crtl+C" to ignore following line and jump to next waiting prompt
	signal(SIGINT, handle_interrupt);
	// ignore "Crtl+Z"
	// signal(SIGTSTP, SIG_IGN);
	// ignore "Ctrl+\"
	signal(SIGQUIT, SIG_IGN);
	return ;
}
