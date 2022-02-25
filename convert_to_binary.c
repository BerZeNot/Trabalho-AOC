#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos
void getOpCode(char* instruction, char* strOut);
void getRegisterCode(char* regName, char* strOut);
void getShamt(char* instruction, char* strOut);
void getFunct(char* instruction, char* strOut);

void instructionToBinary(char* instruction, int instructionLenght){ //, char* arrayOut
    // add $s7, $v0, $zero

    char* subString = malloc(5*sizeof(char));
    int i = 0;
    int positionOnSubstring = 0;
    while(instruction[i] != ' '){
        subString[positionOnSubstring] = instruction[i];
        i++;
        positionOnSubstring++;
    }
    positionOnSubstring = 0;
    i++;

    printf("instruction: %s\n", subString);

    if(strcmp(subString, "add")==0){
        // Lê rs
        char* rs = malloc(5*sizeof(char));
        while(instruction[i] != ' '){
            if(instruction[i] != ',')
                rs[positionOnSubstring] = instruction[i];
            i++;
            positionOnSubstring++;
        }
        positionOnSubstring = 0;
        i++;
        
        // Lê rt
        char* rt = malloc(5*sizeof(char));
        while(instruction[i] != ' '){
            if(instruction[i] != ',')
                rt[positionOnSubstring] = instruction[i];
            i++;
            positionOnSubstring++;
        }
        positionOnSubstring = 0;
        i++;
        // Lê rd
        char* rd = malloc(5*sizeof(char));
        while(instruction[i] != ' '){
            if(instruction[i] != ',')
                rd[positionOnSubstring] = instruction[i];
            i++;
            positionOnSubstring++;
        }
        positionOnSubstring = 0;
        i++;

        // Aloca os arrays para opcode, rs, rt, rd, shamt e funct;
        char* opcodeBin = malloc(6*sizeof(char));
        char* rsBin = malloc(5*sizeof(char));
        char* rtBin = malloc(5*sizeof(char));
        char* rdBin = malloc(5*sizeof(char));
        char* shamtBin = malloc(5*sizeof(char));
        char* functBin = malloc(6*sizeof(char));

        // Pega cada valor com as funções
        getOpCode(subString, opcodeBin);
        getRegisterCode(rs, rsBin);
        getRegisterCode(rt, rtBin);
        getRegisterCode(rd, rdBin);
        getShamt(subString, shamtBin);
        getFunct(subString, functBin);
        
        // Imprime na ordem
        printf("%s %s %s %s %s %s\n", opcodeBin, rtBin, rdBin, rsBin, shamtBin, functBin);
    }

    else if(strcmp(subString, "sub")==0){}

    else if(strcmp(subString, "and")==0){}

    else if(strcmp(subString, "or")==0){}

    else if(strcmp(subString, "nor")==0){}

    else if(strcmp(subString, "xor")==0){}

    else if(strcmp(subString, "slt")==0){}
}


// É necessário passar um array de tamanho 6
void getOpCode(char* instruction, char* strOut){
        if(strcmp(instruction, "add")==0
        || strcmp(instruction, "sub")==0
        || strcmp(instruction, "and")==0
        || strcmp(instruction, "or")==0
        || strcmp(instruction, "nor")==0
        || strcmp(instruction, "xor")==0
        || strcmp(instruction, "slc")==0){
            strcpy(strOut, "000000");
    }

    else if(strcmp(instruction, "sub")==0){}

    else if(strcmp(instruction, "and")==0){}

    else if(strcmp(instruction, "or")==0){}

    else if(strcmp(instruction, "xor")==0){}

    else if(strcmp(instruction, "slt")==0){}
}

