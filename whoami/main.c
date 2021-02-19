#include <pwd.h>
#include <stdio.h>
#include <unistd.h>

#define AUTHOR "Marvin Huber"
#define BIN_NAME "whoami"
#define VERSION "0.1.0"
#define LICENSE                                                                \
	"BSD-3-Clause License "                                                \
	"<https://raw.githubusercontent.com/sirh3e/tools/master/LICENSE.txt>"

int main(int argc, char **argv)
{
	int version_flag = 0;
	int option;
	while ((option = getopt(argc, argv, "v")) != -1) {
		switch (option) {
		case 'v':
			version_flag = 1;
			break;
		default:
			break;
		}
	}

	if (version_flag) {
		printf("%s %s\n", BIN_NAME, VERSION);
		printf("%s\n", LICENSE);
		printf("Written by %s\n", AUTHOR);
		goto end;
	}

	struct passwd *pwd;
	if ((pwd = getpwuid(getuid())) == NULL) {
		return 1;
	}
	printf("%s\n", pwd->pw_name);

end:
	return 0;
}
