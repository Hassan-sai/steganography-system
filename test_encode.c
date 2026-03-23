#include <stdio.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include<string.h>
#include "decode.h"

int main(int argc, char *argv[])
{
    EncodeInfo encInfo;
    uint img_size;
    DecodeInfo decInfo;

   //for checking whether the usr selectd encode or decode
    if(check_operation_type(argv) == e_encode)
    {
        printf("selected encoding\n");
        if(read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("read and validation is successful\n");
            printf("started encoding\n");
            if(do_encoding(&encInfo) == e_success)
			{
				printf("<-------------------Encoded done------------------->\n");
			}
			else
			{
				printf("Failed to encode\n");
			}
        }
        else
        {
            printf("read and validation is failed\n");
        }


    }
    else if(check_operation_type(argv) == e_decode)
    {
        printf("selected decoding\n");
        if(read_and_validate_decode_args(argv,&decInfo) == e_success)
        {
            printf("read and validate of decode is success\n");
            printf("statrted decoding\n");
            if(do_decoding(&decInfo) == e_success)
            {
                printf("decoded done\n");
            }
            else
            {
                printf("failed to decode\n");
            }
        }
        else
        {
            printf("read and validation of decoding is failed\n");
        }

    }
    else
    {
        printf("pass valid type\n");
    
    }
    

}
OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e") == 0)
    {
        return e_encode;
    }
    else if (strcmp(argv[1],"-d")==0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}





 
