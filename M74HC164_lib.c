
/* Definindo a função de cada pino */
sbit SERIAL_A at RC5_bit;
sbit SERIAL_B at RC4_bit;

sbit CLEAN at RC3_bit;
sbit CLOCK at RC6_bit;

/* Basta chamar essa função com o valor em ucByte */
void M74HC164(unsigned char ucByte)
{
    int x = 0;
    char flag = 0x01;
    
    CLEAN = 1;
    CLOCK = 0;
    
    for(x = 0;x < 8;x++)
    {
         if( (ucByte & flag) == flag ) SERIAL_A = 1;
         else SERIAL_A = 0;
         flag <<= 1;
         CLOCK = 1;
         delay_us(1);
         CLOCK = 0;
    }
}