#include <stdio.h>

int main(void) {
  int n;     /* ステップ数 */
  double x;  /* ステップ n における x の値 */
  double y;  /* x における y の値 */

  for (n=-100; n<=100; n++) {
    x = (double)n / 10;
    y = (x*x*x)/2 - x*x + 20*x;
    printf("%f %f\n", x, y);
  }

  return 0;
}
