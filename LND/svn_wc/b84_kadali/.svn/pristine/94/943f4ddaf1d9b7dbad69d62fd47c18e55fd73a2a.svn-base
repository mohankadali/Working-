#include "header.h"

bool elf_header ( FILE *name )
{		
	int i;
        //create file pointer
        FILE *fp;
        //create structure instance
        Elf32_Ehdr ehdr;
        //open file
        if(NULL == (fp = fopen(name, "r"))){
                printf("Error\n");
                return 0;
        }

        //read bytes from file
        if(UNSET == fread(&ehdr, MAXBYTES, SET, fp)){
                printf("error\n");
                return 0;
        }
        if(UNVALID == ((ELFMAG0 == ehdr.e_ident[EI_MAG0]) &&
                                (ELFMAG1 == ehdr.e_ident[EI_MAG1])&&
                                (ELFMAG2 == ehdr.e_ident[EI_MAG2])&&
                                (ELFMAG3 == ehdr.e_ident[EI_MAG3]))){
                printf("Not elf format file\n");
                return 0;
        }

        //display magic number from elf header
        printf("\nELF Header:\n");
        printf("%-s","  magic:  ");
        for(i = 0; i < EI_NIDENT; i++){
                printf(" %.2x",ehdr.e_ident[i]);
        }
        //check properties of elf file
        for(i = EI_CLASS; i <= EI_ABIVERSION; i++){
                switch(i){
                        case EI_CLASS:
                                if(ELFCLASS32 == ehdr.e_ident[EI_CLASS]){
                                        printf("\n%-40sELF32","  class:");
                                }else if(ELFCLASS64 == ehdr.e_ident[EI_CLASS]){
                                        printf("\n%-40sELF64","  class:");
                                }else{
                                        printf("\n%-40sInvalid class","  class:");
                                }
                                break;
                        case EI_DATA:
                                if(ELFDATA2LSB == ehdr.e_ident[EI_DATA]){
                                        printf("\n%-40s2's complement, little endian"
                                                        ,"  Data:");
                                }else if(ELFDATA2MSB == ehdr.e_ident[EI_DATA]){
                                        printf("\n%-40s2's complenent, big endian"
                                                        ,"  Data:");
                                }else{
                                        printf("\n%-40sInvalid data type"
                                                        ,"  Data:");
                                }
                                break;
                        case EI_VERSION:
                                printf("\n%-40s%d (current)"
                                                ,"  Version:"
                                                ,ehdr.e_ident[EI_VERSION]);
                                break;
                        case EI_OSABI:
                                if(ELFOSABI_NONE == ehdr.e_ident[EI_OSABI]){
                                        printf("\n%-40sUNIX - System V"
                                                        ,"  OS/ABI:");
                                }else{
                                        printf("\n%-40snot for unix any other"
                                                        ,"  OS/ABI:");
                                }
                                break;
                        case EI_ABIVERSION:
                                printf("\n%-40s%d"
                                                ,"  ABI Version:"
                                                ,ehdr.e_ident[EI_ABIVERSION]);
                                break;
                        default:
                                break;

                }
        }
        //type of file
        switch(ehdr.e_type){

                case ET_NONE:
                        printf("\n%-40sno file type"
                                        ,"  Type:");
                        break;
                case ET_REL:
                        printf("\n%-40sREL (relocatable file)"
                                        ,"  Type:");
                        break;
                case ET_EXEC:
                        printf("\n%-40sEXEC (executable file)"
                                        ,"  Type:");
                        break;
                case ET_DYN:
                        printf("\n%-40sDYN (share object file)"
                                        ,"  Type:");
                        break;
                case ET_CORE:
                        printf("\n%-40sCORE (core file)"
                                        ,"  Type:");
                        break;
                case ET_LOPROC:
                        printf("\n%-40sLOPROC (Processor specific file)"
                                        ,"  Type:");
                        break;
                case ET_HIPROC:
                        printf("\n%-40sHIPROC (Processor specific file)"
                                        ,"  Type:");
                        break;
                default:
                        break;
        }
        //which machine specific file
        switch(ehdr.e_machine){

                case ET_NONE:
                        printf("\n%-40sno Machine"
                                        ,"  Machine:");
                        break;
                case EM_860:
                        printf("\n%-40sIntel Architecture"
                                        ,"  Machine:");
                        break;
                case EM_386:
                        printf("\n%-40sIntel 80386"
                                        ,"  Machine:");
                        break;
                default:
                        break;
        }

        printf("\n%-40s0x%x","  Version:",ehdr.e_version);
        printf("\n%-40s0x%x","  Entry point address:",ehdr.e_entry);
        printf("\n%-40s%d (bytes)","  Start of program headers:",ehdr.e_phoff);
        printf("\n%-40s%d (bytes)","  Start of section headers:",ehdr.e_shoff);
        printf("\n%-40s0x%x","  Flags:",ehdr.e_flags);
        printf("\n%-40s%d (bytes)","  Size of this headers:",ehdr.e_ehsize);
        printf("\n%-40s%d (bytes)","  Size of program headers:",ehdr.e_phentsize);
        printf("\n%-40s%d","  Number of program headers:",ehdr.e_phnum);
        printf("\n%-40s%d (bytes)","  Size of section headers:",ehdr.e_shentsize);
        printf("\n%-40s%d","  Number of Section headers:",ehdr.e_shnum);
        printf("\n%-40s%d","  Section header string table index:",ehdr.e_shstrndx);
}
	
