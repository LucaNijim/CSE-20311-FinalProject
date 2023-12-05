This program generates a visualization of the Mandelbrot set, an interesting and beautiful fractal. The image that will display first upon running the program has two panes. On the left, the Mandelbrot set will appear. The Mandelbrot set is defines as the set of all points $c$ that are complex numbers that satisfy the following property: if we consider the sequence $z_n$, where $z_0=0$ and it is defined recursively by $z_{n+1}=z_n^2+c$, then the sequence is bounded. This definition seems relatively opaque, but luckily in our case, the sequence is "bounded" if and only if its complex absolute value never exceeds 2. 

The Julia set is defined similarly, and there is one Julia set associated to each complex number $c$. it's the set of all points $x$ such that the sequence defined recursively by $z_0=x$, $z_{n+1}=z_n^2+c$ is bounded. 

The program allows one to see and navigate a subset of the complex plane and the points that are in the Mandelbrot set and Julia sets. 

Two questions may naturally arise. First, if the sets are well-defined, why do some Mandelbrot and Julia sets clearly show a gradient from black to white? The answer is that I use the escape time, or how many values of the sequence are needed before one has magnitude greater than 2, to color them. I make the assumption (which isn't true, but it's an approximation) that an escape value over 255 means it will be in the set, and I color these points pure white and stop the iteration there. 

Second: why is the first Julia set that appears simply a circle, and how can we find more interesting ones? There's a key relationship between julia sets and mandelbrot sets. A point is in the Mandelbrot set if and only if the Julia set based on that point contains the number 0. Furthermore, an interesting result in complex analysis is that points in the Mandelbrot set generate path-connected Julia sets, while points outside of the Mandelbrot set generate Julia sets with interior equal to the empty set. The important part for the reader is that the most visually interesting Julia sets are generated from points near the boundary of the Mandelbrot set.

Please reach out with any further questions, and read more about the fractals in question and see more beautiful visualizations than I can render at https://en.wikipedia.org/wiki/Mandelbrot_set. 
