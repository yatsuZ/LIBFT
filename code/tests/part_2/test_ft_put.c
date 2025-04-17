/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:54:06 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 17:08:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

#define TEST_FILE "test_putfd_output.txt"

static bool check_file_content(const char *expected)
{
	int fd = open(TEST_FILE, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening test file for reading");
		return false;
	}

	char buffer[1024];
	ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);

	if (bytes_read == -1)
	{
		perror("Error reading from test file");
		return false;
	}
	buffer[bytes_read] = '\0';

	if (strcmp(buffer, expected) == 0)
		return true;
	else
	{
		printf("   Expected output in file: \"%s\"\n", expected);
		printf("   Actual output in file:   \"%s\"\n", buffer);
		return false;
	}
}

static int test_putchar_fd(void)
{
	printf("--- putchar_fd\t: ");
	int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening test file for writing");
		return 1;
	}
	ft_putchar_fd('X', fd);
	close(fd);

	if (check_file_content("X"))
	{
		printf("\t✅\n");
		return 0;
	}
	else
	{
		printf("\t❌\n");
		return 1;
	}
}

static int test_putstr_fd(void)
{
	printf("--- putstr_fd\t: ");
	int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening test file for writing");
		return 1;
	}
	ft_putstr_fd("Hello World!", fd);
	close(fd);

	if (check_file_content("Hello World!"))
	{
		printf("\t✅\n");
		return 0;
	}
	else
	{
		printf("\t❌\n");
		return 1;
	}
}

static int test_putendl_fd(void)
{
	printf("--- putendl_fd\t: ");
	int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening test file for writing");
		return 1;
	}
	ft_putendl_fd("Line with newline", fd);
	close(fd);

#ifdef __APPLE__
	if (check_file_content("Line with newline\n"))
#else
	if (check_file_content("Line with newline\n"))
#endif
	{
		printf("\t✅\n");
		return 0;
	}
	else
	{
		printf("\t❌\n");
		return 1;
	}
}

static int test_putnbr_fd(void)
{
	printf("--- putnbr_fd\t: ");
	int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening test file for writing");
		return 1;
	}
	ft_putnbr_fd(-12345, fd);
	close(fd);

	if (check_file_content("-12345"))
	{
		printf("\t✅\n");
		return 0;
	}
	else
	{
		printf("\t❌\n");
		return 1;
	}
}

int test_ft_putfd(void)
{
	int result = 0;
	result |= test_putchar_fd();
	result |= test_putstr_fd();
	result |= test_putendl_fd();
	result |= test_putnbr_fd();
	if (unlink(TEST_FILE) == -1)
		perror("Error deleting test file");
	return result;
}
