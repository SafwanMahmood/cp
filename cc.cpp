
// A C++ program to check if a given point lies inside a given polygon
// Refer http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// for explanation of functions onSegment(), orientation() and doIntersect()
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <utility>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <vector>
#include <bitset>
#include <iomanip>
using namespace std;
 
// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10000
 
struct Point
{
    int x;
    int y;
};
 
bool isInsidecc(Point p1, int rad, Point p2)
{
    // Compare radius of circle with distance of its center from 
    // given point
    if ((p2.x - p1.x)*(p2.x - p1.x) + 
        (p2.y - p1.y)*(p2.y - p1.y) <= rad*rad)
        return true;
    else
        return false;
} 
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

 
// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}
 
// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}
int maxx =99999;
int maxy =99999;
int mixx =-99999;
int mixy =-99999;
bool isInsidesq(Point *sq,Point p)
{
	int x ;
	for (int i = 0; i < 4; ++i)
	{
		if (sq[i].x < maxx )
		{
			maxx = sq[i].x;
		}
		if (sq[i].y < maxy )
		{
			maxy = sq[i].y;
		}
		if (sq[i].x > mixx )
		{
			mixx = sq[i].x;
		}
		if (sq[i].y > mixy )
		{
			mixy = sq[i].y;
		}
	}
	
	if ( p.x > maxx && p.x< mixx && p.y > maxy && p.y < mixy)
	{
		return true;
	}
	return false;
}
 
// Driver program to test above functions
int main()
{
    Point sq[4];
     // =  {{8, 14}, {12, 10},{16, 14}, {12, 20}};
    
    int h,w,radius;
    cin>>h>>w;
    Point circle;
    cin>>circle.x>>circle.y>>radius;
     Point sq1[2];
    for (int i = 0; i < 2; ++i)
     {
     	cin>>sq1[i].x>>sq1[i].y;
     }
     if(sq1[0].y==sq1[1].y)
     {	
     sq[0].x = abs(sq1[0].x - sq1[1].x)/2 + min(sq1[1].x,sq1[0].x);
     sq[2].x = abs(sq1[0].x - sq1[1].x)/2 + min(sq1[1].x,sq1[0].x);
     sq[0].y = abs(sq1[0].x - sq1[1].x)/2 + sq1[1].y;
     sq[2].y =  sq1[1].y - abs(sq1[0].x - sq1[1].x)/2;
     if(sq1[1].x>sq1[0].x)
     {
     	sq[1] = sq1[0];
     	sq[3] = sq1[1];
     }
     else
     {
           sq[1] = sq1[1];
     	sq[3] = sq1[0];   
       }
     }

     else
     {
         sq[0].y = abs(sq1[0].y - sq1[1].y)/2 + min(sq1[1].y,sq1[0].y);
     sq[2].y = abs(sq1[0].y - sq1[1].y)/2 + min(sq1[1].y,sq1[0].y);
     sq[0].y = abs(sq1[0].y - sq1[1].y)/2 + sq1[1].y;
     sq[2].x =  sq1[1].x - abs(sq1[0].y - sq1[1].y)/2;
     if(sq1[1].y>sq1[0].y)
     {
     	sq[1] = sq1[0];
     	sq[3] = sq1[1];
     }
     else{
           sq[1] = sq1[1];
     	sq[3] = sq1[0];   
       }
     } 
      swap(sq[0],sq[2]);  
     for (int i = 0; i < w; ++i)
     {
     	for (int j = 0; j < h; ++j)
     	{
     		Point p;
     		p.x = j;
     		p.y = i;
     		if (isInside(sq,4,p) || isInsidecc(circle,radius,p))
     		 {
     		 	cout<<"#";
     		 }
        //     else if (p.x > min(sq1[0].x,sq1[1].x) && p.x < max(sq1[0].x,sq1[1].x)  && p.y == sq1[0].y )
     		 //  {
     		 //  	cout<<"#";
     		 //  }
     		 // else if (p.y > min(sq1[0].y,sq1[1].y) && p.y < max(sq1[0].y,sq1[1].y)  && p.x == sq1[0].x )
     		 //  {
     		 //  	cout<<"#";
     		 //  }   
     	
     		else{
     			cout<<".";
     		}

     	}
     	cout<<endl;
     }

    return 0;
}