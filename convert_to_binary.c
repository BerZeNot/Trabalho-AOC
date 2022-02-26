#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos
void getOpCode(char* instruction, char* strOut);
void getRegisterCode(char* regName, char* strOut);
void getShamt(char* instruction, char* strOut);
void getFunct(char* instruction, char* strOut);
void writeRegistersOnOut(char* rs, char* rt, char* rd, char* arrayOut);
void writeOpShamtAndFunctOnOut(char* opCode, char* shamt, char* funct, char* arrayOut);
void getOpcodeOrFunc(char* code, int num);
int getType(char* instruction);
void convertToHexadecimal(char* arrayBin, char* arrayHexa);
char getHexa(char* sequence);
void instructionToBinary(char* instruction, char* arrayOut){ 
    // add $s7, $v0, $zero

    char* subString = malloc(5*sizeof(char));
    int i = 0;
    int positionOnSubstring = 0;
    while(instruction[i] != ' '){
        subString[positionOnSubstring] = instruction[i];
        i++;
        positionOnSubstring++;
    }
    subString[i] = '\0';
    
    positionOnSubstring = 0;
    i++;

    int typeIndex = getType(subString);

    if(typeIndex <=13) {
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

        // Pega cada valor com as funções
        getRegisterCode(rs, rs);
        getRegisterCode(rt, rt);
        getRegisterCode(rd, rd);
        
        // Coloca os valores de rs, rt e rd no array de saída antes de liberar a memória
        writeRegistersOnOut(rs, rt, rd, arrayOut);

        // Libera a memória das variáveis rs rt e rd
        free(rs);
        free(rt);
        free(rd);

        char* opcode = malloc(6*sizeof(char));
        getOpCode(subString, opcode);

        char* shamt = malloc(5*sizeof(char));
        char* funct = malloc(6*sizeof(char));
        getShamt(subString, shamt);
        // getFunct(subString, funct);
        getOpcodeOrFunc(funct, typeIndex);

        writeOpShamtAndFunctOnOut(opcode, shamt, funct, arrayOut);
        
        free(opcode);
        free(shamt);
        free(funct);
    }
}

void writeRegistersOnOut(char* rs, char* rt, char* rd, char* arrayOut){
            // rs
        arrayOut[6] = rs[0];
        arrayOut[7] = rs[1];
        arrayOut[8] = rs[2];
        arrayOut[9] = rs[3];
        arrayOut[10] = rs[4];

        // rt
        arrayOut[11] = rt[0];
        arrayOut[12] = rt[1];
        arrayOut[13] = rt[2];
        arrayOut[14] = rt[3];
        arrayOut[15] = rt[4];

        // rd
        arrayOut[16] = rd[0];
        arrayOut[17] = rd[1];
        arrayOut[18] = rd[2];
        arrayOut[19] = rd[3];
        arrayOut[20] = rd[4];
}

void writeOpShamtAndFunctOnOut(char* opCode, char* shamt, char* funct, char* arrayOut){
        //opcode
        arrayOut[0] = opCode[0];
        arrayOut[1] = opCode[1];
        arrayOut[2] = opCode[2];
        arrayOut[3] = opCode[3];
        arrayOut[4] = opCode[4];
        arrayOut[5] = opCode[5];

        // shamt
        arrayOut[21] = shamt[0];
        arrayOut[22] = shamt[1];
        arrayOut[23] = shamt[2];
        arrayOut[24] = shamt[3];
        arrayOut[25] = shamt[4];

        // funct
        arrayOut[26] = funct[0];
        arrayOut[27] = funct[1];
        arrayOut[28] = funct[2];
        arrayOut[29] = funct[3];
        arrayOut[30] = funct[4];
        arrayOut[31] = funct[5];
}


