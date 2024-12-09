#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <assert.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdarg.h>

#include <libft.h>

#define ANSI_COMMAND_TITLE  FT_ANSI_BOLD FT_ANSI_UNDERLINE FT_ANSI_GREEN
#define ANSI_COMMAND FT_ANSI_YELLOW

typedef struct s_elf_parser	t_elf_parser;
typedef bool	(*const t_callable)(t_elf_parser *data, char *line, va_list);

typedef enum {
	CALLABLE_FAIL,
	CALLABLE_SUCCESS,
	CALLABLE_RETURN,
}	t_callable_action;

t_callable_action	check_callables(t_callable *callables, size_t count,
						t_elf_parser *data, char *line, ...);

typedef struct s_elf_parser {
	union {
		void		*v_buf;
		uint8_t		*buf;
		Elf64_Ehdr	*main_header;
	};
	const char	*global_command_strs[4];
	size_t	global_command_str_count;
	t_callable	global_commands[2];
	//bool	(*const global_commands[2])(t_elf_parser *data, char *line);
	size_t	global_command_count;
}	t_elf_parser;


bool	print_Elf64_Ehdr(t_elf_parser *data, char *input, va_list);
void	print_Elf64_Shdr(Elf64_Shdr *header);

bool	is_elf(uint8_t	*buf, struct stat file_stats);
bool	print_section_headers(t_elf_parser *data, char *input_line, va_list);
