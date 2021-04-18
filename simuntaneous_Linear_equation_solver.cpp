#include<iostream>
#include<math.h>
using namespace std;


int main(){
    cout<<"\n\nWELCOME TO SIMUNTANEOUS-LINEAR-EQUATION-SOLVER"<<endl<<endl<<endl;
   float a[100][100],b[100];
    cout<<"Number of variables:  ";
    int n;
    cin>>n;
    cout<<"Write down cofficients of x row-wise: ";

    
    //taking input of A

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            cin>>a[row][col];
        }
    }
    float check_row[100];
    for(int row=0;row<n;row++){
        check_row[row]=a[0][row];
    }
    cout<<"Write down constants line by line:  ";
    //taking input for B
    for(int row=0;row<n;row++){
        cin>>b[row];
        a[row][n]=b[row];//making last col of A with B vector..(A|B)
    }
    float check=b[0];
    // Now of the form AX=B
    //Gauss-Jordan Algo

    for(int row=0;row<n;row++){
        //making row-pivot element as 1..that is for ith row..making a[i][i]=1
        float pivot_element=a[row][row];//..pivot-element=a[i][i]..for ith row
        //making pivot-element=1
        for(int col=0;col<=n;col++){
            a[row][col]=a[row][col]/pivot_element;

        }
        //making ith-col....non diagonal..element=0..a[i][j]=0..if(i!=j)


        //row-transformation...


        for(int row_trans=0;row_trans<n;row_trans++){
            if(row_trans==row)continue;
            float key=a[row_trans][row];
            for(int col=0;col<=n;col++){
                a[row_trans][col]-=(key*a[row][col]);//row-transformation...r2=r2-2*r1...2=1-coloumn element of r2..(2,1)
            }
            
        }
        
        //finally in the form of gauss-jordan matrix
       
    }
        

    
    cout<<"\n\n\nIf the Solutions are floating point then it'll be represented with near accuracy not exactly."<<endl<<endl;
    cout<<"Solutions are: "<<endl;

    //checking for integer solutions....



    for(int row=0;row<n;row++){
        float key=a[row][n];
        if(fabs(key-ceil(key))<=fabs(key-floor(key)))b[row]=ceil(key);
        else b[row]=floor(key);

    }
    float sum=0;
    for(int row=0;row<n;row++){
        sum+=(check_row[row]*b[row]);

    }
    
    if(sum==check){
        for(int row=0;row<n;row++){
        
        a[row][n]=b[row];
        
        
        //making last col of A with B vector..(A|B)
    }
    }
    for(int row=0;row<n;row++){
        if(a[row][n]==-0)a[row][n]=0;
        cout<<"x"<<row+1<<"= "<<a[row][n]<<endl;
    }

    
}