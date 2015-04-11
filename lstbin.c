#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* helper function to convert a hex string to a binary string */
void hexBin( char* hexstring, char* binstring ) 
{
  char* nchar = hexstring;
  
  while (*nchar)
  {
    switch ( *nchar )
    {
      case '0':
      strcpy( binstring, "0000" );
      break;
      
      case '1':
      strcpy( binstring, "0001" );
      break;
      
      case '2':
      strcpy( binstring, "0010" );
      break;
      
      case '3':
      strcpy( binstring, "0011" );
      break;
      
      case '4':
      strcpy( binstring, "0100" );
      break;
      
      case '5':
      strcpy( binstring, "0101" );
      break;
      
      case '6':
      strcpy( binstring, "0110" );
      break;
      
      case '7':
      strcpy( binstring, "0111" );
      break;
      
      case '8':
      strcpy( binstring, "1000" );
      break;
      
      case '9':
      strcpy( binstring, "1001" );
      break;
      
      case 'A':
      strcpy( binstring, "1010" );
      break;
      
      case 'B':
      strcpy( binstring, "1011" );
      break;
      
      case 'C':
      strcpy( binstring, "1100" );
      break;
      
      case 'D':
      strcpy( binstring, "1101" );
      break;
      
      case 'E':
      strcpy( binstring, "1110" );
      break;
      
      case 'F':
      strcpy( binstring, "1111" );
      break;
    }
    binstring += 4;
    nchar++;
  }
}

/* function to read in a listing file and output a pure binary file */
void lstBin( char* lstfile, char* binfile )
{
  FILE* infile;
  FILE* outfile;
  
  /* allocate memory to read hex into */
  char* hexstring = ( char* ) malloc ( 8 );
  /* and to write binary into */
  char* binstring = ( char* ) malloc ( 32 );
  
  if( hexstring == NULL )
  { 
    printf( "Memory error" ); 
    return;
  }
  
  if( binstring == NULL )
  { 
    printf( "Memory error" ); 
    return;
  }
  
  /* open the listing file for read in text mode */
  infile = fopen( lstfile, "r" );
  /* and the binary file for write */
  outfile = fopen( binfile, "w" );
  
  if ( infile != NULL && outfile != NULL )
  {
    while( !feof( infile ) )
    {
        fread( hexstring, 1, 8, infile );
        hexBin( hexstring, binstring );
        fwrite( binstring, 1, 32, outfile );
        fputc ( '\n', outfile );
    }
    fclose( infile );
    fclose( outfile );
  }
  
  free( hexstring );
  free( binstring );
}

/* will read in filenames from the command line, then execute the conversion */

int main ( int argc, char **argv ) 
{ 
  char* infile = NULL;
  char* outfile = NULL;
  
  if ( argc == 1 )
  {
    printf( "Usage: \n lstbin fib.lst fib.bin \n" );
  }
  else
  {
    infile = argv[ 1 ];
    outfile = argv[ 2 ];
  }
  
  lstBin( infile, outfile );
  
  return 0;
}