#include stdio
#include stdlib
typedef struct {
    int x, y, speed, direction;
} state;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void move(int** arr, state* init, int pathvar[]){
    void move(int** arr, state* init, int pathvar[]) {
    int subpath = pathvar[0];
    int steps = pathvar[1];
    
    if (subpath == 0) {
        
    } else if (subpath == 1) {
        init->direction = (init->direction + 1) % 4;
    } else if (subpath == 2) {
        init->direction = (init->direction + 3) % 4;
    }
    
    init->speed = 0; 
    
    
    for (int step = 0; step < steps; ) {
        if (step < steps / 2) {
            init->speed++;
        } else if (step > steps / 2) {
            init->speed--;
        }
        init->x += dx[init->direction] * init->speed;
        init->y += dy[init->direction] * init->speed;
        step += init->speed;
    }
    
    init->speed = 0; 
}
}
int* pathlength(int lanepos, state init, int** arr){
    int* pathvar = (int*)malloc(sizof(int)*3);
    int rem[2];
    rem[0]=init.x;
    rem[1]=init.y;
    int paths[3][2]={{0,0,0},{0,0,0}};
    if(lanepos ==0){
        while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[0][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[0][1]++;
        }
       

        if(direction!=3){
             init.x=rem[0]+dx[init.direction+1];init.y=rem[1]+dy[init.direction+1];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[1][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[1][1]++;
        }
        init.x=rem[0]+2*dx[init.direction+1];init.y=rem[1]+2*dy[init.direction+1];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[2][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[2][1]++;
        }
        }
        else{
             init.x=rem[0]+dx[0];init.y=rem[1]+dy[0];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[1][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[1][1]++;
        }
        init.x=rem[0]+2*dx[0];init.y=rem[1]+2*dy[0];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[2][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[2][1]++;
        }
        }
    if(lanepos ==1){
        while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[0][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[0][1]++;
        }
       

        if(direction!=3){
             init.x=rem[0]+dx[init.direction+1];init.y=rem[1]+dy[init.direction+1];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[1][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[1][1]++;
        }
        init.x=rem[0]-dx[init.direction+1];init.y=rem[1]-dy[init.direction+1];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[2][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[2][1]++;
        }
        }
        else{
             init.x=rem[0]+dx[0];init.y=rem[1]+dy[0];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[1][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[1][1]++;
        }
        init.x=rem[0]-dx[0];init.y=rem[1]-dy[0];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[2][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[2][1]++;
        }
        }

    }

    if(lanepos ==2){
        while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[0][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[0][1]++;
        }
       

        if(direction!=3){
             init.x=rem[0]-dx[init.direction+1];init.y=rem[1]-dy[init.direction+1];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[1][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[1][1]++;
        }
        init.x=rem[0]-2*dx[init.direction+1];init.y=rem[1]-2*dy[init.direction+1];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[2][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[2][1]++;
        }
        }
        else{
             init.x=rem[0]-dx[0];init.y=rem[1]-dy[0];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[1][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[1][1]++;
        }
        init.x=rem[0]-2*dx[0];init.y=rem[1]-2*dy[0];
            while( (arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=1)&&(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]!=2)){
            paths[2][0]++;
            init.x =init.x+dx[init.direction];
            init.y = init.y+dy[init.direction];
        }
        if(arr[init.x+dx[init.direction]][init.y+dy[init.direction]]==2){
            paths[2][1]++;
        }
        }

    }
    int counter =  paths[0][0]
    int mini;
    for(int i=0;i<3;i++){
        if(paths[i][0]>counter){
            mini =i;
        }
    }
    pathvar[0]=i;
    pathvar[1]=paths[mini][0];
    pathvar[2]= paths[mini][1];

    return pathvar;
}
int lanpos(state init){
    int counter =0;
int check[2];
check[0]= init.x;
check[1]= init.y;
while(arr[check[0]+dx[init.direction+1]][check[1]+dy[init.direction+1]]!=1){
    counter++;
    check[0]=check[0]+dx[init.direction+1];
    check[1]=check[1]+dy[init.direction+1];
}
int lanepos;
if(counter==0){
  lanepos=2;  
}
else if(counter==1){
    lanepos=1;
}
else if(counter==2){
    lanepos=0;
}
return lanepos
}
int main(){
int m, n;
scanf("%d %d", &m,&n);
int arr[m][n];
state init;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        scanf("%d", &arr[i][j] );
        if(arr[i][j]==3){
            init.x=i;
            init.y=j;
            init.speed =0;
            init.direction = 0;
        }
    }
}
scanf("%d", &init.direction);


int rotations=0;
state* intiti = &init;
int* pathvar = (int*)malloc(3*sizeof(int));
while(rotations!=4){ 
int lanepos = lanepos(init);
pathvar = pathlength(lanepos, init, arr);

move(arr, initi, pathvar)
while(pathvar[2]==1){
    lanepos = lanepos(init);
    pathvar = pathlength(lanepos, init, arr);
    move(arr, initi,pathvar);
}
init.direction= (init.direction+1)%4;
rotations++;
}



while (arr[init.x][init.y] != 3) {
        int lane_position = lanepos(init, arr);
        int* target_pathvar = pathlength(lane_position, init, arr);
        move(arr, &init, target_pathvar);
        free(target_pathvar);
    }
    return 0;
}
