
#include <stdio.h>
#include <string.h>

int main(int argc , char *argv[])
{
	FILE *bmp = NULL ; 
	FILE *header = NULL ;
	
	bmp = fopen(argv[1] , "r");
	if(NULL == bmp)
	{
		fprintf(stderr , "open bmp fail \n");
		return -1 ; 
	}

	header = fopen(argv[2] , "a");
	if(NULL == header)
	{
		fprintf(stderr , "open header fail \n");
		return -2 ; 
	}


	fseek(bmp , 54 , SEEK_SET);

	unsigned char Buffer[3] ;

	int row  , col ; 
	unsigned int color ; 

	for(row = 0 ; row < 480 ; row++)
	{
		for(col = 0 ; col < 800 ; col++)
		{
			fread(Buffer , 3 , 1 , bmp);
			#define RGB(r,g,b)   (((r)<<16)|((g)<<8)|(b))
			color = RGB(Buffer[2],Buffer[1],Buffer[0]);	
			if(col % 10 == 0)
				fprintf(header , "\n");

			fprintf(header , "%#x ," , color);
		}
	}

	fclose(bmp);
	fclose(header);

	return 0 ;
}


