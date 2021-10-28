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
    }
    else {
        fb = (fb_t*)mmap(0, 128, PROT_READ | PROT_WRITE,MAP_SHARED, fbfd, 0);
        if (!fb) {
            printf("Failed to mmap.\n");
        }
        else {
            memset(fb, 0, 128);
            clear();
        }
        close(fbfd);
    }

    printf("SenseHAT init done.\n");
}

// https://compiler-explorer.com/z/YM963o1Ya
