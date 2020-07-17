#Cria um executável com o nome teste a partir do ficheiro teste.c

#Compiler: gcc for C program.
CC = gcc
#Compiler Flags:
# -Wall turns on most,but not all, compiler warnings
# -g Adds debugging information to the executable file
CFLAGS = -Wall
RM = rm 
RMD = rm -rf

#The build target executable:
TARGET= calculo

$(TARGET): $(TARGET).c
	$(CC)  $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
	$(RM)  calculo 

cleanDir:
	$(RMD)  Outputs2Threads  Outputs4Threads Outputs6Threads Outputs8Threads

