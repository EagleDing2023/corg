#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <assert.h>

// get_extension(filename) returns the address of the last occurence of charater '.'
// requires: filename not be NULL
// time: O(n), where n is the length of filename
const char *get_extension(const char *filename) {
	assert(filename);

	const char *tmp = filename;
	while (*filename != '\0') {
		if (*filename == '.') {
			tmp = filename;
		}
		filename++;
	}
	if (*tmp != '.') return NULL;
	return tmp;
}



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
