#ifndef POLYNOMIALFIT_H
#define POLYNOMIALFIT_H

#include <vector>
#include <cmath>

/**
 * Polynomial fit and validation.
 * @param x vector of X values
 * @param y vector of Y values
 * @param n the order of a polynomial
 */
template<typename T>
std::vector<T> polynomialFit(const std::vector<T>& x, const std::vector<T>& y, int n)
{
    int i, j, k, m, m2;
    int N = x.size();
    T X[2*n+1];
    for (i=0;i<2*n+1;i++)
    {
        X[i]=0;
        for (j=0;j<N;j++)
            X[i]=X[i]+pow(x[j],i);
    }

    T B[n+1][n+2];
    std::vector<double> a(n+1);
    for (i=0;i<=n;i++)
        for (j=0;j<=n;j++)
            B[i][j]=X[i+j];

    T Y[n+1];
    for (i=0;i<n+1;i++)
    {
        Y[i]=0;
        for (j=0;j<N;j++)
        Y[i]=Y[i]+pow(x[j],i)*y[j];
    }

    for (i=0;i<=n;i++)
        B[i][n+1]=Y[i];

    n=n+1;

    for (i=0;i<n;i++)
        for (k=i+1;k<n;k++)
            if (B[i][i]<B[k][i])
                for (j=0;j<=n;j++)
                {
                    T temp=B[i][j];
                    B[i][j]=B[k][j];
                    B[k][j]=temp;
                }

    for (i=0;i<n-1;i++)
        for (k=i+1;k<n;k++)
            {
                T t=B[k][i]/B[i][i];
                for (j=0;j<=n;j++)
                    B[k][j]=B[k][j]-t*B[i][j];
            }
    for (i=n-1;i>=0;i--)
    {
        a[i]=B[i][n];
        for (j=0;j<n;j++)
            if (j!=i)
                a[i]=a[i]-B[i][j]*a[j];
        a[i]=a[i]/B[i][i];
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

/**
 * Linear fit, might be used instead of the the polynomial fit if the chosen polynomial order is 1.
 * It takes less memmory resources to compute.
 */
template<typename T>
std::vector<T> linearfit(const std::vector<T>& x, const std::vector<T>& y)
{
        int i,n;
        n = x.size();
        T a,b;

        T xsum=0,x2sum=0,ysum=0,xysum=0;
        for (i=0;i<n;i++)
        {
            xsum=xsum+x[i];
            ysum=ysum+y[i];
            x2sum=x2sum+pow(x[i],2);
            xysum=xysum+x[i]*y[i];
        }
        a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);
        b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);
        std::vector<T> yFit(n);
        for (i=0;i<n;i++)
            yFit[i]=y[i] - (a*x[i]+b);

        return yFit;
}

#endif // POLYNOMIALFIT_H
