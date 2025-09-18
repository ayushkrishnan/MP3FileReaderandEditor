#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "common.h"



void edit_tag(char *fname,char *mode,char *editcontent,int tgsize)
{
    //making char
    char *modes[]={"-t","-a","-A","-y","-c","-m"};
    char *operation[]={"TIT2","TPE1","TALB","TYER","TCON","COMM"};

    char target_tag[5];
    int i=0;
    while(modes[i])
    {
        if(strcmp(mode,modes[i])==0)
        {
            strcpy(target_tag,operation[i]);
            break;
        }
        i++;
    }
    printf("Target => %s\n",target_tag);
    FILE *fptr = fopen(fname,"rb");
    if(fptr==NULL)
    {
        printf("FILE Opening Failed\n");
        return;
    }
    FILE *fptr2=fopen("newfile.mp3","wb");
    if(fptr2==NULL)
    {
        printf("New File opening failed\n");
        return;
    }
    char file_header[10];
    fread(file_header,1,10,fptr);
    fwrite(file_header,1,10,fptr2);
    //fseek(fptr,10,SEEK_SET);
    char tagheader[10];
    
    
    while((ftell(fptr)<tgsize))
    {
        //printf("HII\n");
        //reading the first 10 bytes after the file header into the tagheader
        fread(tagheader,1,10,fptr);
        
        //Declaring this to get the first 4 bytes of the header
        char tagsignature[5];
        //printf("TAG Header => %s\n",tagheader);
        //copy the first 4 bytes to the tag signature
        strncpy(tagsignature,tagheader,4);

        tagsignature[4]='\0';
        //printf("TAG => %s",tagsignature);
        //return ;
        //Declaring the tag size 
        unsigned int tagsize;
        //printf("%d",tagsize);
        //return;
        // read the tag size from the header 
        //structure of header is like 4 bytes name then 4 bytes size then 2 bytes flag and 1 byte encoding bits
        tagsize=bigendian_to_litle((unsigned char *)tagheader+4);
       
        
        //Reading the tag content so that it the contents will be copied to the array
        char *tagcontent=malloc(tagsize+1);
       
        //Reading the tag content so that it the contents of size will be copied to the array 
        fread(tagcontent,1,tagsize,fptr);

        //making the last element as zero
        tagcontent[tagsize]='\0';

        if(strcmp(tagsignature,target_tag)==0)
        {
            //printf("\ninside if =>%s",target_tag);
            //return;
            unsigned int new_size=strlen(editcontent)+1;
            //printf("\nedit content=> %s",editcontent);
           // return;
           int arr[4]; 
           little_to_big_endian(&new_size , arr);

            memcpy(tagheader+4,&new_size,4);
            fwrite(tagheader, 1, 10, fptr2);
            fputc(0x00, fptr2);
            fwrite(editcontent,1,strlen(editcontent),fptr2);


        }
        else{

                fwrite(tagheader,1,10,fptr2);
                fwrite(tagcontent,1,tagsize,fptr2);
        }
        free(tagcontent);

    }

    int ch;
    while(ch = (fgetc(fptr)) !=EOF)
    {
        fputc(ch,fptr2);
    }

    fclose(fptr);
    fclose(fptr2);
    rename("newfile.mp3",fname);
    
}