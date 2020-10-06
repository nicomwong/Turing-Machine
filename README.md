# Turing-Machine
This is a personal project, inspired by UCSB's CS 138's "mentor" tool made for describing and simulating finite automata and pushdown automata, but not Turing Machines.

The goal is to create a virtual structure that represents a Turing Machine using OOP principles. The behavior of the Turing Machine itself is user-defined through a strictly-formatted text file, and it is parsed using the TM_Parser.

Future goals include...
  - The implementation of a physical Turing Machine using 3D printing, an Arduino, and multicolor LEDs to represent the tape symbols.
  - A way to generate the node graph of the Turing Machine as it was defined by the user
  - An interactive web-based implementation
\
\
Format for TM description text file:
```
alphabet: '{'<char> (',' <char>)*'}'
start: <state>
accept: <state>
reject: <state>

<state> ('('<char> '->' <char>',' ('L'|'R')',' <state>')')+
...

```
\
\
Run the TM you created with:

```./TMParser.exe <description text file> <accepts|run> <input>```
\
\
\
\
*Created by Bill Zhang and Nico Wong.
