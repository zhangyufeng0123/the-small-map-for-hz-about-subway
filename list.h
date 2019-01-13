#pragma once

#include"common.h"

typedef int DataType;

struct ListNode {
	DataType data;
	struct ListNode *next;
};

struct List {
	int size;
	struct ListNode *head;
	struct ListNode *tail;
};

void list_init(struct List *list);

void list_destroy(struct List *list);

enum Status list_insert_after(struct List *list, struct ListNode *node, DataType data);

enum Status ist_push_front(struct List *list, DataType data);

enum Status list_push_back(struct List *list, DataType data);

enum Status list_remove_after(struct List *list, struct ListNode *node);

enum Status list_pop_front(struct List *list);

int list_size(struct List *list);

struct ListNode *list_at(struct List *list, int i);