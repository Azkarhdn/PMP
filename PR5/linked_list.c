//Muhammad Azka Rahadian
//13224036
//Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tree {
    int    id;
    char   species[64];
    double lat;
    double lon;
    int    age;
    double diameter;
} Tree;

//singly linked list
typedef struct SNode {
    Tree         data;
    struct SNode *next;
} SNode;

//doubly linked list
typedef struct DNode {
    Tree         data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

//circular linked list
typedef struct CNode {
    Tree         data;
    struct CNode *next;
} CNode;

void print_tree(Tree *t) {
    printf("  ID      : %d\n",   t->id);
    printf("  Species : %s\n",   t->species);
    printf("  GPS     : (%.6f, %.6f)\n", t->lat, t->lon);
    printf("  Age     : %d years\n", t->age);
    printf("  Diam.   : %.2f cm\n",  t->diameter);
    printf("  ----------------------------------------\n");
}

void print_separator(const char *title) {
    printf("\n========================================\n");
    printf("  %s\n", title);
    printf("========================================\n");
}

//SINGLY
SNode *singly_head = NULL;
int singly_count   = 0;

//add
void singly_add(Tree t) {
    SNode *node = (SNode *)malloc(sizeof(SNode));
    if (!node) { fprintf(stderr, "Memory allocation failed!\n"); return; }
    node->data = t;
    node->next = NULL;

    if (!singly_head) {
        singly_head = node;
    } else {
        SNode *cur = singly_head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
    singly_count++;
}

//view
void singly_view(void) {
    print_separator("SINGLY LINKED LIST - All Trees");
    if (!singly_head) { printf("  [Empty list]\n"); return; }
    int i = 1;
    SNode *cur = singly_head;
    while (cur) {
        printf("  [Record %d]\n", i++);
        print_tree(&cur->data);
        cur = cur->next;
    }
    printf("  Total records: %d\n", singly_count);
}

//delete by ID
int singly_delete(int id) {
    SNode *cur = singly_head, *prev = NULL;
    while (cur) {
        if (cur->data.id == id) {
            if (prev) prev->next = cur->next;
            else singly_head = cur->next;
            free(cur);
            singly_count--;
            printf("  [Singly] Tree ID %d deleted successfully.\n", id);
            return 1;
        }
        prev = cur;
        cur  = cur->next;
    }
    printf("  [Singly] Tree ID %d not found.\n", id);
    return 0;
}

//free all singly nodes
void singly_free(void) {
    SNode *cur = singly_head;
    while (cur) { SNode *tmp = cur->next; free(cur); cur = tmp; }
    singly_head  = NULL;
    singly_count = 0;
}

//DOUBLY
DNode *doubly_head = NULL;
DNode *doubly_tail = NULL;
int    doubly_count = 0;

//Add
void doubly_add(Tree t) {
    DNode *node = (DNode *)malloc(sizeof(DNode));
    if (!node) { fprintf(stderr, "Memory allocation failed!\n"); return; }
    node->data = t;
    node->next = NULL;
    node->prev = doubly_tail;

    if (!doubly_tail) {
        doubly_head = doubly_tail = node;
    } else {
        doubly_tail->next = node;
        doubly_tail       = node;
    }
    doubly_count++;
}

//view forward
void doubly_view(void) {
    print_separator("DOUBLY LINKED LIST - All Trees (Forward)");
    if (!doubly_head) { printf("  [Empty list]\n"); return; }
    int i = 1;
    DNode *cur = doubly_head;
    while (cur) {
        printf("  [Record %d]\n", i++);
        print_tree(&cur->data);
        cur = cur->next;
    }
    printf("  Total records: %d\n", doubly_count);
}

//view backward
void doubly_view_backward(void) {
    print_separator("DOUBLY LINKED LIST - All Trees (Backward)");
    if (!doubly_tail) { printf("  [Empty list]\n"); return; }
    int i = doubly_count;
    DNode *cur = doubly_tail;
    while (cur) {
        printf("  [Record %d]\n", i--);
        print_tree(&cur->data);
        cur = cur->prev;
    }
}

// delete by ID
int doubly_delete(int id) {
    DNode *cur = doubly_head;
    while (cur) {
        if (cur->data.id == id) {
            if (cur->prev) cur->prev->next = cur->next;
            else           doubly_head     = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            else           doubly_tail     = cur->prev;
            free(cur);
            doubly_count--;
            printf("  [Doubly] Tree ID %d deleted successfully.\n", id);
            return 1;
        }
        cur = cur->next;
    }
    printf("  [Doubly] Tree ID %d not found.\n", id);
    return 0;
}

// free all doubly nodes
void doubly_free(void) {
    DNode *cur = doubly_head;
    while (cur) { DNode *tmp = cur->next; free(cur); cur = tmp; }
    doubly_head  = NULL;
    doubly_tail  = NULL;
    doubly_count = 0;
}

// CIRCULAR
CNode *circular_tail = NULL;   //tail pointer for circular list
int    circular_count = 0;

//Add circular linked list
void circular_add(Tree t) {
    CNode *node = (CNode *)malloc(sizeof(CNode));
    if (!node) { fprintf(stderr, "Memory allocation failed!\n"); return; }
    node->data = t;

    if (!circular_tail) {
        node->next    = node;   /* points to itself */
        circular_tail = node;
    } else {
        node->next         = circular_tail->next;  /* new->next = head */
        circular_tail->next = node;                /* old tail -> new */
        circular_tail       = node;                /* update tail */
    }
    circular_count++;
}

//view circular linked list
void circular_view(void) {
    print_separator("CIRCULAR LINKED LIST - All Trees");
    if (!circular_tail) { printf("  [Empty list]\n"); return; }

    CNode *head = circular_tail->next;
    CNode *cur  = head;
    int    i    = 1;
    do {
        printf("  [Record %d]\n", i++);
        print_tree(&cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("  Total records: %d\n", circular_count);
}

// Delete by ID
int circular_delete(int id) {
    if (!circular_tail) {
        printf("  [Circular] List is empty.\n");
        return 0;
    }

    CNode *head = circular_tail->next;
    CNode *cur  = head;
    CNode *prev = circular_tail;

    do {
        if (cur->data.id == id) {
            if (circular_count == 1) {
                // hanya 1 node
                free(cur);
                circular_tail  = NULL;
                circular_count = 0;
            } else {
                prev->next = cur->next;
                if (cur == circular_tail)
                    circular_tail = prev;
                free(cur);
                circular_count--;
            }
            printf("  [Circular] Tree ID %d deleted successfully.\n", id);
            return 1;
        }
        prev = cur;
        cur  = cur->next;
    } while (cur != head);

    printf("  [Circular] Tree ID %d not found.\n", id);
    return 0;
}

// free all circular nodes
void circular_free(void) {
    if (!circular_tail) return;
    CNode *head = circular_tail->next;
    circular_tail->next = NULL;   /* break the circle */
    CNode *cur = head;
    while (cur) { CNode *tmp = cur->next; free(cur); cur = tmp; }
    circular_tail  = NULL;
    circular_count = 0;
}

// PERFORMANCE BENCHMARK
double get_ms(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 +
           (end.tv_nsec - start.tv_nsec) / 1e6;
}

Tree make_tree(int id) {
    Tree t;
    t.id       = id;
    snprintf(t.species, sizeof(t.species), "Species_%d", id % 20);
    t.lat      = -6.9 + (id % 100) * 0.001;
    t.lon      = 107.6 + (id % 100) * 0.001;
    t.age      = 5 + (id % 50);
    t.diameter = 10.0 + (id % 80) * 0.5;
    return t;
}

void benchmark(int n) {
    struct timespec ts, te;
    double t_add, t_view, t_del;

    printf("\n  --- N = %d ---\n", n);

    //singly
    singly_free();
    clock_gettime(CLOCK_MONOTONIC, &ts);
    for (int i = 0; i < n; i++) singly_add(make_tree(i + 1));
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_add = get_ms(ts, te);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    //traverse tanpa print
    { SNode *c = singly_head; while (c) c = c->next; }
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_view = get_ms(ts, te);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    singly_delete(n / 2);
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_del = get_ms(ts, te);

    printf("  Singly LL  | Add: %.4f ms | View: %.4f ms | Delete: %.4f ms\n",
           t_add, t_view, t_del);
    singly_free();

    //doubly
    doubly_free();
    clock_gettime(CLOCK_MONOTONIC, &ts);
    for (int i = 0; i < n; i++) doubly_add(make_tree(i + 1));
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_add = get_ms(ts, te);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    { DNode *c = doubly_head; while (c) c = c->next; }
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_view = get_ms(ts, te);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    doubly_delete(n / 2);
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_del = get_ms(ts, te);

    printf("  Doubly LL  | Add: %.4f ms | View: %.4f ms | Delete: %.4f ms\n",
           t_add, t_view, t_del);
    doubly_free();

    //circular
    circular_free();
    clock_gettime(CLOCK_MONOTONIC, &ts);
    for (int i = 0; i < n; i++) circular_add(make_tree(i + 1));
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_add = get_ms(ts, te);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    if (circular_tail) {
        CNode *head = circular_tail->next, *c = head;
        do { c = c->next; } while (c != head);
    }
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_view = get_ms(ts, te);

    clock_gettime(CLOCK_MONOTONIC, &ts);
    circular_delete(n / 2);
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_del = get_ms(ts, te);

    printf("  Circular LL| Add: %.4f ms | View: %.4f ms | Delete: %.4f ms\n",
           t_add, t_view, t_del);
    circular_free();
}

//MENU
void menu_add(void) {
    Tree t;
    printf("\n  Enter Tree ID      : "); scanf("%d",  &t.id);
    printf("  Enter Species Name : "); scanf("%63s", t.species);
    printf("  Enter Latitude     : "); scanf("%lf", &t.lat);
    printf("  Enter Longitude    : "); scanf("%lf", &t.lon);
    printf("  Enter Age (years)  : "); scanf("%d",  &t.age);
    printf("  Enter Diameter (cm): "); scanf("%lf", &t.diameter);

    singly_add(t);
    doubly_add(t);
    circular_add(t);
    printf("\n  Tree ID %d added to all three lists.\n", t.id);
}

void menu_delete(void) {
    int id;
    printf("\n  Enter Tree ID to delete: "); scanf("%d", &id);
    singly_delete(id);
    doubly_delete(id);
    circular_delete(id);
}


int main(void) {
    int choice;

    /* Pre-load sample data */
    Tree samples[] = {
        {1, "Mahogany",   -6.914464, 107.609810, 25, 45.5},
        {2, "Teak",       -6.921300, 107.615200, 30, 60.0},
        {3, "Pine",       -6.905000, 107.601500, 15, 22.3},
        {4, "Eucalyptus", -6.930100, 107.620800, 10, 18.7},
        {5, "Banyan",     -6.918750, 107.611900, 50, 120.0},
    };
    int ns = sizeof(samples) / sizeof(samples[0]);
    for (int i = 0; i < ns; i++) {
        singly_add(samples[i]);
        doubly_add(samples[i]);
        circular_add(samples[i]);
    }
    printf("  [System] %d sample records pre-loaded into all lists.\n", ns);

    do {
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║   TREE INVENTORY  -  LINKED LIST     ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Add Tree                         ║\n");
        printf("║  2. View All (Singly)                ║\n");
        printf("║  3. View All (Doubly - Forward)      ║\n");
        printf("║  4. View All (Doubly - Backward)     ║\n");
        printf("║  5. View All (Circular)              ║\n");
        printf("║  6. Delete Tree by ID                ║\n");
        printf("║  7. Performance Benchmark            ║\n");
        printf("║  0. Exit                             ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("  Choice: "); scanf("%d", &choice);

        switch (choice) {
            case 1: menu_add();           break;
            case 2: singly_view();        break;
            case 3: doubly_view();        break;
            case 4: doubly_view_backward(); break;
            case 5: circular_view();      break;
            case 6: menu_delete();        break;
            case 7:
                print_separator("PERFORMANCE BENCHMARK");
                printf("  [Small]  N = 100\n");
                benchmark(100);
                printf("\n  [Medium] N = 10,000\n");
                benchmark(10000);
                printf("\n  [Large]  N = 100,000\n");
                benchmark(100000);
                break;
            case 0:
                printf("\n  Exiting... Goodbye!\n");
                break;
            default:
                printf("\n  Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    singly_free();
    doubly_free();
    circular_free();
    return 0;
}
