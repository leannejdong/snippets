#include <stdio.h>
#include <sys/mman.h>
#include <memory.h>
#include <unistd.h>

extern int open_fbdev(const char *);
extern void clear();

struct fb_t;

fb_t *fb;


void f()
{
    // based on snake.c (SenseHAT examples)
    int fbfd = 0;
    fbfd = open_fbdev("RPi-Sense FB");
    if (fbfd <= 0) {
        printf("Error: cannot open framebuffer device.\n");
        goto err_ev;
    }
    fb = (fb_t*)mmap(0, 128, PROT_READ | PROT_WRITE,MAP_SHARED, fbfd, 0);
    if (!fb) {
        printf("Failed to mmap.\n");
        goto err_fb;
    }
    memset(fb, 0, 128);
    clear();
    err_fb: close(fbfd);
    err_ev: printf("SenseHAT init done.\n");
}

/* How to refactor?
One would try to look at the code and understand what it is doing, then write equivalent code.
here is that function put into CE: https://compiler-explorer.com/z/YsxE35o8v
the goto on line 21 is skipping over most of the rest of the function
this is similar to what an else does
{
  if (A) {
    B
    goto a;
  }
  C
  a: D
}
is like
{
  if (A) {
    B
  }
  else {
    C
  }
  D
}

so we can change the code like that: https://compiler-explorer.com/z/cdGffEq9o
the other goto is similar
so it can be changed like this: https://compiler-explorer.com/z/77veG4EP6

*/
