pkgname=ashellwig_m5c9_programming_assignment-bin
_pkgname=ashellwig_m5c9_programming_assignment

pkgver=0.0.1
pkgrel=1

pkgdesc="Solution to FRCC/CCCOnline SP2020 CSC160: C++ course's assignment"
pkgdesc+=" in Module 5 for Chapter 9."

source=(
  "$pkgname::git+https://github.com/ashellwig/ashellwig_m5c9_programming_assignment.git#branch=master"
)

url="https://github.com/ashellwig/ashellwig_m5c9_programming_assignment"
license=('LGPLv3')
privides=('ashellwig_m5c9_programming_assignment')
conflicts=('ashellwig_m5c9_programming_assignment')

arch=('x86_64')
makedepends=('cmake' 'gcc-libs' 'make' 'latex-core')
md5sums=('SKIP')

pkgver() {
  cd "${srcdir}/${pkgname}" || exit 2
  set -o pipefail
  git describe --long | sed 's/\([^-]*-g\)/r\1/;s/-/./g' || echo 0.0.1
}

prepare() {
  true
}

build() {
  true
}

check() {
  true
}

install() {
  true
}
