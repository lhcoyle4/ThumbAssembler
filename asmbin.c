/* program to convert an asm file to a binary file */
/* the created binary file should diff with the binary file generated from the lst */

void asmbin ( char* infile, char* outfile)
{
    FILE* infile;
    FILE* outfile;
  
    char* asmstring = ( char* ) malloc( 80 );
    char* binstring = ( char* ) malloc( 16 );
    
    /* idk what to do here yet, somehow it needs to grab whole lines from the infile
       then parse the lines, converting the asm instructions to binary, but only the
       instructions. needs to ignore comments, directives, etc. */
}

int main ( int argc, char** argv )
{
    char* infile = NULL;
    char* outfile = NULL;
    
    if ( argc == 1 )
    {
        printf ( "Usage: \n asmbin fib.asm fib.obj.\n" );
    }
    else
    {
        infile = argv[ 1 ];
        outfile = argv[ 2 ];
    }
    
    asmbin ( infile, outfile );
    
    return 0;
}