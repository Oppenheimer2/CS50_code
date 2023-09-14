#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please Enter Filename as ./recover FILENAME");
        return 1;
    }
    FILE *Raw_file = fopen(argv[1],"r");
    if (Raw_file == NULL)
    {
        printf("Could not open %s",argv[1]);
        return 1;
    }
    int *buffer  = malloc(512);
    FILE *out = NULL;
    int i = 0;
    while (fread(buffer, 1, 512, Raw_file) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3]&0xf0)==0xe0)
        {
            char *filename = NULL;
            sprintf(filename, "%03i.jpg",i);
            i = i + 1;
            FILE *img = fopen(filename,"w");
            fwrite(buffer,1,512,img);
        }
    }
    fclose(Raw_file);
    free(buffer);
    return 0;

}