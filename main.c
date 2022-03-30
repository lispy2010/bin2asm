// bin2asm - converter from bin to nasm

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: bin2asm <input file> <output file>\n");
        return 1;
    }
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    printf("Converting %s to %s\n", input_file, output_file);
    FILE *input = fopen(input_file, "rb");
    if (!input)
    {
        printf("Failed to open input file\n");
        return 1;
    }
    FILE *output = fopen(output_file, "w");
    if (!output)
    {
        printf("Failed to open output file\n");
        return 1;
    }
    // go through each byte and convert it to a hex value
    // and then get these values and turn them into nasm code
    // and then write code to output file
    unsigned char byte;
    unsigned bytes = 0;
    fprintf(output, "; Generated with bin2asm by lispy2010\n");
    while (fread(&byte, 1, 1, input))
    {
        bytes++;
        fprintf(output, "db 0x%02x\n", byte);
    }
    fprintf(output, "; written %u bytes\n", bytes + 1);
    fclose(input);
    fclose(output);
    printf("Converted!\n");
    return 0;
}