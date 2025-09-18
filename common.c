#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "common.h"


unsigned int bigendian_to_litle(char size[4])
{
    //Swapping the elements and convert it from big endian 
    unsigned char arr[4];
    // for(int i=0;i<4;i++)
    //     {
    //         arr[i]=size[3-i];
    //     }

    arr[0]=size[3];
    arr[1]=size[2];
    arr[2]=size[1];
    arr[3]=size[0];
    
    int new_size;
    memcpy(&new_size,arr,4);
    return new_size;

}

int check_valid(char * frame_header)
{
    if(frame_header[0]!='I' && frame_header[1]!='D'&& frame_header[2]!='3')
        {
            printf("Unsupported ID3 Version");
            //fclose(mptr);
            return 1;
        }
        if(frame_header[3]!=3 && frame_header[4]!=0)
        {
            printf("Unsupported Version other than 2.3");
            //fclose(mptr);
            return 1;
        }
        return 0;
}

void little_to_big_endian(unsigned int *ptr , int arr[])
{
    
    for(int i=0;i<4;i++)
    {
         arr[i]=*((char *)ptr+(3-i));
    }

}