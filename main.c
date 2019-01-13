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
			printf("����Ҫ��ѯ����·����y/n\n");
			scanf("%c", &c);
		}
		if (c == 'n') {
			break;
		}
		if (c == 'y') {
			judge=1;
			printf("��������ϵص�ѡ����ĳ����㣺 ");
			scanf("%s", begin);
			getchar();
			printf("\n\n");
			printf("��������ϵص�ѡ�����Ŀ�ĵأ� ");
			scanf("%s", aim);
			getchar();
			printf("\n\n");
			place1 = search(&g, begin);
			place2 = search(&g, aim);
			if (place1==-1||place2==-1) {
				if (place1 == -1 && place2 == -1) {
					printf("���������������Լ�Ŀ�ĵ�\n\n\n");
				}
				else {
					if (place1 == -1) {
						printf("��������������\n\n\n");
					}
					if (place2 == -1) {
						printf("��������Ŀ�ĵ�\n\n\n");
					}
				}
				printf("���س�������ѡ��Ŀ¼\n\n");
				getchar();
				system("cls");
				printf("����Ҫ������ѯ����·����y/n\n");
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
					printf("�����ҵĵط����ڸ���\n");
				}
				else {
					k = 0;
					printf("������Ҫ����%d��վ��\n", sum);
					printf("�㾭����վ���˳�����±�ʾ��\n");
					p.route[0] = place1;
					p.judge[place1] = 1;
					route_search(&g, &p, place1, place2, 0, sum);
					p.route[sum] = place2;
					route_print(&g, &p, sum, begin, aim);
					printf("����Ҫ������ѯ����·����y/n\n");
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