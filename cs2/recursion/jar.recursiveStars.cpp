#include <iostream>
using namespace std;

void drawStars(int rows);

int main(){
    int n;
    cout<<"number of lines in the pattern >";
    cin>>n;
    drawStars(n);
    return 0;
}

void drawStars(int rows){
    for(int i=0;i<rows;i++){
        cout<<"*";
    }
    cout<<endl;
    if(rows>1){
        drawStars(rows-1);
    }
    for(int i=0;i<rows;i++){
        cout<<"*";
    }
    cout<<endl;
}