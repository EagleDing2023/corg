#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <assert.h>
#include "extensions.h"

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
			const char *ext = get_extension(entry->d_name);
			if (ext == NULL) ext = "no ext";
			printf("[%s] %s\n", ext, entry->d_name);
		} else {
		   	printf("[OTHER] %s\n", entry->d_name);
		}
	}

	closedir(dir);
	return 0;
}
