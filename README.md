# 42-select
Hive Helsinki project.

**What?**

Small user interface for selecting arguments. Program displays arguments in a list and user can interact with the list using specific keys. The keys are listed in this readme.

`ft_select: usage: ft_select arg [arg] ...`

![User interface](select_ui.png)

Key | Action
------------ | -------------
Right arrow | Move cursor to the right
Left arrow | Move cursor to the left
Space | Select/unselect current argument
Enter | Exit program and print selected arguments
Esc | Exit program without printing selected arguments
Backspace/Del | Remove current argument from the list

 Selected arguments are printed to the standard output, which enables them to be used as arguments for another command.
 
 `ls -l ´ft_select srcs/*´`
 
**Compilation**

You will need few other 42 projects to compile the program successfully. Clone this project and run following command inside the repository: `git clone https://github.com/vkuokka/42-printf.git libftprintf && git clone https://github.com/vkuokka/42-libft.git libftprintf/libft && make`
