#include <stdio.h>
#include <inttypes.h>
#include <signal.h>

int main (char **argv, int argc)
{
        uint16_t byte;
        uint16_t reg;
        uint16_t reg2;
        switch (byte & 0xf000) {
                case 0x0:
                        if (byte == 0x00e0)
                               printf("clear screen\n");
                        else if (byte == 0x00ee)
                               printf("return \n");
                        else if (byte >= 0x0200)
                               printf("call subroutine at 0x%x\n", byte & 0x0fff);
                        else {
                                fprintf(stderr, "Incorrect opcode\n");
                                return SIGILL;
                        }
                        break;
                case 0x1:
                        if (byte >= 0x0200)
                               printf("jump to 0x%x\n", byte & 0x0fff);
                        else {
                                fprintf(stderr, "Incorrect opcode\n");
                                return SIGILL;
                        }
                        break;
                case 0x2:
                        if (byte >= 0x0200)
                               printf("call subroutine at 0x%x\n", byte & 0x0fff);
                        else {
                                fprintf(stderr, "Incorrect opcode\n");
                                return SIGILL;
                        }
                        break;
                case 0x3:
                        reg = (byte & 0x0f00) >> 8;
                        printf("V%x == 0x%x\n", reg, byte & 0x00ff);
                        break;
                case 0x4:
                        reg = (byte & 0x0f00) >> 8;
                        printf("V%x != 0x%x\n", reg, byte & 0x00ff);
                        break;
                case 0x5:
                        reg = (byte & 0x0f00) >> 8;
                        reg2 = (byte & 0x00f0) >> 4;
                        printf("V%x == V%x\n", reg, reg2);
                        break;
                case 0x6:
                        reg = (byte & 0x0f00) >> 8;
                        printf("V%x = 0x%x\n", reg, byte & 0x00ff);
                        break;
                case 0x7:
                        break;
                case 0x8:
                        break;
                case 0x9:
                        break;
                case 0xa:
                        break;
                case 0xb:
                        break;
                case 0xc:
                        break;
                case 0xd:
                        break;
                case 0xe:
                        break;
                case 0xf:
                        break;
                default:
                        fprintf(stderr, "Incorrect opcode\n");
                        return SIGILL;
        }
        return 0;
}
