#include "shell.h"
/**
 * sig_handler : handler cntrl c
 * @num: num argument
 */
void sig_handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", _strlength("\n$ "));
}
/**
 * prompt : a shell using c
 * @arv: argument by user
 * @envp: envirement variable argument
 * @flg: flag argument for mode
 */
void prompt(char **arv, char **envp, bool flg)
{
	size_t n = 0;
	ssize_t num_c = 0;
	char *cmd = NULL, *rgv[MAX_C];
	int x/*, stat,path*/;

	while (1)
	{
		if (flg && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlength("$ "));
		signal(SIGINT, sig_handler);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (cmd[num_c - 1] == '\n')
			cmd[num_c - 1] = '\0';
		cmd = trim(cmd);
		if (_strlength(cmd) == 0)
			continue;
		x = 0;
		rgv[x] = strtok(cmd, " \n");
		to_exit(cmd);
		handling_path(rgv, cmd);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		run_cmd(rgv, arv, envp); /* envir */
	}
	free(cmd);
}
