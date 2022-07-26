# C - Simple shell

## Description :
This project consists to recreate a unix shell. It is a team project realized for the end of the first trimester of our first year at Holberton School.


## Tasks :

### 0. README, man, AUTHORS

* Write a `README`
* Write a `man` for your shell.
* You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker


 ### 1. Betty would be proud
 Write a beautiful code that passes the Betty checks


 ### 2. Simple shell 0.1

 Write a UNIX command line interpreter.

  * Usage: `simple_shell`

Your Shell should:

   * Display a prompt and wait for the user to type a command. A command line always ends with a new line.
   * The prompt is displayed again each time a command has been executed.
   * The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
   * The command lines are made only of one word. No arguments will be passed to programs.
   * If an executable cannot be found, print an error message and display the prompt again.
   * Handle errors.
   * You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

   * use the `PATH`
   * implement built-ins
   * handle special characters : `", ', , \, *, &, #`
   * be able to move the cursor
   * handle commands with arguments

    julien@ubuntu:~/shell$ ./shell

    #cisfun$ ls
    ./shell: No such file or directory
    #cisfun$ /bin/ls
    barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
    #cisfun$ ^[[D^[[D^[[D
    ./shell: No such file or directory
    #cisfun$ ^[[C^[[C^[[C^[[C
    ./shell: No such file or directory
    #cisfun$ exit
    ./shell: No such file or directory
    #cisfun$ ^C
    julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
    barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
    #cisfun$ julien@ubuntu:~/shell$


 ### 3. Simple shell 0.2

 Simple shell 0.1 +

  * Handle command lines with arguments



 ### 4. Simple shell 0.3

 Simple shell 0.2 +

   * Handle the `PATH`
   * `fork` must not be called if the command doesn’t exist

    julien@ubuntu:~/shell$ ./shell_0.3
    :) /bin/ls
    barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
    :) ls
    barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
    :) ls -l /tmp
    total 20
    -rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
    drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
    drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
    drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
    -rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
    :) ^C
    julien@ubuntu:~/shell$


 ### 5. Simple shell 0.4

 Simple shell 0.3 +

 * Implement the `exit` built-in, that exits the shell
 * Usage: `exit`
 * You don’t have to handle any argument to the built-in `exit`


 ### 6. Simple shell 1.0

 Simple shell 0.4 +

   * Implement the `env` __built-in__, that prints the current environment

    julien@ubuntu:~/shell$ ./simple_shell
    $ env
    USER=julien
    LANGUAGE=en_US
    SESSION=ubuntu
    COMPIZ_CONFIG_PROFILE=ubuntu
    SHLVL=1
    HOME=/home/julien
    C_IS=Fun_:)
    DESKTOP_SESSION=ubuntu
    LOGNAME=julien
    TERM=xterm-256color
    PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
    DISPLAY=:0
    $ exit
    julien@ubuntu:~/shell$


 ### 7. What happens when you type `ls -l *.c` in the shell

 Write a blog post describing step by step what happens when you type ls -l *.c and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

  * Have at least one picture, at the top of the blog post
  * Publish your blog post on Medium or LinkedIn
  * Share your blog post at least on LinkedIn
  * Only one blog post by team
  * The blog post must be done and published before the first deadline (it will be part of the manual review)
  * Please, remember that these blogs must be written in English to further your technical ability in a variety of settings

When done, please add all urls below (blog post, LinkedIn post, etc.)


## List of allowed functions and system calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)


## Installation and compilation :

To install our hsh shell, you have to clone our repository :

    $ git clone https://github.com/luciel53/holbertonschool-simple_shell.git

 Then, to compile your file, use the command below :

 `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`


 ## Testing :

To run the shell :

`./hsh`

 The shell should work like this in interactive mode:

    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

But also in non-interactive mode:

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $


## Examples :

![Image](https://zupimages.net/up/22/30/f7cz.png)

![Image](https://zupimages.net/up/22/30/w44s.png)


## Files

* main.h - That is the header file.
* execFind.c - Containing a function that find a file and an other function that executes the program of the command given.
* shell.c - That contains 3 functions. The principal function that simules the shell. A function that prepares the use of the command and
a third function that cuts the string at spaces and line returns and put its result in an array.
* README.md
* man_1_simple_shell - The manpage of our shell.
* AUTHORS


## Authors :

* Murdo Nicolai
* Lucie Leroty


