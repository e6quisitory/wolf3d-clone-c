# Raycaster in C

I previously implemented a Wolfenstein 3D renderer from scratch in [C++](https://github.com/e6quisitory/wolf3d-clone). I then moved my implementation over to [Rust](https://github.com/e6quisitory/wolf3d-clone-rs), and plan to finish the project in Rust.

This repo is a port of the basic raycasting code from that project over to plain vanilla C. The point of doing this was as a learning exercise to brush up on my knowledge of C. I had started a semester at school where I was taking a couple C-programming-heavy classes. I had experience with C++ and Rust, but very little in plain old C. Thus, porting the code over was a good refresher.

## Demo

https://github.com/e6quisitory/wolf3d-clone-c/assets/25702188/0cf7ded5-8664-4564-9fed-1d40833369ba

## A Game of Simple Structs & Functions

My Wolfenstein clone started as a C++ project. C++ is quite the beast, allowing for as much abstraction as your heart desires. Thus, writing a game from scratch in C++ was a generally positive experience. In Rust, due to the borrowing rules and lifetimes, I encountered some of my C++ design patterns / code structure failing to satisfy the borrow checker, and thus had to learn the Rust ways of doing things.

In C, it's a game of simple structs and functions, i.e. a much more limited feature set compared to C++ and Rust. But despite this, I didn't have to change the original code/architecture much to get this simple raycaster working. However, if I choose to port over more of the project's code to C, I'll likely encounter more of a challange with the tile system, due to the lack of inheritance/polymorphism in C, as well as enemy movement between tiles.

However, I think it shouldn't be too much of a challenge; even though C's feature set is limited, it is so simple and clean that program designs/architectures are easy to come up with. Sure, you might have to write a bit more code compared with using the powerful abstraction features in C++ and Rust, but, you can certainly still accomplish what you're trying to, and, honestly, your code and design/architecture will probably be simpler and much easier to keep track of and maintain.

## Build Instructions
Have `cmake`, `ninja` and [SDL2](https://github.com/libsdl-org/SDL/releases) installed. Then, after cloning this repo, from the root of it, run the following:
```
cd build
cmake -GNinja ..
ninja
./c-raycaster
```
