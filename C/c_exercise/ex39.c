#include <memory.h>
#include <string.h>
#include <stdio.h>

char str1[17] = "abcdef";

int main()
{

   printf( "The string: %s\n", str1 );
   memcpy( (str1+6), str1, 10 );	//memory areas must not overlap
   printf( "New string: %s\n", str1 );

   strcpy( str1, "abcdef" );   // reset string

   printf( "The string: %s\n", str1 );
   memmove( (str1+6), str1, 10 );
   printf( "New string: %s\n", str1 );

}

/*The differernce between memcpy and memmove is that	: 
1.in memmove ,the source memory of specified size is copied into buffer and then moved    
	 to destination. so if the memory is over lapping .there is no side effects.

2.in case of memcpy() ,there is no extra buffer taken for source memory . 
	the copying is done directly on the memory 
	so that when there is memory over lap,we get un expected results.

3.memcpy -->  abcdefabcdefabcd
 memove  -->  abcdefabcdef 
*/
