/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:49:09 by agiraud           #+#    #+#             */
/*   Updated: 2022/07/29 22:58:08 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		infile;
	int		outfile;
	int		tube[2];
}	t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	first_child(t_pipex pipex, char **argv, char **envp);
void	perror_msg(char *str);
int		error_msg(char *str);
void	free_cmd_paths(t_pipex *pipex);
void	free_cmd_args(t_pipex *pipex);
void	second_child(t_pipex pipex, char **argv, char **envp);
void	close_pipes(t_pipex *pipex);

#endif
