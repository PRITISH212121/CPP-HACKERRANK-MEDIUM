#include<bits/stdc++.h>

using namespace std;
struct Workshop{
    int starttime;
    int duration;
    int endtime;
};
struct Available_Workshops{
    int n;
    Workshop *arr;
};
Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops *ob=new Available_Workshops;
    ob->n=n;
    ob->arr= new Workshop[n];
    for (int i=0; i<n; i++) {
        (ob->arr+i)->starttime=start_time[i];
        (ob->arr+i)->duration=duration[i];
        (ob->arr+i)->endtime=(ob->arr+i)->starttime+(ob->arr+i)->duration;
    }
   
    return ob;
}
bool compare( Workshop a, Workshop b){
    if(a.endtime < b.endtime)
        return 1;
    else 
        return 0;
}
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
int CalculateMaxWorkshops(Available_Workshops* ptr){
    int count=1;
     sort(ptr->arr,ptr->arr+ptr->n,&compare);
    for (int i=0; i<(ptr->n)-1; i++) {
        if(ptr->arr[i].starttime+ptr->arr[i].duration<=ptr->arr[i+1].starttime){
            count++;
        }
        else{
            ptr->arr[i+1].starttime=ptr->arr[i].starttime;
            ptr->arr[i+1].duration=ptr->arr[i].duration;
        }
    }
    return count;
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
