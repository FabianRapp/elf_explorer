#include <elf_parser.h>
/* this file is based on elf.h on my system */

void	print64_type(Elf64_Ehdr *header) {
	Elf64_Half	val = header->e_type;

	switch (val) {
		case (ET_NONE):
			printf("ET_NONE: %s\n", "No file type");
			break ;
		case (ET_REL):
			printf("ET_REL: %s\n", "Relocatable file");
			break ;
		case (ET_EXEC):
			printf("ET_EXEC: %s\n", "Executable file");
			break ;
		case (ET_DYN):
			printf("ET_DYN: %s\n", "Shared object file");
			break ;
		case (ET_CORE):
			printf("ET_CORE: %s\n", "Core file");
			break ;
		case (ET_NUM):
			printf("ET_NUM: %s\n", "Number of defined types");
			break ;
		case (ET_LOOS):
			printf("ET_LOOS: %s\n", "OS-specific range start");
			break ;
		case (ET_HIOS):
			printf("ET_HIOS: %s\n", "OS-specific range end");
			break ;
		case (ET_LOPROC):
			printf("ET_LOPROC: %s\n", "Processor-specific range start");
			break ;
		case (ET_HIPROC):
			printf("ET_HIPROC: %s\n", "Processor-specific range end");
			break ;
		default:
			printf("Unkonow type: %u\n", val);
	}
}

