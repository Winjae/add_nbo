#include <stdio.h>
#include <stdint.h>

uint32_t my_change(uint32_t a){
        return (a << 24) | ((a << 8) & 0xFF0000) | ((a >> 8) & 0xFF00) | (a >> 24);
}

int main(int argc, char *argv[]){
        uint32_t data1, data2;
        if(argc != 3){
                printf("./add-nbo [.bin1] [.bin2]\n");
                return 0;
        }
        FILE *pFile1 = NULL, *pFile2;
        pFile1 = fopen(argv[1], "rb");
        pFile2 = fopen(argv[2], "rb");

        if(pFile1 == NULL || pFile2 == NULL){
                printf("Wrong File name\n");
                return 0;
        }

        fread(&data1, sizeof(uint32_t), 1, pFile1);
        fread(&data2, sizeof(uint32_t), 1, pFile2);

        uint32_t a1 = my_change(data1);
        uint32_t a2 = my_change(data2);
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a1, a1, a2, a2, a1+a2, a1+a2);



        return 0;
}
