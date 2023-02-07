/* Your first program*/
#define LED_BASE 0xFF200000
#define HEX3_HEX0_BASE 0xFF200020
#define SW_BASE 0xFF200040
#define DELAY_LENGTH 7000000

int main()
{
    volatile int hex_code[16] = {0x0, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

    while (1)
    {

        volatile int switchValue = (*(int *)SW_BASE);
        if (switchValue <= 0b1111)
        {
            (*(int *)HEX3_HEX0_BASE) = hex_code[(int)switchValue];
        }
    }
}