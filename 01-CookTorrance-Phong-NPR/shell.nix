{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  packages = with pkgs; [
    cmake
    gcc
    gdb
    glfw
    glm
    mesa
    libGL
    pkg-config
    llvmPackages.clang-tools
  ];
}
