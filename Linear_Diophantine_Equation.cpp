//25x+15y=400
// first we will find one solution and then prove that there is a genralised solution (infinite set of solutions)
//Generalised form is ax+by=c
// let g=gcd(a,b) eg if a is 8 and b is 12 then g=4
// we can write a=k1*g and b=k2*g
// so the equation becomes k1*g*x+k2*g*y=c or k1*x+k2*y=c/g Now as the LHS is an integer so the RHS Must be an integer too
// hence c%g==0 or c=k3*g
// Now the equation becomes ax+by=k3*gcd(a,b)
//Using Extended Euclid algorithm, I know how to find out the solution to ax+by=gcd(a,b)
// Let after calling the recursive procedure the solution to the above equation is x' and y'
// then ax'+by'=gcd(a,b) multiplying the equation with k I get
// (a*k)x'+(b*k)y'=k*gcd(a,b)  --equation 1
// ax+by=k*gcd(a,b)  --equation 2
// from equation 1 and equation 2
// so x would be k*x' and y would be k*y'

//Generalised solution would be {x,y}={x0 +a/g*t , y0+ b/g*t} where g is gcd (a,b) and t is a paramater
// Proof of generalised solution would be by putting it in the equation ax+by=c