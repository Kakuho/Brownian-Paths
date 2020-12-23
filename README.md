# Brownian-Paths
A simulation of the paths of Brownian Motion. 

Brownian Motion is the name given to a stochastic process which has stationary independent increments that neccesarily follows an gaussian distribution. The process 
can be found in many applications to natural sciences and also economics and finance. It is for this reason that makes Brownian motion a very interesting process to study as understanding it gives us many tools to deal with uncertainty in the aforementioned fields. 

The code in here simulates a realisation of a path Brownian motion can take. This means that we fix a value in the sample space of all Brownian paths and letting
the time parameter vary, giving us one possible path. Further, the program saves the data to a csv file called "bmdata.csv" so if ran, allowing us to plot the path 
using any software which can display csv data such as Matlab and R.

Algorithm found in Ren ́e L. Schilling and Lothar Partzsch. Brownian Motion: An Introduction to Stochastic Pro- cesses. De Gruyter, 2012. isbn: 978-3-11-027898-9.
