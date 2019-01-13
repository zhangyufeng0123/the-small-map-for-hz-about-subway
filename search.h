#pragma once

#include"graph.h"

struct Judge {
	int m;
	int judge[80];
	int route[80];
};

void place_print(struct Graph *g);

void route_init(struct Graph *g);

int search(struct Graph *g, char *name);

void route_search(struct Graph *g, struct Judge *p, int u, int v, int sum, int n);

void route_print(struct Graph *g, struct Judge *p, int sum);