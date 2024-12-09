#include <elf_parser.h>

static void	put_address_space(uint64_t address) {
	printf("%s", "   ");
	if (address % 16 && !(address % 8)) {
		printf("| ");
	}
}

static void	put_address_char(t_elf_parser *data, uint64_t address) {
	if (isprint(data->buf[address])) {
		printf(" %c ", data->buf[address++]);
	} else {
		printf(" . ");
	}
	if (address % 16 && !(address % 8)) {
		printf("| ");
	}
}

static void	put_address_hex(t_elf_parser *data, uint64_t address) {
	printf("%02X ", data->buf[address++]);
	if (address % 16 && !(address % 8)) {
		printf("| ");
	}
}

/*todo: currently does not protect invalid memory acceses */
bool	print_address(t_elf_parser *data, char *line, va_list args) {
	(void)args;
	uint64_t	address;
	uint64_t	count;

	char	**split = ft_split(line, ':');
	assert(split);

	/* Check if input line is of format '[<address>]:<count>'.
	 * Check is not perfect but should not conflict with other commads like
	 * this */
	if (!split[0] || !split[1] || split[2]) {
		free_2d_arr(split);
		return (false);
	}
	size_t	len0 = strlen(split[0]);
	size_t	len1 = strlen(split[1]);
	if (split[0][0] != '[' || split[0][len0 - 1] != ']' || len0 < 3
		|| !isdigit(split[0][1])
		|| !len1
		|| !isdigit(split[1][0]))
	{
		free_2d_arr(split);
		return (false);
	}

	count = atoll(split[1]);
	address = atoll(split[0] + 1);
	free_2d_arr(split);

	uint64_t	end = address + count;
	printf("Address         Data (Hexadecimal)\n");
	printf("---------------------------------------------------\n");
	bool	first = true;
	/*todo: post fix is broken and refactor */
	while (address < end) {
		uint64_t	line_begin = address;
		printf("0x%08lx  ", address);
		if (first) {
			uint64_t prefix = (line_begin % 16) ?
				line_begin - (line_begin % 16) : line_begin;
			for (; prefix < line_begin; prefix++) {
				put_address_space(prefix);
			}
		}
		do {
			put_address_hex(data, address++);
		} while ((address % 16) && address < end);
		if (address == end) {
			for (; address % 16; address++) {
				put_address_space(address);
			}
		}
		printf("\t||\t");
		address = line_begin;
		if (first) {
			uint64_t prefix = (line_begin % 16) ?
				line_begin - (line_begin % 16) : line_begin;
			for (; prefix < line_begin; prefix++) {
				put_address_space(prefix);
			}
			first = false;
		}
		do {
			put_address_char(data, address++);
		} while ((address % 16) && address < end);
		for (; address % 16; address++) {
			put_address_space(address);
		}
		printf("\n");
	}
	return (true);
}

void	main_loop(t_elf_parser *data) {
	char	*command_strs[] = {
		ANSI_COMMAND_TITLE "Current additional commands:" FT_ANSI_RESET,
		ANSI_COMMAND "'section table'" FT_ANSI_RESET,
	};
	size_t	command_strs_count = sizeof command_strs / sizeof command_strs[0];
	t_callable	commands[] = {
		print_section_headers,
	};
	size_t	command_count = sizeof commands / sizeof commands[0];
	while (1) {
		for (size_t j = 0; j < data->global_command_str_count; j++){
			printf("\t%s\n", data->global_command_strs[j]);
		}
		for (size_t j = 0; j < command_strs_count; j++){
			printf("\t%s\n", command_strs[j]);
		}
		char	*line = readline("enter command: ");
		if (!line) {
			continue ;
		}
		check_callables(commands, command_count, data, line);
	}
}

int	main(int ac, char *av[]) {
	t_elf_parser	data = {
		.buf = NULL,
		/* when addeding here the array length in struct t_elf_parser needs
		 * to be increased */
		.global_command_strs = {
			ANSI_COMMAND_TITLE "General commands:" FT_ANSI_RESET,
			ANSI_COMMAND "'main header'" FT_ANSI_RESET,
			ANSI_COMMAND"'[<address>]:<byte count>'" FT_ANSI_RESET, 
			ANSI_COMMAND"'exit'" FT_ANSI_RESET,
		},
		.global_commands = {
			print_Elf64_Ehdr,
			print_address,
		},
	};
	data.global_command_str_count =
		sizeof data.global_command_strs / sizeof data.global_command_strs[0];
	data.global_command_count =
		sizeof data.global_commands / sizeof data.global_commands[0];

	if (ac < 2) {
		printf("Need file as args\n");
		return (1);
	}
	char	*file = av[1];
	int	fd = open(file, O_RDONLY);
	assert(fd > 1);
	struct stat	file_stats;
	assert(fstat(fd, &file_stats) != -1);
	data.v_buf = malloc(file_stats.st_size);
	assert(data.buf);
	int read_ret = read(fd, data.v_buf, file_stats.st_size);
	close(fd);
	if (read_ret != file_stats.st_size) {
		printf("error: %s\nread %d bytes, expected %ld\n", strerror(errno),
			read_ret, file_stats.st_size);
		return (free(data.v_buf), 2);
	}
	if (!is_elf(data.buf, file_stats)) {
		return (free(data.v_buf), 1);
	}
	printf("*************************************\n");
	main_loop(&data);

	free(data.v_buf);
	return (0);
}
