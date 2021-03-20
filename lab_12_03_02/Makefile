CC := gcc

OBJ_DIR := ./out
OBJECTS := $(CFILES:$(CFILES_DIR)/%.c=$(OBJ_DIR)/%.o)


LIB_FILES_DIR := ./libs
LIB_CFILES := $(wildcard $(LIB_FILES_DIR)/*.c)
LIBS_DYNAMIC := $(LIB_CFILES:$(LIB_FILES_DIR)/%.c=$(LIB_FILES_DIR)/lib_%.so)


FLAGS := -Wall -Werror -std=c99 -fPIC
U_FLAGS := -lcheck -lpthread -lrt	

APP = app.py


.PHONY : clean push run unit

$(LIB_FILES_DIR)/lib_%.so: $(OBJ_DIR)/%.o
	$(CC) -shared $< -o $@


$(OBJ_DIR)/%.o: $(LIB_FILES_DIR)/%.c $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@


$(OBJ_DIR):
	@mkdir -p $@


create_lib: $(LIBS_DYNAMIC)
	@echo "\nCreated libs"


run: $(LIBS_DYNAMIC)
	@echo "\nCreated libs"
	python3 $(APP)

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