#include <unistd.h>

// initialize the tape with 30,000 zeroes
unsigned char tape[30000] = {0};
 
// set the pointer to point at the left-most cell of the tape
unsigned char* ptr = tape;
 
 
void interpret(char* input)
{
    char current_char;
    int i;
    int loop;
 
    for (i = 0; input[i] != 0; i++) {
        current_char = input[i];
        if (current_char == '>') {
            ++ptr;
        } else if (current_char == '<') {
            --ptr;
        } else if (current_char == '+') {
            ++*ptr;
        } else if (current_char == '-') {
            --*ptr;
        } else if (current_char == '.' ) {
            write(1, ptr, 1);
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && *ptr) {
            loop = 1;
            while (loop > 0) {
                current_char = input[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        }
    }
}
 
 
int main(int ac, char **av)
{
    if (ac == 2)
        interpret(av[1]);
    return 0;
}