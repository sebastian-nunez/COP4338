# Chapter 0: UNIX OS

- [**Chapter 0: UNIX OS**](#chapter-0-unix-os)
  - [UNIX Cheat Sheet](#unix-cheat-sheet)
  - [.vimrc](#vimrc)
  - [.nanorc](#nanorc)

## UNIX Cheat Sheet

![UNIX Cheat Sheet](./0.%20UNIX%20Cheat%20Sheet.png)

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

## .nanorc

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
