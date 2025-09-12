#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "view.h"


void view_tag(char *fname,int tgsize)
{
    FILE *fptr = fopen("fname.txt","r");
    fseek(fptr,10,SEEK_SET);
    char tagheader[11];
    while(tgsize)
    {
        //reading the first 10 bytes after the file header
        fread(tagheader,1,10,fptr);
        char tagsignature[4];
        //copy the first 4 bytes to the tag signature
        strncpy(tagsignature,tagheader,4);

        //readsize;
        //char tagsize[4];
        //strncpy(tagsize,tagheader+4,4);
        unsigned int tagsize;
        tagsize=bigendian_to_litle(tagheader+4);

        //Reading the tag content so that it the contents will be copied to the array
        char tagcontent[tagsize+1];
        fread(tagcontent,1,tagsize,fptr);

        if(strcmp(tagsignature,"TIT2")==0)
        {
            printf("TITLE  => %s",tagcontent);
        }
        else if(strcmp(tagsignature,"TPE1")==0)
        {
            printf("ARTIST NAME =>%s",tagcontent);
        }
        else if(strcmp(tagsignature,"TALB")==0)
        {
            printf("\nALBUM NAME\t:\t%s",tagcontent);
        }
        else if(strcmp(tagsignature,"TYER")==0)
        {
            printf("\nYEAR\t:\t%s",tagcontent);
        }

    }
}