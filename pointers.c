// #include <stdio.h>
// #include <stdint.h>

// int main() {
//     // Simulated incoming buffer: Temp = 0x011A (282), Timestamp = 0x65F0A1B2
//     uint8_t rx_buffer[6] = {0x1A, 0x01, 0xB2, 0xA1, 0xF0, 0x65};
    
//     uint16_t temperature = 0;
//     uint32_t timestamp = 0;

//     // TODO: Use pointer casting and arithmetic on rx_buffer 
//     // to populate 'temperature' and 'timestamp'.
//     temperature = *(uint16_t*)(rx_buffer);
//     timestamp = *(uint32_t*)(rx_buffer + 2);


//     printf("Temp: %u\n", temperature);
//     printf("Time: %u\n", timestamp);

//     uint32_t xyz = 0xAABBCCDD;

//     uint8_t* px_buffer = (uint8_t*) &xyz;
//     printf("Px_0: %u\n", px_buffer[0]);
//     printf("Px_1: %u\n", px_buffer[1]);
//     return 0;
// }


// #include <stdint.h>
// #include <stdio.h>
// // TODO: 1. Define your packed struct here (Control, Counter, Status)
// typedef struct {
//     uint32_t Control;
//     uint32_t Counter;
//     uint32_t Status;
// }reg;

// // TODO: 2. Define your pointer to the base address 0x40001000
// // Hint: You will need to cast the hardcoded hex address.
// #define BASE 0x40001000

// void enable_timer(reg* regs) {
//     // TODO: 3. Use your struct pointer to set bit 0 of the Control register
//     regs->Control |= 1;
// }

// int main() {

//     // These macros are predefined by GCC/Clang
//     #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
//         printf("Compiled for a Little-Endian architecture.\n");
//     #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
//         printf("Compiled for a Big-Endian architecture.\n");
//     #else
//         printf("Unknown Endianness.\n");
//     #endif

//     // Note: If you compile and run this on a PC, it will crash (segmentation fault) 
//     // because 0x40001000 is restricted PC memory. But the syntax will be correct for an MCU!
//     reg* regs = (reg*) BASE;
//     enable_timer(regs);
//     return 0;
// }


#include <stdio.h>
#include <stdint.h>

void handle_uart_rx() { printf("Processing UART...\n"); }
void handle_spi_tx()  { printf("Processing SPI...\n"); }
void handle_i2c_err() { printf("Handling I2C Error...\n"); }

typedef void (*callback_t)(void);

int main() {
    // TODO: Define an array of function pointers that takes no arguments 
    // and returns void. Initialize it with the three functions above.
    callback_t fn[3] = {handle_uart_rx,handle_spi_tx,handle_i2c_err};
    
    uint8_t incoming_interrupt_id = 2; // Simulate SPI interrupt firing

    // TODO: Call the correct function using the array and the interrupt_id
    fn[incoming_interrupt_id]();

    return 0;
}