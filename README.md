# Polynomial Calculator

- Polynomials are mathematical objects which are expressions of variables and coefficients added to-gether. These polynomials can use operator overloading in a very intuitive manner since most of the operators that we can overload are mathematical operators, which can also be applied to polynomials.
- In this implementation I will create a polynomial class, as well as a few derived classes, which will inherit some of the basic functionality of polynomials but add their own restrictions.

<img src="./Images/UML_Diagram.png" alt="UML Random" width="100%">

---

- ## Section 1: Polynomial Calculator


---

- ## Section 2: Requirements before running Code:

  - Install an `IDE` that compiles and runs C++ codes.
    - 1st Recommendation: `VS Code`
    - 2nd Recommendation: `IntelliJ IDEA`
    - 3rd Recommendation: `Visual Studio`
  - Setup Video:
    - Title: How to set up WSL Ubuntu terminal shell and run it from Visual Studio Code
    - Video Link: [Youtube-Video-Link](https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s)

  - ###### NB: The makefile is included to compile and run the code on the terminal.
    - ###### `Commands:=`
        - make clean
        - make
        - make run

    ```C++
    main:
    g++ -g *.cpp -std=c++98 -pedantic -o main

    clean:
    rm -f *.o *.tar.gz main
    reset
    clear

    run:
    valgrind --leak-check=full ./main

    tar:
    tar -cvz *.* -f Code.tar.gz

    untar:
    tar -zxvf *.tar.gz
    ```

---

---

<p align="center">The End, Thank You</p>

---

---
