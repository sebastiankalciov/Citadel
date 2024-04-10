#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files/utils.h"
#include "../templates/templates.h"

int getOption(int lowerLimit, int upperLimit);
int isValidCommand(const char *command);