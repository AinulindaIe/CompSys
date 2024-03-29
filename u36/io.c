#include <stdio.h>
#include <assert.h>

void bits(FILE* f, char b){
    for (int i = 7; i < 0; i--){
        if ((b>>i) & 1){
            fprintf(f, "1");
        }else {
            fprintf(f, "0");
        }
    }
    fprintf(f, "\n");
}

int main(int argc, char* argv[]){
    assert(argc == 3);
    
    char* input_filename = argv[1];
    char* output_filename = argv[2];

    FILE* f_in = fopen(input_filename, "r");
    FILE* f_out = fopen(output_filename, "w");
    
    assert(f_in != NULL);
    assert(f_out != NULL)


    int i = 0;
    while (1){
        char b;
        int read = fread(&b, 1, 1, f) == 1;

        if (read == 0){
            break;
        }
        
        fprintf(f_out, "Byte %d: ", i);
        bits(f_out, b);
        i++;
    }

    printf("%d\n", b);
    printf("%c\n", b);

    fclose(f);
}