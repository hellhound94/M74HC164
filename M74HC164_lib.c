
/* Definindo a função de cada pino */
sbit SERIAL_B at RC5_bit;
sbit CLOCK at RC6_bit;

/* Basta chamar essa função com o valor em ucByte */
void M74HC164(unsigned char ucByte)
{
    int x = 0;
    unsigned char flag = 0x01;
    
    CLOCK    = 0;
    SERIAL_B = 0;
    for(x = 0;x < 8;x++)
    {
         if( (ucByte & flag) == flag ) SERIAL_B = 1;
         else SERIAL_B = 0;
         flag <<= 1;
         CLOCK = 1;
         delay_us(1);
         CLOCK = 0;
    }
    SERIAL_B = 0;
}
