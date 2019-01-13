#include "graph.h"
#include"search.h"

#include<stdio.h>
#include<string.h>

int main(void) {
	struct Graph g;
	struct Matrix dists;
	struct Judge p;
	int sum, m, k;
	char begin[100], aim[100], c;
	int judge = 0;
	int place1, place2;
	int route1[100];
	int *route2;
	int judge1[100];
	graph_init(&g, 79, UNDIRECTED_GRAPH);
	route_init(&g);
	while (1) {
		place_print(&g);
		graph_dijkstra(&g, 0);
		if (judge == 0) {
			printf("你想要查询地铁路线吗？y/n\n");
			scanf("%c", &c);
		}
		if (c == 'n') {
			break;
		}
		if (c == 'y') {
			judge=1;
			printf("请根据以上地点选择你的出发点： ");
			scanf("%s", begin);
			getchar();
			printf("\n\n");
			printf("请根据以上地点选择你的目的地： ");
			scanf("%s", aim);
			getchar();
			printf("\n\n");
			place1 = search(&g, begin);
			place2 = search(&g, aim);
			if (place1==-1||place2==-1) {
				if (place1 == -1 && place2 == -1) {
					printf("搜索不到出发地以及目的地\n\n\n");
				}
				else {
					if (place1 == -1) {
						printf("搜索不到出发地\n\n\n");
					}
					if (place2 == -1) {
						printf("搜索不到目的地\n\n\n");
					}
				}
				printf("按回车键返回选择目录\n\n");
				getchar();
				system("cls");
				printf("你想要继续查询地铁路线吗？y/n\n");
				scanf("%c", &c);
				getchar();
			}
			else {
				for (int i = 0; i < g.v; i++) {
					p.judge[i] = 0;
				}
				p.m = 0;
				sum=graph_vertex_distance(&g, place1, place2);
				if (sum == 0) {
					printf("你所找的地方就在附近\n");
				}
				else {
					k = 0;
					printf("你至少要乘坐%d个站点\n", sum);
					printf("你经过的站点的顺序如下表示：\n");
					p.route[0] = place1;
					p.judge[place1] = 1;
					route_search(&g, &p, place1, place2, 0, sum);
					p.route[sum] = place2;
					route_print(&g, &p, sum, begin, aim);
					printf("你想要继续查询地铁路线吗？y/n\n");
					scanf("%c", &c);
					getchar();
					if (c == 'n') {
						break;
					}
					else {
						system("cls");
					}
				}
			}
		}
	}
}