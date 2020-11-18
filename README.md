# Turing-Machine
This is a personal project, inspired by UCSB's CS 138's "mentor" tool made for describing and simulating finite automata and pushdown automata, but it did not support Turing Machines.

The goal is to create a virtual structure that represents a (decisive) Turing Machine using OOP principles. The behavior of the Turing Machine itself is user-defined through a strictly-formatted text file.

To use it, perform the following steps:
1. Run `make` to generate the `TMParser.exe` executable
2. Write a TM description text file that describes the Turing Machine states and transitions, following the format below
3. Simulate your TM by running `./TMParser.exe <description text file> <accepts|run> <input>`

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
Example 1:

TM_addOneToBinaryNumber.txt:
```
alphabet: {0, 1}
start: q0
accept: Accept
reject: Reject

q0 (0 -> 0, R, q0) (1 -> 1, R, q0) (_ -> _, L, q1)
q1 (1 -> 0, L, q1) (0 -> 1, R, Accept) (_ -> 1, R, Accept)
```

Simulate:
```
$ ./TMParser.exe TM_addOneToBinaryNumber.txt run 10110111\
$ Input: '10110111'   Output: '10111000'
```

Example 2:

TM_acceptIfEven.txt:
```
alphabet: {0, 1}
start: q0
accept: Accept
reject: Reject

q0 (0 -> 0, R, q0) (1 -> 1, R, q0) (_ -> _, L, q1)
q1 (0 -> 0, R, Accept) (1 -> 1, R, Reject)
```

Simulate:
```
$ ./TMParser.exe TM_acceptIfEvenBinary.txt accept 10010101
$ '10010101' is accepted by the machine
```
\
Future goals include...
  - The implementation of a physical Turing Machine using 3D printing, an Arduino, and multicolor LEDs to represent the tape symbols.
  - A way to generate the node graph of the Turing Machine as it was defined by the user
  - An interactive web-based implementation
\

*Created by Bill Zhang and Nico Wong.
