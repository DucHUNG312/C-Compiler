# Build LLVM 17.0.6 with Visual Studio 2022 (Windows x64)

### Build LLVM

- This instruction is used for LLVM version 17.0.6 on Windows x64 operating system, for requirements of hardware, software, toolchain..., please refer to **[LLVM documentation](https://llvm.org/docs/GettingStarted.html#requirements)**.

- First, download llvm-project-17.0.6.src.tar.xz **[here](https://github.com/llvm/llvm-project/releases/tag/llvmorg-17.0.6)** and unzip it.

- For example, to build LLVM with clang, clang-tools-extra(optional) and lld(optional) in Release:

  ```
  cmake -S llvm -B build -DCMAKE_BUILD_TYPE="Release" -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra;lld" -DLLVM_TARGETS_TO_BUILD=X86 -Thost=x64
  ```

- Cmake will generate a `LLVM.sln` solution file in the `build` folder, use Visual Studio to build LLVM in `Release` mode (Visual Studio set the Debug mode by default, change it to Release).

- **Note**, build Release takes about `1 hour` on my Core i7 16GB RAM machine and `2-3 GB` memory, build Debug will take `much slower` and could consume more than `100GB` memory !!!

### Build the project

- Note that because I build LLVM in Release, therefore I only can run the project in `Release` mode, (will fix later).

- Create an environment variable name `LLVM17`, point to your installation path (folder that you unzip the source code, mine is `"D:\LLVM\llvm-project-17.0.6"`). Also create a new path in your Path point to the build bin folder in order to use `clang` in terminal (mine is `"D:\LLVM\llvm-project-17.0.6\build\Release\bin"`)

- Now you can run the `scripts\Setup.bat` to generate VS2022 project solution.
