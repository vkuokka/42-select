# 42-select
Hive Helsinki project.

**What?**

Small user interface for selecting arguments. Program displays arguments in a list and user can interact with the list using specific keys. The keys are listed in this readme.

**Compilation**

Clone repository and compile the program into your current working directory with the following commands:  
$ `git clone https://github.com/vkuokka/42-select.git ft_select`  
$ `make`  
Now you should have binary file inside the repository which you can run with the following command:  
$ `./ft_select`  
`ft_select: usage: ft_select arg [arg] ...`

![User interface](select_ui.png)

Key | Action
------------ | -------------
<kbd>right</kbd> | Move cursor to the right
<kbd>left</kbd> | Move cursor to the left
<kbd>Space</kbd> | Select/unselect current argument
<kbd>enter</kbd> | Exit program and print selected arguments
<kbd>esc</kbd> | Exit program without printing selected arguments
<kbd>backspace</kbd>/<kbd>del</kbd> | Remove current argument from the list

 Selected arguments are printed to the standard output, which enables them to be used as arguments for another command.  
 `ls -l ´ft_select srcs/*´`
