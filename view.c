#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "view.h"


void view_tag(char *fname,int tgsize)
{
    
    FILE *fptr = fopen(fname,"rb");
    fseek(fptr,10,SEEK_SET);
    char tagheader[10];
     printf("\n------------------------------------------------------------------------------------------------------------------------\n");
     printf("\n\t\t\t\t\tMP3 FILE VIEW\n");
     printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    //printf("HELLOOOOO\n");
    printf("%d",tgsize);
    //printf("Hello\n");
    while((ftell(fptr)<tgsize))
    {
        //reading the first 10 bytes after the file header into the tagheader
        fread(tagheader,1,10,fptr);
        
        //Declaring this to get the first 4 bytes of the header
        char tagsignature[5];

        //copy the first 4 bytes to the tag signature
        strncpy(tagsignature,tagheader,4);
        
        //making the last bit of the tag signature as NULL so that it can be act as a string
        tagsignature[4]='\0';
        
        //Declaring the tag size 
        unsigned int tagsize;
       
        // read the tag size from the header 
        //structure of header is like 4 bytes name then 4 bytes size then 2 bytes flag and 1 byte encoding bits
        tagsize=bigendian_to_litle((unsigned char *)tagheader+4);
       
        
        //Reading the tag content so that it the contents will be copied to the array
        char *tagcontent=malloc(tagsize+1);
       
        //Reading the tag content so that it the contents of size will be copied to the array 
        fread(tagcontent,1,tagsize,fptr);

        //making the last element as zero
        tagcontent[tagsize]='\0';
        
        //If the elements equal to a particular name then its content will gets printed
        if(strcmp(tagsignature,"TIT2")==0)
        {
            printf("\nTITLE\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TPE1")==0)
        {
            printf("\nARTIST\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TALB")==0)
        {
            printf("\nALBUM\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TYER")==0)
        {
            printf("\nYEAR\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TCON")==0)
        {
            printf("\nGENRE\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TRCK")==0)
        {
            printf("\nTRACK\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"COMM")==0)
        {
            printf("\nCOMMENTS\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TPE2")==0)
        {
            printf("\nBAND\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TEXT")==0)
        {
            printf("\nLYRICIST\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TENC")==0)
        {
            printf("\nENCODED BY\t\t:\t%s",tagcontent+1);
        }
        else if(strcmp(tagsignature,"TCOM")==0)
        {
            printf("\nCOMPOSER\t\t:\t%s",tagcontent+1);
        }

    }
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}