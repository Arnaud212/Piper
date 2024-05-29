/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:49:36 by agiraud           #+#    #+#             */
/*   Updated: 2022/08/24 16:31:05 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], 1);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		error_msg(pipex.cmd_args[0]);
		error_msg(": command not found\n");
		free_cmd_args(&pipex);
		free_cmd_paths(&pipex);
		close_pipes(&pipex);
		exit(1);
	}
	close_pipes(&pipex);
	close(pipex.infile);
	close(pipex.outfile);
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], 0);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		error_msg(pipex.cmd_args[0]);
		error_msg(": command not found\n");
		free_cmd_args(&pipex);
		free_cmd_paths(&pipex);
		close_pipes(&pipex);
		exit(1);
	}
	close_pipes(&pipex);
	close(pipex.infile);
	close(pipex.outfile);
	execve(pipex.cmd, pipex.cmd_args, envp);
}
