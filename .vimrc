syntax on
set number
filetype plugin indent on
" sho wexisting tab with 4 spaces width
set tabstop=4
" when indenti with '>', use 4 spaces width
set shiftwidth=4
" On pressing tab, insert 4 spaces
set expandtab
set backspace=indent,eol,start " more powerful backspacing
set laststatus=2
set statusline=%<%f\ %h%m%r%=%-14.(%l,%c%V%)\ %P " example from :help statusline
