#ifndef LIST_H
#define LIST_H

struct node {
    int value;                      /* data stored in the node */
    struct node *next;              /* pointer to the next node */
};

/*
    创建一个新节点将其插入到首部
    list 是旧链表首节点
    n 存储新节点的值

    返回插入的新节点
*/
struct node* add_to_list(struct node *list, int n);

/*
    搜索链表
    list 是链表首节点
    n 是要搜索的节点的值
    
    返回搜索到的节点的指针，找不到返回空指针
*/
struct node* search_list(struct node *list, int n);

/*
    删除节点
    list 是链表首节点
    n 是要删除的节点的值

    返回首节点
*/
struct node* delete_from_list(struct node *list, int n);

/* 返回 NULL 代表没有修改首节点，否则返回首节点 */
struct node* delete_from_list_ex_07(struct node *list, int n);

void delete_from_list_ex_11(struct node **list, int n);

/*
    销毁链表
*/
void destroy_list(struct node *list);

#endif // LIST_H