#include <elf_parser.h>

/* adds the given line to the history in case it was valid and always frees it*/
/* shold be simple to enable the option to pass many more t_callable arrays */
t_callable_action	check_callables(t_callable *callables, size_t count,
	t_elf_parser *data, char *line, ...)
{
	va_list	args;

	if (!strcmp(line, "exit")) {
		free(line);
		free(data->main_header);
		exit(0);
	} else if (!strcmp(line, "return")) {
		/* adds 'return' to history even when it's ignored but it's fine */
		add_history(line);
		free(line);
		return (CALLABLE_RETURN);
	}

	t_callable	*command_groups[] = {
		callables,
		data->global_commands,
	};
	size_t		counts_per_group[] = {
		count,
		data->global_command_count,
	};
	size_t		group_count = sizeof command_groups / sizeof command_groups[0];
	for (size_t group_idx = 0;
		group_idx < group_count;
		group_idx++)
	{
		for (size_t command_idx = 0;
			command_idx < counts_per_group[group_idx];
			command_idx++)
		{
			va_start(args, line);
			if (command_groups[group_idx][command_idx](data, line, args)) {
				va_end(args);
				add_history(line);
				free(line);
				return (CALLABLE_SUCCESS);
			}
			va_end(args);
		}
	}
	free(line);
	return (CALLABLE_FAIL);
}

bool	is_elf(uint8_t	*buf, struct stat file_stats) {
	if ((size_t)file_stats.st_size < sizeof(Elf32_Ehdr)) {
		printf("file is too small to be an ELF file\n");
	} else if (memcmp(buf, ELFMAG, 4)) {
		printf("Is not ELF\n");
	} else if (buf[EI_CLASS] != ELFCLASS32 && buf[EI_CLASS] != ELFCLASS64) {
		printf("invalid bit type\n");
	} else if (buf[EI_CLASS] != ELFCLASS64) {
		printf("only 64 bit supported\n");
	} else if (buf[EI_CLASS] == ELFCLASS64
		&& (size_t)file_stats.st_size < sizeof(Elf64_Ehdr))
	{
		printf("file is too small to be a 6 bit ELF file\n");
	} else if (buf[EI_DATA] != ELFDATA2LSB) {
		printf("only little endian files are supported\n");
	} else if (buf[EI_VERSION] != EV_CURRENT) {
		printf("invalid version: %d\n", buf[EI_VERSION]);
	} else {
		return (true);
	}
	return (false);
}
