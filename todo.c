#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_LEN 100
typedef struct {
    char desc[MAX_LEN];
    int done;
} Task;

Task tasks[MAX_TASKS];
int count = 0;

void loadTasks() {
    FILE *f = fopen("tasks.txt", "r");
    if(!f) return;
    while(fscanf(f, "%d %[^\n]", &tasks[count].done, tasks[count].desc)==2) count++;
    fclose(f);
}

void saveTasks() {
    FILE *f = fopen("tasks.txt", "w");
    for(int i=0;i<count;i++) {
        fprintf(f, "%d %s\n", tasks[i].done, tasks[i].desc);
    }
    fclose(f);
}

void addTask() {
    if(count>=MAX_TASKS){printf("Full!\n");return;}
    printf("Enter task: ");
    getchar(); // consume newline
    fgets(tasks[count].desc, MAX_LEN, stdin);
    tasks[count].desc[strcspn(tasks[count].desc, "\n")] = 0;
    tasks[count].done = 0;
    count++;
}

void viewTasks() {
    for(int i=0;i<count;i++) {
        printf("%d. [%c] %s\n", i+1, tasks[i].done?'x':' ', tasks[i].desc);
    }
}

void markTask() {
    int n;
    printf("Task number to mark done: ");
    scanf("%d", &n);
    if(n>=1 && n<=count) tasks[n-1].done = 1;
}

void deleteTask() {
    int n;
    printf("Task number to delete: ");
    scanf("%d", &n);
    if(n>=1 && n<=count) {
        for(int i=n-1;i<count-1;i++) tasks[i] = tasks[i+1];
        count--;
    }
}

int main(){
    loadTasks();
    int choice;
    do {
        printf("\nMenu:\n1.Add 2.View 3.Mark done 4.Delete 5.Save & Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTask(); break;
            case 4: deleteTask(); break;
            case 5: saveTasks(); printf("Saved. Bye.\n"); break;
            default: printf("Invalid\n");
        }
    } while(choice != 5);
    return 0;
}
