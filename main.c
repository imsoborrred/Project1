#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void assembler(const char *inputFile, const char *outputFile);

int main() {
  
    assembler("Fibonacci.asm", "binary.bin");
    return 0;
}

void assembler(const char *inputFile, const char *outputFile) {
    FILE *fp2;
    FILE *fp;
    char line[50];

    
    fp = fopen(inputFile, "r");
    fp2 = fopen(outputFile, "w");

    
    if (fp == NULL) {
        printf("File %s not found!\n", inputFile);
        return;
    }

    
    if (fp2 == NULL) {
        printf("Could not open output file %s!\n", outputFile);
        fclose(fp);
        return;
    }

    
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = 0;

        //spaces
        char command[50];
        strcpy(command, line);
        for (char *p = command; *p; ++p) {
            if (*p == ' ') {
                memmove(p, p + 1, strlen(p));
                p--; 
            }
        }

        
        if (strcmp(command, "RA=RA+RB") == 0) {
            fprintf(fp2, "00000000\n");
        } else if (strcmp(command, "RB=RA+RB") == 0) {
            fprintf(fp2, "00010000\n");
        } else if (strcmp(command, "RA=RA-RB") == 0) { 
            fprintf(fp2, "00000100\n");
        } else if (strcmp(command, "RB=RA-RB") == 0) {
            fprintf(fp2, "00010100\n");
        } else if (strcmp(command, "RO=RA") == 0) {
            fprintf(fp2, "00100000\n");

        
        } else if (strncmp(command, "RA=", 3) == 0) {
            int imm = atoi(command + 3);
            switch (imm) {
                case 0: fprintf(fp2, "00001000\n"); break;
                case 1: fprintf(fp2, "00001001\n"); break;
                case 2: fprintf(fp2, "00001010\n"); break;
                case 3: fprintf(fp2, "00001011\n"); break;
                case 4: fprintf(fp2, "00001100\n"); break;
                case 5: fprintf(fp2, "00001101\n"); break;
                case 6: fprintf(fp2, "00001110\n"); break;
                case 7: fprintf(fp2, "00001111\n"); break;
                default: printf("Uncategorized immediate value: %d\n", imm); break;
            }

        
        } else if (strncmp(command, "RB=", 3) == 0) {
            int imm = atoi(command + 3);
            switch (imm) {
                case 0: fprintf(fp2, "00011000\n"); break;
                case 1: fprintf(fp2, "00011001\n"); break;
                case 2: fprintf(fp2, "00011010\n"); break;
                case 3: fprintf(fp2, "00011011\n"); break;
                case 4: fprintf(fp2, "00011100\n"); break;
                case 5: fprintf(fp2, "00011101\n"); break;
                case 6: fprintf(fp2, "00011110\n"); break;
                case 7: fprintf(fp2, "00011111\n"); break;
                default: printf("Uncategorized immediate value: %d\n", imm); break;
            }

        
        } else if (strncmp(command, "JC=", 3) == 0) {
            int imm = atoi(command + 3); 
            switch (imm) {
                case 0: fprintf(fp2, "01110000\n"); break;
                case 1: fprintf(fp2, "01110001\n"); break;
                case 2: fprintf(fp2, "01110010\n"); break;
                case 3: fprintf(fp2, "01110011\n"); break;
                case 4: fprintf(fp2, "01110100\n"); break;
                case 5: fprintf(fp2, "01110101\n"); break;
                case 6: fprintf(fp2, "01110110\n"); break;
                case 7: fprintf(fp2, "01110111\n"); break;
                default: printf("Uncategorized immediate value: %d\n", imm); break;
            }

        
        } else if (strncmp(command, "J=", 2) == 0) {
            int imm = atoi(command + 2); 
            switch (imm) {
                case 0: fprintf(fp2, "10110000\n"); break;
                case 1: fprintf(fp2, "10110001\n"); break;
                case 2: fprintf(fp2, "10110010\n"); break;
                case 3: fprintf(fp2, "10110011\n"); break;
                case 4: fprintf(fp2, "10110100\n"); break;
                case 5: fprintf(fp2, "10110101\n"); break;
                case 6: fprintf(fp2, "10110110\n"); break;
                case 7: fprintf(fp2, "10110111\n"); break;
                default: printf("Uncategorized immediate value: %d\n", imm); break;
            }
        }
    }

    
    fclose(fp);
    fclose(fp2);
}
