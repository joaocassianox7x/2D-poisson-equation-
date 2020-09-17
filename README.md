This code is able to solve Poisson's equation for "x" and "y" with time dependency and under Neumann Boundary Condition (NBC). The README summary will be shown as seen below:
<p align="center"><img src="/tex/7bf1fde6260dc84825f6353758270a11.svg?invert_in_darkmode&sanitize=true" align=middle width=326.53059945pt height=113.24201624999999pt/></p>

# PACKAGES
Five different packages were used:
<p align="center"><img src="/tex/a1f062da0bca07af9ebd725f2e0aff78.svg?invert_in_darkmode&sanitize=true" align=middle width=675.6169678499999pt height=185.57078264999998pt/></p>

# Basic Constants and Considerations
The code uses a square lattice where "x" and "y" are in the close interval [0,a]. The charge distribution is placed in the "charge_distribution" function. The "time_sol" function solves the hole system for each time step, for that to happen you need to create two files ("charge" and "poisson"): i)in the first one we want to save the charge distribution to plot in the Python file; ii) the second one is the most important because it saves the PDE solution, the file has a number (filen) where "n" is the number of the time step with that configuration.

# 2-D Laplacian in Finite-Difference Method
The Laplace operator for two dimentions:

<p align="center"><img src="/tex/90f978af0020da04a46fe481a9f72722.svg?invert_in_darkmode&sanitize=true" align=middle width=244.71930779999997pt height=38.973783749999996pt/></p>

In the discrete domain, "x" and "y" become "i" and "j" (<img src="/tex/a514cb4ecbeeadb2ec506d6853cc0da7.svg?invert_in_darkmode&sanitize=true" align=middle width=101.45938274999999pt height=24.65753399999998pt/>) and also in my code "<img src="/tex/d2228dcd964eb02fa342af3116b4ac2b.svg?invert_in_darkmode&sanitize=true" align=middle width=92.69005514999999pt height=22.831056599999986pt/>", so the above equation becomes:

![Image of Grid](pictures/grid.png)

<p align="center"><img src="/tex/7541697d815f4cacd8c30e4105181b15.svg?invert_in_darkmode&sanitize=true" align=middle width=713.60179605pt height=33.81208709999999pt/></p>

So we can use the above equation as a matrix, but here we have a real big matrix, because for each <img src="/tex/5bee78fa60ead6227f0532f06ee2519f.svg?invert_in_darkmode&sanitize=true" align=middle width=127.50103079999998pt height=24.65753399999998pt/> we have <img src="/tex/3f629b41d66f9863c225a4879bf22093.svg?invert_in_darkmode&sanitize=true" align=middle width=26.30529494999999pt height=22.831056599999986pt/> <img src="/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>. So if we want to solve an NxN grid, our matrix will have dimension <img src="/tex/dce2940cef64fab623cb791ca86cbe90.svg?invert_in_darkmode&sanitize=true" align=middle width=53.32193129999998pt height=26.76175259999998pt/>. So that's the reason behind the use of Sparse matrix. 

![Image of Matrix](pictures/sparse_matrix.jpeg)


# PDE
Poisson's equation is well-known:

<p align="center"><img src="/tex/da59378424ab0fd9818bdc340966c044.svg?invert_in_darkmode&sanitize=true" align=middle width=98.1945756pt height=18.905967299999997pt/></p>
 
Notice that we need to solve one system for each time step. Also, since we already have the vector "<img src="/tex/26c10cb46001fc4981b80a871eaccbd0.svg?invert_in_darkmode&sanitize=true" align=middle width=27.416429699999988pt height=14.15524440000002pt/>" and the matrix "<img src="/tex/5e895dd204708dc9847f42fa146f280e.svg?invert_in_darkmode&sanitize=true" align=middle width=20.25121889999999pt height=26.76175259999998pt/>", but "<img src="/tex/afdfc127ee67a9f3feef38c0ce6c69d2.svg?invert_in_darkmode&sanitize=true" align=middle width=26.965532549999992pt height=22.831056599999986pt/>" is unknown we have a problem like "<img src="/tex/70681e99f542745bf6a0c56bd4600b39.svg?invert_in_darkmode&sanitize=true" align=middle width=50.69621369999999pt height=22.831056599999986pt/>". For that I used the routine "spsolve" from Armadillo's library.
