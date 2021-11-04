#include<iostream>

void check(int64_t a, int64_t b, int64_t c) {
  int64_t k = a+b+c;
  k = k*k*k;
  int64_t l = (a*10000+b)*10000+c;
  if(k==l) {
    std::cout << "(" << a << " + " << b << " + " << c <<")^3 = "
              << l << std::endl;
  }
}

int main() {
  int64_t a, b, c;
  for(a=0; a < 10000; ++a) for(b=0; b < 10000; ++b) {
    int k=(a+b)%10;
    switch(k) {
      case 0:
      for(c=0; c < 10000; c+=10) {
        check(a, b, c);
        check(a, b, c+1);
        check(a, b, c+4);
        check(a, b, c+5);
        check(a, b, c+6);
        check(a, b, c+9);
      }
      break;
      case 4:
      for(c=0; c < 10000; c+=10) {
        check(a, b, c+3);
        check(a, b, c+8);
      }
      break;
      case 6:
      for(c=0; c < 10000; c+=10) {
        check(a, b, c+2);
        check(a, b, c+7);
      }
      break;
    }
  }
  return 0;
}