void	print64_emachine(Elf64_Ehdr *header) {
	Elf64_Half	val = header->e_machine;
	switch (val) {
		case (EM_NONE):
			printf("EM_NONE: %s\n", "No machine");
			break ;
		case (EM_M32):
			printf("EM_M32: %s\n", "AT&T WE 32100");
			break ;
		case (EM_SPARC):
			printf("EM_SPARC: %s\n", "SUN SPARC");
			break ;
		case (EM_386):
			printf("EM_386: %s\n", "Intel 80386");
			break ;
		case (EM_68K):
			printf("EM_68K: %s\n", "Motorola m68k family");
			break ;
		case (EM_88K):
			printf("EM_88K: %s\n", "Motorola m88k family");
			break ;
		case (EM_IAMCU):
			printf("EM_IAMCU: %s\n", "Intel MCU");
			break ;
		case (EM_860):
			printf("EM_860: %s\n", "Intel 80860");
			break ;
		case (EM_MIPS):
			printf("EM_MIPS: %s\n", "MIPS R3000 big-endian");
			break ;
		case (EM_S370):
			printf("EM_S370: %s\n", "IBM System/370");
			break ;
		case (EM_MIPS_RS3_LE):
			printf("EM_MIPS_RS3_LE: %s\n", "MIPS R3000 little-endian");
			break ;
		case (EM_PARISC):
			printf("EM_PARISC: %s\n", "HPPA");
			break ;
		case (EM_VPP500):
			printf("EM_VPP500: %s\n", "Fujitsu VPP500");
			break ;
		case (EM_SPARC32PLUS):
			printf("EM_SPARC32PLUS: %s\n", "Sun's \"v8plus\"");
			break ;
		case (EM_960):
			printf("EM_960: %s\n", "Intel 80960");
			break ;
		case (EM_PPC):
			printf("EM_PPC: %s\n", "PowerPC");
			break ;
		case (EM_PPC64):
			printf("EM_PPC64: %s\n", "PowerPC 64-bit");
			break ;
		case (EM_S390):
			printf("EM_S390: %s\n", "IBM S390");
			break ;
		case (EM_SPU):
			printf("EM_SPU: %s\n", "IBM SPU/SPC");
			break ;
		case (EM_V800):
			printf("EM_V800: %s\n", "NEC V800 series");
			break ;
		case (EM_FR20):
			printf("EM_FR20: %s\n", "Fujitsu FR20");
			break ;
		case (EM_RH32):
			printf("EM_RH32: %s\n", "TRW RH-32");
			break ;
		case (EM_RCE):
			printf("EM_RCE: %s\n", "Motorola RCE");
			break ;
		case (EM_ARM):
			printf("EM_ARM: %s\n", "ARM");
			break ;
		case (EM_FAKE_ALPHA):
			printf("EM_FAKE_ALPHA: %s\n", "Digital Alpha");
			break ;
		case (EM_SH):
			printf("EM_SH: %s\n", "Hitachi SH");
			break ;
		case (EM_SPARCV9):
			printf("EM_SPARCV9: %s\n", "SPARC v9 64-bit");
			break ;
		case (EM_TRICORE):
			printf("EM_TRICORE: %s\n", "Siemens Tricore");
			break ;
		case (EM_ARC):
			printf("EM_ARC: %s\n", "Argonaut RISC Core");
			break ;
		case (EM_H8_300):
			printf("EM_H8_300: %s\n", "Hitachi H8/300");
			break ;
		case (EM_H8_300H):
			printf("EM_H8_300H: %s\n", "Hitachi H8/300H");
			break ;
		case (EM_H8S):
			printf("EM_H8S: %s\n", "Hitachi H8S");
			break ;
		case (EM_H8_500):
			printf("EM_H8_500: %s\n", "Hitachi H8/500");
			break ;
		case (EM_IA_64):
			printf("EM_IA_64: %s\n", "Intel Merced");
			break ;
		case (EM_MIPS_X):
			printf("EM_MIPS_X: %s\n", "Stanford MIPS-X");
			break ;
		case (EM_COLDFIRE):
			printf("EM_COLDFIRE: %s\n", "Motorola Coldfire");
			break ;
		case (EM_68HC12):
			printf("EM_68HC12: %s\n", "Motorola M68HC12");
			break ;
		case (EM_MMA):
			printf("EM_MMA: %s\n", "Fujitsu MMA Multimedia Accelerator");
			break ;
		case (EM_PCP):
			printf("EM_PCP: %s\n", "Siemens PCP");
			break ;
		case (EM_NCPU):
			printf("EM_NCPU: %s\n", "Sony nCPU embedded RISC");
			break ;
		case (EM_NDR1):
			printf("EM_NDR1: %s\n", "Denso NDR1 microprocessor");
			break ;
		case (EM_STARCORE):
			printf("EM_STARCORE: %s\n", "Motorola Start*Core processor");
			break ;
		case (EM_ME16):
			printf("EM_ME16: %s\n", "Toyota ME16 processor");
			break ;
		case (EM_ST100):
			printf("EM_ST100: %s\n", "STMicroelectronic ST100 processor");
			break ;
		case (EM_TINYJ):
			printf("EM_TINYJ: %s\n", "Advanced Logic Corp. Tinyj emb.fam");
			break ;
		case (EM_X86_64):
			printf("EM_X86_64: %s\n", "AMD x86-64 architecture");
			break ;
		case (EM_PDSP):
			printf("EM_PDSP: %s\n", "Sony DSP Processor");
			break ;
		case (EM_PDP10):
			printf("EM_PDP10: %s\n", "Digital PDP-10");
			break ;
		case (EM_PDP11):
			printf("EM_PDP11: %s\n", "Digital PDP-11");
			break ;
		case (EM_FX66):
			printf("EM_FX66: %s\n", "Siemens FX66 microcontroller");
			break ;
		case (EM_ST9PLUS):
			printf("EM_ST9PLUS: %s\n", "STMicroelectronics ST9+ 8/16 mc");
			break ;
		case (EM_ST7):
			printf("EM_ST7: %s\n", "STmicroelectronics ST7 8 bit mc");
			break ;
		case (EM_68HC16):
			printf("EM_68HC16: %s\n", "Motorola MC68HC16 microcontroller");
			break ;
		case (EM_68HC11):
			printf("EM_68HC11: %s\n", "Motorola MC68HC11 microcontroller");
			break ;
		case (EM_68HC08):
			printf("EM_68HC08: %s\n", "Motorola MC68HC08 microcontroller");
			break ;
		case (EM_68HC05):
			printf("EM_68HC05: %s\n", "Motorola MC68HC05 microcontroller");
			break ;
		case (EM_SVX):
			printf("EM_SVX: %s\n", "Silicon Graphics SVx");
			break ;
		case (EM_ST19):
			printf("EM_ST19: %s\n", "STMicroelectronics ST19 8 bit mc");
			break ;
		case (EM_VAX):
			printf("EM_VAX: %s\n", "Digital VAX");
			break ;
		case (EM_CRIS):
			printf("EM_CRIS: %s\n", "Axis Communications 32-bit emb.proc");
			break ;
		case (EM_JAVELIN):
			printf("EM_JAVELIN: %s\n", "Infineon Technologies 32-bit emb.proc");
			break ;
		case (EM_FIREPATH):
			printf("EM_FIREPATH: %s\n", "Element 14 64-bit DSP Processor");
			break ;
		case (EM_ZSP):
			printf("EM_ZSP: %s\n", "LSI Logic 16-bit DSP Processor");
			break ;
		case (EM_MMIX):
			printf("EM_MMIX: %s\n", "Donald Knuth's educational 64-bit proc");
			break ;
		case (EM_HUANY):
			printf("EM_HUANY: %s\n", "Harvard University machine-independent object files");
			break ;
		case (EM_PRISM):
			printf("EM_PRISM: %s\n", "SiTera Prism");
			break ;
		case (EM_AVR):
			printf("EM_AVR: %s\n", "Atmel AVR 8-bit microcontroller");
			break ;
		case (EM_FR30):
			printf("EM_FR30: %s\n", "Fujitsu FR30");
			break ;
		case (EM_D10V):
			printf("EM_D10V: %s\n", "Mitsubishi D10V");
			break ;
		case (EM_D30V):
			printf("EM_D30V: %s\n", "Mitsubishi D30V");
			break ;
		case (EM_V850):
			printf("EM_V850: %s\n", "NEC v850");
			break ;
		case (EM_M32R):
			printf("EM_M32R: %s\n", "Mitsubishi M32R");
			break ;
		case (EM_MN10300):
			printf("EM_MN10300: %s\n", "Matsushita MN10300");
			break ;
		case (EM_MN10200):
			printf("EM_MN10200: %s\n", "Matsushita MN10200");
			break ;
		case (EM_PJ):
			printf("EM_PJ: %s\n", "picoJava");
			break ;
		case (EM_OPENRISC):
			printf("EM_OPENRISC: %s\n", "OpenRISC 32-bit embedded processor");
			break ;
		case (EM_ARC_COMPACT):
			printf("EM_ARC_COMPACT/EM_ARC_A5: %s\n", "ARC International ARCompact");
			break ;
		case (EM_XTENSA):
			printf("EM_XTENSA: %s\n", "Tensilica Xtensa Architecture");
			break ;
		case (EM_VIDEOCORE):
			printf("EM_VIDEOCORE: %s\n", "Alphamosaic VideoCore");
			break ;
		case (EM_TMM_GPP):
			printf("EM_TMM_GPP: %s\n", "Thompson Multimedia General Purpose Proc");
			break ;
		case (EM_NS32K):
			printf("EM_NS32K: %s\n", "National Semi. 32000");
			break ;
		case (EM_TPC):
			printf("EM_TPC: %s\n", "Tenor Network TPC");
			break ;
		case (EM_SNP1K):
			printf("EM_SNP1K: %s\n", "Trebia SNP 1000");
			break ;
		case (EM_ST200):
			printf("EM_ST200: %s\n", "STMicroelectronics ST200");
			break ;
		case (EM_IP2K):
			printf("EM_IP2K: %s\n", "Ubicom IP2xxx");
			break ;
		case (EM_MAX):
			printf("EM_MAX: %s\n", "MAX processor");
			break ;
		case (EM_CR):
			printf("EM_CR: %s\n", "National Semi. CompactRISC");
			break ;
		case (EM_F2MC16):
			printf("EM_F2MC16: %s\n", "Fujitsu F2MC16");
			break ;
		case (EM_MSP430):
			printf("EM_MSP430: %s\n", "Texas Instruments msp430");
			break ;
		case (EM_BLACKFIN):
			printf("EM_BLACKFIN: %s\n", "Analog Devices Blackfin DSP");
			break ;
		case (EM_SE_C33):
			printf("EM_SE_C33: %s\n", "Seiko Epson S1C33 family");
			break ;
		case (EM_SEP):
			printf("EM_SEP: %s\n", "Sharp embedded microprocessor");
			break ;
		case (EM_ARCA):
			printf("EM_ARCA: %s\n", "Arca RISC");
			break ;
		case (EM_UNICORE):
			printf("EM_UNICORE: %s\n", "PKU-Unity & MPRC Peking Uni. mc series");
			break ;
		case (EM_EXCESS):
			printf("EM_EXCESS: %s\n", "eXcess configurable cpu");
			break ;
		case (EM_DXP):
			printf("EM_DXP: %s\n", "Icera Semi. Deep Execution Processor");
			break ;
		case (EM_ALTERA_NIOS2):
			printf("EM_ALTERA_NIOS2: %s\n", "Altera Nios II");
			break ;
		case (EM_CRX):
			printf("EM_CRX: %s\n", "National Semi. CompactRISC CRX");
			break ;
		case (EM_XGATE):
			printf("EM_XGATE: %s\n", "Motorola XGATE");
			break ;
		case (EM_C166):
			printf("EM_C166: %s\n", "Infineon C16x/XC16x");
			break ;
		case (EM_M16C):
			printf("EM_M16C: %s\n", "Renesas M16C");
			break ;
		case (EM_DSPIC30F):
			printf("EM_DSPIC30F: %s\n", "Microchip Technology dsPIC30F");
			break ;
		case (EM_CE):
			printf("EM_CE: %s\n", "Freescale Communication Engine RISC");
			break ;
		case (EM_M32C):
			printf("EM_M32C: %s\n", "Renesas M32C");
			break ;
		case (EM_TSK3000):
			printf("EM_TSK3000: %s\n", "Altium TSK3000");
			break ;
		case (EM_RS08):
			printf("EM_RS08: %s\n", "Freescale RS08");
			break ;
		case (EM_SHARC):
			printf("EM_SHARC: %s\n", "Analog Devices SHARC family");
			break ;
		case (EM_ECOG2):
			printf("EM_ECOG2: %s\n", "Cyan Technology eCOG2");
			break ;
		case (EM_SCORE7):
			printf("EM_SCORE7: %s\n", "Sunplus S+core7 RISC");
			break ;
		case (EM_DSP24):
			printf("EM_DSP24: %s\n", "New Japan Radio (NJR) 24-bit DSP");
			break ;
		case (EM_VIDEOCORE3):
			printf("EM_VIDEOCORE3: %s\n", "Broadcom VideoCore III");
			break ;
		case (EM_LATTICEMICO32):
			printf("EM_LATTICEMICO32: %s\n", "RISC for Lattice FPGA");
			break ;
		case (EM_SE_C17):
			printf("EM_SE_C17: %s\n", "Seiko Epson C17");
			break ;
		case (EM_TI_C6000):
			printf("EM_TI_C6000: %s\n", "Texas Instruments TMS320C6000 DSP");
			break ;
		case (EM_TI_C2000):
			printf("EM_TI_C2000: %s\n", "Texas Instruments TMS320C2000 DSP");
			break ;
		case (EM_TI_C5500):
			printf("EM_TI_C5500: %s\n", "Texas Instruments TMS320C55x DSP");
			break ;
		case (EM_TI_ARP32):
			printf("EM_TI_ARP32: %s\n", "Texas Instruments App. Specific RISC");
			break ;
		case (EM_TI_PRU):
			printf("EM_TI_PRU: %s\n", "Texas Instruments Prog. Realtime Unit");
			break ;
		case (EM_MMDSP_PLUS):
			printf("EM_MMDSP_PLUS: %s\n", "STMicroelectronics 64bit VLIW DSP");
			break ;
		case (EM_CYPRESS_M8C):
			printf("EM_CYPRESS_M8C: %s\n", "Cypress M8C");
			break ;
		case (EM_R32C):
			printf("EM_R32C: %s\n", "Renesas R32C");
			break ;
		case (EM_TRIMEDIA):
			printf("EM_TRIMEDIA: %s\n", "NXP Semi. TriMedia");
			break ;
		case (EM_QDSP6):
			printf("EM_QDSP6: %s\n", "QUALCOMM DSP6");
			break ;
		case (EM_8051):
			printf("EM_8051: %s\n", "Intel 8051 and variants");
			break ;
		case (EM_STXP7X):
			printf("EM_STXP7X: %s\n", "STMicroelectronics STxP7x");
			break ;
		case (EM_NDS32):
			printf("EM_NDS32: %s\n", "Andes Tech. compact code emb. RISC");
			break ;
		case (EM_ECOG1X):
			printf("EM_ECOG1X: %s\n", "Cyan Technology eCOG1X");
			break ;
		case (EM_MAXQ30):
			printf("EM_MAXQ30: %s\n", "Dallas Semi. MAXQ30 mc");
			break ;
		case (EM_XIMO16):
			printf("EM_XIMO16: %s\n", "New Japan Radio (NJR) 16-bit DSP");
			break ;
		case (EM_MANIK):
			printf("EM_MANIK: %s\n", "M2000 Reconfigurable RISC");
			break ;
		case (EM_CRAYNV2):
			printf("EM_CRAYNV2: %s\n", "Cray NV2 vector architecture");
			break ;
		case (EM_RX):
			printf("EM_RX: %s\n", "Renesas RX");
			break ;
		case (EM_METAG):
			printf("EM_METAG: %s\n", "Imagination Tech. META");
			break ;
		case (EM_MCST_ELBRUS):
			printf("EM_MCST_ELBRUS: %s\n", "MCST Elbrus");
			break ;
		case (EM_ECOG16):
			printf("EM_ECOG16: %s\n", "Cyan Technology eCOG16");
			break ;
		case (EM_CR16):
			printf("EM_CR16: %s\n", "National Semi. CompactRISC CR16");
			break ;
		case (EM_ETPU):
			printf("EM_ETPU: %s\n", "Freescale Extended Time Processing Unit");
			break ;
		case (EM_SLE9X):
			printf("EM_SLE9X: %s\n", "Infineon Tech. SLE9X");
			break ;
		case (EM_L10M):
			printf("EM_L10M: %s\n", "Intel L10M");
			break ;
		case (EM_K10M):
			printf("EM_K10M: %s\n", "Intel K10M");
			break ;
		case (EM_AARCH64):
			printf("EM_AARCH64: %s\n", "ARM AARCH64");
			break ;
		case (EM_AVR32):
			printf("EM_AVR32: %s\n", "Amtel 32-bit microprocessor");
			break ;
		case (EM_STM8):
			printf("EM_STM8: %s\n", "STMicroelectronics STM8");
			break ;
		case (EM_TILE64):
			printf("EM_TILE64: %s\n", "Tilera TILE64");
			break ;
		case (EM_TILEPRO):
			printf("EM_TILEPRO: %s\n", "Tilera TILEPro");
			break ;
		case (EM_MICROBLAZE):
			printf("EM_MICROBLAZE: %s\n", "Xilinx MicroBlaze");
			break ;
		case (EM_CUDA):
			printf("EM_CUDA: %s\n", "NVIDIA CUDA");
			break ;
		case (EM_TILEGX):
			printf("EM_TILEGX: %s\n", "Tilera TILE-Gx");
			break ;
		case (EM_CLOUDSHIELD):
			printf("EM_CLOUDSHIELD: %s\n", "CloudShield");
			break ;
		case (EM_COREA_1ST):
			printf("EM_COREA_1ST: %s\n", "KIPO-KAIST Core-A 1st gen.");
			break ;
		case (EM_COREA_2ND):
			printf("EM_COREA_2ND: %s\n", "KIPO-KAIST Core-A 2nd gen.");
			break ;
		case (EM_ARCV2):
			printf("EM_ARCV2: %s\n", "Synopsys ARCv2 ISA. ");
			break ;
		case (EM_OPEN8):
			printf("EM_OPEN8: %s\n", "Open8 RISC");
			break ;
		case (EM_RL78):
			printf("EM_RL78: %s\n", "Renesas RL78");
			break ;
		case (EM_VIDEOCORE5):
			printf("EM_VIDEOCORE5: %s\n", "Broadcom VideoCore V");
			break ;
		case (EM_78KOR):
			printf("EM_78KOR: %s\n", "Renesas 78KOR");
			break ;
		case (EM_56800EX):
			printf("EM_56800EX: %s\n", "Freescale 56800EX DSC");
			break ;
		case (EM_BA1):
			printf("EM_BA1: %s\n", "Beyond BA1");
			break ;
		case (EM_BA2):
			printf("EM_BA2: %s\n", "Beyond BA2");
			break ;
		case (EM_XCORE):
			printf("EM_XCORE: %s\n", "XMOS xCORE");
			break ;
		case (EM_MCHP_PIC):
			printf("EM_MCHP_PIC: %s\n", "Microchip 8-bit PIC(r)");
			break ;
		case (EM_INTELGT):
			printf("EM_INTELGT: %s\n", "Intel Graphics Technology");
			break ;
		case (EM_KM32):
			printf("EM_KM32: %s\n", "KM211 KM32");
			break ;
		case (EM_KMX32):
			printf("EM_KMX32: %s\n", "KM211 KMX32");
			break ;
		case (EM_EMX16):
			printf("EM_EMX16: %s\n", "KM211 KMX16");
			break ;
		case (EM_EMX8):
			printf("EM_EMX8: %s\n", "KM211 KMX8");
			break ;
		case (EM_KVARC):
			printf("EM_KVARC: %s\n", "KM211 KVARC");
			break ;
		case (EM_CDP):
			printf("EM_CDP: %s\n", "Paneve CDP");
			break ;
		case (EM_COGE):
			printf("EM_COGE: %s\n", "Cognitive Smart Memory Processor");
			break ;
		case (EM_COOL):
			printf("EM_COOL: %s\n", "Bluechip CoolEngine");
			break ;
		case (EM_NORC):
			printf("EM_NORC: %s\n", "Nanoradio Optimized RISC");
			break ;
		case (EM_CSR_KALIMBA):
			printf("EM_CSR_KALIMBA: %s\n", "CSR Kalimba");
			break ;
		case (EM_Z80):
			printf("EM_Z80: %s\n", "Zilog Z80");
			break ;
		case (EM_VISIUM):
			printf("EM_VISIUM: %s\n", "Controls and Data Services VISIUMcore");
			break ;
		case (EM_FT32):
			printf("EM_FT32: %s\n", "FTDI Chip FT32");
			break ;
		case (EM_MOXIE):
			printf("EM_MOXIE: %s\n", "Moxie processor");
			break ;
		case (EM_AMDGPU):
			printf("EM_AMDGPU: %s\n", "AMD GPU");
			break ;
		case (EM_RISCV):
			printf("EM_RISCV: %s\n", "RISC-V");
			break ;
		case (EM_BPF):
			printf("EM_BPF: %s\n", "Linux BPF -- in-kernel virtual machine");
			break ;
		case (EM_CSKY):
			printf("EM_CSKY: %s\n", "	/* C-SKY");
			break ;
		case (EM_LOONGARCH):
			printf("EM_LOONGARCH: %s\n", "LoongArch");
			break ;
		default:
			printf("reserved value: %d\n", val);
			break ;
	}
}

