/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __LINUX_PUBLIC_PRIVCMD_H__
#define __LINUX_PUBLIC_PRIVCMD_H__
#include <linux/types.h>
#include <linux/compiler.h>
#include <xen/interface/xen.h>
struct privcmd_hypercall {
  __u64 op;
  __u64 arg[5];
};
struct privcmd_mmap_entry {
  __u64 va;
  __u64 mfn;
  __u64 npages;
};
struct privcmd_mmap {
  int num;
  domid_t dom;
  struct privcmd_mmap_entry  * entry;
};
struct privcmd_mmapbatch {
  int num;
  domid_t dom;
  __u64 addr;
  xen_pfn_t  * arr;
};
#define PRIVCMD_MMAPBATCH_MFN_ERROR 0xf0000000U
#define PRIVCMD_MMAPBATCH_PAGED_ERROR 0x80000000U
struct privcmd_mmapbatch_v2 {
  unsigned int num;
  domid_t dom;
  __u64 addr;
  const xen_pfn_t  * arr;
  int  * err;
};
struct privcmd_dm_op_buf {
  void  * uptr;
  size_t size;
};
struct privcmd_dm_op {
  domid_t dom;
  __u16 num;
  const struct privcmd_dm_op_buf  * ubufs;
};
struct privcmd_mmap_resource {
  domid_t dom;
  __u32 type;
  __u32 id;
  __u32 idx;
  __u64 num;
  __u64 addr;
};
#define IOCTL_PRIVCMD_HYPERCALL _IOC(_IOC_NONE, 'P', 0, sizeof(struct privcmd_hypercall))
#define IOCTL_PRIVCMD_MMAP _IOC(_IOC_NONE, 'P', 2, sizeof(struct privcmd_mmap))
#define IOCTL_PRIVCMD_MMAPBATCH _IOC(_IOC_NONE, 'P', 3, sizeof(struct privcmd_mmapbatch))
#define IOCTL_PRIVCMD_MMAPBATCH_V2 _IOC(_IOC_NONE, 'P', 4, sizeof(struct privcmd_mmapbatch_v2))
#define IOCTL_PRIVCMD_DM_OP _IOC(_IOC_NONE, 'P', 5, sizeof(struct privcmd_dm_op))
#define IOCTL_PRIVCMD_RESTRICT _IOC(_IOC_NONE, 'P', 6, sizeof(domid_t))
#define IOCTL_PRIVCMD_MMAP_RESOURCE _IOC(_IOC_NONE, 'P', 7, sizeof(struct privcmd_mmap_resource))
#endif
