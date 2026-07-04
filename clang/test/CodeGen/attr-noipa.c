// RUN: %clang_cc1 -emit-llvm -x c %s -triple x86_64-unknown-linux-gnu -O1 -o - | FileCheck %s --check-prefix=C
// RUN: %clang_cc1 -emit-llvm -x c++ %s -triple x86_64-unknown-linux-gnu -std=c++23 -O1 -o - | FileCheck %s --check-prefix=CXX

// C-LABEL: define {{.*}} @with_noipa(
// C-SAME: ) {{.*}}#[[NOIPA_ATTR:[0-9]+]] {
__attribute__((noipa)) int with_noipa(int x) {
  return x + 1;
}

// C-LABEL: define {{.*}} @without_noipa(
// C-SAME: ) {{.*}}#[[PLAIN_ATTR:[0-9]+]] {
int without_noipa(int x) {
  return x - 1;
}

// CXX-LABEL: define {{.*}} @_Z10with_noipai(
// CXX-SAME: ) {{.*}}#[[NOIPA_ATTR:[0-9]+]] {

// CXX-LABEL: define {{.*}} @_Z13without_noipai(
// CXX-SAME: ) {{.*}}#[[PLAIN_ATTR:[0-9]+]] {

// C: attributes #[[NOIPA_ATTR]] = { {{.*}}noipa{{.*}} }
// C: attributes #[[PLAIN_ATTR]] = { {{.*}} }
// C-NOT: attributes #[[PLAIN_ATTR]] = { {{.*}}noipa{{.*}} }

// CXX: attributes #[[NOIPA_ATTR]] = { {{.*}}noipa{{.*}} }
// CXX: attributes #[[PLAIN_ATTR]] = { {{.*}} }
// CXX-NOT: attributes #[[PLAIN_ATTR]] = { {{.*}}noipa{{.*}} }
