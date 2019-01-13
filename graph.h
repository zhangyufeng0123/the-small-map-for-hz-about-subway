#pragma once

#include <stdbool.h>

#include "matrix.h"

enum GraphType { UNDIRECTED_GRAPH = 0, DIRECTED_GRAPH = 1 };

typedef char VertexData;

struct Graph {
	int v;
	int order[80];
	int sum[80];
	char *name[80];
	char *sign[80][10];
	int e;
	enum GraphType type;
	struct Matrix m;

	VertexData *vertex_data;

	bool *marked;
	int *path;
	DataType *dists;
};

void graph_init(struct Graph *g, int num_vertices, enum GraphType type);

void graph_destroy(struct Graph *g);

void graph_set_edge(struct Graph *g, int u, int v, DataType weight);

bool graph_has_edge(struct Graph *g, int u, int v);

int graph_edge(struct Graph *g, int u, int v);

int graph_degree(struct Graph *g, int v);

int graph_in_degree(struct Graph *g, int v);

int graph_out_degree(struct Graph *g, int v);

// �ж��Ƿ���ͨͼ
bool graph_is_connected(struct Graph *g);

// �ж����������Ƿ���ͨ
bool graph_is_vertex_connected(struct Graph *g, int u, int v);

// ��������֮��ľ���
DataType graph_vertex_distance(struct Graph *g, int u, int v);

// �ж�sg�Ƿ�Ϊg����ͼ
bool graph_is_subgraph(struct Graph *g, struct Graph *sg);

// �ж�sg�Ƿ���g�ģ�ǿ����ͨ����
bool graph_is_connected_component(struct Graph *g, struct Graph *sg);

// ��ȱ��������������marked, path
void graph_dfs(struct Graph *g, int v);

// ��ȱ��������������marked, path
void graph_bfs(struct Graph *g, int v);

// ��Dijkstra�㷨���㶥��v����������ľ���,
// ���������¼��dists�У�·����¼��path��
void graph_dijkstra(struct Graph *g, int v);

// ��Floyd�㷨���㶥������֮��ľ���, �����¼��dists������
void graph_floyd(struct Graph *g, struct Matrix *dists);

// ��Ford Fulkerson�㷨�����s��t��������������������ֵ������������¼��flow��
DataType graph_ford_fulkerson(struct Graph *g, int s, int t,
	struct Graph *flow);

void graph_save(struct Graph *g, const char *filename);