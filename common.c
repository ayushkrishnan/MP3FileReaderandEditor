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