# Wolfenstein 3D Clone in Pure C

🚧🚧 _**Work in Progress**_ 🚧🚧

I previously implemented a Wolfenstein 3D renderer from scratch in [C++](https://github.com/e6quisitory/wolf3d-clone). I then moved my implementation over to [Rust](https://github.com/e6quisitory/wolf3d-clone-rs), and plan to finish the project in Rust.

In the mean time though, I have a couple programming-heavy classes this term at school for which I'll need to code in pure C. So, to brush up on my C knowledge, and to learn the various design patterns and ways to structure code in pure C, I decided I'd port my Wolfenstein project to pure C.

C++ is quite the beast, allowing for as much abstraction as your heart desires. Thus, writing a game engine in C++ was a generally positive experience. In Rust, due to the borrowing rules and lifetimes, I encountered some of my C++ design patterns / code structure failing to satisfy the borrow checker, and thus had to learn the Rust ways of doing things.

Now in pure C, it's a game of simple structs and functions, i.e. a much more limited feature set compared to C++ and Rust. Thus, it shall be an interesting challenge to port over all of the Wolfenstein project's functionality to pure C.

I'll again be using SDL2 as the cross-pattern multimedia library for this project. It's a natural fit, as SDL2 is written in pure C.

## Build Instructions
Have `cmake`, `ninja` and [SDL2](https://github.com/libsdl-org/SDL/releases) installed. Then, after cloning this repo, from the root of it, run the following:
```
cd build
cmake -GNinja ../src
ninja
./wolf3d-clone-c
```

