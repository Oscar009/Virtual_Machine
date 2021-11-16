# Virtual_Machine

Simulation of Virtual Machine

## Script to run from terminal

Run inside the directory with the project files.

To compile:

```
g++ -Wall main.cpp VirtualMachine.cpp CPU.cpp Memory.cpp ProgramLoader.cpp Program.cpp Instruction.cpp Data.cpp START.cpp END.cpp MOV.cpp STO.cpp ADD.cpp MULT.cpp REST.cpp DIV.cpp CU.cpp ALU.cpp Register.cpp PC.cpp IR.cpp MAR.cpp MBR.cpp ACC.cpp AL.cpp AH.cpp BL.cpp BH.cpp LexicalAnalyzer.cpp Errorhandler.cpp Compiler.cpp ParseTree.cpp AbstractSyntaxTree -o main
```
To execute:

```
./main;
```
