# AtCoder Begineer Contest 181

[Tasks](https://atcoder.jp/contests/abc181/tasks_print)

## A - Heavy Rotation

White in even days and black in odd days.

Time complexity: $O(1)$.

## B - Trapezoid Sum 

Note that $\sum_{i=a}^{b} = \frac{(a+b)(b-a+1)}{2}$ when $b > a$. Sum over all the ranges.

Time complexity: $O(N)$.

## C - Collinearity

Since the point set is small, thus we can loop over arbitrary triplets of points and judge whether they are in the same line.

Time complexity: $O(N^3)$.

Also, we can loop over one point, use `unordered_map` to store different slopes between this point and the other point.

Time complexity: $O(N^2)$.

Note: calculate `gcd` before store / compare the slope.

## D - Hachi

Since `1e3 % 8 == 0`, thus we only need to investigate (at most) the last 3 digits. Maintain a frequency table of each digit and check if one number who is multiple of 8 can be composed by subset of these digits.

Time complexity: $O(|S|)$.

Note: It is slightkly different in checking process when `S` only has one or two digit(s).

## E - Transformable Teacher

First, sort the child list. It is easy to find that choosing pairs sequently in a **sorted** array is the best option. Then we can use **binary search** to find the insert position of each teacher and maintain the minimized sum of the differences. To save time, we can use **prefix/suffix sum** trick maintain the sum before / after the insert position.

Time complexity: $O(N + M\log(N))$.

## F - Silver Woods

Key points: Union-Find, Binary Search

First, we **binary search** the radius of circle to find the max value that the circle can walk through. For each nail, we check whether the circle could walk through this nail and other nails / lines. 

Thus we can use **union-find** data structure to maintain the "connectitivity". For each pair, if the circle cannot connect, we link them together. And the final connectitivity of top and bottom lines determines whether the circle can walk through.

Time complexity: $O(N^2\log(y))$, where $y$ denotes the distance between two lines.