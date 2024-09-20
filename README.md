# Minishell

This project was one of the most challenging yet indulging projects of the 42 curriculum that I have faced so far, when you have to deal with many test cases and when you get to learn many things, from software architecture, system calls, file descriptors… to team coordination, management, and work distribution.

Building a shell that mimics the bash was an intimidating thing for me at first, because the only thing that I knew back then about shells was how to use them, in a basic way to accomplish basic tasks, but I was not really aware of how they internally work or function, and building a shell from scratch was really a challenging task for me, though this is one of the main things that I do really like about the 42 pedagogy, is that I always keep finding myself at a challenge, always trying to learn something new, from the early days of the Piscine (42 selection phase) up to writing this article.



https://github.com/user-attachments/assets/61aa3119-087d-4a9c-b97c-f8d742427adc



### Anyway, let’s have a project overview…

##### We are required to build a mini shell (command-line interpreter) that mimics the bash, hence the name it wouldn’t be doing all the work that bash does, but the basic functionality:

** The shell will work only in interactive mode (no scripts, i.e. the executable takes no arguments)

Run simple commands with absolute, relative path ```(e.g. /bin/ls, ../bin/ls)```

Run simple commands without a path ```(e.g. ls, cat, grep, etc…)```

Have a working history (you can navigate through commands with up/down arrows)

** Implement pipes ```(|)```

** Implement redirections ```(<, >, >>)```

** Implement the here-doc ```(<<)```

** Handle double quotes ```("")``` and single quotes ```('')```, which should escape special characters, beside ```$``` for double quotes.

** Handle environment variables ($ followed by a sequence of characters).

** Handle signals like in bash ```(ctrl + C, ctrl + \, ctrl + D).```

** Implement the following built-ins:

— ```echo``` (option -n only)

— ```exit```

— ```env``` (with no options or arguments)

— ```export``` (with no options)

— ```unset``` (with no options)

— ```cd```

— ```pwd```
