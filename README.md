# COP4338 - Systems Programming

## Table of Contents

- [**Chapter 0: UNIX Basics**](#chapter-0-unix-basics)

  - [UNIX Cheat Sheet](#unix-cheat-sheet)
  - [.vimrc](#vimrc)
  - [.nanorc](#nanorc)

- [**Chapter 1: Basics, Command Line Arguments, and Makefile**](#chapter-1-basics-command-line-arguments-and-makefile)

  - [Command Line Arguments (argc, argv)](#command-line-arguments-argc-argv)
  - [Command Line Arguments (Validation)](#command-line-arguments-validation)
  - [Command Line Arguments and Files](#command-line-arguments-and-files)
  - [Macros (#define directive)](#macros-define-directive)
  - [Single Step Compilation](#single-step-compilation)
  - [Modular Compilation](#modular-compilation)
  - [Makefiles](#makefiles)
  - [Makefile (Sample)](#makefile-sample)

- [**Chapter 2: Variables, Data Types, and Random Numbers**](#chapter-2-variables-data-types-and-random-numbers)

  - [Variables](#variables)
  - [Variable Declaration (Integers)](#variable-declaration-integers)
  - [Identifiers](#identifiers)
  - [Keywords Table](#keywords-table)
  - [Arithmetic Expressions](#arithmetic-expressions)
  - [Precendence](#precendence)
  - [Double vs Int](#double-vs-int)
  - [Floating Point Numbers](#floating-point-numbers)
  - [Printing Floating Point Numbers](#printing-floating-point-numbers)
  - [Floating Point Division by Zero (-inf, +inf)](#floating-point-division-by-zero--inf-inf)
  - [Scientific Notation](#scientific-notation)
  - [Constants](#constants)
  - [Math Library \<math.h\>](#math-library-mathh)
  - [Integer Division (floor division)](#integer-division-floor-division)
  - [Integer Division by Zero (NaN, Undefined)](#integer-division-by-zero-nan-undefined)
  - [Modulo (%)](#modulo-)
  - [Extracting Digits (%, /)](#extracting-digits--)
  - [Random Numbers in Range (%)](#random-numbers-in-range-)
  - [Type Conversions](#type-conversions)
  - [Type Casting](#type-casting)
  - [Binary](#binary)
  - [ASCII Table](#ascii-table)
  - [Character Data Type](#character-data-type)
  - [Strings](#strings)
  - [Strings as Character Arrays - char\[\]](#strings-as-character-arrays---char)
  - [Scanf and Whitespace](#scanf-and-whitespace)
  - [Integer Overflow](#integer-overflow)
  - [Numeric Data Types](#numeric-data-types)
  - [Floating Point Data Types](#floating-point-data-types)
  - [Unsigned Data Types](#unsigned-data-types)
  - [Random Numbers \<stdlib.h\> and \<time.h\>](#random-numbers-stdlibh-and-timeh)
  - [Format Specifier Table \<stdio.h\>](#format-specifier-table-stdioh)
  - [Input using Scanf (I/O)](#input-using-scanf-io)

- [**Chapter 3: Control Flow and String Manipulation**](#chapter-3-control-flow-and-string-manipulation)

  - [Control Statements (if, else, else if)](#control-statements-if-else-else-if)
  - [Equality Operator (==)](#equality-operator-)
  - [Integer, Character and Floating Point Equality](#integer-character-and-floating-point-equality)
  - [Relational Operators (\<, \>, \<=,\>=)](#relational-operators---)
  - [Logical Operators (\&\&, ||, !)](#logical-operators---)
  - [Bitwise Operators (\&, |, \<\<, \>\>)](#bitwise-operators----)
  - [Order of Evaluation](#order-of-evaluation)
  - [Switch Case Statement](#switch-case-statement)
  - [Boolean Data Type \<stdbool.h\>](#boolean-data-type-stdboolh)
  - [String Comparison (strcmp)](#string-comparison-strcmp)
  - [String Indexing](#string-indexing)
  - [String Methods \<string.h\>](#string-methods-stringh)
  - [Character Operations \<ctype.h\>](#character-operations-ctypeh)
  - [Ternary Operator (?)](#ternary-operator-)
  - [Floating Point Comparison (delta)](#floating-point-comparison-delta)
  - [Short Circuit Evaluation](#short-circuit-evaluation)

- [**Chapter 4: Loops, Scope and Enums**](#chapter-4-loops-scope-and-enums)

  - [While Loops](#while-loops)
  - [For Loops](#for-loops)
  - [Pre vs Post Operators](#pre-vs-post-operators)
  - [Do-While Loops](#do-while-loops)
  - [Loops and Strings](#loops-and-strings)
  - [Nested Loops](#nested-loops)
  - [Break Statement](#break-statement)
  - [Continue Statement](#continue-statement)
  - [Loop Indexing](#loop-indexing)
  - [Variable Scope](#variable-scope)
  - [Enums](#enums)
  - [Enums Example](#enums-example)

- [**Chapter 5: Arrays and Strings**](#chapter-5-arrays-and-strings)

  - [General Concept](#general-concept)
  - [Array Declaration](#array-declaration)
  - [Array Initialization](#array-initialization)
  - [Array Iteration (+ Out of Bounds)](#array-iteration--out-of-bounds)
  - [Multiple Arrays](#multiple-arrays)
  - [Swapping Values](#swapping-values)
  - [2D Arrays](#2d-arrays)
  - [Character Arrays](#character-arrays)
  - [String Library \<string.h\>](#string-library-stringh)
  - [I/O: scanf vs fgets \<stdio.h\>](#io-scanf-vs-fgets-stdioh)
  - [Type Checking and Conversion \<ctype.h\>](#type-checking-and-conversion-ctypeh)
  - [Arrays and Strings (Example)](#arrays-and-strings-example)
  - [Annual Salary (Example)](#annual-salary-example)

- [**Chapter 6: Functions**](#chapter-6-functions)

  - [Basics](#basics)
  - [Parameters](#parameters)
  - [Void Functions](#void-functions)
  - [Modular Development](#modular-development)
  - [Modular Math Expressions](#modular-math-expressions)
  - [Unit Testing](#unit-testing)
  - [Assertions (Unit Testing) <assert.h>](#assertions-unit-testing-asserth)
  - [How Functions Work](#how-functions-work)
  - [Pass by Value](#pass-by-value)
  - [Pass by Pointer/Reference](#pass-by-pointerreference)
  - [Functions with Array Parameters](#functions-with-array-parameters)
  - [Const and Array Parameters](#const-and-array-parameters)
  - [Strings as Parameters](#strings-as-parameters)
  - [Function Protope/Declaration](#function-protopedeclaration)
  - [Variable Scope (Functions)](#variable-scope-functions)
  - [Preprocessor and Include](#preprocessor-and-include)
  - [Header Guards](#header-guards)
  - [Separate Files](#separate-files)

- [**Chapter 7: Structs**](#chapter-7-structs)

  - [Defining Structs and Typedef](#defining-structs-and-typedef)
  - [Returning Structs from Functions](#returning-structs-from-functions)
  - [Structs and Arrays](#structs-and-arrays)
  - [Structs, Arrays, and Functions (Example)](#structs-arrays-and-functions-example)
  - [Derefencing a Pointer to a Struct (->)](#derefencing-a-pointer-to-a-struct--)
  - [Seperate Files for Structs](#seperate-files-for-structs)

- [**Chapter 8: Pointers**](#chapter-8-pointers)

  - [Why Pointers](#why-pointers)
  - [Pointer Basics](#pointer-basics)
  - [Dereferencing a Pointer](#dereferencing-a-pointer)
  - [Null Pointer](#null-pointer)
  - [Common Pointer Mistakes](#common-pointer-mistakes)
  - [**Malloc Function**](#malloc-function)
  - [**Free Function**](#free-function)
  - [Pointers with Structs](#pointers-with-structs)
  - [String Functions with Pointers](#string-functions-with-pointers)
  - [String Searching Methods (Table)](#string-searching-methods-table)
  - [Malloc for Arrays and Strings](#malloc-for-arrays-and-strings)
  - [Dynamic Copy of a String](#dynamic-copy-of-a-string)
  - [**Realloc Function**](#realloc-function)
    - [Dynamically Reallocating Size of an Array (Code)](#dynamically-reallocating-size-of-an-array-code)
  - [**Vector ADT**](#vector-adt)
    - [vector.h](#vectorh)
    - [Vector Implementation](#vector-implementation)
    - [**Vector Functions (Table)**](#vector-functions-table)
    - [Segmentation Fault](#segmentation-fault)
  - [LinkedList vs. Vector](#linkedlist-vs-vector)
    - [LinkedList (Code)](#linkedlist-code)
  - [**Memory Regions - Heap and Stack (Table)**](#memory-regions---heap-and-stack-table)
  - [Memory Leaks](#memory-leaks)

- [**Chapter 9: Input and Output**](#chapter-9-input-and-output)
  - [File Pointer: stdout (fprintf)](#file-pointer-stdout-fprintf)
  - [File Pointer: stdin (fscanf)](#file-pointer-stdin-fscanf)
  - [Formatted Output (Table)](#formatted-output-table)
    - [Integer Formatting](#integer-formatting)
    - [String Formatting](#string-formatting)
  - [Flushing Output (fflush)](#flushing-output-fflush)
  - [**Input Parsing**](#input-parsing)
    - [Input Validation](#input-validation)
  - [Parsing Input String (sscanf)](#parsing-input-string-sscanf)
    - [Parsing Input (sscanf and fgets) Example](#parsing-input-sscanf-and-fgets-example)
  - [**File Input and Output**](#file-input-and-output)
    - [**Writting to Files (fopen)**](#writting-to-files-fopen)
  - [**Parsing Through an Entire File (!feof)**](#parsing-through-an-entire-file-feof)
  - [Binary Files](#binary-files)
    - [Writting to a Binary Files](#writting-to-a-binary-files)
    - [Reading from a Binary File](#reading-from-a-binary-file)

## Chapter 0: UNIX Basics

### UNIX Cheat Sheet

![UNIX Cheat Sheet](./images/0.%20UNIX%20Cheat%20Sheet.png)

## .vimrc

```vim
""set background=dark
""set termguicolors
""colorscheme fleet2

syntax on
set number
set expandtab
set tabstop=4
set shiftwidth=4
set ignorecase
set smarttab
set smartcase
""set showmatch
set history=500
set lbr
set tw=500
set ai "Auto Indent"
set wrap "Wrap Lines"
set hlsearch
set lazyredraw
set magic
set wildmenu

" Ignore compiled files
set wildignore=*.o,*~,*.pyc
if has("win16") || has("win32")
    set wildignore+=.git\*,.hg\*,.svn\*
else
    set wildignore+=*/.git/*,*/.hg/*,*/.svn/*,*/.DS_Store
endif

" Set to auto read when a file is changed from the outside
set autoread
au FocusGained,BufEnter * checktime

" Configure backspace so it acts as it should act
set backspace=eol,start,indent
set whichwrap+=<,>,h,l

" Enable filetype plugins
filetype on
filetype plugin on
filetype indent on

" in makefiles, don't expand tabs to spaces, since actual tab characters are
" needed, and have indentation at 8 chars to be sure that all indents are tabs
" (despite the mappings later):
autocmd FileType make set noexpandtab shiftwidth=8 softtabstop=0

" for C-like  programming where comments have explicit end
" characters, if starting a new line in the middle of a comment automatically
" insert the comment leader characters:
autocmd FileType c,cpp,java set formatoptions+=ro
autocmd FileType c set omnifunc=ccomplete#Complete

" add completion for xHTML
autocmd FileType xhtml,html set omnifunc=htmlcomplete#CompleteTags

" Return to last edit position when opening files (You want this!)
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

" Delete trailing white space on save, useful for some filetypes ;)
fun! CleanExtraSpaces()
    let save_cursor = getpos(".")
    let old_query = getreg('/')
    silent! %s/\s\+$//e
    call setpos('.', save_cursor)
    call setreg('/', old_query)
endfun

inoremap { {}<Esc>ha
inoremap ( ()<Esc>ha
inoremap [ []<Esc>ha
inoremap " ""<Esc>ha
inoremap ' ''<Esc>ha
inoremap ` ``<Esc>ha

" Output the current syntax group
nnoremap <f10> :echo "hi<" . synIDattr(synID(line("."),col("."),1),"name") . '> trans<'
\ . synIDattr(synID(line("."),col("."),0),"name") . "> lo<"
\ . synIDattr(synIDtrans(synID(line("."),col("."),1)),"name") . ">"<cr>

```

### .nanorc

```vim
set atblanks        # wrap line at blanks.
set softwrap        # Enable softwrap of lines.
set tabsize 4       # Sets tab-to-spaces size to 4.
set tabstospaces    # Converts TAB key press to spaces.
set linenumbers     # Lines are numbered.
set casesensitive   # Case insensitive search.
set historylog      # Save the last 100 history searches for later use.
set positionlog     # Saves the cursor position between editing sessions.
set autoindent      # A new line will have the same number of leading spaces as the previous one.
set brackets ""')>]}"
set matchbrackets "(<[{)>]}"
set smooth

```

[Back to top](#table-of-contents)

## Chapter 1: Basics, Command Line Arguments, and Makefile

### Command Line Arguments (argc, argv)

![Command Line Arguments (argc, argv)](./images/1.13%20Command%20Line%20Arguments.png)

### Command Line Arguments (Validation)

![Command Line Arguments (Validation)](<./images/1.13%20Validation%20(argc%20and%20argv).png>)

### Command Line Arguments and Files

![Command Line Arguments and Files](./images/1.14%20Command%20Line%20Args%20and%20Files.png)

### Macros (#define directive)

![Macros (#define directive)](<./images/1.15%20%23define%20Directive%20(macro).png>)

### Single Step Compilation

![Single Step Compilation](./images/1.16%20Single%20Step%20Compilation.png)
[Back to top](#table-of-contents)

### Modular Compilation

![Modular Compilation](./images/1.16%20Modular%20Compilation.png)

### Makefiles

![Makefiles](./images/1.17%20Makefiles.png)

### Makefile (Sample)

![Makefiles (Sample)](./images/1.17%20Sample%20Makefile.png)

[Back to top](#table-of-contents)

## Chapter 2: Variables, Data Types, and Random Numbers

### Variables

![Variables](./images/2.1%20Variables.png)

### Variable Declaration (Integers)

![Variable Declaration (Integers)](<./images/2.2%20Variable%20Declaration%20(int).png>)

### Identifiers

![Identifiers](./images/2.3%20Identifiers.png)

### Keywords Table

![Keywords Table](./images/2.3%20Keywords.png)
[Back to top](#table-of-contents)

### Arithmetic Expressions

![Arithmetic Expressions](./images/2.4%20Arithmetic%20Expressions.png)

### Precendence

![Precendence](./images/2.4%20Precendence.png)

### Double vs Int

![Double vs Int](./images/2.7%20Double%20vs%20Int.png)

### Floating Point Numbers

![Floating Point Numbers](./images/2.7%20Floating%20Point%20Numbers.png)

### Printing Floating Point Numbers

![Printing Floating Point Numbers](./images/2.7%20Printing%20Floating%20Points.png)

### Floating Point Division by Zero (-inf, +inf)

![Floating Point Division by Zero (-inf, +inf)](./images/2.7%20Floating%20Point%20Division%20by%20Zero.png)
[Back to top](#table-of-contents)

### Scientific Notation

![Scientific Notation](./images/2.8%20Scientific%20Notation.png)

### Constants

![Constants](./images/2.9%20Constants.png)

### Math Library <math.h>

![Math Library <math.h>](./images/2.10%20Math%20Library%20%3Cmath.h%3E.png)

### Integer Division (floor division)

![Integer Division](./images/2.11%20Integer%20Division.png)

### Integer Division by Zero (NaN, Undefined)

![Integer Division by Zero (NaN, Undefined)](./images/2.11%20Integer%20Division%20by%20Zero.png)

### Modulo (%)

![Modulo (%)](./images/2.11%20Modulo.png)

### Extracting Digits (%, /)

![Extracting Digits (%, /)](./images/2.11%20Getting%20Digits.png)

### Random Numbers in Range (%)

![Random Numbers](./images/2.11%20Random%20Numbers.png)

### Type Conversions

![Type Conversions](./images/2.12%20Type%20Conversion.png)

### Type Casting

[Back to top](#table-of-contents)

![Type Casting](./images/2.12%20Type%20Casting.png)

### Binary

![Binary](./images/2.13%20Binary.png)

### ASCII Table

![ASCII Table](./images/2.14%20ASCII%20Table.png)

### Character Data Type

![Character Data Type](./images/2.14%20Characters.png)

### Strings

![Strings](./images/2.15%20Strings.png)

### Strings as Character Arrays - char[]

![Strings as Character Arrays - char[]](./images/2.15%20String%20as%20char%5B%5D.png)

### Scanf and Whitespace

![Scanf and Whitespace](./images/2.15%20scanf%20and%20Whitespace.png)

### Integer Overflow

![Integer Overflow](./images/2.16%20Integer%20Overflow.png)
![Integer Overflow](./images/2.16%20Overflow%20Error.png)
[Back to top](#table-of-contents)

### Numeric Data Types

![Numeric Data Types](./images/2.17%20Numeric%20Data%20Types.png)

### Floating Point Data Types

![Floating Point Data Types](./images/2.17%20Floating%20Point%20Data%20Types.png)

### Unsigned Data Types

![Unsigned Data Types](./images/2.17%20Unsigned%20Data%20Types.png)

### Random Numbers <stdlib.h> and <time.h>

![Random Numbers <stdlib.h> and <time.h>](./images/2.19%20Random%20Numbers%20%3Ctime.h%3E.png)

### Format Specifier Table <stdio.h>

![Format Specifier Table <stdio.h>](./images/2.20%20Format%20Specifier%20%3Cstdio.h%3E.png)

### Input using Scanf (I/O)

[Back to top](#table-of-contents)

![Input using Scanf (I/O)](./images/2.20%20scanf.png)

[Back to top](#table-of-contents)

## Chapter 3: Control Flow and String Manipulation

### Control Statements (if, else, else if)

![Control Statements (if, else, else if)](./images/3.1%20If-else%20if-else.png)

### Equality Operator (==)

![Equality Operator (==)](./images/3.2%20Equality%20Operator.png)

### Integer, Character and Floating Point Equality

![Integer, Character and Floating Point Equality](<./images/3.2%20ints%2C%20chars%2C%20and%20floats%20(%3D%3D).png>)

### Relational Operators (<, >, <=,>=)

[Back to top](#table-of-contents)

![Relational Operators (<, >, <=,>=)](./images/3.4%20Relational%20Operators.png)

### Logical Operators (&&, ||, !)

![Logical Operators (&&, ||, !)](./images/3.5%20Logical%20Operators.png)
![Logical Operators (&&, ||, !) C](<./images/3.5%20Logical%20Operators%20(C).png>)

### Bitwise Operators (&, |, <<, >>)

![Bitwise Operators (&, |, <<, >>)](./images/3.10%20Bitwise%20Operators.png)

### Order of Evaluation

![Order of Evaluation](./images/3.10%20Order%20of%20Evaluation.png)
[Back to top](#table-of-contents)

### Switch Case Statement

![OSwitch Case Statement](./images/3.11%20Switch%20Statement.png)
![OSwitch Case Statement](<./images/3.11%20Switch%20(No%20Break).png>)

### Boolean Data Type <stdbool.h>

![Boolean Data Type <stdbool.h>](./images/3.12%20Boolean%20%3Cstdbool.h%3E.png)

### String Comparison (strcmp)

![String Comparison (strcmp)](<./images/3.13%20String%20Comparison%20(strcmp).png>)
![String Comparison Common Errors](./images/3.13%20String%20Error.png)

### String Indexing

![String Indexing](./images/3.14%20String%20Index.png)

### String Methods <string.h>

![String Methods <string.h>](./images/3.14%20String%20Methods%20%3Cstring.h%3E.png)
[Back to top](#table-of-contents)

### Character Operations <ctype.h>

![Character Operations <ctype.h>](./images/3.15%20Character%20Operations%20%3Cctype.h%3E.png)

### Ternary Operator (?)

![Ternary Operator (?)](<./images/3.16%20Ternary%20Operator%20(%3F).png>)

## Floating Point Comparison (delta)

![Floating Point Comparison (delta)](<./images/3.17%20Float%20Comparison%20(delta).png>)
[Back to top](#table-of-contents)

### Short Circuit Evaluation

![Short Circuit Evaluation](./images/3.18%20Short%20Circuit%20Evaluation.png)

[Back to top](#table-of-contents)

## Chapter 4: Loops, Scope and Enums

### While Loops

![While Loops](./images/4.2%20While%20Loops.png)

### For Loops

![For Loops](./images/4.4%20For%20Loops.png)
![For Loops](./images/4.4%20For%20Loop%20Styling.png)
[Back to top](#table-of-contents)

### Pre vs Post Operators

![Pre vs Post Operators](./images/4.4%20Pre%20vs%20Post%20Increment.png)

### Do-While Loops

![Do-While Loops](./images/4.6%20Do-While%20Loops.png)

### Loops and Strings

![Loops and Strings](./images/4.7%20Loops%20and%20Strings.png)

### Nested Loops

![Nested Loops](./images/4.8%20Nested%20Loops.png)
[Back to top](#table-of-contents)

### Break Statement

![Break Statement](./images/4.10%20Break%20Statement.png)

### Continue Statement

![Continue Statement](./images/4.10%20Continue%20Statement.png)

### Loop Indexing

![Loop Indexing](./images/4.11%20Loop%20Index.png)
[Back to top](#table-of-contents)

### Variable Scope

![Variable Scope](./images/4.11%20Variable%20Scope.png)

### Enums

![Enums](./images/4.12%20Enums.png)

### Enums Example

![Enums Example](./images/4.12%20Enum%20Example.png)

```c
#include <stdio.h>

/* Manual controller for traffic light */
int main(void) {
    enum LightState { LS_RED,
                      LS_GREEN,
                      LS_YELLOW,
                      LS_DONE };
    enum LightState lightVal;
    char userCmd;

    lightVal = LS_RED;
    userCmd = '-';

    printf("User commands: n (next), r (red), q (quit).\n\n");

    lightVal = LS_RED;
    while (lightVal != LS_DONE) {
        if (lightVal == LS_GREEN) {
            printf("Green light  ");
            scanf(" %c", &userCmd);
            if (userCmd == 'n') {  // Next
                lightVal = LS_YELLOW;
            }
        } else if (lightVal == LS_YELLOW) {
            printf("Yellow light  ");
            scanf(" %c", &userCmd);
            if (userCmd == 'n') {  // Next
                lightVal = LS_RED;
            }
        } else if (lightVal == LS_RED) {
            printf("Red light  ");
            scanf(" %c", &userCmd);
            if (userCmd == 'n') {  // Next
                lightVal = LS_GREEN;
            }
        }

        if (userCmd == 'r') {  // Force immediate red
            lightVal = LS_RED;
        } else if (userCmd == 'q') {  // Quit
            lightVal = LS_DONE;
        }
    }

    printf("Quit program.\n");

    return 0;
}

```

[Back to top](#table-of-contents)

## Chapter 5: Arrays and Strings

### General Concept

![General](./images/5.1.%20Arrays%20General.png)

### Array Declaration

![Array Declaration](./images/5.2%20Array%20Declaration.png)

### Array Initialization

![Array Initialization](./images/5.3%20Array%20Initialization.png)

### Array Iteration (+ Out of Bounds)

![Array Iteration](./images/5.4%20Array%20Iteration.png)
![Array Out of Bounds](./images/5.4%20Out%20of%20Bounds.png)

### Multiple Arrays

![Multiple Arrays](./images/5.5%20Multiple%20Arrays.png)
[Back to top](#table-of-contents)

### Swapping Values

![Swapping Values](./images/5.6%20Swapping%20Values.png)

### 2D Arrays

![2D Arrays](./images/5.9%202D%20Arrays.png)

### Character Arrays

![Character Arrays](./images/5.10%20Character%20Arrays.png)
![Character Arrays Common Errors](<./images/5.10%20String%20Error%20(strcpy).png>)

### String Library <string.h>

![String Library 1](./images/5.11%20String%20Library%20%3Cstring.h%3E.png)
![String Library 2](./images/5.11%20String%20Function%20%3Cstring.h%3E.png)

### I/O: scanf vs fgets <stdio.h>

![I/O: scanf vs fgets](<./images/5.11%20User%20Input%20(scanf%20and%20fgets).png>)
[Back to top](#table-of-contents)

### Type Checking and Conversion <ctype.h>

![Type Checking](./images/5.12%20Character%20Checking%20%3Cctype.h%3E.png)
![Type Conversion](./images/5.12%20Character%20Conversion%20%3Cctype.h%3E.png)

### Arrays and Strings (Example)

![Arrays and Strings (Example)](./images/5.13%20Arrays%20and%20Strings.png)

### Annual Salary (Example)

![Annual Salary (Example)](./images/5.14%20Example.png)

```c
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const int BASE_TABLE_ELEMENTS = 5;
    const int MAX_ELEMENTS = 10;
    int annualSalary;
    double taxRate;
    int taxToPay;
    int totalSalaries;
    int totalTaxes;
    int numSalaries;
    bool keepLooking;
    int i;

    int salaryBase[] = {20000, 50000, 100000, 999999999};
    double taxBase[] = {.10, .20, .30, .40};
    int annualSalaries[MAX_ELEMENTS];
    int taxesToPay[MAX_ELEMENTS];

    numSalaries = 0;

    printf("\nEnter annual salary (0 to exit): \n");
    scanf("%d", &annualSalary);

    while ((annualSalary > 0) && (numSalaries < MAX_ELEMENTS)) {
        i = 0;
        taxRate = 0;
        keepLooking = true;

        // Search for appropriate table row for given annualSalary
        while ((i < BASE_TABLE_ELEMENTS) && keepLooking) {
            if (annualSalary <= salaryBase[i]) {
                taxRate = taxBase[i];
                keepLooking = false;
            } else {
                ++i;
            }
        }  // End inner while loop (search for appropriate table row)

        taxToPay = (int)(annualSalary * taxRate);  // Truncate tax to an integer amount
        annualSalaries[numSalaries] = annualSalary;
        taxesToPay[numSalaries] = taxToPay;

        printf("Annual salary: %d", annualSalaries[numSalaries]);
        printf("\tTax rate: %lf", taxRate);
        printf("\tTax to pay: %d\n", taxesToPay[numSalaries]);
        ++numSalaries;

        // Get the next annual salary
        printf("\nEnter annual salary (0 to exit): \n");
        scanf("%d", &annualSalary);
    }  // End outer while loop (valid annualSalary entered)

    // Sum the annual salaries and taxes to pay and print the totals
    totalSalaries = 0;
    totalTaxes = 0;

    for (i = 0; i < numSalaries; ++i) {
        totalSalaries += annualSalaries[i];
        totalTaxes += taxesToPay[i];
    }
    printf("\nTotal salaries: %d", totalSalaries);
    printf("\tTotal taxes: %d\n", totalTaxes);

    return 0;
}

```

[Back to top](#table-of-contents)

## Chapter 6: Functions

### Basics

![Basics](./images/6.1%20Basic%20Functions.png)

### Parameters

![Parameters](./images/6.1%20Parameters.png)
![Parameters](./images/6.1%20Void%20Parameter.png)

### Void Functions

![Void Functions](./images/6.2%20Void%20Functions.png)

### Modular Development

![Modular Development](./images/6.3%20Modular%20Development.png)

### Modular Math Expressions

![Modular Math Expressions](./images/6.4%20Modular%20Math%20Expressions.png)
[Back to top](#table-of-contents)

### Unit Testing

![Unit Testing](./images/6.7%20Unit%20Testing.png)

### Assertions (Unit Testing) <assert.h>

![Assertions (Unit Testing) <assert.h>](./images/6.7%20Assert%20%3Cassert.h%3E.png)

### How Functions Work

![How Functions Work](./images/6.8%20How%20Functions%20Work.png)

### Pass by Value

![Pass by Value](./images/6.10%20Pass%20by%20Value.png)

### Pass by Pointer/Reference

![Pass by Pointer/Reference](./images/6.10%20Pass%20by%20pointer.png)
[Back to top](#table-of-contents)

### Functions with Array Parameters

![Functions with Array Parameters](./images/6.11%20Functions%20With%20Arrays%20Params.png)

### Const and Array Parameters

![Const and Array Parameters](./images/6.11%20Const%20and%20Array%20Parameters.png)

### Strings as Parameters

![Strings as Parameters](./images/6.12%20Strings%20as%20Parameters.png)

### Function Protope/Declaration

[Back to top](#table-of-contents)

![Function Prototype/Declaration](./images/6.14%20Variable%20Scope.png)

### Variable Scope (Functions)

![Variable Scope (Functions)](./images/6.14%20Variable%20Scope.png)

### Preprocessor and Include

![Header Guards](./images/6.16%20Preprocessor%20and%20Include.png)

### Header Guards

![Header Guards](./images/6.17%20Header%20Guards.png)

### Separate Files

![Separate Files](./images/6.17%20Separate%20Files.png)

[Back to top](#table-of-contents)

## **Chapter 7: Structs**

- [**Chapter 7: Structs**](#chapter-7-structs)
  - [Defining Structs and Typedef](#defining-structs-and-typedef)
  - [Returning Structs from Functions](#returning-structs-from-functions)
  - [Structs and Arrays](#structs-and-arrays)
  - [Structs, Arrays, and Functions (Example)](#structs-arrays-and-functions-example)
  - [Seperate Files for Structs](#seperate-files-for-structs)

### Defining Structs and Typedef

![Defining Structs and Typedef](./images//7.1%20Defining%20Structs%20and%20Typedef.png)

### Returning Structs from Functions

![Returning Structs from Functions](./images/7.2%20Returning%20Structs%20from%20Functions.png)

### Structs and Arrays

![Structs and Arrays](./images/7.3%20Structs%20and%20Arrays.png)

### Structs, Arrays, and Functions (Example)

A programmer commonly uses structs, arrays, and functions together. Consider a program that allows a reservations agent to reserve seats for people, useful for a theater, an airplane, etc. The below program defines a Seat struct whose data members are a person's first name, last name, and the amount paid for the seat. The program declares an array of 5 seats to represent the theater, airplane, etc., initializes all seats to being empty (indicated by a first name of "empty"), and then allows a user to enter commands to print all seats, reserve a seat, or quit.

```c
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Seat_struct {
    char firstName[50];
    char lastName[50];
    int amountPaid;
} Seat;

/*** Functions for Seat ***/

void SeatMakeEmpty(Seat* seat) {
    strcpy((*seat).firstName, "empty");
    strcpy((*seat).lastName, "empty");
    (*seat).amountPaid = 0;
}

bool SeatIsEmpty(Seat seat) {
    return (strcmp(seat.firstName, "empty") == 0);
}

void SeatPrint(Seat seat) {
    printf("%s ", seat.firstName);
    printf("%s, ", seat.lastName);
    printf("Paid: %d\n", seat.amountPaid);
}
/*** End functions for Seat ***/

/*** Functions for array of Seat ***/
void SeatsMakeEmpty(Seat seats[], int numSeats) {
    int i;

    for (i = 0; i < numSeats; ++i) {
        SeatMakeEmpty(&seats[i]);
    }
}

void SeatsPrint(Seat seats[], int numSeats) {
    int i;

    for (i = 0; i < numSeats; ++i) {
        printf("%d: ", i);
        SeatPrint(seats[i]);
    }
}
/*** End functions for array of Seat ***/

int main(void) {
    const int NUM_SEATS = 5;
    char userKey;
    int seatNum;
    Seat allSeats[NUM_SEATS];
    Seat currSeat;

    userKey = '-';

    SeatsMakeEmpty(allSeats, NUM_SEATS);

    while (userKey != 'q') {
        printf("Enter command (p/r/q): ");
        scanf(" %c", &userKey);

        if (userKey == 'p') {  // Print seats
            SeatsPrint(allSeats, NUM_SEATS);
            printf("\n");
        } else if (userKey == 'r') {  // Reserve seat
            printf("Enter seat num: ");
            scanf("%d", &seatNum);

            if (!SeatIsEmpty(allSeats[seatNum])) {
                printf("Seat not empty.\n\n");
            } else {
                printf("Enter first name: ");
                scanf("%s", currSeat.firstName);
                printf("Enter last name: ");
                scanf("%s", currSeat.lastName);
                printf("Enter amount paid: ");
                scanf("%d", &currSeat.amountPaid);

                allSeats[seatNum] = currSeat;

                printf("Completed.\n\n");
            }
        }
        // FIXME: Add option to delete reservations
        else if (userKey == 'q') {  // Quit
            printf("Quitting.\n");
        } else {
            printf("Invalid command.\n\n");
        }
    }

    return 0;
}
```

### Derefencing a Pointer to a Struct (->)

![Derefencing a Pointer to a Struct](./images/7.4%20Deferencing%20a%20Pointer%20to%20a%20Struct.png)

### Seperate Files for Structs

![Seperate Files for Structs](./images/7.5%20Separate%20Files%20for%20Structs.png)

## Chapter 8: Pointers

### Why Pointers

![Why pointers](./images/8.1%20Pointers.png)

### Pointer Basics

![Pointer Basics](./images/8.2%20Pointer%20Basics.png)

[Back to top](#table-of-contents)

### Dereferencing a Pointer

![Dereferencing a Pointer](./images/8.2%20Derefencing%20a%20Pointer.png)

### Null Pointer

![Null Pointer](./images/8.2%20Null%20Pointer.png)

### Common Pointer Mistakes

![Common Pointer Mistakes](./images/8.2%20Common%20Pointer%20Mistakes.png)

### **Malloc Function**

![Mallot and Free Functions](./images/8.3%20Mallot%20and%20Free.png)

### **Free Function**

![Free Function](./images/8.3%20Free%20Function.png)

### Pointers with Structs

![Pointers with Structs](./images/8.4%20Pointers%20with%20Structs.png)

[Back to top](#table-of-contents)

### String Functions with Pointers

![String Functions with Pointers](./images/8.5%20String%20functions%20with%20Pointers.png)

### String Searching Methods (Table)

![String Searching Methods](<./images/8.5%20String%20Searching%20(Table).png>)

### Malloc for Arrays and Strings

![Malloc for Arrays and Strings](./images/8.6%20Malloc%20for%20Arrays%20and%20Strings.png)

### Dynamic Copy of a String

![Dynamic Copy of a String](./images/8.6%20Dynamic%20Copy%20of%20a%20String.png)

- Make sure to account of the NULL character terminator in the String Length

[Back to top](#table-of-contents)

### Realloc Function

![Realloc Function](./images/8.7%20Realloc%20Function.png)

#### Dynamically Reallocating Size of an Array (Code)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int* userVals = NULL; // No array yet
   int numVals;
   int i;
   char userInput;
   int userValsSum;
   double userValsAvg;

   userInput = 'c';

   while (userInput == 'c') {

      printf("Enter number of integer values: ");
      scanf(" %d", &numVals);

      if (userVals == NULL) {
         userVals = (int*)malloc(numVals * sizeof(int));
      }
      else {
         userVals = (int*)realloc(userVals, numVals * sizeof(int));
      }

      printf("Enter %d integer values...\n", numVals);
      for (i = 0; i < numVals; ++i) {
         printf("Value: ");
         scanf("%d", &(userVals[i]));
      }

      // Calculate average
      userValsSum = 0;
      for (i = 0; i < numVals; ++i) {
         userValsSum = userValsSum + userVals[i];
      }
      userValsAvg = (double)userValsSum / (double)numVals;

      printf("Average = %lf\n", userValsAvg);

      printf("\nEnter 'c' to compute another average (any other key to quit): ");
      scanf(" %c", &userInput);
   }

   free(userVals);

   return 0;
}
```

[Back to top](#table-of-contents)

### **Vector ADT**

![Vector ADT](./images/8.8%20Vector%20ADT.png)

#### vector.h

```c
#ifndef VECTOR_H
#define VECTOR_H

// struct and typedef declaration for Vector ADT
typedef struct vector_struct {
  int* data;
  unsigned int size;
} vector;

// interface for accessing Vector ADT

// Initialize vector
void vector_create(vector* v, unsigned int vectorSize);

// Destroy vector
void vector_destroy(vector* v);

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize);

// Return pointer to element at specified index
int* vector_get(vector* v, unsigned int index);

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, int value);

// Insert new value at end of vector
void vector_push_back(vector* v, int value);

// Erase (remove) value at specified index
void vector_remove(vector* v, unsigned int index);

// Return number of elements within vector
int vector_size(vector* v);

#endif

```

[Back to top](#table-of-contents)

#### Vector Implementation

```c
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  vector v;
  vector_create(&v, 4);

  *vector_get(&v, 0) = 27;
  *vector_get(&v, 1) = 44;
  *vector_get(&v, 2) = 9;
  *vector_get(&v, 3) = 17;

  vector_remove(&v, 1);
  vector_remove(&v, 0);
  vector_insert(&v, 0, 88);

  vector_pop(&v);

  printf("Contents:\n");
  for (int i = 0; i < vector_size(&v); ++i) {
    printf("%d\n", *vector_get(&v, i));
  }

  vector_destroy(&v);

  return 0;
}

// Initialize vector with specified size
void vector_create(vector* v, unsigned int vectorSize) {
  if (v == NULL)
    return;

  v->data = (int*)malloc(vectorSize * sizeof(int));
  v->size = vectorSize;

  for (int i = 0; i < v->size; ++i) {
    v->data[i] = 0;
  }
}

// Destroy vector
void vector_destroy(vector* v) {
  if (v == NULL)
    return;

  free(v->data);
  v->data = NULL;
  v->size = 0;
}

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize) {
  if (v == NULL)
    return;

  int oldSize = v->size;
  v->data = (int*)realloc(v->data, vectorSize * sizeof(int));
  v->size = vectorSize;

  for (int i = oldSize; i < v->size; ++i) {
    v->data[i] = 0;
  }
}

// Return pointer to element at specified index
int* vector_get(vector* v, unsigned int index) {
  if (v == NULL || index >= v->size)
    return NULL;

  return &(v->data[index]);
}

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, int value) {
  if (v == NULL || index > v->size)
    return;

  vector_resize(v, v->size + 1);
  for (int i = v->size - 1; i > index; --i) {
    v->data[i] = v->data[i - 1];
  }

  v->data[index] = value;
}

// Insert new value at end of vector
void vector_push_back(vector* v, int value) {
  vector_insert(v, v->size, value);
}
// Remove value at specified index
void vector_remove(vector* v, unsigned int index) {
  if (v == NULL || index >= v->size)
    return;

  for (int i = index; i < v->size - 1; ++i) {
    v->data[i] = v->data[i + 1];
  }

  vector_resize(v, v->size - 1);
}

// Remove value at the last element
void vector_pop(vector* v) {
  if (v == NULL)
    return;

  vector_remove(v, v->size - 1);
}

// Return number of elements within vector
int vector_size(vector* v) {
  if (v == NULL)
    return -1;

  return v->size;
}
```

#### **Vector Functions (Table)**

![Vector Functions (Table)](<./images/8.8%20Vector%20Functions%20(Table).png>)

#### Segmentation Fault

![Segmentation Fault](./images/8.8%20Segmentation%20Fault.png)

### LinkedList vs. Vector

![LinkedList vs. Vector](./images/8.9%20LinkedList%20vs.%20Vector.png)

[Back to top](#table-of-contents)

#### LinkedList (Code)

```c

#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
  int dataVal;
  struct IntNode_struct* nextNodePtr;
} IntNode;

// Constructor
void IntNode_Create(IntNode* thisNode, int dataInit, IntNode* nextLoc) {
  thisNode->dataVal = dataInit;
  thisNode->nextNodePtr = nextLoc;
}

/* Insert newNode after node.
 Before: thisNode -- next
 After:  thisNode -- newNode -- next
 */
void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode) {
  IntNode* tmpNext = NULL;

  tmpNext = thisNode->nextNodePtr;  // Remember next
  thisNode->nextNodePtr = newNode;  // this -- new -- ?
  newNode->nextNodePtr = tmpNext;   // this -- new -- next
}

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode) {
  printf("%d\n", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
  return thisNode->nextNodePtr;
}

int main(void) {
  IntNode* headObj = NULL;  // Create IntNode objects
  IntNode* nodeObj1 = NULL;
  IntNode* nodeObj2 = NULL;
  IntNode* nodeObj3 = NULL;
  IntNode* currObj = NULL;

  // Front of nodes list
  headObj = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(headObj, -1, NULL);

  // Insert nodes
  nodeObj1 = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(nodeObj1, 555, NULL);
  IntNode_InsertAfter(headObj, nodeObj1);

  nodeObj2 = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(nodeObj2, 999, NULL);
  IntNode_InsertAfter(nodeObj1, nodeObj2);

  nodeObj3 = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(nodeObj3, 777, NULL);
  IntNode_InsertAfter(nodeObj1, nodeObj3);

  // Print linked list
  currObj = headObj;
  while (currObj != NULL) {
    IntNode_PrintNodeData(currObj);
    currObj = IntNode_GetNext(currObj);
  }

  return 0;
}
```

### **Memory Regions - Heap and Stack (Table)**

![Memory Regions - Heap and Stack (Table)](<./images/8.10%20Memory%20Regions%20-%20Heap%20and%20Stack%20(Table).png>)

### Memory Leaks

![Memory Leaks](./images/8.12%20Memory%20Leaks.png)

[Back to top](#table-of-contents)

## **Chapter 9: Input and Output**

### File Pointer: stdout (fprintf)

![File Buffer](./images/9.1.1%20File%20Pointers.png)

### File Pointer: stdin (fscanf)

![std in](./images/9.1.1%20std%20in.png)

### Formatted Output (Table)

![formatted output](./images/9.2.1%20Formated%20Output.png)

#### Integer Formatting

![Integer Formatting](./images/9.2.2%20Integer%20Formatting.png)

[Back to top](#table-of-contents)

#### String Formatting

![String Formatting](./images/9.2.3%20String%20Formatting.png)

### Flushing Output (fflush)

![Flusing Output](./images/9.2.4%20Flushing%20Ouput.png)

### **Input Parsing**

![9.3.1 Input Parsing](./images/9.3.1%20Formatted%20Input.png)

#### Input Validation

![Input Validation](./images/9.3.2%20Input%20Validation.png)

[Back to top](#table-of-contents)

### Parsing Input String (sscanf)

![Parsing Input String (sscanf)](<./images/9.3.4%20Parsing%20Input%20String%20(sscanf).png>)

#### Parsing Input (sscanf and fgets) Example

![Parsing Input (sscanf and fgets) Example](./images/9.3.5%20Sscanf.png)

### **File Input and Output**

![File Input and Output](./images/9.4.1%20File%20Input%20and%20Output.png)

#### **Writting to Files (fopen)**

![Writting to Files (fopen)](./images/9.4.2%20Writting%20to%20Files.png)

[Back to top](#table-of-contents)

### **Parsing Through an Entire File (!feof)**

![Parsing Through an Entire File (!feof)](<./images/9.4.3%20Parsing%20Though%20A%20File%20(!feof).png>)

### Binary Files

![Binary Files](./images/9.5.1%20Binary%20Files.png)

#### Writting to a Binary Files

![Writting to a Binary Files](./images/9.5.3%20Writting%20to%20a%20Binary%20File.png)

#### Reading from a Binary File

![Reading from a Binary File](./images/9.5.2%20Reading%20from%20A%20binary%20File.png)

[Back to top](#table-of-contents)
