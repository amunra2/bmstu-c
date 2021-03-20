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
	@echo "\nInput file in (like this - pos_xx or neg_xx):"; \
	read FILE_IN; \
	#echo "Input file out:"; \
	#read FILE_OUT; \
	echo "Input filtration:"; \
	read FILTER; \
	./app.exe func_tests/$$FILE_IN\_in.txt func_tests/$$FILE_IN\_out.txt $$FILTER
	

unit: $(UNIT_TEST)
	@./$(UNIT_TEST)


clean:
	@rm -rf $(OBJ_DIR) *.exe *.txt; \
	echo "Clean OK"
 

push:
	@git add . ; \
	echo "Input reason of a commit:"; \
	read MSG; \
	git commit -m "$$MSG"; \
	echo "Commit added with message:" $$MSG; \
	git push; \
	echo "Pushed OK"