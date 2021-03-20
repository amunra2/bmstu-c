CC := gcc

CFILES_DIR := ./src
CFILES := $(wildcard $(CFILES_DIR)/*.c)
INC_DIR := ./inc
INCLUDES := $(wildcard $(INC_DIR)/*.h)
UNIT_DIR := ./unit_tests
UNITS := $(wildcard $(UNIT_DIR)/*.c)

OBJ_DIR := ./out
OBJECTS := $(CFILES:$(CFILES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_UNIT := $(UNITS:$(UNIT_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_UNIT += $(filter-out $(OBJ_DIR)/main.o, $(OBJECTS))
FLAGS := -Wall -Werror -pedantic -std=c99
U_FLAGS := -lcheck -lpthread -lrt

APP = app.exe
UNIT_TEST = unit_tests.exe


.PHONY : clean push run unit


$(APP): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@


$(UNIT_TEST): $(OBJECTS_UNIT)
	$(CC) $(OBJECTS_UNIT) -o $@ $(U_FLAGS)


$(OBJ_DIR):
	@mkdir -p $@


$(OBJ_DIR)/%.o: $(CFILES_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(FLAGS) $(U_FLAGS) -c $< -o $@


$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(FLAGS) $(U_FLAGS) -c $< -o $@



run: $(APP)
	@./app.exe # func_tests/$$FILE_IN\_in.txt func_tests/$$FILE_IN\_out.txt; \
	#cat func_tests/$$FILE_IN\_out.txt



debug: $(APP)
	@valgrind --leak-check=full --leak-resolution=med --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./app.exe # func_tests/$$FILE_IN\_in.txt func_tests/$$FILE_IN\_out.txt; \
	#cat func_tests/$$FILE_IN\_out.txt

	

unit: $(UNIT_TEST)
	@./$(UNIT_TEST)

clean:
	@rm -rf $(OBJ_DIR) *.exe *.txt; \
	echo "Clean OK"
 

.ONESHELL:
push:
	@git status
	echo "\nDo u want to continue? y/n"
	read ANSWER
	
	if [ $$ANSWER = y ]
	then
		echo "\nInput reason of a commit:"
		read MSG
		git add .
		git commit -m "$$MSG"
		echo "\nCommit added with message:" $$MSG
		git push
		echo "\nPushed OK"
	else
		echo "\nPush canceled"
	fi