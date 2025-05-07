#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 8192
#define SEARCH_BYTES "\x94\x28\xBB\x37"
#define REPLACE_BYTES "\xD4\x10\x68\x35"
#define PATTERN_LENGTH 4

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read, buffer_pos;
    int replacements = 0;
    long file_offset = 0;
    
    // Check if a filename was provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        return 1;
    }
    
    // Open the input file in binary read mode
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }
    
    // Create the output file
    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Error creating output file");
        fclose(input_file);
        return 1;
    }
    
    printf("Searching for byte pattern 94 28 BB 37 to replace with D4 10 68 35\n");
    printf("Original file will not be modified. Patched version will be saved as '%s'\n", argv[2]);
    
    // Read the file in chunks and process each chunk
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        // Process the buffer
        buffer_pos = 0;
        while (buffer_pos < bytes_read) {
            // Check if we have a match starting at the current position
            if (buffer_pos <= bytes_read - PATTERN_LENGTH && 
                memcmp(&buffer[buffer_pos], SEARCH_BYTES, PATTERN_LENGTH) == 0) {
                
                // Print the offset where the replacement is happening
                printf("Replacing pattern at offset: 0x%lX\n", file_offset + buffer_pos);
                
                // Write the replacement bytes
                fwrite(REPLACE_BYTES, 1, PATTERN_LENGTH, output_file);
                
                buffer_pos += PATTERN_LENGTH;
                replacements++;
            } else {
                // Write the current byte as is
                fputc(buffer[buffer_pos], output_file);
                buffer_pos++;
            }
        }
        
        file_offset += bytes_read;
    }
    
    // Close the files
    fclose(input_file);
    fclose(output_file);
    
    // Report results
    if (replacements > 0) {
        printf("\nTotal replacements made: %d\n", replacements);
        printf("Patched file saved as '%s'\n", argv[2]);
    } else {
        printf("\nNo instances of the pattern were found.\n");
        printf("Output file '%s' is identical to the input file.\n", argv[2]);
    }
    
    return 0;
}
