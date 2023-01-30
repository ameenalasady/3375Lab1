/* Your first program*/
#define LED_BASE 0xFF200000
#define HEX3_HEX0_BASE 0xFF200020
#define SW_BASE 0xFF200040
#define DELAY_LENGTH 700000

int main()
{
    volatile char hex_code[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
    int offOrOn = 1;

    while (1)
    {
        if (offOrOn == 1)
        {
            char switchValue = (*(char *)SW_BASE);
            (*(char *)HEX3_HEX0_BASE) = hex_code[(int)switchValue];
            offOrOn = 0;
        }

        else
        {
            offOrOn = 1;
        }

        for (int delay = DELAY_LENGTH; delay != 0; --delay)
            ;
    }
}
