#include<iostream>
#include<list>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define MAX 9999
#define V 5


//dataset of location within the college 

map<int,string>PlacesOutput={
    {0,"1st block"},
    {1,"2nd block"},
    {2,"3rd block"},
    {3,"4th block"},
    {4,"5th block"},
    {5,"6th block"},
    {6,"7th block"},
    {7,"8th block"},
    {8,"9th block"},
    {9,"10th block"},
    {10,"11th block"},
    {11,"12th block"},
    {12,"MAC"},
    {13,"Library"},
    {14,"Ground"},
    {15,"FOod court"}
};

map<int,string>::iterator it1;
int shortDistance=0;

//function for printing the shortest path 

void BFSPATH(vector<int>distance ,int dest,vector<int> &path)
{
    
  
     
    cout<<"the Shortest path is of total"<<"--------"<<shortDistance<<endl;
        
    
    
    for(int i=1;i<path.size();i++){
        cout<<PlacesOutput.find(path[i])->second<<"->";
    }
    cout<<PlacesOutput.find(dest)->second;
    cout<<endl;
}


//function for printing the shortest path 

int ary[10][10],completed[10],cost=0;

//function for printing the shortest path 

int least(int c)
    {
        int i,nc=999;
        int min=999,kmin;

        for(i=0;i < V;i++)
        {
            if((ary[c][i]!=0)&&(completed[i]==0))
                if(ary[c][i]+ary[i][c] < min)
                {
                    min=ary[i][0]+ary[c][i];
                    kmin=ary[c][i];
                    nc=i;
                }
        }

        if(min!=999)
            cost+=kmin;

    return nc;
}


//Main function of TSP and for printing the optimal path and to update cost 

void mincost(int city,int location[V])
    {
        
        int i,ncity;

        completed[city]=1;

        cout<<PlacesOutput.find(location[city])->second<<"--->";
        ncity=least(city);
        if(ncity==999)
        {
        ncity=0;
        cout<<ncity+1;
        cost+=ary[city][ncity];

        return;
    }

    mincost(ncity,location);
}


// function to find minimum distance between two node

int minimumDistance (vector<int>distance,bool visited[])
{
    int mini=INT_MAX;
    int miniIndex;
    for(int i=0;i<V;i++){
        if(visited[i]==false && distance[i] <=mini){
            mini=distance[i];
            miniIndex=i;
        }
    }
    return miniIndex;
}


//Main Dijkstra algorithim for shortest path

void BFS(int graph[V][V],int src,int dest)
{
    vector<int> path;
    vector<int> distance(V);
    bool visited[V];


    for(int i=0;i<V;i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }

    distance[src]=0;
    for(int i=0;i<V-1;i++){
        int vertex= minimumDistance(distance,visited);
        visited[vertex]=true;
        for(int j=0;j<V;j++){
            if(!visited[j] && graph[vertex][j] && distance[vertex]!=INT_MAX && distance[vertex] +graph[vertex][j] <distance[j] ){
                distance[j]=distance[vertex]+graph[vertex][j];
                path.push_back( vertex);
            }

        }
    }

    BFSPATH(distance,dest,path);
}


int main()
{

    //dataset of location within the college

    map<int,vector<int> > Places={
    {0,{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}},
    {1,{1,0,5,6,7,8,9,10,11,12,13,14,15,16,17,18}},
    {2,{2,5,0,7,8,9,10,11,12,13,14,15,16,17,18,19}},
    {3,{3,6,7,0,9,10,11,12,13,14,15,16,17,18,19,20}},
    {4,{4,7,8,9,0,11,12,13,14,15,16,17,18,19,20,21}},
    {5,{5,8,9,10,11,0,13,14,15,16,17,18,19,20,21,22}},
    {6,{6,9,10,11,12,13,0,15,16,17,18,19,20,21,22,23}},
    {7,{7,10,11,12,13,14,15,0,17,18,19,20,21,22,23,24}},
    {8,{8,11,12,13,14,15,16,17,0,19,20,21,22,23,24,25}},
    {9,{9,12,13,14,15,16,17,18,19,0,21,22,23,24,25,26}},
    {10,{10,13,14,15,16,17,18,19,20,21,0,23,24,25,26,27}},
    {11,{11,14,15,16,17,18,19,20,21,22,23,0,25,26,27,28}},
    {12,{12,15,16,17,18,19,20,21,22,23,24,25,0,27,28,29}},
    {13,{13,16,17,19,19,20,21,22,23,24,25,26,27,0,29,30}},
    {14,{14,17,18,20,20,21,22,23,24,25,26,27,28,29,0,31}},
    {15,{15,18,19,20,21,22,23,24,25,26,27,28,29,30,31,0}}
    };
    
    //     map<int,vector<int> > Places={
    //     {0,{0,4,10,0,12}},
    //     {1,{4,0,0,14,13}},
    //     {2,{10,0,0,12,14}},
    //     {3,{0,14,12,0,15}},
    //     {4,{12,13,14,15,0}},
    // };
    
    map<int,vector<int> >::iterator it;

    cout<< "----------------Location label---------------------"<<endl<<"0:1st block \n1:2nd block \n2:3rd block \n3:4th block \n4:5th block \n5:6th block \n6:7th block \n7:8th block \n8:9th block \n9:10th block \n10:11th block \n11:12th block \n12:MAC \n13:Library \n14:Ground \n15:Food court \n";
    int location[V];
    cout<<"\nEnter all the 5 location"<<endl;
    
    for(int i=0;i<V;i++){
        if(i==0){
            cout<<"Enter the Start point \t";
        }
        if(i==V-1){
            cout<<"Enter the Destination \t";
        }
        
        cin>>location[i];
    }

    int graph[V][V]={0};
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            
            if(location[i]==location[j]){
                
                graph[i][j]=graph[j][i]=0;
                graph[i][j]=graph[j][i]=0;
            }
            else{
                graph[i][j]=graph[j][i]=Places.find(location[i])->second[location[j]];
                ary[i][j]=ary[j][i]=Places.find(location[i])->second[location[j]];
            }
        }
        completed[i]=0;
    }
    
    cout<<endl;
    int src=location[0],dest=location[V-1];
    shortDistance=Places.find(location[0])->second[location[V-1]];
    cout<<"-----------------------------------RESULT-------------------------"<<endl;
    BFS(graph, src,dest);

    cout<<"\n\nThe Path is:\n";
    mincost(0,location);
    cout<<"\n\nOptimal cost is "<<cost<<endl;
    return 0;

}
