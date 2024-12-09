#include <elf_parser.h>

void	print64_sh_name(Elf64_Shdr *header) {
	Elf64_Word	val = header->sh_name;
	printf("sh_name: string table index: %u", val);
	if (val > SHN_HIRESERVE) {
		printf(": not a reserved index");
	} else {
		printf(": reserved index");
	}
	if (val == SHN_UNDEF) {
		printf(": Undefined section");
	} else if (val == SHN_BEFORE) {
		printf(": Order section before all others(Solaris)");
	} else if (val == SHN_AFTER) {
		printf(": Order section after all others(Solaris)");
	}
	if (val >= SHN_LOPROC && val < SHN_HIPROC) {
		printf(": Prooessor-specific");
	} else if (val >= SHN_LOOS && val < SHN_HIOS) {
		printf(": OS-specific");
	}

	if (val == SHN_ABS) {
		printf(": Associated symbol is absolute");
	} else if (val == SHN_COMMON) {
		printf(": Associated symbol is common");
	} else if (val == SHN_XINDEX) {
		printf(": index is in extra table");
	}
	printf("\n");
}

void	print64_sh_type(Elf64_Shdr *header) {
	Elf64_Word	val = header->sh_type;
	printf("sh_type (Section type): %u", val);

	switch (val) {
		case (SHT_NULL):
			printf(": Section header table entry unused");
			break ;
		case (SHT_PROGBITS):
			printf(": Program data");
			break ;
		case (SHT_SYMTAB):
			printf(": Symbol table");
			break ;
		case (SHT_STRTAB):
			printf(": String table");
			break ;
		case (SHT_RELA):
			printf(": Relocation entries with addends");
			break ;
		case (SHT_HASH):
			printf(": Symbol hash table");
			break ;
		case (SHT_DYNAMIC):
			printf(": Dynamic linking information");
			break ;
		case (SHT_NOTE):
			printf(": Notes");
			break ;
		case (SHT_NOBITS):
			printf(": Program space with no data (bss)");
			break ;
		case (SHT_REL):
			printf(": Relocation entries, no addends");
			break ;
		case (SHT_SHLIB):
			printf(": Reserved");
			break ;
		case (SHT_DYNSYM):
			printf(": Dynamic linker symbol table");
			break ;
		case (SHT_INIT_ARRAY):
			printf(": Array of constructors");
			break ;
		case (SHT_FINI_ARRAY):
			printf(": Array of destructors");
			break ;
		case (SHT_PREINIT_ARRAY):
			printf(": Array of pre-constructors");
			break ;
		case (SHT_GROUP):
			printf(": Section group");
			break ;
		case (SHT_SYMTAB_SHNDX):
			printf(": Extended section indices");
			break ;
		case (SHT_RELR):
			printf(": RELR relative relocations");
			break ;
		case (SHT_GNU_ATTRIBUTES):
			printf(" Object attributes.");
			break ;
		case (SHT_GNU_HASH):
			printf(" GNU-style hash table.");
			break ;
		case (SHT_GNU_LIBLIST):
			printf(" Prelink library list");
			break ;
		case (SHT_CHECKSUM):
			printf(" Checksum for DSO content");
			break ;
		case (SHT_SUNW_move):
			printf(" SHT_SUNW_move");
			break ;
		case (SHT_SUNW_COMDAT):
			printf(" SHT_SUNW_COMDAT");
			break ;
		case (SHT_SUNW_syminfo):
			printf(" SHT_SUNW_syminfo");
			break ;
		case (SHT_GNU_verdef):
			printf(" Version definition section");
			break ;
		case (SHT_GNU_verneed):
			printf(" Version needs section");
			break ;
		case (SHT_GNU_versym):
			printf(" Version symbol table");
			break ;
	}
	if (val >= SHT_LOOS && val < SHT_HIOS) {
		printf(": OS-specific");
	}
	if (val >= SHT_LOSUNW && val < SHT_HISUNW) {
		printf(": Sun-specific");
	}
	if (val >= SHT_LOPROC && val < SHT_HIPROC) {
		printf(": processor-specific");
	}
	if (val >= SHT_LOUSER && val < SHT_HIUSER) {
		printf(": application-specific");
	}
	printf("\n");
}

