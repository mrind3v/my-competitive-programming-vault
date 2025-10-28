# Pointers
To declare a pointer -> pick the type of pointer with a star and name it
For example, let's create an integer pointer
```cpp
int* ptr
```
What is it really? It's a variable that holds the memory address of the thing it is pointing to. In our case, it is pointing to an integer (because it is of integer type) and holds the memory address of that integer.
By default (the moment the pointer is created - be it of any type) when its not instructed to point to anything (in our case, where we have just declared it ), holds the value 0 or 0x0 in hex.
This is what our pointer looks like now:
```text
name: ptr
-------
| 0x0 |--->
-------
```
let's create two more vars and initialise with some values.
```cpp
int var = 10
int foo = 20
```
var and foo now is automatically assigned some memory address

In a nutshell, Everytime you create any variable (be it a integer pointer variable or just an integer variable), you will get a box with a name. You may initialise that variable with some value inside it or not -> it's your choice
So, if we try to print, ptr, var and foo:

```cpp
cout<<ptr // we get 0x0 (bcus that's what's inside the ptr box)
cout<<var // we get 10 (inside the var box)
cout<<foo // we get 20 (inside the foo box)
```

Now, if we instead try to print `*ptr`, we would get something else - some garbage value (as the memory addr inside ptr has nothing inside it as of right now). The `*` in `*(some pointer name)` is called the de-reference operator that gives the value that is in the memory addr held in the pointer box/variable 

Next, we try to store address of a variable inside our pointer box. Let's try to store the address of var inside ptr:
```cpp
ptr = &var
```
so ptr box now holds the address of var instead of 0x0. Therefore now if we do
```cpp
cout<<*ptr // output: 10
```


# References 
Creating a reference to a var means creating a different name for the same var - both the reference and the var have the same memory addr

```cpp
int var = 10 // if var has mem addr 0xA
int& ref // then ref also has mem addr as 0xA

// Therefore
cout<<var // output: 10
cout<<ref // output: 10
```
This is how it looks like
```text
var,ref
------
| 10 |
------
 0xA
```
Now if an int ptr stores the memory address of var and then we try to de-ref ptr, we get the same output for var and ref
```cpp
int* ptr = &var // meaning, ptr's stores mem addr of var
cout<<*ptr // output: 10

// Then we store the addr of ref instead
ptr = &ref
cout<<*ptr // output: 10
```


# Arrow operator

Let's define a pointer ptr (of type Class) which stores the memory addr of some object of type Class
```cpp
struct Point {
    int x;
    int y;
}
Point p;
p.x=10;
p.y=20;

Point* ptr = &p // ptr box stores the mem addr of obj p which is of type Point

cout<<p.x // output: 10
cout<<ptr->x // output: 10
```
Here the notation `ptr->x` is same as `(*ptr).x` which in turn is same as `p.x`. Therefore, what the arrow operator does is basically "deference first and then access a member"