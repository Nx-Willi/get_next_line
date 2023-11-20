#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("tests/test_simple.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}

// #include "bonus/get_next_line_bonus.h"
// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int	fd[7];

// 	fd[0] = open("tests/test0.txt", O_RDONLY);
// 	fd[1] = open("tests/test1.txt", O_RDONLY);
// 	fd[2] = open("tests/test2.txt", O_RDONLY);
// 	fd[3] = open("tests/test3.txt", O_RDONLY);
// 	fd[4] = open("tests/test4.txt", O_RDONLY);
// 	fd[5] = open("tests/test5.txt", O_RDONLY);
// 	fd[6] = open("tests/test6.txt", O_RDONLY);

// 	printf("%s", get_next_line(fd[0]));
// 	printf("%s", get_next_line(fd[1]));
// 	printf("%s", get_next_line(fd[2]));
// 	printf("%s", get_next_line(fd[3]));
// 	printf("%s", get_next_line(fd[4]));
// 	printf("%s", get_next_line(fd[5]));
// 	printf("%s", get_next_line(fd[6]));
// 	printf("%s", get_next_line(fd[0]));
// 	printf("%s", get_next_line(fd[1]));
// 	printf("%s", get_next_line(fd[2]));
// 	printf("%s", get_next_line(fd[3]));
// 	printf("%s", get_next_line(fd[4]));
// 	printf("%s", get_next_line(fd[5]));
// 	printf("%s", get_next_line(fd[6]));
// 	return (0);
// }