// strOut deve ter o tamanho 5
void getRegisterCode(char* regName, char* strOut){
    // 0
    if(strcmp(regName, "$zero")==0){ strcpy(strOut, "00000"); }
    // 1
    else if(strcmp(regName, "$at")==0){ strcpy(strOut, "00001"); }
    // 2
    else if(strcmp(regName, "$v0")==0){ strcpy(strOut, "00010"); }
    // 3
    else if(strcmp(regName, "$v1")==0){ strcpy(strOut, "00011"); }
    // 4
    else if(strcmp(regName, "$a0")==0){ strcpy(strOut, "00100"); }
    // 5
    else if(strcmp(regName, "$a1")==0){ strcpy(strOut, "00101"); }
    // 6
    else if(strcmp(regName, "$a2")==0){ strcpy(strOut, "00110"); }
    // 7
    else if(strcmp(regName, "$a3")==0){ strcpy(strOut, "00111"); }
    // 8
    else if(strcmp(regName, "$t0")==0){ strcpy(strOut, "01000"); }
    // 9
    else if(strcmp(regName, "$t1")==0){ strcpy(strOut, "01001"); }
    // 10
    else if(strcmp(regName, "$t2")==0){ strcpy(strOut, "01010"); }
    // 11
    else if(strcmp(regName, "$t3")==0){ strcpy(strOut, "01011"); }
    // 12
    else if(strcmp(regName, "$t4")==0){ strcpy(strOut, "01100"); }
    // 13
    else if(strcmp(regName, "$t5")==0){ strcpy(strOut, "01101"); }
    // 14
    else if(strcmp(regName, "$t6")==0){ strcpy(strOut, "01110"); }
    // 15
    else if(strcmp(regName, "$t7")==0){ strcpy(strOut, "01111"); }
    // 16
    else if(strcmp(regName, "$s0")==0){ strcpy(strOut, "10000"); }
    // 17
    else if(strcmp(regName, "$s1")==0){ strcpy(strOut, "10001"); }
    // 18
    else if(strcmp(regName, "$s2")==0){ strcpy(strOut, "10010"); }
    // 19
    else if(strcmp(regName, "$s3")==0){ strcpy(strOut, "10011"); }
    // 20
    else if(strcmp(regName, "$s4")==0){ strcpy(strOut, "10100"); }
    // 21
    else if(strcmp(regName, "$s5")==0){ strcpy(strOut, "10101"); }
    // 22
    else if(strcmp(regName, "$s6")==0){ strcpy(strOut, "10110"); }
    // 23
    else if(strcmp(regName, "$s7")==0){ strcpy(strOut, "10111"); }
    // 24
    else if(strcmp(regName, "$t8")==0){ strcpy(strOut, "11000"); }
    // 25
    else if(strcmp(regName, "$t9")==0){ strcpy(strOut, "11001"); }
    // 26
    else if(strcmp(regName, "$k0")==0){ strcpy(strOut, "11010"); }
    // 27
    else if(strcmp(regName, "$k1")==0){ strcpy(strOut, "11011"); }
    // 28
    else if(strcmp(regName, "$gp")==0){ strcpy(strOut, "11100"); }
    // 29
    else if(strcmp(regName, "$sp")==0){ strcpy(strOut, "11101"); }
    // 30
    else if(strcmp(regName, "$fp")==0){ strcpy(strOut, "11110"); }
    // 31
    else if(strcmp(regName, "$ra")==0){ strcpy(strOut, "11111"); }
}

void getShamt(char* instruction, char* strOut){
    if(strcmp(instruction, "sll")){ stpcpy(strOut, "00001"); } // descobrir o valor do shamt para sll e substituir
    
    else if(strcmp(instruction, "slr")){ stpcpy(strOut, "00002"); } // descobrir o valor do shamt para sll e substituir
    
    else { stpcpy(strOut, "00000"); }
}

// É necessário passar uma array de tamanho 6
void getFunct(char* instruction, char* strOut){
    if(strcmp(instruction, "add")==0){
        strcpy(strOut, "100000");
    }

    else if(strcmp(instruction, "sub")==0){
        strcpy(strOut, "100010");
    }

    else if(strcmp(instruction, "and")==0){
        strcpy(strOut, "100100");
    }

    else if(strcmp(instruction, "or")==0){
        strcpy(strOut, "100101");
    }

    else if(strcmp(instruction, "nor")==0){
        strcpy(strOut, "100111");
    }

    else if(strcmp(instruction, "xor")==0){
        strcpy(strOut, "100110");
    }

    else if(strcmp(instruction, "slt")==0){
        strcpy(strOut, "101010");
    }
}

void main(){
    
    char* instr = "add $s7, $v0, $zero";
    instructionToBinary(instr, strlen(instr));
}