void	print64_e_ident(Elf64_Ehdr *header) {
	unsigned char val;
	printf("Magic bytes (header->e_ident[EI_MAG0 - EI_MAG3]): ");
	for (size_t i = 0; i <= EI_MAG3; i++) {
		val = header->e_ident[i];
		printf("%02x(%c) ", val, val);
	}
	printf("\n");

	val = header->e_ident[EI_CLASS];
	switch (val) {
		case ELFCLASSNONE:
			printf("e_ident[EI_CLASS]: ELFCLASSNONE\n");
			break;
		case ELFCLASS32:
			printf("e_ident[EI_CLASS]: ELFCLASS32\n");
			break;
		case ELFCLASS64:
			printf("e_ident[EI_CLASS]: ELFCLASS64\n");
			break;
		default:
			printf("e_ident[EI_CLASS]: NOT STANDARD: %u\n", val);
	}

	val = header->e_ident[EI_DATA];
	switch (val) {
		case ELFDATANONE:
			printf("e_ident[EI_DATA]: ELFDATANONE\n");
			break;
		case ELFDATA2LSB:
			printf("e_ident[EI_DATA]: ELFDATA2LSB (Little Endian)\n");
			break;
		case ELFDATA2MSB:
			printf("e_ident[EI_DATA]: ELFDATA2MSB (Big Endian)\n");
			break;
		default:
			printf("e_ident[EI_DATA]: NOT STANDARD: %u\n", val);
	}

	val = header->e_ident[EI_VERSION];
	printf("e_ident[EI_VERSION]: ");
	switch (val) {
		case (EV_NONE):
			printf("EV_NONE: %s\n", "Invalid ELF version");
			break ;
		case (EV_CURRENT):
			printf("EV_CURRENT: %s\n", "Current version");
			break ;
		default:
			printf("unknow version: %u\n", val);
	}

	printf("e_ident[EI_OSABI]: ");
	val = header->e_ident[EI_OSABI];
	switch (val) {
		case (ELFOSABI_AIX):
			printf("ELFOSABI_AIX: %s\n", "IBM AIX");
			break ;
		case (ELFOSABI_NONE):
			printf("ELFOSABI_NONE: %s\n", "UNIX System V ABI");
			break ;
		case (ELFOSABI_HPUX):
			printf("ELFOSABI_HPUX: %s\n", "HP-UX");
			break ;
		case (ELFOSABI_NETBSD):
			printf("ELFOSABI_NETBSD: %s\n", "NetBSD.");
			break ;
		case (ELFOSABI_GNU):
			printf("ELFOSABI_LINUX/ELFOSABI_GNU: %s\n", "Object uses GNU ELF extensions.");
			break ;
		case (ELFOSABI_SOLARIS):
			printf("ELFOSABI_SOLARIS: %s\n", "Sun Solaris.");
			break ;
		case (ELFOSABI_IRIX):
			printf("ELFOSABI_IRIX: %s\n", "SGI Irix.");
			break ;
		case (ELFOSABI_FREEBSD):
			printf("ELFOSABI_FREEBSD: %s\n", "FreeBSD.");
			break ;
		case (ELFOSABI_TRU64):
			printf("ELFOSABI_TRU64: %s\n", "Compaq TRU64 UNIX.");
			break ;
		case (ELFOSABI_MODESTO):
			printf("ELFOSABI_MODESTO: %s\n", "Novell Modesto.");
			break ;
		case (ELFOSABI_OPENBSD):
			printf("ELFOSABI_OPENBSD: %s\n", "OpenBSD.");
			break ;
		case (ELFOSABI_ARM_AEABI):
			printf("ELFOSABI_ARM_AEABI: %s\n", "ARM EABI");
			break ;
		case (ELFOSABI_ARM):
			printf("ELFOSABI_ARM: %s\n", "ARM");
			break ;
		case (ELFOSABI_STANDALONE):
			printf("ELFOSABI_STANDALONE: %s\n", "Standalone (embedded) application");
			break ;
		default:
			printf("Uknown: %u\n", val);
	}

	printf("e_ident[EI_ABIVERSION]: %d\n", header->e_ident[EI_ABIVERSION]);
	for (unsigned i = 0;
		(i + EI_PAD) < sizeof header->e_ident / sizeof header->e_ident[0];
		i++)
	{
		val = header->e_ident[EI_PAD + i];
		printf("header->e_indent[EI_PAD + %u]: %x\n", i, val);
	}
}

