// Muhammad Azka Rahadian
// 13224036
// Array
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

typedef struct {
    Tree  *data;
    int    size;       //element skrg
    int    capacity;   //slot
} TreeArray;

void print_tree(const Tree *t) {
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

#define INITIAL_CAPACITY 8

//inisiasi empty arr
void arr_init(TreeArray *arr) {
    arr->data     = (Tree *)malloc(INITIAL_CAPACITY * sizeof(Tree));
    if (!arr->data) { fprintf(stderr, "Memory allocation failed!\n"); exit(1); }
    arr->size     = 0;
    arr->capacity = INITIAL_CAPACITY;
}

static void arr_grow(TreeArray *arr) {
    int new_cap = arr->capacity * 2;
    Tree *tmp   = (Tree *)realloc(arr->data, new_cap * sizeof(Tree));
    if (!tmp) { fprintf(stderr, "Realloc failed!\n"); exit(1); }
    arr->data     = tmp;
    arr->capacity = new_cap;
}

//add
void arr_add(TreeArray *arr, Tree t) {
    if (arr->size >= arr->capacity) arr_grow(arr);
    arr->data[arr->size++] = t;
}

//view
void arr_view(const TreeArray *arr) {
    print_separator("ARRAY - All Trees");
    if (arr->size == 0) { printf("  [Empty array]\n"); return; }
    for (int i = 0; i < arr->size; i++) {
        printf("  [Record %d]\n", i + 1);
        print_tree(&arr->data[i]);
    }
    printf("  Total records : %d\n", arr->size);
    printf("  Capacity      : %d slots\n", arr->capacity);
    printf("  Memory used   : %lu bytes\n",
           (unsigned long)(arr->capacity * sizeof(Tree)));
}

//delete and shift
int arr_delete(TreeArray *arr, int id) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i].id == id) {
            //shift kiri
            memmove(&arr->data[i],
                    &arr->data[i + 1],
                    (arr->size - i - 1) * sizeof(Tree));
            arr->size--;
            printf("  [Array] Tree ID %d deleted successfully.\n", id);
            return 1;
        }
    }
    printf("  [Array] Tree ID %d not found.\n", id);
    return 0;
}

//shrink
void arr_shrink_if_needed(TreeArray *arr) {
    if (arr->capacity > INITIAL_CAPACITY &&
        arr->size < arr->capacity / 4) {
        int new_cap = arr->capacity / 2;
        if (new_cap < INITIAL_CAPACITY) new_cap = INITIAL_CAPACITY;
        Tree *tmp = (Tree *)realloc(arr->data, new_cap * sizeof(Tree));
        if (tmp) { arr->data = tmp; arr->capacity = new_cap; }
    }
}

//search 
int arr_search(const TreeArray *arr, int id) {
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i].id == id) return i;
    return -1;
}

//free memory
void arr_free(TreeArray *arr) {
    free(arr->data);
    arr->data     = NULL;
    arr->size     = 0;
    arr->capacity = 0;
}

//performance
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
    TreeArray arr;
    struct timespec ts, te;
    double t_add, t_view, t_del;

    printf("\n  --- N = %d ---\n", n);

    //add
    arr_init(&arr);
    clock_gettime(CLOCK_MONOTONIC, &ts);
    for (int i = 0; i < n; i++) arr_add(&arr, make_tree(i + 1));
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_add = get_ms(ts, te);

    //view
    clock_gettime(CLOCK_MONOTONIC, &ts);
    volatile long dummy = 0;
    for (int i = 0; i < arr.size; i++) dummy += arr.data[i].id;
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_view = get_ms(ts, te);
    (void)dummy;

    //delete
    clock_gettime(CLOCK_MONOTONIC, &ts);
    arr_delete(&arr, n / 2);
    clock_gettime(CLOCK_MONOTONIC, &te);
    t_del = get_ms(ts, te);

    printf("  Dynamic Array | Add: %.4f ms | View: %.4f ms | Delete: %.4f ms\n",
           t_add, t_view, t_del);
    printf("                | Peak capacity: %d slots (%lu KB)\n",
           arr.capacity,
           (unsigned long)(arr.capacity * sizeof(Tree) / 1024));

    arr_free(&arr);
}

//tampilan
void menu_add(TreeArray *arr) {
    Tree t;
    printf("\n  Enter Tree ID      : "); scanf("%d",  &t.id);
    printf("  Enter Species Name : "); scanf("%63s", t.species);
    printf("  Enter Latitude     : "); scanf("%lf", &t.lat);
    printf("  Enter Longitude    : "); scanf("%lf", &t.lon);
    printf("  Enter Age (years)  : "); scanf("%d",  &t.age);
    printf("  Enter Diameter (cm): "); scanf("%lf", &t.diameter);
    arr_add(arr, t);
    printf("\n  Tree ID %d added. Current size: %d / %d\n",
           t.id, arr->size, arr->capacity);
}

void menu_search(const TreeArray *arr) {
    int id;
    printf("\n  Enter Tree ID to search: "); scanf("%d", &id);
    int idx = arr_search(arr, id);
    if (idx >= 0) {
        printf("\n  Found at index %d:\n", idx);
        print_tree(&arr->data[idx]);
    } else {
        printf("  Tree ID %d not found.\n", id);
    }
}

int main(void) {
    TreeArray arr;
    arr_init(&arr);
    int choice;

    //sample data awal
    Tree samples[] = {
        {1, "Mahogany",   -6.914464, 107.609810, 25, 45.5},
        {2, "Teak",       -6.921300, 107.615200, 30, 60.0},
        {3, "Pine",       -6.905000, 107.601500, 15, 22.3},
        {4, "Eucalyptus", -6.930100, 107.620800, 10, 18.7},
        {5, "Banyan",     -6.918750, 107.611900, 50, 120.0},
    };
    int ns = sizeof(samples) / sizeof(samples[0]);
    for (int i = 0; i < ns; i++) arr_add(&arr, samples[i]);
    printf("  [System] %d sample records pre-loaded into array.\n", ns);

    do {
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║   TREE INVENTORY  -  DYNAMIC ARRAY   ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Add Tree                         ║\n");
        printf("║  2. View All Trees                   ║\n");
        printf("║  3. Search Tree by ID                ║\n");
        printf("║  4. Delete Tree by ID                ║\n");
        printf("║  5. Performance Benchmark            ║\n");
        printf("║  0. Exit                             ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("  Choice: "); scanf("%d", &choice);

        switch (choice) {
            case 1: menu_add(&arr);             break;
            case 2: arr_view(&arr);             break;
            case 3: menu_search(&arr);          break;
            case 4: {
                int id;
                printf("\n  Enter Tree ID to delete: "); scanf("%d", &id);
                arr_delete(&arr, id);
                arr_shrink_if_needed(&arr);
                break;
            }
            case 5:
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

    arr_free(&arr);
    return 0;
}
