
call plug#begin()

Plug 'vim-syntastic/syntastic'
Plug 'alexandregv/norminette-vim'

call plug#end()

let g:user42 = 'luicasad'
let g:mail42 = 'luicasad@student.42.fr'

" Enable norminette-vim (and gcc)
let g:syntastic_c_checkers = ['norminette', 'gcc']
let g:syntastic_aggregate_errors = 1

" Set the path to norminette (do no set if using norminette of 42 mac)
let g:norminette_exec = '/home/luis/.venv/inquisitor/bin/norminette'

let g:syntastic_c_norminette_exec = 'norminette'

" Support headers (.h)
let g:c_syntax_for_h = 1
let g:syntastic_c_include_dirs = ['inc', '../inc', '../../inc', '/usr/include/readline', '../libft/include', '../../libft/include']

" Pass custom arguments to norminette (this one ignores 42header)
let g:syntastic_c_norminette_args = '-R CheckTopCommentHeader'

" Check errors when opening a file (disable to speed up startup time)
let g:syntastic_check_on_open = 1

" Enable error list
let g:syntastic_always_populate_loc_list = 1

" Automatically open error list
let g:syntastic_auto_loc_list = 1

" Skip check when closing
let g:syntastic_check_on_wq = 0

set number
set relativenumber
set tabstop=4
set shiftwidth=4
set autoindent
set smartindent
set mouse=a
set nowrap
set incsearch
set showmatch
set hlsearch
set wildmenu
set wildmode=list:longest
set colorcolumn=80
set tabpagemax=20
