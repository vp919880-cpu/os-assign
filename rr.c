#include <stdio.h>

int main() {
    int n, q;

    scanf("%d", &n);

    char pid[n][10];
    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    scanf("%d",&q);

    int time = 0;
    int completed = 0;

    int queue[100];
    int front = 0, rear = 0;
    int visited[100] = {0};

    queue[rear++] = 0;
    visited[0] = 1;

    while(front < rear){

        int i = queue[front++];

        if(rt[i] > q){
            time += q;
            rt[i] -= q;
        }
        else{
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
            completed++;
        }

        for(int j=0;j<n;j++){
            if(at[j] <= time && visited[j]==0){
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        if(rt[i] > 0)
            queue[rear++] = i;
    }

    float avgwt=0,avgtat=0;

    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n", pid[i], wt[i]);

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n", pid[i], tat[i]);

    printf("Average Waiting Time: %.2f\n", avgwt/n);
    printf("Average Turnaround Time: %.2f\n", avgtat/n);

    return 0;
}
