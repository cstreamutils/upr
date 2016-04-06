#include <fcntl.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

char to_upper(char c)
{
	if (c > 0x60 && c < 0x7B)
		return c - 0x20;
	return c;
}

int main(void)
{
	int i;
	ssize_t num_read, num_written;
	char in_buf[BUF_SIZE];
	char out_buf[BUF_SIZE];

	while((num_read = read(STDIN_FILENO, in_buf, BUF_SIZE)) > 0) {
		i = 0;
		while(i < num_read) {
			out_buf[i] = to_upper(in_buf[i]);
			i++;
		}
		if ((num_written = write(STDOUT_FILENO, out_buf, num_read)) != num_read)
			return 1;
	}

	return 0;
}
