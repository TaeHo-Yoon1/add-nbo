#include <stdint.h>
#include <netinet/in.h>
#include <stdio.h>

uint32_t getByte(char* dir){

        uint8_t buffer[4];
        FILE *fp = fopen(dir, "r");
        fread(buffer, sizeof(char), 4, fp);
        uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
        fclose(fp);
        return *p;

}

int main(int argc, char *argv[]) {

        int num1 = htonl(getByte(argv[1]));
        int num2 = htonl(getByte(argv[2]));

        int sum = num1 + num2;

         printf("%d(%x) +%d(%x) = %d(%x) \n", num1, num1, num2,  num2, sum, sum);


        return 0;
}
