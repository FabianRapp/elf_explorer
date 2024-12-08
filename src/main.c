#include <elf_parser.h>

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

int	main(int ac, char *av[]) {
	if (ac < 2) {
		printf("Need file as args\n");
		return (1);
	}
	char	*file = av[1];
	int	fd = open(file, O_RDONLY);
	assert(fd > 1);
	struct stat	file_stats;
	assert(fstat(fd, &file_stats) != -1);
	void	*buf = malloc(file_stats.st_size);
	assert(buf);
	int read_ret = read(fd, buf, file_stats.st_size);
	close(fd);
	if (read_ret != file_stats.st_size) {
		printf("error: %s\nread %d bytes, expected %ld\n", strerror(errno),
			read_ret, file_stats.st_size);
		return (free(buf), 2);
	}
	if (!is_elf(buf, file_stats)) {
		return (free(buf), 1);
	}
	print64(buf);

	free(buf);
	return (0);
}
