#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h> 

bool isMultOf4();
uint16_t flipBytes(uint16_t N);

int main(){
    printByte(flipBytes(11));
}

//Print the byte in base 2 form
void printByte(uint32_t Byte){
    uint32_t Mask = 0x80000000;
    for(int bit = 32; bit > 0; bit--){
        if(bit % 4 == 0 && bit != 32) printf(" ");
        printf("%c", ((Byte & Mask) == 0 ? '0' : '1'));
        Mask = Mask >> 1;
    }
}

//Print the bits in base 2 form
void printBits(const uint8_t* source, uint32_t Length){
    uint8_t* pCurrByte = source + Length - 1;
    for(uint8_t byte = 0; byte < Length; byte++){
        uint8_t currByte = *pCurrByte;

        printByte(currByte);

        if(byte < Length - 1) printf(" ");

        pCurrByte--;
    }
}

//fliping the byte
uint16_t flipBytes(uint16_t N){
    uint16_t hiByte = N & 0xFF00; //& with 1111 1111 0000 0000
    hiByte = hiByte >> 8;
    N = N << 8;
    N = N | hiByte;
    printf("Fliped byte (base 10): %u\n", N);
    return N;
}

//Check if the value is divisible by 4
bool isMultOf4(int32_t Value){
    uint16_t Mask = 0x00000003;
    int32_t low2bits = Value & Mask;
    return low2bits == 0x0;
}