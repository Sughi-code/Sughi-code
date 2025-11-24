SOURC = cipher.c loger.c
CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable

all: cipher
check: clangformat cppcheck
clean:
	rm ../build/*
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURC);
clangformat:
	clang-format -i *.c & clang-format -i *.h
add:
	clang format -i *.c *.h; git add $(SOURC)
push:
	git branch develop; git switch dvelop; git commit -m "final"; git push --set-upstream origin develop;
git: add push
cipher:
	$(CC) $(FLAGS) $(SOURC) -o ../build/cipher;../build/cipher
logging_cipher:
	$(CC) $(FLAGS) $(SOURC) -o ../build/logging_cipher;../build/logging_cipher