// Simple test for kat.h
#include <stdio.h>
#include "kat.h"

int main(void) {
    const char *path = "test.cfg";

    // Create a configuration file
    if (kat.create(path)) {
        printf("file not created\n");
    } else {
        printf("file created\n");
    }

    // Add a comment to the file
    kat.addComment("kat.h example cfg file", path);

    // Create a key with a value (in the file)
    if (kat.add("cute", "yes\n", path)) {
        printf("key not added\n");
    } else {
        printf("key added\n");
    }

    // Read values from keys (in the file)
    char buffer[128]; // Create a buffer for the read

    // The synposis for kat.readKey is [query, file, buffer, buffer_size (in bytes)]
    if (kat.read("cute", path, buffer, sizeof(buffer)) == 0) {
        printf("value: %s\n", buffer);
    } else {
        printf("key not found\n");
    }
    
    // And now let's try reading a non-existent key
    char buff2[128];
    if (kat.read("I_DO_NOT_EXIST", path, buff2, sizeof(buff2)) == 0) {
        printf("value: %s\n", buff2);
    } else {
        printf("key not found\n");
    }

    // Delete a key
    kat.del("cute", path);
    printf("key deleted\n");

    return 0;
}