// É necessário passar um array de tamanho 6
void getOpCode(char* instruction, char* strOut){
        if(strcmp(instruction, "add")==0
        || strcmp(instruction, "sub")==0
        || strcmp(instruction, "and")==0
        || strcmp(instruction, "or")==0
        || strcmp(instruction, "nor")==0
        || strcmp(instruction, "xor")==0
        || strcmp(instruction, "slt")==0){
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
    if(strcmp(instruction, "sll")==0){ stpcpy(strOut, "00001"); } // descobrir o valor do shamt para sll e substituir
    
    else if(strcmp(instruction, "slr")==0){ stpcpy(strOut, "00002"); } // descobrir o valor do shamt para sll e substituir
    
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


int getType(char* instruction){
  int numString = 24, maxsize = 7;

  char arrinstype[24][7] =
	{ 
    "add",
    "sub",
    "and",
    "or",
    "nor",
    "xor",
    "slt",
    "sll",
    "srl",
    "jr",
    "mult",
    "div",
    "mfo",
    "mfhi",
    "j",
    "jal",
    "addi",
    "andi",
    "ori",
    "xori",
    "beq",
    "lw",
    "sw",
    "lui"
	};

  int ret;
  int i;

  for ( i = 0; i < numString; ++i){
    ret = strcmp(arrinstype[i], instruction);
		if(ret == 0){
      break;
    }
	}

  return i;
}

void getOpcodeOrFunc(char* code, int num){
  char arrcode[24][7] =
	{ 
    "100000",
    "100010",
    "100100",
    "100101",
    "100111",
    "100110",
    "101010",
    "000000",
    "000010",
    "001000",
    "011000",
    "011010",
    "010010",
    "010000",
    "000010",
    "000011",
    "001000",
    "001100",
    "001101",
    "001110",
    "000100",
    "100011",
    "101011",
    "001111"
	};

  strcpy(code, arrcode[num]);
}


void convertToHexadecimal(char* arrayBin, char* arrayHexa){
    char* sequence = malloc(5*sizeof(char));
    int nextPosOnHexaArray = 0;
    for(int i=0; i<32; i+=4){

        sequence[0] = arrayBin[i];
        sequence[1] = arrayBin[i+1];
        sequence[2] = arrayBin[i+2];
        sequence[3] = arrayBin[i+3];
        sequence[4] = '\0';
        arrayHexa[nextPosOnHexaArray] = getHexa(sequence);
        nextPosOnHexaArray++;
    }

}

char getHexa(char* sequence){
    if(strcmp(sequence,"0000")==0) return '0'; 
    else if(strcmp(sequence,"0001")==0) return '1'; 
    else if(strcmp(sequence,"0010")==0) return '2'; 
    else if(strcmp(sequence,"0011")==0) return '3'; 
    else if(strcmp(sequence,"0100")==0) return '4'; 
    else if(strcmp(sequence,"0101")==0) return '5'; 
    else if(strcmp(sequence,"0110")==0) return '6'; 
    else if(strcmp(sequence,"0111")==0) return '7'; 
    else if(strcmp(sequence,"1000")==0) return '8'; 
    else if(strcmp(sequence,"1001")==0) return '9'; 
    else if(strcmp(sequence,"1010")==0) return 'a'; 
    else if(strcmp(sequence,"1011")==0) return 'b'; 
    else if(strcmp(sequence,"1100")==0) return 'c'; 
    else if(strcmp(sequence,"1101")==0) return 'd'; 
    else if(strcmp(sequence,"1110")==0) return 'e'; 
    else if(strcmp(sequence,"1111")==0) return 'f'; 
}

/* main de teste
void main(){
    
    char* instr = "add $s7, $v0, $zero";
    char* instr1 = "sub $t0, $v0, $v1";
    char* instr2 = "and $t1, $v0, $zero";
    char* instr3 = "or $t0, $t0, $t1";
    char* instr4 = "xor $a0, $t0, $zero";
    char* instr5 = "slt $a0, $t0, $zero";
    char* instrBin = (char*)malloc(32*sizeof(char));
    
    instructionToBinary(instr, instrBin);
    printf("%s\n", instrBin);
    char* instrHexa = malloc(8*sizeof(char));
    convertToHexadecimal(instrBin, instrHexa);
    printf(" %s\n", instrHexa);

    instructionToBinary(instr1, instrBin);
    printf("%s\n", instrBin);
    convertToHexadecimal(instrBin, instrHexa);
    printf(" %s\n", instrHexa);
    free(instrBin);

    instructionToBinary(instr2, instrBin);
    printf("%s\n", instrBin);
    convertToHexadecimal(instrBin, instrHexa);
    printf(" %s\n", instrHexa);
    free(instrBin);

    instructionToBinary(instr3, instrBin);
    printf("%s\n", instrBin);
    convertToHexadecimal(instrBin, instrHexa);
    printf(" %s\n", instrHexa);
    free(instrBin);

    instructionToBinary(instr4, instrBin);
    printf("%s\n", instrBin);
    convertToHexadecimal(instrBin, instrHexa);
    printf(" %s\n", instrHexa);
    free(instrBin);

    instructionToBinary(instr5, instrBin);
    printf("%s\n", instrBin);
    convertToHexadecimal(instrBin, instrHexa);
    printf(" %s\n", instrHexa);
    free(instrBin);
}
fim do main de teste*/