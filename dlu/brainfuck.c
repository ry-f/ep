/*
Exercitiu  : brainfuck
Fisiere de iesire   : *.c, *.h
Functii autorizate : write, malloc, free
--------------------------------------------------------------------------------

Scrieti un interpretor de programe numit Brainfuck.
Codul sursa va fi dat ca primul argument.
Codul va fi mereu valid, cu cel mult 4096 operatii.
Barinfuck este un limbaj minimal. Contine un vector de bytes
(pentru acest exercitiu, 2048 bytes) initializati cu zero, si
un pointer spre primul byte.

Fiecare operator consista dintr-un singur caracter:
- '>' incrementeaza pointerul ;
- '<' decrementeaza pointerul ;
- '+' incrementeaza byte-ul la care pointeaza ;
- '-' decrementeaza byte-ul la care pointeaza ;
- '.' printeaza la iesirea standard byte-ul spre care pointeaza ;
- '[' du-te la perechea ']' byte-ul la care pointeaza e 0 (while start) ;
- ']' du-te la perechea '[' byte-ul la care pointeaza nu e 0 (while end).

Orice alt caracter este un comentariu.

Examples:

$>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
Hello World!$
$>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
Hi$
$>./brainfuck | cat -e
$
*/

/*
Assignment name  : brainfuck
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a Brainfuck interpreter program.
The source code will be given as first parameter.
The code will always be valid, with no more than 4096 operations.
Brainfuck is a minimalist language. It consists of an array of bytes 
(in our case, let's say 2048 bytes) initialized to zero, 
and a pointer to its first byte.

Every operator consists of a single character :
- '>' increment the pointer ;
- '<' decrement the pointer ;
- '+' increment the pointed byte ;
- '-' decrement the pointed byte ;
- '.' print the pointed byte on standard output ;
- '[' go to the matching ']' if the pointed byte is 0 (while start) ;
- ']' go to the matching '[' if the pointed byte is not 0 (while end).

Any other character is a comment.

Examples:

$>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
Hello World!$
$>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
Hi$
$>./brainfuck | cat -e
$
*/