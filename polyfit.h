#ifndef POLYFIT_H
#define POLYFIT_H

#include <vector>
#include <cmath>

template<typename T>
std::vector<T> polyfit(const std::vector<T>& x, const std::vector<T>& y, int n)
{
    int i, j, k, m, m2;
    int N = x.size();
    T X[2*n+1];                        //Array that will store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
    for (i=0;i<2*n+1;i++)
    {
        X[i]=0;
        for (j=0;j<N;j++)
            X[i]=X[i]+pow(x[j],i);        //consecutive positions of the array will store N,sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
    }


    T B[n+1][n+2];            //B is the Normal matrix(augmented) that will store the equations, 'a' is for value of the final coefficients
    std::vector<double> a(n+1);
    for (i=0;i<=n;i++)
        for (j=0;j<=n;j++)
            B[i][j]=X[i+j];            //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix


    T Y[n+1];                    //Array to store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    for (i=0;i<n+1;i++)
    {
        Y[i]=0;
        for (j=0;j<N;j++)
        Y[i]=Y[i]+pow(x[j],i)*y[j];        //consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    }


    for (i=0;i<=n;i++)
        B[i][n+1]=Y[i];                //load the values of Y as the last column of B(Normal Matrix but augmented)


    n=n+1;                //n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n+1 equations


    for (i=0;i<n;i++)                    //From now Gaussian Elimination starts(can be ignored) to solve the set of linear equations (Pivotisation)
        for (k=i+1;k<n;k++)
            if (B[i][i]<B[k][i])
                for (j=0;j<=n;j++)
                {
                    T temp=B[i][j];
                    B[i][j]=B[k][j];
                    B[k][j]=temp;
                }

    for (i=0;i<n-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<n;k++)
            {
                T t=B[k][i]/B[i][i];
                for (j=0;j<=n;j++)
                    B[k][j]=B[k][j]-t*B[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
            }
    for (i=n-1;i>=0;i--)                //back-substitution
    {                        //x is an array whose values correspond to the values of x,y,z..
        a[i]=B[i][n];                //make the variable to be calculated equal to the rhs of the last equation
        for (j=0;j<n;j++)
            if (j!=i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                a[i]=a[i]-B[i][j]*a[j];
        a[i]=a[i]/B[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
    }


    std::vector<T> yFit(x.size());
    for (m = 0; m <N; m++){
        T nY = 0;
        T nXT = 1;
        T nX = x[m];
        for(m2 =0; m2 <n; m2++){
            nY += a[m2] * nXT;
            nXT *= nX;
        }
        yFit[m] = y[m] - nY;
    }
    return yFit;
}

template<typename T>
std::vector<T> linearfit(const std::vector<T>& x, const std::vector<T>& y)
{
        int i,n;
        n = x.size();
        T a,b;

        T xsum=0,x2sum=0,ysum=0,xysum=0;                //variables for sums/sigma of xi,yi,xi^2,xiyi etc
        for (i=0;i<n;i++)
        {
            xsum=xsum+x[i];                        //calculate sigma(xi)
            ysum=ysum+y[i];                        //calculate sigma(yi)
            x2sum=x2sum+pow(x[i],2);                //calculate sigma(x^2i)
            xysum=xysum+x[i]*y[i];                    //calculate sigma(xi*yi)
        }
        a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);            //calculate slope
        b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);            //calculate intercept
        std::vector<T> yFit(n);                        //an array to store the new fitted values of y
        for (i=0;i<n;i++)
            yFit[i]=y[i] - (a*x[i]+b);                    //to calculate y(fitted) at given x points


        return yFit;
}

#endif // POLYFIT_H
