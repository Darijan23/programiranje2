#include <stdio.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void print_binary(uint32_t b, int n) {
	uint32_t p = (1 << (n - 1));

	while(p != 0) {
		printf("%d",b & p ? 1 : 0);
		p >>= 1;
	}
	printf("\n");
}

uint32_t create_bitmask(int n) {
	uint32_t mask = 0;

	for (int i = 0; i < n; i++) {
		mask <<= 1;
		mask |= 1;
	}

	return mask;
}

uint32_t reverse_binary(uint32_t input, int n) {
    uint32_t output = 0;
    
    for (int i = 0; i < n; i++) {
        output <<= 1;
        output |= input & 0x01;
        input >>= 1;
    }

    return output;
}

int main() {
  uint32_t bin = 0;
  int n;

  scanf("%d", &n);

  uint32_t halfmask = create_bitmask((n >> 1));
  uint32_t mask = create_bitmask(n);

  // Implementirajte modalitet rada sukladno uputama
  print_binary(0, n);
  bin = 1 & mask;
  bin |= reverse_binary(bin, n);
  uint32_t mov = reverse_binary(1, n);
  while ((~mov & 2) != 0) {
    mov >>= 1;
    print_binary(bin | mov, n);
  }


  return 0;
}