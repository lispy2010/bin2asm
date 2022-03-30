# bin2asm

bin2asm is a program that converts .bin files into NASM source code. To be more precise, completely unreadable NASM source code, as it is just a bunch of 'declare byte' statements.

## Usage

bin2asm &lt;.bin file to convert&gt; &lt;.asm file for output&gt;

## Building

To build, just execute:

`gcc main.c -o bin2asm`
