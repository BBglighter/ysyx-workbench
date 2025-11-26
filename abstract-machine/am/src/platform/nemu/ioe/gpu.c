#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // int i;
  // AM_GPU_CONFIG_T info = io_read(AM_GPU_CONFIG);
  // int w = info.width, h = info.height;
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t wh = inl(VGACTL_ADDR);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = wh >> 16, .height = wh & 0xFFFF,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t x = ctl->x,y = ctl->y,w = ctl->w,h = ctl->h;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *pixels = (uint32_t *)(uintptr_t)(ctl->pixels);
  uint32_t len = inl(VGACTL_ADDR) >> 16;
  for(int i = y;i < y+h;i ++){
    for(int j = x;j < x+w;j ++){
      fb[len*i + j] = pixels[(i-y)*w + (j-x)]; 
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
