#include<stdio.h> 
#pragma pack(push)

struct st1{
    char  vpi:4;
    int gfc:4;
    char vci:4;
    short vpi1:4;
    char vci1;
    char clp:1;
    int d1:1;
    char pti:1;
    char d2:1;
    short vci2:4;
    char hec;
} __attribute__((packed)) ST;
#pragma pack(pop)

#pragma pack(push)

struct st2{
    short dp;
    short sp;
    int   sn;
    int   an;
    short window;
    short cb:6;
    short reserved:6;
    short header:4;
    short urgent;
    short checksum;
    //    int option;
    //  int data;
}ST2;
#pragma pack(pop)


#pragma pack(push)
struct st3{
    char version:4;
    char hl:4;
    char st;
    short tl;
    short ident;
    short flags:4;
    short fo:12;
    short ttl:8;
    short protocol:8;
    short hc;
    int sipa;
    int dipa;
    int options:19;
    int padding:12;
}ST3;
#pragma pack(pop)
int q1_a()
{
    return sizeof(ST); 
    //      printf("%d    ",sizeof(ST));
    //printf("%d    ",sizeof(ST2));
    // printf("%d    ",sizeof(ST3));
}
int q1_b()
{
    return sizeof(ST2); 
}
int q1_c()
{
    return sizeof(ST3); 
}
