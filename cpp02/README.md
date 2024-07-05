# CPP Module02 

## ex00

## ex01

## ex02

## ex03 BSP

Implement a function which indicates whether a point is inside of a triangle or not.

<img width="80%" alt="bsp01" src="https://github.com/ysengoku/42-cpp/assets/130462445/ce3270c9-f8bb-4dbf-bcd1-ea5d30b6622c">

### Area Method Algorithm  
I used the area method to determine if a point P lies inside a triangle formed by three points A, B, and C.  
The algorithm compares the area of triangle ABC with the sum of the areas of triangles PAB, PBC, and PCA. 
If the sum of the areas of these three triangles equals the area of triangle ABC, then point P is inside the triangle.

#### Steps
1. Define the vertices of the triangle and the point to be tested:   
  - Triangle vertices: A(x1,y1), B(x2,y2), and C(x3,y3).   
  - Point to test: P(x,y).   

2. Calculate the area of a triangle:
I used Shoelace formula to calculate the area of a triangle.   
For the triangle ABC, the formula is as following.   
`area = | 1/2 ((x2 - x1) * (y3 - y1)) - ((y2 - y1) * (x3 - x1))|`

<img width="80%" alt="bsp02" src="https://github.com/ysengoku/42-cpp/assets/130462445/a12b7b98-c67e-4cd4-b05b-a015e87a1708">

  
3. Comapre the area of the triangle ABC and the sum of 3 triangles PAB, PBC, and PCA.   
Because the subject says _"Thus, if the point is a vertex or on edge, it will return False."_, We need to check it before return the result.
- If the point is a vertex, P(x,y) equals A(x1,y1), B(x2,y2), or C(x3,y3).
- If the point is in edge, the area of one of the 3 triangles is zero.
