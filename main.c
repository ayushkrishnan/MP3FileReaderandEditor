/*
NAME:Ayush Krishnan
DATE:03/09/2025
DESC:MP3 File tag reader and editor
*/

#include<stdio.h>
#include<string.h>


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

    if(argc == 3 && (strcmp(args[1],"-v")==0));
    {
        printf("view in mp3");
    }

    if(argc == 3 && (strcmp(args[1],"-e")==0));
    {
        printf("view in mp3");
    }
}