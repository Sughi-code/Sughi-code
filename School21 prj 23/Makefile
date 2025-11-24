SOURC = state_sort.c clear_state.c state_search.c
SOURC1 = state_sort.c
SOURC2=  state_search.c
SOURC3 = clear_state.c
CC = gcc
FLAGS = -Wall -Werror -Wextra 

all: state_sort
check: clangformat cppcheck
clean:
	rm ../build/*
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURC);
clangformat:
	clang-format -i *.c;
add:
	clang format -i *.c; git add $(SOURC)
push:
	git branch develop; git switch dvelop; git commit -m "final"; git push --set-upstream origin develop;
git: add push
state_sort:
	$(CC) $(FLAGS) $(SOURC1) -o ../build/Quest_1;../build/Quest_1
state_search:
	$(CC) $(FLAGS) $(SOURC2) -o ../build/Quest_2;../build/Quest_2
clear_state:
	$(CC) $(FLAGS) $(SOURC3) -o ../build/Quest_3;../build/Quest_3