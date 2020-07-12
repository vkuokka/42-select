# 42-select
Hive Helsinki project.

### Introduction
Small UI for selecting arguments. Program prints arguments to terminal window and user can interact with
the list using specific keybindings. These keybindings are listed in this readme.

### Compilation
Clone repository into your current working directory and compile the program with the following commands:
```
$> git clone https://github.com/vkuokka/42-select.git ft_select  
$> cd ft_select  
$> make  
```
Now you should have binary file inside the repository which you can run with the following command:
```
$> ./ft_select  
ft_select: usage: ft_select arg [arg] ...
```
### Usage
 Selected arguments are printed to the standard output, which enables them to be used as arguments for another command.  
 ```
 $> ls -l `ft_select srcs/*`
```
![User interface](select_ui.png)

### Keybindings
Key | Action
------------ | -------------
<kbd>right</kbd> | Move cursor to the right
<kbd>left</kbd> | Move cursor to the left
<kbd>Space</kbd> | Select/unselect current argument
<kbd>enter</kbd> | Exit program and print selected arguments
<kbd>esc</kbd> | Exit program without printing selected arguments
<kbd>backspace</kbd>/<kbd>del</kbd> | Remove current argument from the list
