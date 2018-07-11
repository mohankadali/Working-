#include <stdio.h>
#include <stdlib.h>

#define EI_NIDENT (16)

typedef struct st
{
	unsigned char	e_ident[EI_NIDENT];	/* Magic number and other info */
	short int 	e_type;			/* Object file type */
	short int 	e_machine;		/* Architecture */
	int   e_version;		/* Object file version */
	int   e_entry;		/* Entry point virtual address */
	int   e_phoff;		/* Program header table file offset */
	int   e_shoff;		/* Section header table file offset */
	int   e_flags;		/* Processor-specific flags */
	short int 	e_ehsize;		/* ELF header size in bytes */
	short int 	e_phentsize;		/* Program header table entry size */
	short int 	e_phnum;		/* Program header table entry count */
	short int	e_shentsize;		/* Section header table entry size */
	short int 	e_shnum;		/* Section header table entry count */
	short int 	e_shstrndx;		/* Section header string table index */
} Ehdr;

typedef struct
{
	int 	p_type;			/* Segment type */
	int 	p_offset;		/* Segment file offset */
	int 	p_vaddr;		/* Segment virtual address */
	int 	p_paddr;		/* Segment physical address */
	int 	p_filesz;		/* Segment size in file */
	int 	p_memsz;		/* Segment size in memory */
	int 	p_flags;		/* Segment flags */
	int 	p_align;		/* Segment alignment */
} Phdr;

typedef struct
{
	int 	sh_name;		/* Section name (string tbl index) */
	int 	sh_type;		/* Section type */
	int     sh_flags;		/* Section flags */
	int 	sh_addr;		/* Section virtual addr at execution */
	int 	sh_offset;		/* Section file offset */
	int 	sh_size;		/* Section size in bytes */
	int 	sh_link;		/* Link to another section */
	int 	sh_info;		/* Additional section information */
	int 	sh_addralign;		/* Section alignment */
	int 	sh_entsize;		/* Entry size if section holds table */
} Shdr;

int main (void)
{
	int i;
	FILE *fp;
	struct st *p;
	char buf[60];
	p=buf;	

	fp = fopen ("main.c","r");

	if (fp == NULL) {
		printf ("failed to open\n");
		exit (0);
	}
	fread(buf, 52, 1, fp);
	printf("ELF header\n");
	printf("MAGIC: ");
	for (i=0;i<16;i++) {
		printf("%x ",p->e_ident[i]);
	}
	printf("\n");
	if(buf[4] == 1 )
		printf("CLASS:\t\t\t\t\t ELF32\n");
	if(buf[4] == 2 )
		printf("CLASS:\t\t\t\t\t ELF64"); 

	if(buf[5] == 1 )
		printf("Data:\t\t\t\t\t 2's complement, little endian\n");
	if(buf[5] == 2)
		printf("Data:\t\t\t\t\t 2's complement, big endian\n");

	printf("version:\t\t\t\t %d (current)\n",buf[6]);

	if (buf[7] == 0)
		printf("OS/ABI:\t\t\t\t\t UNIX - System V\n");
	if (buf[7] == 1)
		printf("OS/ABI:\t\t\t\t\t HP - UX\n");

	printf("ABI Version:\t\t\t\t %d\n", buf[8]);

	if(buf[16] == 1)
		printf("Type:\t\t\t\t\t REL (Relocatble file)\n");
	if(buf[16] == 2)
		printf("Type:\t\t\t\t\t EXEC (Executable file)\n");
	if(buf[16] == 3)
		printf("Type:\t\t\t\t\t DYN (Shared object file)\n");

	if (buf[18] == 1)
		printf("Machine:\t\t\t\t AT&T WE 32100\n");
	if (buf[18] == 2)
		printf("Machine:\t\t\t\t SUN SPARC\n");
	if (buf[18] == 3)
		printf("Machine:\t\t\t\t Intel 80386\n");

	printf("Version:\t\t\t\t %d\n", buf[20]);

		p=&buf[24];
		printf("Entry point address:\t\t\t %x\n",*p);

	printf("Start of Program headers:\t\t %d (bytes into file)\n", buf[28]);
	p=&buf[32];
	printf("Start of Section headers:\t\t %d (bytes into file)\n", *p);
	p=&buf[36];
	printf("Flags:\t\t\t\t\t 0x%x\n", *p);

	printf("Size of this headers:\t\t\t %d (bytes)\n", buf[40]);

	printf("Size of Program headers:\t\t %d (bytes)\n", buf[42]);
	
	printf("Number of Program headers:\t\t %d\n", buf[44]);

	printf("Size of Section headers:\t\t %d (bytes)\n", buf[46]);

	printf("Number of Section headers:\t\t %d\n", buf[48]);

	printf("Section header string table index:\t %d\n", buf[50]);


	fclose (fp);
}
