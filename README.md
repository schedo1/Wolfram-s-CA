# Wolfram-s-CA

## In short
This program takes a number, from 0 to 255, if it's larger or smaller it rounds it up to 255 or 0, then it converts it into binary, each bit is associate to a possible configuration of 3 cells, each cell can be 0 or 1, in the next tourn the cell in the middle of the configuration became the bit associate before, so for example:

Rule (input) = 90
90 -> 01011010
possible config: 111 110 101 100 011 010 001 000
if the cell is 0 and its neighbors are both 1, in the next step it will became a 0, because the 101 config. is associate with 0.

This program generate a number of step given by input.

## feedback's
If you have any feedback's feel free to contact me at "e.schiavocampo1@gmail.com"