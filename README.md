# Forbidden Function Checker for 42 Projects

This tool detects forbidden function usage in 42 school projects by attempting to link your project’s object files with a file that declares  **only allowed functions** . If forbidden functions are used, the linker will raise errors.

## 📦 Setup

Clone this repository into the root of your 42 project:

```bash
git clone https://github.com/yourname/forbidden-function-checker.git
```

## 🛠️ Makefile Integration

Add the following lines to your project's `Makefile`:

```makefile
CC := gcc
INCLUDE := -I ./include

CFLAGS := -Wall -Wextra -g -ffreestanding -fno-builtin -fno-tree-loop-distribute-patterns $(INCLUDE)

PROJECT_OBJECTS_AND_LIBRARIES := $(OBJ) $(LDLIBS)
ALLOWED_FCTS_DIR := forbidden-function-checker/allowed_functions

check_forbidden_%:
	$(CC) -c $(ALLOWED_FCTS_DIR)/$*.c
	@ld $*.o $(LDFLAGS) $(PROJECT_OBJECTS_AND_LIBRARIES)
	@$(RM) $*.o
	@echo "No forbidden function detected."
```

* `$(OBJ)` and `$(LDLIBS)` must already be defined in your Makefile.
* Each project must have a corresponding C file in `forbidden-function-checker/allowed_functions/` named `<project>.c`, which declares only allowed functions.

## ✅ Usage

To check a specific project, run:

```bash
make check_forbidden_<project_name>
```

Example:

```bash
make check_forbidden_pipex
```

This will compile and link `forbidden-function-checker/allowed_functions/pipex.c` with your object files.

## 🔍 Output

* ✅ **Success:**
  ```
  No forbidden function detected.
  ```
  → Your project uses only allowed functions.
* ❌ **Failure:**
  ```
  undefined reference to `...`
  ```
  → One or more forbidden functions are used. Linker errors will point them out.
