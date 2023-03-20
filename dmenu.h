#pragma once

/* enums */

typedef struct item {
	char *text;
	struct item *left, *right;
	int out;
} item_t;
