/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_NFSD_FH_H
#define _UAPI_LINUX_NFSD_FH_H
#include <linux/types.h>
#include <linux/nfs.h>
#include <linux/nfs2.h>
#include <linux/nfs3.h>
#include <linux/nfs4.h>
struct nfs_fhbase_old {
  __u32 fb_dcookie;
  __u32 fb_ino;
  __u32 fb_dirino;
  __u32 fb_dev;
  __u32 fb_xdev;
  __u32 fb_xino;
  __u32 fb_generation;
};
struct nfs_fhbase_new {
  __u8 fb_version;
  __u8 fb_auth_type;
  __u8 fb_fsid_type;
  __u8 fb_fileid_type;
  __u32 fb_auth[1];
};
struct knfsd_fh {
  unsigned int fh_size;
  union {
    struct nfs_fhbase_old fh_old;
    __u32 fh_pad[NFS4_FHSIZE / 4];
    struct nfs_fhbase_new fh_new;
  } fh_base;
};
#define ofh_dcookie fh_base.fh_old.fb_dcookie
#define ofh_ino fh_base.fh_old.fb_ino
#define ofh_dirino fh_base.fh_old.fb_dirino
#define ofh_dev fh_base.fh_old.fb_dev
#define ofh_xdev fh_base.fh_old.fb_xdev
#define ofh_xino fh_base.fh_old.fb_xino
#define ofh_generation fh_base.fh_old.fb_generation
#define fh_version fh_base.fh_new.fb_version
#define fh_fsid_type fh_base.fh_new.fb_fsid_type
#define fh_auth_type fh_base.fh_new.fb_auth_type
#define fh_fileid_type fh_base.fh_new.fb_fileid_type
#define fh_fsid fh_base.fh_new.fb_auth
#define fh_auth fh_base.fh_new.fb_auth
#endif