void	print64_sh_flags(Elf64_Shdr *header) {
	Elf64_Xword	val = header->sh_flags;
	printf("sh_flags ( Section flags): %lu", val);

	if (val & SHF_WRITE) {
		printf(": Writable");
	}
	if (val & SHF_ALLOC) {
		printf(": Occupies memory during execution");
	}
	if (val & SHF_EXECINSTR) {
		printf(": Executable");
	}
	if (val & SHF_MERGE) {
		printf(": Might be merged");
	}
	if (val & SHF_STRINGS) {
		printf(": Contains nul-terminated strings");
	}
	if (val & SHF_INFO_LINK) {
		printf(": `sh_info' contains SHT index");
	}
	if (val & SHF_LINK_ORDER) {
		printf(": Preserve order after combining");
	}
	if (val & SHF_OS_NONCONFORMING) {
		printf(": Non-standard OS specific handling required");
	}
	if (val & SHF_GROUP) {
		printf(": Section is member of a group. ");
	}
	if (val & SHF_TLS) {
		printf(": Section hold thread-local data.");
	}
	if (val & SHF_COMPRESSED) {
		printf(": Section with compressed data.");
	}
	if (val & SHF_MASKOS) {
		printf(": OS-specific.");
	}
	if (val & SHF_MASKPROC) {
		printf(": Processor-specific");
	}
	if (val & SHF_GNU_RETAIN) {
		printf(": Not to be GCed by linker. ");
	}
	if (val & SHF_ORDERED) {
		printf(": Special ordering requirement (Solaris)");
	}
	if (val & SHF_EXCLUDE) {
		printf(": Section is excluded unless referenced or allocated (Solaris)");
	}
	printf("\n");
}

void	print64_sh_addr(Elf64_Shdr *header) {
	printf("sh_addr (Section virtual addr at execution): %lu\n", header->sh_addr);
}

void	print64_sh_offset(Elf64_Shdr *header) {
	printf("sh_offset (* Section file offset): %lu\n", header->sh_offset);
}

void	print64_sh_size(Elf64_Shdr *header) {
	printf("sh_size (Section size in bytes): %lu\n", header->sh_size);
}

void	print64_sh_link(Elf64_Shdr *header) {
	printf("sh_link (Link to another section): %u\n", header->sh_link);
}

void	print64_sh_info(Elf64_Shdr *header) {
	printf("sh_info (Additional section information): %u\n", header->sh_info);
}

void	print64_sh_addralign(Elf64_Shdr *header) {
	printf("sh_addralign: (Section alignment): %lu\n", header->sh_addralign);
}

void	print64_sh_entsize(Elf64_Shdr *header) {
	printf("sh_entsize (Entry size if section holds table): %lu\n", header->sh_entsize);
}

void	print_Elf64_Shdr(Elf64_Shdr *header) {
	print64_sh_name(header);
	print64_sh_type(header);
	print64_sh_flags(header);
	print64_sh_addr(header);
	print64_sh_offset(header);
	print64_sh_size(header);
	print64_sh_link(header);
	print64_sh_info(header);
	print64_sh_addralign(header);
	print64_sh_entsize(header);
}

/*args: int *idx */
static bool	print_cur(t_elf_parser *data, char *line, va_list args) {
	if (strcmp(line, "c") && strcmp(line, "cur") && strcmp(line, "current")) {
		return (false);
	}

	int	*idx = va_arg(args, int *);

	printf("cur: %d\n", *idx);
	Elf64_Shdr	*section_table = 
		(Elf64_Shdr *)(data->buf + data->main_header->e_shoff);

	print_Elf64_Shdr(section_table + *idx);
	return (true);
}

/*args: int *idx */
static bool	print_next(t_elf_parser *data, char *line, va_list args) {
	if (strcmp(line, "n") && strcmp(line, "next")) {
		return (false);
	}

	int	*idx = va_arg(args, int *);

	printf("next: %d\n", *idx);
	Elf64_Shdr	*section_table = 
		(Elf64_Shdr *)(data->buf + data->main_header->e_shoff);

	print_Elf64_Shdr(section_table + *idx);
	*idx = ((*idx) + 1) % data->main_header->e_shnum;
	return (true);
}

