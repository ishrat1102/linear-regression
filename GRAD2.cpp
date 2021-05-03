/*----------------------------DONE BY ISHRAT JABEN BUSHRA----------------------*/
#include<bits/stdc++.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <bits/stdc++.h>
using namespace std ;

int m;

vector<float>w, y_pred, slop, y, x[100];
vector<float>slope;

void linearRegression(int feature, int m)
{

    float cal = 0.0,alpha=0.0001 ;
    for(int i = 0 ; i < m ; i++)
    {


        for(int j = 0 ; j <= feature ; j++)
        {
            cal += w[j]*x[j][i] ;

        }//cout<<"cal:"<<cal;

        y_pred.push_back(cal) ;

    }

    for(int i=0; i<=feature; i++)
    {
        float sum=0.0;
        for(int j = 0 ; j < m; j++)
        {

            sum+=(y_pred[j]-y[j])*x[i][j];
        }//cout<<"sum:"<<sum;


        slope.push_back(sum);

    }

    for(int i=0; i<=feature; i++)

    {

        w[i]=w[i]-alpha*slope[i];//cout<<"w:"<<i<<":"<<cal;

    }

}

void prdtn(int feature)
{

    int f[100];
    float w1[100];
    for(int i=1; i<=feature; i++)
    {

        cout<<"x"<<i<<":";
        scanf("%d",&f[i]);

    }

    float pred;
    ifstream myfil;
    myfil.open("filetest2.txt",ios::in);
    myfil>>w1[0];
    pred=w1[0];

    for(int i=1; i<=feature; i++)
    {

        myfil>>w1[i];
        pred+= w1[i]*f[i];

    }

    printf("\nprediction:");
    printf("%f",pred);
}

int main()
{

    fstream newfile;
    m = 0 ;
    int feature ;
    cout<< "Number of feature : " ;
    cin>> feature ;
    newfile.open("datafile.txt",ios::in);
    if(newfile.is_open())
    {

        string str ;
        while(getline(newfile, str))
        {

            m++ ;


            stringstream check1(str);
            string intermediate;
            int i = 1 ;
            for(int k = 0 ; k < m ; k++)

                x[0].push_back(1) ;

            while(getline(check1, intermediate, ','))
            {

                int val = atoi(intermediate.c_str()) ;
                if(i<=feature)
                {
                    x[i].push_back(val) ;
                    i++ ;

                }
                else
                {
                    y.push_back(val) ;
                }

            }

        }

        newfile.close() ;
    }

    cout<< m << endl ;
    for(int i = 0 ; i <= feature ; i++)
    {

        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        w.push_back(r) ;

    }

    cout<< "Initial value of W : " ;
    for(int i = 0 ; i <= feature ; i++)
    {
        cout << w[i] << " " ;
    }

    cout<< endl ;
    int pick;
    cout<<"pick 1 to learn or 2 to use existing value of file:\n";
    cin>>pick;
    if(pick==1)
    {

        linearRegression(feature, m) ;
        cout<< "Learn value of W : " ;
        for(int i = 0 ; i <= feature ; i++)

        {

            printf("%f ", w[i]) ;

        }

        cout<< endl ;
        fstream myfil;

        myfil.open("filetest2.txt",ios::out);
        if(myfil.is_open())
        {
            for(int i = 0 ; i <= feature ; i++)
            {
                myfil<< w[i]<<" " ;
            }

            cout<< endl ;
        }

        myfil.close();
    }
    if(pick==2)
    {
        prdtn(feature);
    }
    return 0;
}

