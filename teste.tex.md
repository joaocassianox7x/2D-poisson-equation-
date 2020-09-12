The code is able to solve the poisson's equation for "x" and "y" with time dependency with Neumann Boundary Condition. The README summary will be show below:
\begin{itemize}
    \item Packages;
    \item 2-D Laplacian in Finite-DIfference method;;
    \item PDE;
\end{itemize}

\section{Packages}
I used:
\begin{itemize}
    \item Armadillo: for sparse matrix construction and system solver;
    \item OPENMP: Armadillo is able to work with OPENMP and improve the code time execution;
    \item LAPACK and BLAS: this both libraries are not really used inside the code, but Armadillo use them as back-end libraries;
    \item Math: basic math librari for constants and basic functions (exponencial, pi, euler's constant ...)
\end{itemize}
