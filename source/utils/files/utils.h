#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFromCSV(const char* filePath);
FILE* openFile(const char* filePath, const char* mode);
