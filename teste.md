

The code is able to solve the poisson's equation for "x" and "y" with time dependency with Neumann Boundary Condition. The README summary will be show below:
<p align="center"><img src="/tex/be63886edc93d55af260a77763eaf16a.svg?invert_in_darkmode&sanitize=true" align=middle width=327.9004575pt height=113.24201624999999pt/></p>

# PACKAGES
I used:
<p align="center"><img src="/tex/801f63865fe5c36ba7fbd72555081c32.svg?invert_in_darkmode&sanitize=true" align=middle width=675.61696125pt height=153.60730934999998pt/></p>



# 2-D Laplacian in Finite-Difference Method
The Laplace operator for two dimentions:

<p align="center"><img src="/tex/90f978af0020da04a46fe481a9f72722.svg?invert_in_darkmode&sanitize=true" align=middle width=244.71930779999997pt height=38.973783749999996pt/></p>

In the discrete domain "x" and "y" become "i" and "j" (<img src="/tex/a514cb4ecbeeadb2ec506d6853cc0da7.svg?invert_in_darkmode&sanitize=true" align=middle width=101.45938274999999pt height=24.65753399999998pt/>) and also in my code "<img src="/tex/d2228dcd964eb02fa342af3116b4ac2b.svg?invert_in_darkmode&sanitize=true" align=middle width=92.69005514999999pt height=22.831056599999986pt/>", so the above equation become:

![Image of Grid](https://github.com/joaocassianox7x/HPC_POISSON/tree/master/pictures/grid.png)


<p align="center"><img src="/tex/7541697d815f4cacd8c30e4105181b15.svg?invert_in_darkmode&sanitize=true" align=middle width=713.60179605pt height=33.81208709999999pt/></p>

So we can use the above equation as a matrix, but here we have a real big matrix, because for each <img src="/tex/5bee78fa60ead6227f0532f06ee2519f.svg?invert_in_darkmode&sanitize=true" align=middle width=127.50103079999998pt height=24.65753399999998pt/> we have <img src="/tex/3f629b41d66f9863c225a4879bf22093.svg?invert_in_darkmode&sanitize=true" align=middle width=26.30529494999999pt height=22.831056599999986pt/> <img src="/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/> so with we want to solve a NxN grid our matrix will have dimension <img src="/tex/4c87ee198ded31321f89b44a38a0ad5a.svg?invert_in_darkmode&sanitize=true" align=middle width=21.552516149999988pt height=26.76175259999998pt/>. So that's the reason behind the use of Sparse matrix. 

![Image of Matrix](https://github.com/joaocassianox7x/HPC_POISSON/tree/master/pictures/sparse_matrix.jpeg)


# PDE
The Poisson's equation is well know:

<p align="center"><img src="/tex/da59378424ab0fd9818bdc340966c044.svg?invert_in_darkmode&sanitize=true" align=middle width=98.1945756pt height=18.905967299999997pt/></p>
 
Notice that we need to solve one system for each time step, also since we already have the vector "<img src="/tex/26c10cb46001fc4981b80a871eaccbd0.svg?invert_in_darkmode&sanitize=true" align=middle width=27.416429699999988pt height=14.15524440000002pt/>" and the matrix "<img src="/tex/5e895dd204708dc9847f42fa146f280e.svg?invert_in_darkmode&sanitize=true" align=middle width=20.25121889999999pt height=26.76175259999998pt/>" and "<img src="/tex/afdfc127ee67a9f3feef38c0ce6c69d2.svg?invert_in_darkmode&sanitize=true" align=middle width=26.965532549999992pt height=22.831056599999986pt/>" in unknow we have a problem like "<img src="/tex/70681e99f542745bf6a0c56bd4600b39.svg?invert_in_darkmode&sanitize=true" align=middle width=50.69621369999999pt height=22.831056599999986pt/>". For that I used the routine "spsolve" of the Armadillo's library.
\end{document}
