/*
NAME:Ayush Krishnan
DATE:03/09/2025
DESC:MP3 File tag reader and editor
*/

#include<stdio.h>
#include<string.h>
#include "common.h"
#include "view.h"
#include "edit.h"


int main(int argc,char *args[])
{
    if(argc==1)
    {
        printf("\n-----------------------------------------------------------------------------------------------------------\n");
        printf("\nERROR: ./a.out : INVLAID ARGUMENTS\nUSAGE:\n");
        printf("To view please pass like: ./a.out -v mp3filename\n");
        printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
        printf("To get help pass like: ./a.out --help\n");
        printf("\n-----------------------------------------------------------------------------------------------------------\n");
        return 0;

    }

    if(argc==2 && (strcmp(args[1],"--help")==0) || (strcmp(args[1],"--h")==0))
    {
        printf("\n-------------------------------------------------------HELP MENU-------------------------------------------------------\n");
        printf("\n1. -v -> to view mp3 file contents\n");
        printf("2. -e -> to edit mp3 file contents\n");
        printf("\t 2.1  -t  ->  to edit song title\n");
        printf("\t 2.2  -a  ->  to edit artist name\n");
        printf("\t 2.3  -A  ->  to edit album name\n");
        printf("\t 2.4  -y  ->  to edit year\n");
        printf("\t 2.5  -m  ->  to edit content\n");
        printf("\t 2.6  -c  ->  to edit comment\n");
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        return 0;
    }

    if(argc == 3 && (strcmp(args[1],"-v")==0))
    {
        FILE *mptr = fopen(args[2],"r");
        if(mptr==NULL)
        {
            printf("File Opening Failed ");
            return 1;
        }
       

        //Declare the frame header
        unsigned char frame_header[11];

        //reading first 10 bytes from the mp3 file
        fread(frame_header,1,10,mptr);

       
        if(check_valid(frame_header))
        {
            printf("Unsupported version");
            fclose(mptr);
            return 1;
        }
        
        //Taking the frame tag size and convert it
        unsigned int tagsize= bigendian_to_litle(frame_header+6);
        frame_header[10]='\0';
        view_tag(args[2],tagsize);

        fclose(mptr);
        
    }

    if(argc >3 && (strcmp(args[1],"-e")==0))
    {

        printf("edit in mp3");
        FILE *mptr = fopen(args[4],"r");
        if(mptr==NULL)
        {
            printf("File Opening Failed ");
            return 1;
        }

        unsigned char f_head[11];
        
        fread(f_head,10,1,mptr);

        if(check_valid(f_head))
        {
            printf("Unsupported Version");
            return 1;
        }

        unsigned int tagsize= bigendian_to_litle(f_head+6);
        f_head[10]='\0';
        edit_tag(args[4],args[2],args[3],tagsize);
        view_tag(args[4],tagsize);
        fclose(mptr);

    }
}