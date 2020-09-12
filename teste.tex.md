

The code is able to solve the poisson's equation for "x" and "y" with time dependency with Neumann Boundary Condition. The README summary will be show below:
\begin{itemize}
    \item Packages;
    \item Basic Constants;
    \item 2-D Laplacian in Finite-DIfference method;
    \item PDE;
\end{itemize}

# PACKAGES
I used:
\begin{itemize}
    \item Armadillo: for sparse matrix construction and system solver;
    \item OPENMP: Armadillo is able to work with OPENMP and improve the code time execution;
    \item LAPACK and BLAS: this both libraries are not really used inside the code, but Armadillo use them as back-end libraries;
    \item Math: basic math librari for constants and basic functions (exponencial, pi, euler's constant ...)
\end{itemize}

# Basic Constants


# 2-D Laplacian in Finite-Difference Method
The Laplace operator for two dimentions:

\begin{equation*}
    \nabla ^2 f(x,y) = \frac{d^2f(x,y)}{dx^2} + \frac{d^2f(x,y)}{dy^2}
\end{equation*}

In the discrete domain "x" and "y" become "i" and "j" ($f(x,y) -> f_{ij}$) and also in my code "$dx = dy = \Delta$", so the above equation become:

![Image of Grid](pictures/grid.png)

\begin{equation*}
    \nabla ^2 f(x,y) = \frac{f_{i-1,j}+f_{i+1,j}-2f_{i,j}}{\Delta ^2} + \frac{f_{i,j-1}+f_{i,j+1}-2f_{i,j}}{\Delta ^2} = \frac{f_{i-1,j}+f_{i+1,j}+f_{i,j-1}+f_{i,j+1}-4f_{i,j}}{\Delta ^2}
\end{equation*}

So we can use the above equation as a matrix, but here we have a real big matrix, because for each $i = m (m=[0,n))$ we have $"n"$ $y$ so with we want to solve a NxN grid our matrix will have dimension $N^2$. So that's the reason behind the use of Sparse matrix. 

![Image of Matrix](pictures/sparse_matrix.jpeg)


# PDE
The Poisson's equation is well know:

\begin{equation*}
    \nabla ^2 f_{ij,t} = \rho_{ij,t}
\end{equation*}
 
Notice that we need to solve one system for each time step, also since we already have the vector "$\rho_{ij,t}$" and the matrix "$\nabla ^2$" and "$f_{ij,t}$" in unknow we have a problem like "$Ax = b$". For that I used the routine "spsolve" of the Armadillo's library.
\end{document}