/*args: int *idx */
static bool	print_last(t_elf_parser *data, char *line, va_list args) {
	if (strcmp(line, "l") && strcmp(line, "last")) {
		return (false);
	}
	int	*idx = va_arg(args, int *);

	printf("last: %d\n", *idx);
	Elf64_Shdr	*section_table = 
		(Elf64_Shdr *)(data->buf + data->main_header->e_shoff);

	*idx = (*idx) - 1;
	if (*idx < 0) {
		*idx = data->main_header->e_shnum - 1;
	}
	print_Elf64_Shdr(section_table + *idx);
	return (true);
}

static bool	print_all(t_elf_parser *data, char *line, va_list args) {
	(void)args;
	if (strcmp(line, "all")) {
		return (false);
	}

	Elf64_Shdr	*section_table =
		(Elf64_Shdr *)(data->buf + data->main_header->e_shoff);

	for (size_t i = 0; i < data->main_header->e_shnum; i++) {
		printf(FT_ANSI_GREEN FT_ANSI_BOLD "Section entry %lu:\n" FT_ANSI_RESET,
			i);
		print_Elf64_Shdr(section_table + i);
	}
	return (true);
}

static bool	print_idx(t_elf_parser *data, char *line, va_list args) {
	(void)args;
	if (!isdigit(line[0])) {
		return (false);
	}
	int	idx = atoi(line);
	if (idx < 0 || idx >= data->main_header->e_shnum) {
		return (false);
	}

	Elf64_Shdr	*section_table = 
		(Elf64_Shdr *)(data->buf + data->main_header->e_shoff);

	printf("FT_ANSI_YELLOW" "Section header %d:\n" FT_ANSI_RESET, idx);
	assert(idx >= 0 && idx < data->main_header->e_shnum);
	print_Elf64_Shdr(section_table + idx);
	return (true);
}

bool	print_section_headers(t_elf_parser *data, char *input_line,
			va_list args)
{
	(void)args;
	if (strcmp(input_line, "section table")) {
		return (false);
	}
	if (!data->main_header->e_shnum) {
		printf("Section table is empty\n");
		return (true);
	}
	char	*command_strs[] = {
		ANSI_COMMAND_TITLE
			"Avialable commands to print section_headers:" FT_ANSI_RESET,
		ANSI_COMMAND "'current'/'cur'/'c'" FT_ANSI_RESET,
		ANSI_COMMAND "'next'/'n'" FT_ANSI_RESET,
		ANSI_COMMAND "'last'/'l'" FT_ANSI_RESET,
		ANSI_COMMAND "'<idx>'" FT_ANSI_RESET,
		ANSI_COMMAND "'all'" FT_ANSI_RESET,
		ANSI_COMMAND "'return'"FT_ANSI_RESET,
		ANSI_COMMAND "'exit'" FT_ANSI_RESET
	};
	size_t	command_str_count = sizeof command_strs / sizeof command_strs[0];
	t_callable	commands[] = {
		print_cur,
		print_next,
		print_last,
		print_idx,
		print_all,
	};
	size_t	command_count = sizeof commands / sizeof commands[0];
	int	section_idx = 0;
	while (1) {
		for (size_t j = 0; j < data->global_command_str_count; j++){
			printf("\t%s\n", data->global_command_strs[j]);
		}
		for (size_t j = 0; j < command_str_count; j++){
			printf("\t%s\n", command_strs[j]);
		}
		printf(FT_ANSI_RESET);
		char	*line = readline("enter command: ");
		if (!line) {
			continue ;
		}
		t_callable_action	callable_ret =
			check_callables(commands, command_count, data, line, &section_idx);
		if (callable_ret == CALLABLE_RETURN) {
			return (true);
		}
		printf(FT_ANSI_ITALIC FT_ANSI_GREEN "Currently in <section headers>"
			" with current header == <%d>\n", section_idx);
	}
}
