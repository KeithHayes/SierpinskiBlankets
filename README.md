# Sierpinski Gaskets and Carpets

This is a Qt C++ project.  The project implements the code of chapter **six** from the Book,  '***Real World Fractals*** by Mark Finlay and Keith Blanton ISBN _1-55851-307-8_   '.  This book  was published in 1993.  

This program essentially reproduces the second demonstration program of this very interesting book.

 Originally the program was written for the IBM PC using Borland 3.0 C++.  I reversed engineered, extracted, and rewrote, the C++ methods and techniques of the chapter six demonstration program.  The program originally was targeted for 32 bit IBM PCs running DOS.  Output now displays in a Qt Widget.

This is the second program I have reversed engineered from this book.  The point of this chapter was to expand on using recursion to fill a video screen.  Recursion was introduced in the chapter 5 demo.

From a programmers point of view this chapter is more exciting to study. The pictures generated are not as artistic as those of chapter 5. The point here was to illustrate recursion. Not to make pretty pictures.

The original program used a tacky light show generated by random flashing colors to make things interesting. Lots of flashing lights, but I did not implement that code. Instead I expanded on demonstrating recursion more than the original code had.

I began by carefully reproducing the original code as much a possible. Once code worked I realized code which implements the different options could be better organized. I made appropriate changes.

The pictures shown here were generated by the reverse star and reverse circle choices.  The reverse circle choice was then modified to produce the Extinction Rebellion symbol shown in the bottom image.  

The 'reverse' options write to the screen at each recursive call instead of when the recursive exit condition is reached. To produce the XR symbol multiple objects are drawn over each other at each recursive call. The original program had not drawn more than one object at a time despite the code having the capacity to do so.


![stars](https://user-images.githubusercontent.com/4401125/103143777-27d0bd80-46d2-11eb-8465-c970d0dfb7ad.png)


![eraseInitiator](https://user-images.githubusercontent.com/4401125/103143502-30be9080-46cc-11eb-8ec9-a868b89439b0.png)

![XR](https://user-images.githubusercontent.com/4401125/103167200-fcd39000-47dd-11eb-99df-6498d2eb765e.png)