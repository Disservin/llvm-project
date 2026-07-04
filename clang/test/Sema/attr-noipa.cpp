// RUN: %clang_cc1 -verify -fsyntax-only %s

__attribute__((noipa)) int a; // expected-warning {{'noipa' attribute only applies to functions}}

__attribute__((noipa)) void t1();

__attribute__((noipa(2))) void t2(); // expected-error {{'noipa' attribute takes no arguments}}
