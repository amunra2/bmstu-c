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


LIB_FILES_DIR := ./libs
LIB_CFILES := $(wildcard $(LIB_FILES_DIR)/*.c)
LIBS_STATIC := $(LIB_CFILES:$(LIB_FILES_DIR)/%.c=$(LIB_FILES_DIR)/lib%.a)

LIBS_DYNAMIC := $(LIB_CFILES:$(LIB_FILES_DIR)/%.c=$(LIB_FILES_DIR)/lib%.so)

OBJ_DIR_DYNAM_LOAD := ./out_dynam_load
LIB_FILES_LOAD_DYNAM_DIR := ./src_dynam_load
LIB_FILES_LOAD_DYNAM := $(wildcard $(LIB_FILES_LOAD_DYNAM_DIR)/*.c)
OBJ_LIB_LOAD_DYNAM := $(LIB_FILES_LOAD_DYNAM:$(LIB_FILES_LOAD_DYNAM_DIR)/%.c=$(OBJ_DIR_DYNAM_LOAD)/%.o)



FLAGS := -Wall -Werror -std=c99 -fPIC
U_FLAGS := -lcheck -lpthread -lrt	

APP_STAT = app_stat.exe
APP_DYNAMIC = app_dynam.exe
APP_DYNAMIC_LOAD = app_dynam_load.exe
UNIT_TEST = unit_tests.exe


.PHONY : clean push run unit


# Static lib
$(APP_STAT): $(OBJECTS) $(LIBS_STATIC)
	$(CC) $(OBJECTS) $(LIBS_STATIC) -o $(APP_STAT)


$(LIB_FILES_DIR)/lib%.a: $(OBJ_DIR)/%.o
	ar rc $@ $<


# Dynamic lib
$(APP_DYNAMIC): $(OBJECTS) $(LIBS_DYNAMIC)
	$(CC) $(OBJECTS) $(LIBS_DYNAMIC) -o $@


$(LIB_FILES_DIR)/lib%.so: $(OBJ_DIR)/%.o
	$(CC) -shared $< -o $@
	

# Dynamic load lib
$(APP_DYNAMIC_LOAD): $(OBJ_LIB_LOAD_DYNAM) $(LIB_FILES_DIR)/lib_io_sort.so
	$(CC) $(OBJ_LIB_LOAD_DYNAM) -ldl -o $@


$(LIB_FILES_DIR)/lib_io_sort.so: $(OBJ_DIR)/file_work.o $(OBJ_DIR)/sort_key.o
	$(CC) -shared $(OBJ_DIR)/file_work.o $(OBJ_DIR)/sort_key.o -o $@

$(OBJ_DIR_DYNAM_LOAD):
	@mkdir -p $@

$(OBJ_DIR_DYNAM_LOAD)/%.o: $(LIB_FILES_LOAD_DYNAM_DIR)/%.c $(INCLUDES) $(OBJ_DIR_DYNAM_LOAD) 
	$(CC) $(FLAGS) -c $< -o $@


# All
$(OBJ_DIR)/%.o: $(LIB_FILES_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(FLAGS) $(U_FLAGS) -c $< -o $@


$(UNIT_TEST): $(OBJECTS_UNIT) $(LIBS_STATIC)
	$(CC) $(OBJECTS_UNIT) $(LIBS_STATIC) -o $@ $(U_FLAGS)


$(OBJ_DIR):
	@mkdir -p $@


$(OBJ_DIR)/%.o: $(CFILES_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(FLAGS) $(U_FLAGS) -c $< -o $@


$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(FLAGS) $(U_FLAGS) -c $< -o $@



run_stat: $(APP_STAT)
	@echo "\nInput file in (like this - pos_xx or neg_xx):"; \
	read FILE_IN; \
	echo "Input filtration:"; \
	read FILTER; \
	./app_stat.exe func_tests/$$FILE_IN\_in.txt func_tests/$$FILE_IN\_out.txt $$FILTER


run_dynam: $(APP_DYNAMIC)
	@echo "\nInput file in (like this - pos_xx or neg_xx):"; \
	read FILE_IN; \
	echo "Input filtration:"; \
	read FILTER; \
	./app_dynam.exe func_tests/$$FILE_IN\_in.txt func_tests/$$FILE_IN\_out.txt $$FILTER


run_dynam_load: $(APP_DYNAMIC_LOAD)
	@echo "\nInput file in (like this - pos_xx or neg_xx):"; \
	read FILE_IN; \
	echo "Input filtration:"; \
	read FILTER; \
	./app_dynam_load.exe func_tests/$$FILE_IN\_in.txt func_tests/$$FILE_IN\_out.txt $$FILTER


unit: $(UNIT_TEST)
	@./$(UNIT_TEST)


clean:
	@rm -rf $(OBJ_DIR) *.exe *.txt $(LIB_FILES_DIR)/*.a $(LIB_FILES_DIR)/*.so; \
	echo "Clean OK"
 

push:
	@git add . ; \
	echo "Input reason of a commit:"; \
	read MSG; \
	git commit -m "$$MSG"; \
	echo "Commit added with message:" $$MSG; \
	git push; \
	echo "Pushed OK"