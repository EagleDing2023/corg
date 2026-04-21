#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("corg: file organizer\n");
		printf("Usage: corg <directory>\n");
		return 1;
	}

	DIR *dir = opendir(argv[1]);
	if (dir == NULL) {
		fprintf(stderr, "corg: cannot open directory '%s'\n", argv[1]);
		return 1;
	}

	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		// Skip hidden files
		if (entry->d_name[0] == '.') {
			continue;
		}

		if (entry->d_type == DT_DIR) {
    			printf("[DIR]  %s\n", entry->d_name);
		} else if (entry->d_type == DT_REG) {
			printf("[FILE] %s\n", entry->d_name);
		} else {
		   	printf("[OTHER] %s\n", entry->d_name);
		}
	}

	closedir(dir);
	return 0;
}
