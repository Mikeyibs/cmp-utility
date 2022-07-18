#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
   FILE *fp;
   FILE *fp2;
   char c1;
   char c2;
   int byte = 0;
   int line = 1;

   if( argc == 3 )
   {
      fp = fopen( argv[1], "r" );
      if( fp == NULL )
      {
         return 0;
      }

      fp2   = fopen( argv[2], "r" );
      if( fp2 == NULL )
      {
         return 0;
      }

      while (1)
      {
         c1 = fgetc( fp );
         c2 = fgetc( fp2 );
         byte++;

         if( c1 == '\n' && c2 == '\n' )
         {
            line++;
         }

         if( c1 != c2 && c2 != EOF && c1 != EOF )
         {
            printf("%s %s differ: byte %d, line %d\n", argv[1], argv[2], byte, line);
            return 1;
            break;
         }

         if( c1 == EOF )
         {
            line--;
            byte--;
            printf("cmp: EOF on %s after byte %d, line %d\n", argv[1], byte, line);
            return 1;
            break;
         }

         if( c2 == EOF )
         {
            line--;
            byte--;
            printf("cmp: EOF on %s after byte %d, line %d\n", argv[2], byte, line);
            break;
         }
      }
   }
   else if ( argc < 3 )
   {
      printf("Too few args\n");
      return 2;
   }
   else
   {
      printf("Too many args\n");
      return 2;
   }

   return 0;
}
