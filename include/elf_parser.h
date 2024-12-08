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


void print64(Elf64_Ehdr *header);