void	print64_e_version(Elf64_Ehdr *header) {
	switch (header->e_version) {
		case(EV_NONE):
			printf("e_version: Invalid ELF version\n");
			break ;
		case(EV_CURRENT):
			printf("e_version: EV_CURRENT\n");
			break ;
		default:
			printf("e_version: UNKNOWN version: %u\n", header->e_version);
	}
}

void	print64_e_falgs(Elf64_Ehdr *header) {
	Elf64_Word	val = header->e_flags;
	printf("e_flags: %u\n", val);
	//todo: print flag strings specific for header->e_machine
}

bool	print_Elf64_Ehdr(t_elf_parser *data, char *input, va_list args) {
	(void)args;
	if (strcmp(input, "main header")) {
		return (false);
	}
	Elf64_Ehdr	*header = data->main_header;
	printf(FT_ANSI_GREEN FT_ANSI_ITALIC "Elf64_Ehdr:\n" FT_ANSI_RESET);
	print64_e_ident(header);
	print64_type(header);
	print64_emachine(header);
	print64_e_version(header);

	printf("e_entry: 0x%lx (Entry point virtual address)\n", header->e_entry);
	printf("e_phoff: 0x%lx (Program header table file offset)\n",
		header->e_phoff);
	printf("e_shoff: 0x%lx (Section header table file offset)\n",
		header->e_shoff);
	print64_e_falgs(header);

	printf("e_ehsize: %d (Size of this header in bytes)\n", header->e_ehsize);

	printf("e_phentsize: %d (Size of an entry in the program header table)\n",
		header->e_phentsize);

	printf("e_phnum: %d (Count of entries in the program header table)\n",
			header->e_phnum);
	printf("e_shentsize: %d (Section header table entry size)\n",
		header->e_shentsize);
	printf("e_shnum: %d (Section header table entry count)\n", header->e_shnum);
	printf("e_shstrndx: %d (Index of the section header string table)\n",
		header->e_shstrndx);
	return (true);
}
