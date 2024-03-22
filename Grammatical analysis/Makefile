GRM=analizador.y
LEX=analizador.l
BIN=analizador
SYM=symbol_table.c


CC=gcc
CFLAGS=-Wall -g

OBJ=y.tab.o lex.yy.o $(SYM:.c=.o) # Include all the objects 

TEST_DIR=samples

# Regla por defecto
all: $(BIN)

# Reglas para compilar objetos
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# Generate y.tab.c y y.tab.h from Bison
y.tab.c: $(GRM)
	yacc -d $<

# Generate lex.yy.c from Flex
lex.yy.c: $(LEX)
	flex $<

# Mix executable
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -L/opt/homebrew/Cellar/flex/2.6.4_2/lib -lfl

# Execute symbol_table.c
$(SYM:.c=.o): $(SYM)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean memory
clean:
	rm -f $(OBJ) y.tab.c y.tab.h lex.yy.c $(BIN)

# Testing Test Files
test: $(BIN)
	@echo "Running tests..."
	@for file in $(TEST_DIR)/*.c; do \
		echo "Testing $$file..."; \
		./$(BIN) < $$file; \
		echo ""; \
	done

.PHONY: all clean test
